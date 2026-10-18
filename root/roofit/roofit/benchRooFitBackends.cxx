/*
 * Project: RooFit
 * Authors:
 *   Jonas Rembser, CERN 2023
 *
 * Copyright (c) 2023, CERN
 *
 * Redistribution and use in source and binary forms,
 * with or without modification, are permitted according to the terms
 * listed in LICENSE (http://roofit.sourceforge.net/license.txt)
 */

// Benchmarks of unbinned maximum likelihood fits with the different RooFit
// evaluation backends. Each benchmark builds a model, generates a dataset of
// nEvents events from it, moves the parameters away from the generation
// values, and then times Migrad with strategy 0 on a likelihood that was
// created outside of the timed loop and is offset by its initial value. The benchmarks are named
// "<Model>_Fit<Backend>", which the script benchRooFitBackends_make_plot.py
// relies on. The CPU backend is benchmarked single-threaded (CPU) and with
// the multi-threaded evaluation on all threads of ROOT's implicit
// multi-threading pool (CPUMT). The benchmarks report wall-clock time, which
// is what matters when comparing thread counts.
//
// The information that is needed to label the results (CPU and GPU, ROOT
// version, the RooBatchCompute library that was loaded, VDT, number of
// events and threads) is written to the context of the benchmark output,
// which the JSON output format includes.
//
// The number of events per fit is 100k by default and can be changed with the
// "--events=N" option. Each benchmark does one untimed warm-up fit before the
// timed iterations. The slower fits take only one iteration, so run with
// "--benchmark_repetitions=3" to get a spread estimate; the plot script then
// uses the median. The number of likelihood evaluations, the Migrad status
// and the minimum NLL are reported as counters to check that the backends do
// the same work.

#include <RooAddModel.h>
#include <RooAddPdf.h>
#include <RooBMixDecay.h>
#include <RooCategory.h>
#include <RooDataSet.h>
#include <RooDecay.h>
#include <RooExponential.h>
#include <RooGaussModel.h>
#include <RooGaussian.h>
#include <RooGlobalFunc.h>
#include <RooHelpers.h>
#include <RooMinimizer.h>
#include <RooMsgService.h>
#include <RooRandom.h>
#include <RooRealVar.h>
#include <RooTruthModel.h>
#include <RooWorkspace.h>

#include <RConfigure.h>
#include <TROOT.h>
#include <TSystem.h>

#include <benchmark/benchmark.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace {

std::size_t nEvents = 100000; // can be set with the --events option

/// Silence RooFit, but keep the FastEvaluations info so we see which classes
/// still need to be supported by the evaluation backends.
std::unique_ptr<RooHelpers::LocalChangeMsgLevel> makeChangeMsgLvl()
{
   auto &msg = RooMsgService::instance();
   msg.reset();
   auto oldKillBelow = msg.globalKillBelow();
   auto out = std::make_unique<RooHelpers::LocalChangeMsgLevel>(RooFit::WARNING);
   msg.setGlobalKillBelow(oldKillBelow);
   msg.addStream(RooFit::INFO, RooFit::Topic(RooFit::FastEvaluations));
   return out;
}

/// Move the parameters away from the values that the dataset was generated
/// with, so that the fit doesn't start at the minimum. The parameters are not
/// randomized, because fits with many parameters are not stable from arbitrary
/// starting points: they are only shifted towards their upper limits by the
/// given fraction of the distance.
void shiftParameters(RooArgSet const &parameters, double fraction)
{
   for (auto *param : static_range_cast<RooRealVar *>(parameters)) {
      double val = param->getVal();
      param->setVal(val + fraction * (param->getMax() - val));
   }
}

