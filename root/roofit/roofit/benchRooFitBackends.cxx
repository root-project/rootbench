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

#include <RooAddPdf.h>
#include <RooDataSet.h>
#include <RooExponential.h>
#include <RooFitResult.h>
#include <RooGaussian.h>
#include <RooRandom.h>
#include <RooRealVar.h>
#include <RooWorkspace.h>

#include <benchmark/benchmark.h>

int printLevel = 0;
size_t nEvents = 100000;
const auto minimizerName = "Minuit2";
constexpr bool verbose = false;

enum RunConfig_t { runScalar, runCpu, fitScalar, fitCpu, fitCuda };

void runFitBenchmark(benchmark::State &state, RooAbsPdf &pdf, RooAbsData &data)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   RooArgSet params;
   pdf.getParameters(data.get(), params);
   RooArgSet paramsInitial;
   params.snapshot(paramsInitial);

   using namespace RooFit;
   for (auto _ : state) {
      if (runConfig == fitScalar) {
         pdf.fitTo(data, EvalBackend::Legacy(), Minimizer(minimizerName), PrintLevel(printLevel - 1), PrintEvalErrors(-1));
      } else if (runConfig == fitCpu) {
         pdf.fitTo(data, EvalBackend::Cpu(), Minimizer(minimizerName), PrintLevel(printLevel - 1), PrintEvalErrors(-1));
      } else if (runConfig == fitCuda) {
         pdf.fitTo(data, EvalBackend::Cuda(), Minimizer(minimizerName), PrintLevel(printLevel - 1), PrintEvalErrors(-1));
      }
      state.PauseTiming();
      params.assign(paramsInitial);
      state.ResumeTiming();
   }
}

static void benchProdPdf(benchmark::State &state)
{
   RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

   const RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
   // const int printLevel = state.range(1);
   // const int nParamSets = 1; // state.range(2) > 1 : state.range(2) ? 1;

   // Declare variables x,mean,sigma with associated name, title, initial value and allowed range

   RooWorkspace w;
   w.factory("Gaussian::g1(x[0,20],mx1[10,0,20],sx1[3,0.1,10])");
   w.factory("Gaussian::g2(x,mx2[10,0,20],sx2[1,0.1,10])");
   w.factory("Gaussian::g3(y[0,20],my[10,0,20],sy[2,0.1,10])");
   w.factory("Polynomial::pol(y,a[-0.01,-0.05,0.1])");
   w.factory("Gamma::gpdf(z[0,10],g[2,0.1,10],b[2,0.1,10],m0[-1,-20,0])");

   w.factory("SUM::pdfx(fx[0.2,0,1]*g1,g2)");
   w.factory("SUM::pdfy(fy[0.4,0.,1.]*g3,pol)");
   w.factory("PROD::model(pdfx,pdfy,gpdf)");

   // set coeffients
   // w.var("ns1")->setVal(0.2*nEvents);
   // w.var("ns2")->setVal(0.3*nEvents);
   // w.var("ng2")->setVal(0.1*nEvents);
   // w.var("ng3")->setVal(0.1*nEvents);
   // w.var("npol")->setVal(0.3*nEvents);

   auto &pdf = *(w.pdf("model"));
   auto &x = *(w.var("x"));
   auto &y = *(w.var("y"));
   auto &z = *(w.var("z"));

   std::unique_ptr<RooDataSet> data{pdf.generate({x, y, z}, nEvents)};

   RooArgSet parameters;
   pdf.getParameters(data->get(), parameters);
   // We need to change the parameters so we don't start already at the minimum
   // (the parameter values for which the dataset was created). This time, we
   // don't randomize them because the fit has many parameter and is not stable
   // from many initial points. That's why they are only shifted away a little
   // bit from their true value.
   for (auto *param : static_range_cast<RooRealVar *>(parameters)) {
      double val = param->getVal();
      val = val + 0.05 * (param->getMax() - val);
      param->setVal(val);
   }

   runFitBenchmark(state, pdf, *data);
}

class GausModel {

private:
   std::unique_ptr<RooWorkspace> _w;
   std::unique_ptr<RooAbsData> _data;
   RooAbsPdf *_pdf;
   std::string _obsName;
   std::vector<double> _results;

public:
   GausModel(std::string const &obsName, size_t nEvts)
   {

      RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

      _w = std::make_unique<RooWorkspace>("w");

      // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
      RooRealVar x("x", "x", -1.5, 40.5);

      RooRealVar mean("mean", "mean of gaussian", 20., 15., 25.);
      RooRealVar sigma("sigma", "width of gaussian", 10., 8., 12.);

      // Build gaussian p.d.f in terms of x,mean and sigma
      RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

      _w->import(gauss);

      _w->defineSet("obs", obsName.c_str());

      _pdf = _w->pdf("gauss");

      generateData(nEvts);
   }
   RooAbsPdf &pdf() { return *_pdf; }
   RooAbsData &data() { return *_data; }

