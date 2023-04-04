#ifndef BenchmarkUtils_h
#define BenchmarkUtils_h

#include <RooArgSet.h>
#include <RooRandom.h>
#include <RooAbsRealLValue.h>
#include <RooFuncWrapper.h>

#include "benchmark/benchmark.h"

#include <random>

namespace RooFitADBenchmarksUtils {

enum backend { Reference, BatchMode, CodeSquashNumDiff, CodeSquashAD };
template <typename F>
void doBenchmarks(F func, int rangeMin, int rangeMax, int step = 1, int numIterations = 1,
                  benchmark::TimeUnit unit = benchmark::kMillisecond)
{
   // Run the minimization with the reference NLL
   benchmark::RegisterBenchmark("NllReferenceMinimization", func)
      ->ArgsProduct({{Reference}, benchmark::CreateDenseRange(rangeMin, rangeMax, step)})
      ->Unit(unit)
      ->Iterations(numIterations);

   // Run the minimization with the reference NLL (BatchMode)
   benchmark::RegisterBenchmark("NllBatchModeMinimization", func)
      ->ArgsProduct({{BatchMode}, benchmark::CreateDenseRange(rangeMin, rangeMax, step)})
      ->Unit(unit)
      ->Iterations(numIterations);

   // Run the minimization with the code-squashed version with numerical-diff.
   benchmark::RegisterBenchmark("NllCodeSquash_NumDiff", func)
      ->ArgsProduct({{CodeSquashNumDiff}, benchmark::CreateDenseRange(rangeMin, rangeMax, step)})
      ->Unit(unit)
      ->Iterations(numIterations);

   // Run the minimization with the code-squashed version with AD.
   benchmark::RegisterBenchmark("NllCodeSquash_AD", func)
      ->ArgsProduct({{CodeSquashAD}, benchmark::CreateDenseRange(rangeMin, rangeMax, step)})
      ->Unit(unit)
      ->Iterations(numIterations);
}

void randomizeParameters(const RooArgSet &parameters)
{
   double lower_bound = -9;
   double upper_bound = 9;
   std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
   std::default_random_engine re;

   for (auto *param : parameters) {
      double mul = unif(re) / 100;

      auto par = dynamic_cast<RooAbsRealLValue *>(param);
      if (!par)
         continue;
      double val = par->getVal();
      val = val + mul * (mul > 0 ? (par->getMax() - val) : (val - par->getMin()));

      par->setVal(val);
   }
}
} // namespace RooFitADBenchmarksUtils
#endif
