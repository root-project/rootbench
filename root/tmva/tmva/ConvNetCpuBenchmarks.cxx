#include "ConvNetBenchmarks.h"
#include "benchmark/benchmark.h"

static void BM_ConvolutionalNetwork_CPU(benchmark::State &state)
{
    TString architecture("CPU");

    // Benchmarking
    for (auto _ : state) {
        CNN_benchmark(architecture);
    }
}
BENCHMARK(BM_ConvolutionalNetwork_CPU);

BENCHMARK_MAIN();