   void randomiseParameters(unsigned long seed = 0)
   {
      RooArgSet parameters;
      _pdf->getParameters(_data->get(), parameters);
      auto random = RooRandom::randomGenerator();
      if (seed != 0)
         random->SetSeed(seed);

      for (auto param : parameters) {
         auto par = static_cast<RooAbsRealLValue *>(param);
         const double uni = random->Uniform();
         const double min = par->getMin();
         const double max = par->getMax();
         par->setVal(min + uni * (max - min));
      }
   }

   void generateData(size_t nEvts)
   {
      _data = std::unique_ptr<RooAbsData>(_pdf->generate(*_w->set("obs"), nEvts));
      // allocate here output vector
      _results = std::vector<double>(nEvts);
   }
};

static void benchFitGauss(benchmark::State &state)
{
   GausModel model("x", nEvents);
   // We need to randomize the parameters so we don't start already at the
   // minimum (the parameter values for which the dataset was created).
   model.randomiseParameters(1337);
   runFitBenchmark(state, model.pdf(), model.data());
}

static void benchFitGaussXSigma(benchmark::State &state)
{
   GausModel model("x,sigma", nEvents);
   // We need to randomize the parameters so we don't start already at the
   // minimum (the parameter values for which the dataset was created).
   model.randomiseParameters(1337);
   runFitBenchmark(state, model.pdf(), model.data());
}

class TestModelPdf {

private:
   std::unique_ptr<RooWorkspace> _ws;
   std::unique_ptr<RooAbsData> _data;
   RooAbsPdf *_pdf;
   std::string _obsName;
   std::vector<double> _results;

public:
   TestModelPdf(size_t nEvts)
   {

      if (printLevel == 0)
         RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

      _ws = std::make_unique<RooWorkspace>("w");

      // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
      RooRealVar x("x", "x", -1.5, 40.5);

      RooRealVar mean("mean", "mean of gaussian", 20., -10, 30);
      RooRealVar sigma("sigma", "width of gaussian", 4., 0.5, 10);

      // Build gaussian p.d.f in terms of x,mean and sigma
      RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

      RooRealVar c1("c1", "Decay constant", -0.5, -10, -0.001);
      RooExponential ex{"Expo", "Exponential PDF", x, c1};

      RooRealVar fractionGaus("fractionGaus", "Fraction of Gauss component", 0.5, 0., 1.);
      RooAddPdf addPdf("SumGausExpo", "Sum of Gaus and Exponential", {gauss, ex}, fractionGaus);
      // to avoid a warning when computing the unnormalized RooAddPdf values
      addPdf.fixCoefNormalization(x);

      _ws->import(addPdf);

      _ws->defineSet("obs", "x");

      _pdf = _ws->pdf("SumGausExpo");
      if (printLevel > 1) {
         _ws->Print();
      }
      generateData(nEvts);

      if (printLevel > 1) {
         _data->Print();
      }
   }
   RooAbsPdf &pdf() { return *_pdf; }
   RooAbsData &data() { return *_data; }

   void randomiseParameters(unsigned long seed = 0)
   {
      std::unique_ptr<RooArgSet> parameters{_pdf->getParameters(_data.get())};
      auto random = RooRandom::randomGenerator();
      if (seed != 0)
         random->SetSeed(seed);

      for (auto param : *parameters) {
         auto par = static_cast<RooAbsRealLValue *>(param);
         const double uni = random->Uniform();
         const double min = par->getMin();
         const double max = par->getMax();
         par->setVal(min + uni * (max - min));
      }
   }

   void generateData(size_t nEvts)
   {
      _data = std::unique_ptr<RooAbsData>(_pdf->generate(*_ws->set("obs"), nEvts));
      // allocate here output vector
      _results = std::vector<double>(nEvts);
   }
};

static void benchFit(benchmark::State &state)
{
   TestModelPdf model(nEvents);
   // We need to randomize the parameters so we don't start already at the
   // minimum (the parameter values for which the dataset was created).
   model.randomiseParameters(1337);
   runFitBenchmark(state, model.pdf(), model.data());
}

