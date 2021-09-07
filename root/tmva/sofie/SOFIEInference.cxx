// Author: Federico Sossai (fsossai), 2021

#include <benchmark/benchmark.h>

#include <iostream>

static void BM_SOFIE_Inference(benchmark::State& state)
{
    for (auto _ : state) {
        ;
    }
}
BENCHMARK(BM_SOFIE_Inference);

BENCHMARK_MAIN();