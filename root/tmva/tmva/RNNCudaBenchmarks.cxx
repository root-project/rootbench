#include "RNNBenchmarks.h"
#include "benchmark/benchmark.h"

static void BM_RNN_CUDA(benchmark::State &state)
{
    TString architecture("GPU");
    
    // Benchmarking
    for (auto _ : state) {
        RNN_benchmark(architecture);
    }
}
BENCHMARK(BM_RNN_CUDA);

BENCHMARK_MAIN();
