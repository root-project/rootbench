#include <RooWorkspace.h>
#include <RooMinimizer.h>
#include <RooMsgService.h>
#include <RooStats/ModelConfig.h>

#include "TestWorkspaces.h"

#include <benchmark/benchmark.h>

/// Benchmark the hf001_example from the HistFactory tutorials.
static void benchHistFactory001(benchmark::State &state)
{
   auto &msg = RooMsgService::instance();
   msg.setGlobalKillBelow(RooFit::WARNING);

   using namespace RooFit;

   RooStats::HistFactory::HistoToWorkspaceFactoryFast::Configuration hfCfg;
   hfCfg.binnedFitOptimization = state.range(0);
   auto *w = TestWorkspaces::getWorkspace001(hfCfg);

   auto *mc = static_cast<RooStats::ModelConfig *>(w->obj("ModelConfig"));

   RooArgSet params;
   if (mc->GetParametersOfInterest())
      params.add(*mc->GetParametersOfInterest());
   if (mc->GetNuisanceParameters())
      params.add(*mc->GetNuisanceParameters());

   auto *pdf = w->pdf("simPdf");
   auto *mu = w->var("SigXsecOverSM");

   std::unique_ptr<RooAbsReal> nll{pdf->createNLL(*w->data("obsData"), Constrain(params),
                                                  GlobalObservables(*mc->GetGlobalObservables()),
                                                  BatchMode(state.range(1)))};
   RooArgSet parameters{};
   RooArgSet initialParameters{};
   nll->getParameters(nullptr, parameters);
   parameters.snapshot(initialParameters);

   RooMinimizer m(*nll);
   m.setPrintLevel(-1);

   for (auto _ : state) {
      m.minimize("Minuit2");
   }
}

auto const unit = benchmark::kMillisecond;

BENCHMARK(benchHistFactory001)->Unit(unit)->Args({1, 0})->Name("hf001__BinnedFitOptimization_ON___BatchMode_OFF");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({0, 0})->Name("hf001__BinnedFitOptimization_OFF__BatchMode_OFF");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({1, 1})->Name("hf001__BinnedFitOptimization_ON___BatchMode_ON_");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({0, 1})->Name("hf001__BinnedFitOptimization_OFF__BatchMode_ON_");

BENCHMARK_MAIN();