/// Generate the dataset for a benchmark. The random generator is seeded before
/// each generation, such that every benchmark fits the same dataset no matter
/// in which order or how often the benchmarks run. Otherwise, the
/// minimization path and hence the timing would vary from run to run,
/// especially for the models that produce evaluation errors during the fit.
std::unique_ptr<RooDataSet> generateData(RooAbsPdf &pdf, RooArgSet const &observables)
{
   RooRandom::randomGenerator()->SetSeed(1337);
   return std::unique_ptr<RooDataSet>{pdf.generate(observables, nEvents)};
}

/// Set the parameters to uniformly distributed random values in their ranges,
/// for models with few parameters where the fit converges from anywhere.
void randomizeParameters(RooArgSet const &parameters, unsigned long seed)
{
   auto random = RooRandom::randomGenerator();
   random->SetSeed(seed);
   for (auto *param : static_range_cast<RooRealVar *>(parameters)) {
      param->setVal(param->getMin() + random->Uniform() * (param->getMax() - param->getMin()));
   }
}

/// Create the likelihood with the backend and the number of threads requested
/// by the benchmark arguments and time Migrad with strategy 0, starting from
/// the same parameter values (and errors, i.e. Minuit step sizes) in each
/// iteration. The parameters are expected to be moved away from the minimum
/// by the caller. A thread count of zero means all threads of ROOT's implicit
/// multi-threading pool, which main() enables.
void runFitBenchmark(benchmark::State &state, RooAbsPdf &pdf, RooAbsData &data)
{
   using namespace RooFit;

   auto evalBackend = static_cast<EvalBackend::Value>(state.range(0));
   auto nThreads = static_cast<int>(state.range(1));
   if (nThreads == 0) {
      nThreads = ROOT::GetThreadPoolSize();
   }
   state.counters["num_threads"] = nThreads;

   RooArgSet params;
   pdf.getParameters(data.get(), params);
   RooArgSet paramsInitial;
   params.snapshot(paramsInitial);

   // The likelihood is offset by its initial value, like it should be done for
   // large datasets: without it, the rounding errors of the large absolute NLL
   // values make Migrad fail to reach the required EDM from a few million
   // events on.
   std::unique_ptr<RooAbsReal> nll{
      pdf.createNLL(data, EvalBackend(evalBackend), NumCPU(nThreads), Offset("initial"))};

   // Every fit gets a fresh minimizer: the evaluation error recovery state of
   // the minimizer function (maximum FCN value, number of invalid
   // evaluations, function offset) persists across Migrad calls, so a second
   // fit with the same minimizer can take a different path than the first one
   // for models with evaluation errors. Creating the minimizer is not timed.
   auto makeMinimizer = [&]() {
      auto m = std::make_unique<RooMinimizer>(*nll);
      m->setPrintLevel(-1);
      m->setPrintEvalErrors(-1);
      m->setStrategy(0);
      return m;
   };

   // One untimed fit first: the first likelihood evaluations pay for one-time
   // work like loading libraries or plugins, spinning up the thread pool, or
   // loading the CUDA kernels. Google Benchmark reports the first iteration
   // as the result if it is slow enough, so without the warm-up that cost
   // would end up in the timing of the slow fits only.
   makeMinimizer()->migrad();
   params.assign(paramsInitial);

   auto m = makeMinimizer();
   for (auto _ : state) {
      const int status = m->migrad();
      state.PauseTiming();
      // The counters show whether the backends do the same work and whether
      // the fit succeeded. They are the same in every iteration, so the last
      // one is reported.
      state.counters["nll_evals"] = m->evalCounter();
      state.counters["migrad_status"] = status;
      state.counters["min_nll"] = nll->getVal();
      params.assign(paramsInitial);
      m = makeMinimizer();
      state.ResumeTiming();
   }
}

