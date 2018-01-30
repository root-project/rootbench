#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooAddModel.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooGaussModel.h"
#include "RooCategory.h"
#include "RooBMixDecay.h"
#include "RooBCPEffDecay.h"
#include "RooBDecay.h"
#include "RooDecay.h"
#include "RooFormulaVar.h"
#include "RooTruthModel.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "RooMinimizer.h"

using namespace RooFit;

#include "benchmark/benchmark.h"

// using namespace RooFit;
// using namespace RooStats;
// using namespace HistFactory;

static void BM_RooFit_BDecayWithMixing(benchmark::State &state)
{
   gErrorIgnoreLevel = kInfo;
   int events = state.range(0);
   int cpu = state.range(1);

   RooRealVar dt("dt", "dt", -10, 10);
   dt.setBins(40);
   // Parameters
   RooRealVar dm("dm", "delta m(B0)", 0.472, 0.1, 0.9);
   RooRealVar tau("tau", "tau (B0)", 1.547, 1.3, 1.9);
   RooRealVar w("w", "flavour mistag rate", 0.1);
   RooRealVar dw("dw", "delta mistag rate for B0/B0bar", 0.1);

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
   RooDataSet *data = bmix.generate(RooArgSet(dt, mixState, tagFlav), events);

   // Create NLL
   RooAbsReal *nll = bmix.createNLL(*data, NumCPU(cpu, 0));
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setLogFile("benchmigradnchanellog");
   while (state.KeepRunning()) {
      m.migrad();
   }
   delete data;
   delete nll;
}

static void BM_RooFit_BDecayGaussResolution(benchmark::State &state)
{
   gErrorIgnoreLevel = kInfo;
   int events = state.range(0);
   int cpu = state.range(1);

   RooRealVar dt("dt", "dt", -10, 10);
   dt.setBins(40);
   // Parameters
   RooRealVar dm("dm", "delta m(B0)", 0.472, 0.1, 0.9);
   RooRealVar tau("tau", "tau (B0)", 1.547, 1.3, 1.9);
   RooRealVar w("w", "flavour mistag rate", 0.1);
   RooRealVar dw("dw", "delta mistag rate for B0/B0bar", 0.1);

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
   RooDataSet *data = decay_gm1.generate(RooArgSet(dt, mixState, tagFlav), events);

   // Create NLL
   RooAbsReal *nll = decay_gm1.createNLL(*data, NumCPU(cpu, 0));
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setLogFile("benchmigradnchanellog");
   while (state.KeepRunning()) {
      m.migrad();
   }
   delete data;
   delete nll;
}

static void BM_RooFit_BDecayDoubleGauss(benchmark::State &state)
{
   gErrorIgnoreLevel = kInfo;
   int events = state.range(0);
   int cpu = state.range(1);

   RooRealVar dt("dt", "dt", -10, 10);
   dt.setBins(40);
   // Parameters
   RooRealVar dm("dm", "delta m(B0)", 0.472, 0.1, 0.9);
   RooRealVar tau("tau", "tau (B0)", 1.547, 1.3, 1.9);
   RooRealVar w("w", "flavour mistag rate", 0.1);
   RooRealVar dw("dw", "delta mistag rate for B0/B0bar", 0.1);

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
   RooRealVar bias2("bias2", "bias2", 0);
   RooRealVar sigma2("sigma2", "sigma2", 5);
   RooGaussModel gm2("gm2", "gauss model 2", dt, bias2, sigma2);
   // Build a composite resolution model f*gm1+(1-f)*gm2
   RooRealVar gm1frac("gm1frac", "fraction of gm1", 0.5);
   RooAddModel gmsum("gmsum", "sum of gm1 and gm2", RooArgList(gm1, gm2), gm1frac);
   // Construct decay(t) (x) (f*gm1 + (1-f)*gm2)
   RooDecay decay_gmsum("decay_gmsum", "decay", dt, tau, gmsum, RooDecay::DoubleSided);

   // Generate Some Data
   RooDataSet *data = decay_gmsum.generate(RooArgSet(dt, mixState, tagFlav), events);

   // Create NLL
   RooAbsReal *nll = decay_gmsum.createNLL(*data, NumCPU(cpu, 0));
   RooMinimizer m(*nll);
   m.setPrintLevel(-1);
   m.setStrategy(0);
   m.setLogFile("benchmigradnchanellog");
   while (state.KeepRunning()) {
      m.migrad();
   }
   delete data;
   delete nll;
}

static void EventArguments(benchmark::internal::Benchmark *b)
{
   for (int i = 1; i <= 4; ++i)
      for (int j = 1; j <= 4; ++j)
         b->Args({i * 10000, j});
}

BENCHMARK(BM_RooFit_BDecayWithMixing)->Apply(EventArguments)->UseRealTime()->Iterations(1);
BENCHMARK(BM_RooFit_BDecayGaussResolution)->Apply(EventArguments)->UseRealTime()->Iterations(1);
BENCHMARK(BM_RooFit_BDecayDoubleGauss)->Apply(EventArguments)->UseRealTime()->Iterations(1);

BENCHMARK_MAIN();
