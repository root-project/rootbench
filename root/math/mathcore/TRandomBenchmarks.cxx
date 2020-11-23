#include <benchmark/benchmark.h>

#include "TRandomGen.h"

#include "TRandom1.h"
#include "TRandom3.h"
#include "TRandomGen.h"

template <class Gen>
void BM_Rndm(benchmark::State& state)
{
   Gen g;
   for (auto _ : state) {
      benchmark::DoNotOptimize(g.Rndm());
   }
}

BENCHMARK_TEMPLATE(BM_Rndm, TRandom1);
BENCHMARK_TEMPLATE(BM_Rndm, TRandom3);
BENCHMARK_TEMPLATE(BM_Rndm, TRandomMixMax);
BENCHMARK_TEMPLATE(BM_Rndm, TRandomRanluxpp);

BENCHMARK_MAIN();