// Common objects of the B decay models.
struct BDecayVars {
   RooRealVar dt{"dt", "dt", -10, 10};
   RooRealVar dm{"dm", "delta m(B0)", 0.472, 0.1, 0.9};
   RooRealVar tau{"tau", "tau (B0)", 1.547, 1.3, 1.9};
   RooRealVar w{"w", "flavour mistag rate", 0.1, 0.0, 1.0};
   RooRealVar dw{"dw", "delta mistag rate for B0/B0bar", 0.1, 0.0, 1.0};
   RooCategory mixState{"mixState", "B0/B0bar mixing state"};
   RooCategory tagFlav{"tagFlav", "Flavour of the tagged B0"};

   BDecayVars()
   {
      dt.setBins(40);
      mixState.defineType("mixed", -1);
      mixState.defineType("unmixed", 1);
      tagFlav.defineType("B0", 1);
      tagFlav.defineType("B0bar", -1);
   }

   void generateAndRun(benchmark::State &state, RooAbsPdf &pdf)
   {
      std::unique_ptr<RooDataSet> data{generateData(pdf, {dt, mixState, tagFlav})};
      RooArgSet params;
      pdf.getParameters(data->get(), params);
      shiftParameters(params, 0.05);
      runFitBenchmark(state, pdf, *data);
   }
};

} // namespace

/// Gaussian with one observable.
static void benchFitGauss(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   RooRealVar x("x", "x", -1.5, 40.5);
   RooRealVar mean("mean", "mean of gaussian", 20., 15., 25.);
   RooRealVar sigma("sigma", "width of gaussian", 10., 8., 12.);
   RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

   std::unique_ptr<RooDataSet> data{generateData(gauss, {x})};
   randomizeParameters({mean, sigma}, 1337);
   runFitBenchmark(state, gauss, *data);
}

/// Gaussian with both x and sigma as observables, i.e. a conditional pdf.
static void benchFitGaussXSigma(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   RooRealVar x("x", "x", -1.5, 40.5);
   RooRealVar mean("mean", "mean of gaussian", 20., 15., 25.);
   RooRealVar sigma("sigma", "width of gaussian", 10., 8., 12.);
   RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

   std::unique_ptr<RooDataSet> data{generateData(gauss, {x, sigma})};
   randomizeParameters({mean}, 1337);
   runFitBenchmark(state, gauss, *data);
}

/// Sum of a Gaussian and an exponential.
static void benchFitAddPdf(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   RooRealVar x("x", "x", -1.5, 40.5);
   RooRealVar mean("mean", "mean of gaussian", 20., -10, 30);
   RooRealVar sigma("sigma", "width of gaussian", 4., 0.5, 10);
   RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);
   RooRealVar c1("c1", "Decay constant", -0.5, -10, -0.001);
   RooExponential ex{"Expo", "Exponential PDF", x, c1};
   RooRealVar fractionGaus("fractionGaus", "Fraction of Gauss component", 0.5, 0., 1.);
   RooAddPdf addPdf("SumGausExpo", "Sum of Gaus and Exponential", {gauss, ex}, fractionGaus);
   // to avoid a warning when computing the unnormalized RooAddPdf values
   addPdf.fixCoefNormalization(x);

   std::unique_ptr<RooDataSet> data{generateData(addPdf, {x})};
   randomizeParameters({mean, sigma, c1, fractionGaus}, 1337);
   runFitBenchmark(state, addPdf, *data);
}

/// Product of three one-dimensional mixtures.
static void benchFitProdPdf(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   RooWorkspace w;
   w.factory("Gaussian::g1(x[0,20],mx1[10,0,20],sx1[3,0.1,10])");
   w.factory("Gaussian::g2(x,mx2[10,0,20],sx2[1,0.1,10])");
   w.factory("Gaussian::g3(y[0,20],my[10,0,20],sy[2,0.1,10])");
   w.factory("Polynomial::pol(y,a[-0.01,-0.05,0.1])");
   w.factory("Gamma::gpdf(z[0,10],g[2,0.1,10],b[2,0.1,10],m0[-1,-20,0])");
   w.factory("SUM::pdfx(fx[0.2,0,1]*g1,g2)");
   w.factory("SUM::pdfy(fy[0.4,0.,1.]*g3,pol)");
   w.factory("PROD::model(pdfx,pdfy,gpdf)");

   auto &pdf = *w.pdf("model");
   std::unique_ptr<RooDataSet> data{generateData(pdf, {*w.var("x"), *w.var("y"), *w.var("z")})};
   RooArgSet parameters;
   pdf.getParameters(data->get(), parameters);
   shiftParameters(parameters, 0.05);
   runFitBenchmark(state, pdf, *data);
}