static void benchModel(benchmark::State &state)
{
   RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

   const RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
   // const int printLevel = state.range(1);
   // const int nParamSets = 1; // state.range(2) > 1 : state.range(2) ? 1;

   // Declare variables x,mean,sigma with associated name, title, initial value and allowed range

   RooWorkspace w;
   //  w.factory("Voigtian::vpdf(x[-10,10],m0[0,-10,10],width[0.5,0,10],s0[0.5,0,10])");
   //  w.factory("Gaussian::vpdf(x[0,20],m0[10,0,20],s0[0.5,0,10])");
   w.factory("Gamma::vpdf(x[0,20],g[20,0.1,40],b[0.5,0.01,10],m0[-1,-20,0])");
   w.factory("Gaussian::gpdf(x,m1[10,0,20],s1[2,0.1,10])");
   w.factory("Gaussian::g2(x,m2[5,0,20],s2[0.3,0.01,10])");
   w.factory("Gaussian::g3(x,m3[15,0,20],s3[0.4,0.01,10])");
   w.factory("Polynomial::pol(x,a[-0.01,-0.05,0.1])");

   w.factory("SUM::model(ns1[0,1000000000]*vpdf,ns2[0,10000000000]*gpdf,ng2[0,1000000000]*g2,ng3[0,10000000000]*g3, "
             "npol[0,10000000000]*pol)");

   // set coeffients
   w.var("ns1")->setVal(0.2 * nEvents);
   w.var("ns2")->setVal(0.3 * nEvents);
   w.var("ng2")->setVal(0.1 * nEvents);
   w.var("ng3")->setVal(0.1 * nEvents);
   w.var("npol")->setVal(0.3 * nEvents);

   auto &pdf = *(w.pdf("model"));
   auto &x = *(w.var("x"));

   std::unique_ptr<RooDataSet> data{pdf.generate({x}, nEvents)};

   RooArgSet parameters;
   pdf.getParameters(data->get(), parameters);
   // We need to change the parameters so we don't start already at the minimum
   // (the parameter values for which the dataset was created). This time, we
   // don't randomize them because the fit has many parameter and is not stable
   // from many initial points. That's why they are only shifted away a little
   // bit from their true value.
   for (auto *param : static_range_cast<RooRealVar *>(parameters)) {
      double val = param->getVal();
      val = val + 0.01 * (param->getMax() - val);
      param->setVal(val);
   }

   runFitBenchmark(state, pdf, *data);
}

auto const unit = benchmark::kMillisecond;

#ifdef DO_BENCH_ROOFIT_CUDA
// Only one iteration for CUDA benchmarks. Otherwise, the benchmark suit will
// repeat them many times are they appear to be very fast, consuming almost no
// CPU time.
#define CUDA_ONLY(code) code->Iterations(1)
#else
#define CUDA_ONLY(code)
#endif

BENCHMARK(benchFitGauss)->Unit(unit)->Name("Gaus_FitLegacy")->Args({fitScalar});
BENCHMARK(benchFitGauss)->Unit(unit)->Name("Gaus_FitCPU")->Args({fitCpu});
CUDA_ONLY(BENCHMARK(benchFitGauss)->Unit(unit)->Name("Gaus_FitCUDA")->Args({fitCuda}));

BENCHMARK(benchFitGaussXSigma)->Unit(unit)->Name("GausXS_FitLegacy")->Args({fitScalar});
BENCHMARK(benchFitGaussXSigma)->Unit(unit)->Name("GausXS_FitCPU")->Args({fitCpu});
CUDA_ONLY(BENCHMARK(benchFitGaussXSigma)->Unit(unit)->Name("GausXS_FitCUDA")->Args({fitCuda}));

BENCHMARK(benchFit)->Unit(unit)->Name("AddPdf_FitLegacy")->Args({fitScalar});
BENCHMARK(benchFit)->Unit(unit)->Name("AddPdf_FitCPU")->Args({fitCpu});
CUDA_ONLY(BENCHMARK(benchFit)->Unit(unit)->Name("AddPdf_FitCUDA")->Args({fitCuda}));

BENCHMARK(benchProdPdf)->Unit(unit)->Name("ProdPdf_FitLegacy")->Unit(benchmark::kMillisecond)->Args({fitScalar});
BENCHMARK(benchProdPdf)->Unit(unit)->Name("ProdPdf_FitCPU")->Unit(benchmark::kMillisecond)->Args({fitCpu});
CUDA_ONLY(BENCHMARK(benchProdPdf)->Unit(unit)->Name("ProdPdf_FitCUDA")->Unit(benchmark::kMillisecond)->Args({fitCuda}));

// Watch out with the result from these benchmarks: if there are evaluation
// errors during the minimization, the time differences will mostly come from
// how the backends are handling those. This might or might not be wanted.
BENCHMARK(benchModel)->Unit(unit)->Name("FitModel_FitLegacy")->Unit(benchmark::kMillisecond)->Args({fitScalar});
BENCHMARK(benchModel)->Unit(unit)->Name("FitModel_FitCPU")->Unit(benchmark::kMillisecond)->Args({fitCpu});
CUDA_ONLY(BENCHMARK(benchModel)->Unit(unit)->Name("FitModel_FitCUDA")->Unit(benchmark::kMillisecond)->Args({fitCuda}));

int main(int argc, char **argv)
{
   // Parse command line arguments
   for (Int_t i = 1; i < argc; i++) {
      std::string arg = argv[i];
      if (arg == "-v") {
         std::cout << "---running in verbose mode" << std::endl;
         printLevel = 1;
      } else if (arg == "-vv") {
         std::cout << "---running in very verbose mode" << std::endl;
         printLevel = 2;
      }
      if (arg == "-n") {
         nEvents = atoi(argv[++i]);
      }
   }

   std::cout << "Using nEvents = " << nEvents << std::endl;

   benchmark::Initialize(&argc, argv);
   benchmark::RunSpecifiedBenchmarks();
}
