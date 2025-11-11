#ifndef BenchmarkUtils_h
#define BenchmarkUtils_h

#include <RooArgSet.h>
#include <RooRandom.h>
#include <RooAbsRealLValue.h>

#include "benchmark/benchmark.h"

#include <random>

namespace RooFitADBenchmarksUtils {

template <typename F>
void doBenchmarks(const char *name, int backend, F func, std::vector<long int> const &range, int numIterations = 1,
                  benchmark::TimeUnit unit = benchmark::kMillisecond)
{
   benchmark::RegisterBenchmark(name, func)->ArgsProduct({{backend}, range})->Unit(unit)->Iterations(numIterations);
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