/// Extended sum of five components.
///
/// The Gamma component is a shoulder at low x, distinct from the broad
/// Gaussian, and the yield ranges scale with the number of events. Otherwise
/// the yields of two nearly identical components are degenerate and Migrad
/// often fails to converge, in particular with many events.
static void benchFitModel(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   RooWorkspace w;
   w.factory("Gamma::vpdf(x[0,20],g[2,0.1,40],b[2,0.01,10],m0[-1,-20,0])");
   w.factory("Gaussian::gpdf(x,m1[10,0,20],s1[2,0.1,10])");
   w.factory("Gaussian::g2(x,m2[5,0,20],s2[0.3,0.01,10])");
   w.factory("Gaussian::g3(x,m3[15,0,20],s3[0.4,0.01,10])");
   w.factory("Polynomial::pol(x,a[-0.01,-0.05,0.1])");
   w.factory("SUM::model(ns1[0,1]*vpdf,ns2[0,1]*gpdf,ng2[0,1]*g2,ng3[0,1]*g3,npol[0,1]*pol)");

   // The yields are set to the expected numbers of events, with ranges up to
   // ten times the total number of events.
   const std::pair<const char *, double> yields[] = {
      {"ns1", 0.2}, {"ns2", 0.3}, {"ng2", 0.1}, {"ng3", 0.1}, {"npol", 0.3}};
   for (auto const &[name, fraction] : yields) {
      w.var(name)->setRange(0, 10. * nEvents);
      w.var(name)->setVal(fraction * nEvents);
   }

   auto &pdf = *w.pdf("model");
   std::unique_ptr<RooDataSet> data{generateData(pdf, {*w.var("x")})};
   RooArgSet parameters;
   pdf.getParameters(data->get(), parameters);
   shiftParameters(parameters, 0.01);
   runFitBenchmark(state, pdf, *data);
}

/// B decay with mixing and a delta function resolution model.
static void benchFitBDecayWithMixing(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   BDecayVars v;
   RooTruthModel tm("tm", "truth model", v.dt);
   RooBMixDecay bmix("bmix", "decay", v.dt, v.mixState, v.tagFlav, v.tau, v.dm, v.w, v.dw, tm,
                     RooBMixDecay::DoubleSided);
   v.generateAndRun(state, bmix);
}

/// B decay convolved with a Gaussian resolution model.
static void benchFitBDecayGaussResolution(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   BDecayVars v;
   RooRealVar bias1("bias1", "bias1", 0, -1., 1.);
   RooRealVar sigma1("sigma1", "sigma1", 1, 0.1, 1.9);
   RooGaussModel gm1("gm1", "gauss model 1", v.dt, bias1, sigma1);
   RooDecay decay_gm1("decay_gm1", "decay", v.dt, v.tau, gm1, RooDecay::DoubleSided);
   v.generateAndRun(state, decay_gm1);
}

