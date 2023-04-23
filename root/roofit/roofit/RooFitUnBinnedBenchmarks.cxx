#include <RooGlobalFunc.h>
#include <RooHelpers.h>
#include <RooMsgService.h>
#include <RooAddModel.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussian.h>
#include <RooGaussModel.h>
#include <RooCategory.h>
#include <RooBMixDecay.h>
#include <RooBCPEffDecay.h>
#include <RooBDecay.h>
#include <RooDecay.h>
#include <RooFormulaVar.h>
#include <RooTruthModel.h>
#include <RooMinimizer.h>

#include <benchmark/benchmark.h>

namespace {

void shiftParameters(const RooArgSet &parameters)
{
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
}

std::string convertBatchModeToString(int batchMode)
{
   if (batchMode == 1)
      return "cpu";
   if (batchMode == 2)
      return "cuda";
   return "off";
}

} // namespace

static void BM_RooFit_BDecayWithMixing(benchmark::State &state)
{
   using namespace RooFit;

   RooHelpers::LocalChangeMsgLevel changeMsgLvl(RooFit::WARNING);

   gErrorIgnoreLevel = kInfo;
   int events = state.range(0);
   int batchMode = state.range(1);
   int cpu = state.range(2);

   RooRealVar dt("dt", "dt", -10, 10);
   dt.setBins(40);
   // Parameters
   RooRealVar dm("dm", "delta m(B0)", 0.472, 0.1, 0.9);
   RooRealVar tau("tau", "tau (B0)", 1.547, 1.3, 1.9);
   RooRealVar w("w", "flavour mistag rate", 0.1, 0.0, 1.0);
   RooRealVar dw("dw", "delta mistag rate for B0/B0bar", 0.1, 0.0, 1.0);

   RooCategory mixState("mixState", "B0/B0bar mixing state");
   mixState.defineType("mixed", -1);
   mixState.defineType("unmixed", 1);

   RooCategory tagFlav("tagFlav", "Flavour of the tagged B0");
   tagFlav.defineType("B0", 1);
   tagFlav.defineType("B0bar", -1);

   // Use delta function resolution model
   RooTruthModel tm("tm", "truth model", dt);
   // Construct Bdecay with mixing
   RooBMixDecay bmix("bmix", "decay", dt, mixState, tagFlav, tau, dm, w, dw, tm, RooBMixDecay::DoubleSided);
   // Generate Some Data
   std::unique_ptr<RooDataSet> data{bmix.generate({dt, mixState, tagFlav}, events)};

   // Save initial parameter snapshot for resetting
   RooArgSet params;
   RooArgSet paramsInitial;
   bmix.getParameters(data->get(), params);
   shiftParameters(params);
   params.snapshot(paramsInitial);

   // Create NLL
   auto bm = convertBatchModeToString(batchMode);
   std::unique_ptr<RooAbsReal> nll{bmix.createNLL(*data, NumCPU(cpu, 0), BatchMode(bm))};
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setLogFile("benchmigradnchanellog");

   while (state.KeepRunning()) {
      m.migrad();
      params.assign(paramsInitial);
   }
}

