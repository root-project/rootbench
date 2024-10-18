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
      ws = TestWorkspaces::getWorkspace001(hfCfg);

      auto *mc = static_cast<RooStats::ModelConfig *>(ws->obj("ModelConfig"));

      if (mc->GetParametersOfInterest())
         constraintParams.add(*mc->GetParametersOfInterest());
      if (mc->GetNuisanceParameters())
         constraintParams.add(*mc->GetNuisanceParameters());
   }

   std::unique_ptr<RooWorkspace> ws;

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
   std::unique_ptr<RooWorkspace> ws = TestWorkspaces::getWorkspace001(hfCfg);

   auto *mc = static_cast<RooStats::ModelConfig *>(ws->obj("ModelConfig"));

   auto *pdf = ws->pdf("simPdf");

   auto evalBackend = static_cast<EvalBackend::Value>(state.range(1));
   std::unique_ptr<RooAbsReal> nll{pdf->createNLL(*ws->data("obsData"), Constrain(g_testData.constraintParams),
                                                  GlobalObservables(*mc->GetGlobalObservables()),
                                                  EvalBackend(evalBackend))};

   RooArgSet parameters;
   RooArgSet initialParams;
   nll->getParameters(nullptr, parameters);
   parameters.snapshot(initialParams);

   // The minimization path depends on the configuration in unpredictable ways.
   // That's why we don't use the RooMinimizer each time, but only "emulate" a
   // fit by taking a reference minimization path.

   for (auto _ : state) {
      state.PauseTiming();
      parameters.assign(initialParams);
      RooMinimizer m(*nll);
      m.setPrintLevel(-1);
      m.setStrategy(0);
      state.ResumeTiming();
      m.minimize("Minuit2");
   }
}

auto const unit = benchmark::kMillisecond;

auto Legacy = static_cast<int>(RooFit::EvalBackend::Value::Legacy);
auto Cpu = static_cast<int>(RooFit::EvalBackend::Value::Cpu);

BENCHMARK(benchHistFactory001)->Unit(unit)->Args({1, Legacy})->Name("hf001__BinnedFitOptimization_ON___BatchMode_OFF");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({0, Legacy})->Name("hf001__BinnedFitOptimization_OFF__BatchMode_OFF");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({1, Cpu})->Name("hf001__BinnedFitOptimization_ON___BatchMode_ON_");
BENCHMARK(benchHistFactory001)->Unit(unit)->Args({0, Cpu})->Name("hf001__BinnedFitOptimization_OFF__BatchMode_ON_");

BENCHMARK_MAIN();