/// B decay convolved with a sum of two Gaussian resolution models.
static void benchFitBDecayDoubleGauss(benchmark::State &state)
{
   auto changeMsgLevel = makeChangeMsgLvl();

   BDecayVars v;
   RooRealVar bias1("bias1", "bias1", 0, -1., 1.);
   RooRealVar sigma1("sigma1", "sigma1", 1, 0.1, 1.9);
   RooGaussModel gm1("gm1", "gauss model 1", v.dt, bias1, sigma1);
   RooRealVar bias2("bias2", "bias2", 0, -1., 1.);
   RooRealVar sigma2("sigma2", "sigma2", 5, 0.5, 10);
   RooGaussModel gm2("gm2", "gauss model 2", v.dt, bias2, sigma2);
   RooRealVar gm1frac("gm1frac", "fraction of gm1", 0.5, 0.0, 1.0);
   RooAddModel gmsum("gmsum", "sum of gm1 and gm2", {gm1, gm2}, gm1frac);
   RooDecay decay_gmsum("decay_gmsum", "decay", v.dt, v.tau, gmsum, RooDecay::DoubleSided);
   v.generateAndRun(state, decay_gmsum);
}

namespace {

constexpr auto unit = benchmark::kMillisecond;

constexpr auto Cpu = static_cast<int>(RooFit::EvalBackend::Value::Cpu);
constexpr auto Cuda = static_cast<int>(RooFit::EvalBackend::Value::Cuda);
constexpr auto Codegen = static_cast<int>(RooFit::EvalBackend::Value::Codegen);

} // namespace

// The benchmark arguments are the evaluation backend and the number of
// threads, where zero means all threads of the implicit multi-threading pool.
#define BENCH_ENTRY(func, name, backend, nThreads) \
   BENCHMARK(func)->Unit(unit)->UseRealTime()->Name(name)->Args({backend, nThreads});

#ifdef DO_BENCH_ROOFIT_CUDA
#define BENCH_CUDA(func, model) BENCH_ENTRY(func, model "_FitCUDA", Cuda, 1)
#else
#define BENCH_CUDA(func, model)
#endif

// The CPU and CUDA backends support all models.
#define BENCH_BACKENDS(func, model)                  \
   BENCH_ENTRY(func, model "_FitCPU", Cpu, 1)        \
   BENCH_ENTRY(func, model "_FitCPUMT", Cpu, 0)      \
   BENCH_CUDA(func, model)

// The codegen variant is only registered for models that the codegen backend
// supports, and only if ROOT was built with clad, which the gradient needs.
#ifdef R__HAS_CLAD
#define BENCH_BACKENDS_WITH_CODEGEN(func, model)     \
   BENCH_BACKENDS(func, model)                       \
   BENCH_ENTRY(func, model "_FitCodegen", Codegen, 1)
#else
#define BENCH_BACKENDS_WITH_CODEGEN(func, model) BENCH_BACKENDS(func, model)
#endif

BENCH_BACKENDS_WITH_CODEGEN(benchFitGauss, "Gaus")
// Normalizing the Gaussian over both x and sigma requires a multi-dimensional
// numeric integral, which the codegen backend doesn't support.
BENCH_BACKENDS(benchFitGaussXSigma, "GausXS")
BENCH_BACKENDS_WITH_CODEGEN(benchFitAddPdf, "AddPdf")
BENCH_BACKENDS_WITH_CODEGEN(benchFitProdPdf, "ProdPdf")
BENCH_BACKENDS_WITH_CODEGEN(benchFitModel, "FitModel")
// The codegen backend has no analytical integrals for RooBMixDecay,
// RooGaussModel and RooAddModel yet.
BENCH_BACKENDS(benchFitBDecayWithMixing, "BDecayWithMixing")
BENCH_BACKENDS(benchFitBDecayGaussResolution, "BDecayGaussResolution")
BENCH_BACKENDS(benchFitBDecayDoubleGauss, "BDecayDoubleGauss")