static void BM_RooFit_BDecayGaussResolution(benchmark::State &state)
{
   using namespace RooFit;

   RooHelpers::LocalChangeMsgLevel changeMsgLvl(RooFit::WARNING);

   gErrorIgnoreLevel = kInfo;
   int events = state.range(0);
   int batchMode = state.range(1);
   int cpu = state.range(2);

   RooRealVar dt("dt", "dt", -10, 10);
   dt.setBins(40);
   // Parameters
   RooRealVar dm("dm", "delta m(B0)", 0.472, 0.1, 0.9);
   RooRealVar tau("tau", "tau (B0)", 1.547, 1.3, 1.9);
   RooRealVar w("w", "flavour mistag rate", 0.1, 0.0, 1.0);
   RooRealVar dw("dw", "delta mistag rate for B0/B0bar", 0.1, 0.0, 1.0);

   RooCategory mixState("mixState", "B0/B0bar mixing state");
   mixState.defineType("mixed", -1);
   mixState.defineType("unmixed", 1);

   RooCategory tagFlav("tagFlav", "Flavour of the tagged B0");
   tagFlav.defineType("B0", 1);
   tagFlav.defineType("B0bar", -1);

   // Use delta function resolution model
   RooTruthModel tm("tm", "truth model", dt);
   // Construct Bdecay with mixing
   RooBMixDecay bmix("bmix", "decay", dt, mixState, tagFlav, tau, dm, w, dw, tm, RooBMixDecay::DoubleSided);
   // Build a gaussian resolution model
   RooRealVar bias1("bias1", "bias1", 0, -1., 1.);
   RooRealVar sigma1("sigma1", "sigma1", 1, 0.1, 1.9);
   RooGaussModel gm1("gm1", "gauss model 1", dt, bias1, sigma1);

   // Construct decay(t) (x) gauss1(t)
   RooDecay decay_gm1("decay_gm1", "decay", dt, tau, gm1, RooDecay::DoubleSided);

   // Generate Some Data
   std::unique_ptr<RooDataSet> data{decay_gm1.generate({dt, mixState, tagFlav}, events)};

   // Save initial parameter snapshot for resetting
   RooArgSet params;
   RooArgSet paramsInitial;
   decay_gm1.getParameters(data->get(), params);
   shiftParameters(params);
   params.snapshot(paramsInitial);

   // Create NLL
   auto bm = convertBatchModeToString(batchMode);
   std::unique_ptr<RooAbsReal> nll{decay_gm1.createNLL(*data, NumCPU(cpu, 0), BatchMode(bm))};
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setLogFile("benchmigradnchanellog");
   while (state.KeepRunning()) {
      m.migrad();
      params.assign(paramsInitial);
   }
}

static void BM_RooFit_BDecayDoubleGauss(benchmark::State &state)
{
   using namespace RooFit;

   RooHelpers::LocalChangeMsgLevel changeMsgLvl(RooFit::WARNING);

   gErrorIgnoreLevel = kInfo;
   int events = state.range(0);
   int batchMode = state.range(1);
   int cpu = state.range(2);

   RooRealVar dt("dt", "dt", -10, 10);
   dt.setBins(40);
   // Parameters
   RooRealVar dm("dm", "delta m(B0)", 0.472, 0.1, 0.9);
   RooRealVar tau("tau", "tau (B0)", 1.547, 1.3, 1.9);
   RooRealVar w("w", "flavour mistag rate", 0.1, 0.0, 1.0);
   RooRealVar dw("dw", "delta mistag rate for B0/B0bar", 0.1, 0.0, 1.0);

   RooCategory mixState("mixState", "B0/B0bar mixing state");
   mixState.defineType("mixed", -1);
   mixState.defineType("unmixed", 1);

   RooCategory tagFlav("tagFlav", "Flavour of the tagged B0");
   tagFlav.defineType("B0", 1);
   tagFlav.defineType("B0bar", -1);

   // Use delta function resolution model
   RooTruthModel tm("tm", "truth model", dt);
   // Construct Bdecay with mixing
   RooBMixDecay bmix("bmix", "decay", dt, mixState, tagFlav, tau, dm, w, dw, tm, RooBMixDecay::DoubleSided);
   // Build a gaussian resolution model
   RooRealVar bias1("bias1", "bias1", 0, -1., 1.);
   RooRealVar sigma1("sigma1", "sigma1", 1, 0.1, 1.9);
   RooGaussModel gm1("gm1", "gauss model 1", dt, bias1, sigma1);

   // Construct decay(t) (x) gauss1(t)
   RooDecay decay_gm1("decay_gm1", "decay", dt, tau, gm1, RooDecay::DoubleSided);

   // Build another gaussian resolution model
   RooRealVar bias2("bias2", "bias2", 0, -1., 1.);
   RooRealVar sigma2("sigma2", "sigma2", 5, 0.5, 10);
   RooGaussModel gm2("gm2", "gauss model 2", dt, bias2, sigma2);
   // Build a composite resolution model f*gm1+(1-f)*gm2
   RooRealVar gm1frac("gm1frac", "fraction of gm1", 0.5, 0.0, 1.0);
   RooAddModel gmsum("gmsum", "sum of gm1 and gm2", {gm1, gm2}, gm1frac);
   // Construct decay(t) (x) (f*gm1 + (1-f)*gm2)
   RooDecay decay_gmsum("decay_gmsum", "decay", dt, tau, gmsum, RooDecay::DoubleSided);

   // Generate Some Data
   std::unique_ptr<RooDataSet> data{decay_gmsum.generate({dt, mixState, tagFlav}, events)};

   // Save initial parameter snapshot for resetting
   RooArgSet params;
   RooArgSet paramsInitial;
   decay_gmsum.getParameters(data->get(), params);
   shiftParameters(params);
   params.snapshot(paramsInitial);

   // Create NLL
   auto bm = convertBatchModeToString(batchMode);
   std::unique_ptr<RooAbsReal> nll{decay_gmsum.createNLL(*data, NumCPU(cpu, 0), BatchMode(bm))};
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setLogFile("benchmigradnchanellog");
   while (state.KeepRunning()) {
      m.migrad();
      params.assign(paramsInitial);
   }
}

