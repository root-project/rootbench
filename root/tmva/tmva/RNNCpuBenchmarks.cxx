#include "RNNBenchmarks.h"
#include "benchmark/benchmark.h"

static void BM_RNN_CPU(benchmark::State &state)
{
    TString architecture("CPU");
    
    // Benchmarking
    for (auto _ : state) {
        RNN_benchmark(architecture);
    }
}
BENCHMARK(BM_RNN_CPU);

BENCHMARK_MAIN();