namespace {

/// The CPU model name from /proc/cpuinfo, or "unknown" elsewhere than Linux.
std::string cpuModelName()
{
   std::ifstream in("/proc/cpuinfo");
   std::string line;
   while (std::getline(in, line)) {
      if (line.rfind("model name", 0) == 0) {
         auto pos = line.find(':');
         if (pos != std::string::npos) {
            pos = line.find_first_not_of(" \t", pos + 1);
            return pos == std::string::npos ? "unknown" : line.substr(pos);
         }
      }
   }
   return "unknown";
}

/// The name of the first NVIDIA GPU, as reported by nvidia-smi.
std::string gpuName()
{
   if (!gSystem->Which(gSystem->Getenv("PATH"), "nvidia-smi")) {
      return "unknown";
   }
   TString out = gSystem->GetFromPipe("nvidia-smi --query-gpu=name --format=csv,noheader 2> /dev/null");
   std::string name = out.Data();
   name = name.substr(0, name.find('\n'));
   return name.empty() ? "unknown" : name;
}

/// The RooBatchCompute library that RooFit loaded for the CPU backend, e.g.
/// "AVX2" or "GENERIC". It is chosen by the "RooFit.BatchCompute" setting of
/// the ROOT configuration (default: generic, "auto" for the fastest one that
/// the CPU supports) when the first likelihood is evaluated, so that is
/// triggered here with a minimal model.
std::string batchComputeLibrary()
{
   {
      RooHelpers::LocalChangeMsgLevel changeMsgLvl(RooFit::WARNING);
      RooRealVar x("x", "x", -5, 5);
      RooRealVar mean("mean", "mean", 0, -1, 1);
      RooRealVar sigma("sigma", "sigma", 1, 0.5, 2);
      RooGaussian gauss("gauss", "gauss", x, mean, sigma);
      std::unique_ptr<RooDataSet> data{gauss.generate({x}, 10)};
      std::unique_ptr<RooAbsReal> nll{gauss.createNLL(*data, RooFit::EvalBackend::Cpu())};
      nll->getVal();
   }
   // The name is taken from the list of loaded libraries, because the
   // RooBatchCompute interface that knows the architecture is not a public
   // header. The CUDA library is not loaded at this point.
   const std::string prefix = "libRooBatchCompute_";
   std::string libs = gSystem->GetLibraries();
   auto pos = libs.find(prefix);
   if (pos == std::string::npos) {
      return "unknown";
   }
   pos += prefix.size();
   return libs.substr(pos, libs.find(".so", pos) - pos);
}

} // namespace

int main(int argc, char **argv)
{
   // Take the "--events=N" option out of the arguments before Google
   // Benchmark parses the rest.
   std::vector<char *> args;
   for (int i = 0; i < argc; ++i) {
      const std::string arg = argv[i];
      const std::string prefix = "--events=";
      if (arg.rfind(prefix, 0) == 0) {
         nEvents = std::strtoull(arg.c_str() + prefix.size(), nullptr, 10);
         if (nEvents == 0) {
            std::cerr << "invalid number of events in \"" << arg << "\"" << std::endl;
            return 1;
         }
      } else {
         args.push_back(argv[i]);
      }
   }
   argc = args.size();
   args.push_back(nullptr);
   argv = args.data();

   benchmark::Initialize(&argc, argv);
   if (benchmark::ReportUnrecognizedArguments(argc, argv)) {
      return 1;
   }

   // Enable the implicit multi-threading up front, so that the process state
   // is the same for all benchmarks no matter in which order they run.
   ROOT::EnableImplicitMT();

   benchmark::AddCustomContext("root_version", gROOT->GetVersion());
   benchmark::AddCustomContext("batchcompute_library", batchComputeLibrary());
#ifdef R__HAS_VDT
   benchmark::AddCustomContext("vdt", "yes");
#else
   benchmark::AddCustomContext("vdt", "no");
#endif
   benchmark::AddCustomContext("events", std::to_string(nEvents));
   benchmark::AddCustomContext("threads", std::to_string(ROOT::GetThreadPoolSize()));
   benchmark::AddCustomContext("cpu", cpuModelName());
#ifdef DO_BENCH_ROOFIT_CUDA
   benchmark::AddCustomContext("gpu", gpuName());
#endif

   benchmark::RunSpecifiedBenchmarks();
   benchmark::Shutdown();
   return 0;
}