int nEvents = 100000;
const auto unit = benchmark::kMillisecond;

#define ARGS UseRealTime()->Unit(unit)

#ifdef R__HAS_CUDA
BENCHMARK(BM_RooFit_BDecayWithMixing)->Name("BDecayWithMixing__BatchMode_CUDA")->Args({nEvents, 2, 1})->ARGS;
#endif
BENCHMARK(BM_RooFit_BDecayWithMixing)->Name("BDecayWithMixing__BatchMode_CPU")->Args({nEvents, 1, 1})->ARGS;
BENCHMARK(BM_RooFit_BDecayWithMixing)->Name("BDecayWithMixing__NumCPU_1")->Args({nEvents, 0, 1})->ARGS;
BENCHMARK(BM_RooFit_BDecayWithMixing)->Name("BDecayWithMixing__NumCPU_2")->Args({nEvents, 0, 2})->ARGS;
BENCHMARK(BM_RooFit_BDecayWithMixing)->Name("BDecayWithMixing__NumCPU_4")->Args({nEvents, 0, 4})->ARGS;

#ifdef R__HAS_CUDA
BENCHMARK(BM_RooFit_BDecayGaussResolution)->Name("BDecayGaussResolution__BatchMode_CUDA")->Args({nEvents, 2, 1})->ARGS;
#endif
BENCHMARK(BM_RooFit_BDecayGaussResolution)->Name("BDecayGaussResolution__BatchMode_CPU")->Args({nEvents, 1, 1})->ARGS;
BENCHMARK(BM_RooFit_BDecayGaussResolution)->Name("BDecayGaussResolution__NumCPU_1")->Args({nEvents, 0, 1})->ARGS;
BENCHMARK(BM_RooFit_BDecayGaussResolution)->Name("BDecayGaussResolution__NumCPU_2")->Args({nEvents, 0, 2})->ARGS;
BENCHMARK(BM_RooFit_BDecayGaussResolution)->Name("BDecayGaussResolution__NumCPU_4")->Args({nEvents, 0, 4})->ARGS;

#ifdef R__HAS_CUDA
BENCHMARK(BM_RooFit_BDecayDoubleGauss)->Name("BDecayDoubleGauss__BatchMode_CUDA")->Args({nEvents, 2, 1})->ARGS;
#endif
BENCHMARK(BM_RooFit_BDecayDoubleGauss)->Name("BDecayDoubleGauss__BatchMode_CPU")->Args({nEvents, 1, 1})->ARGS;
BENCHMARK(BM_RooFit_BDecayDoubleGauss)->Name("BDecayDoubleGauss__NumCPU_1")->Args({nEvents, 0, 1})->ARGS;
BENCHMARK(BM_RooFit_BDecayDoubleGauss)->Name("BDecayDoubleGauss__NumCPU_2")->Args({nEvents, 0, 2})->ARGS;
BENCHMARK(BM_RooFit_BDecayDoubleGauss)->Name("BDecayDoubleGauss__NumCPU_4")->Args({nEvents, 0, 4})->ARGS;

#undef ARGS

BENCHMARK_MAIN();
