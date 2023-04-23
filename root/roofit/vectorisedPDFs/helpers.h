#include <RooAbsPdf.h>
#include <RooAbsData.h>
#include <RooRandom.h>
#include <RooRealVar.h>

#include <benchmark/benchmark.h>

int printLevel = 0;

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
         pdf.fitTo(data, BatchMode("off"), Minimizer("Minuit2"), PrintLevel(printLevel - 1));
      } else if (runConfig == fitCpu) {
         pdf.fitTo(data, BatchMode("cpu"), Minimizer("Minuit2"), PrintLevel(printLevel - 1));
      } else if (runConfig == fitCuda) {
         pdf.fitTo(data, BatchMode("cuda"), Minimizer("Minuit2"), PrintLevel(printLevel - 1));
      }
      state.PauseTiming();
      params.assign(paramsInitial);
      state.ResumeTiming();
   }
}

void randomiseParameters(const RooArgSet &parameters, ULong_t seed = 0)
{
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
