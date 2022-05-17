#include <RooDataSet.h>
#include <RooWorkspace.h>
#include <RooMinimizer.h>
#include <RooMsgService.h>
#include <RooStats/ModelConfig.h>

#include "TestWorkspaces.h"

#include <benchmark/benchmark.h>

#include <fstream>
#include <iomanip>

class TestData {
public:
   // To set up the test data, we do the minimization once with the default
   // configuration to get a reference minimization path.
   TestData()
   {
      auto &msg = RooMsgService::instance();
      msg.setGlobalKillBelow(RooFit::WARNING);

      using namespace RooFit;

      RooStats::HistFactory::HistoToWorkspaceFactoryFast::Configuration hfCfg;
      auto *w = TestWorkspaces::getWorkspace001(hfCfg);

      auto *mc = static_cast<RooStats::ModelConfig *>(w->obj("ModelConfig"));

      if (mc->GetParametersOfInterest())
         constraintParams.add(*mc->GetParametersOfInterest());
      if (mc->GetNuisanceParameters())
         constraintParams.add(*mc->GetNuisanceParameters());

      auto *pdf = w->pdf("simPdf");
      auto *mu = w->var("SigXsecOverSM");

      std::unique_ptr<RooAbsReal> nll{pdf->createNLL(*w->data("obsData"), Constrain(constraintParams),
                                                     GlobalObservables(*mc->GetGlobalObservables()), BatchMode(false))};

      RooMinimizer m(*nll);
      m.setPrintLevel(-1);
      m.setStrategy(0);
      m.setLoggingToDataSet(1);

      m.minimize("Minuit2");

      minimizationPath = std::make_unique<RooDataSet>(*m.getLogDataSet());
   }

   // Dataset with the floating parameters as columns, and each call to getVal
   // in the minimization path as rows.
   std::unique_ptr<RooDataSet> minimizationPath;

   // The constraint parameters in the model.
   RooArgSet constraintParams;
};

TestData g_testData{};

/// Benchmark the hf001_example from the HistFactory tutorials.
static void benchHistFactory001(benchmark::State &state)
{
   using namespace RooFit;

   RooStats::HistFactory::HistoToWorkspaceFactoryFast::Configuration hfCfg;
   hfCfg.binnedFitOptimization = state.range(0);
   auto *w = TestWorkspaces::getWorkspace001(hfCfg);

   auto *mc = static_cast<RooStats::ModelConfig *>(w->obj("ModelConfig"));

   auto *pdf = w->pdf("simPdf");
   auto *mu = w->var("SigXsecOverSM");

   std::unique_ptr<RooAbsReal> nll{pdf->createNLL(*w->data("obsData"), Constrain(g_testData.constraintParams),
                                                  GlobalObservables(*mc->GetGlobalObservables()),
                                                  BatchMode(state.range(1)))};

   auto &minimizationPath = *g_testData.minimizationPath;

   RooArgSet parameters{};
   nll->getParameters(nullptr, parameters);

   // The minimization path depends on the configuration in unpredictable ways.
   // That's why we don't use the RooMinimizer each time, but only "emulate" a
   // fit by taking a reference minimization path.

   for (auto _ : state) {
      for (std::size_t i = 0; i < minimizationPath.numEntries(); ++i) {
         state.PauseTiming();
         parameters.assign(*minimizationPath.get(i));
         state.ResumeTiming();
         nll->getVal();
      }
   }
}

auto const unit = benchmark::kMillisecond;

BENCHMARK(benchHistFactory001)->Unit(unit)->Args({1, 0})->Name("hf001__BinnedFitOptimization_ON___BatchMode_OFF");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({0, 0})->Name("hf001__BinnedFitOptimization_OFF__BatchMode_OFF");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({1, 1})->Name("hf001__BinnedFitOptimization_ON___BatchMode_ON_");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({0, 1})->Name("hf001__BinnedFitOptimization_OFF__BatchMode_ON_");

BENCHMARK_MAIN();
