#include "ConvNetBenchmarks.h"
#include "benchmark/benchmark.h"

static void BM_ConvolutionalNetwork_CUDA(benchmark::State &state)
{
    TString architecture("GPU");

    // Benchmarking
    for (auto _ : state) {
        CNN_benchmark(architecture);
    }
}
BENCHMARK(BM_ConvolutionalNetwork_CUDA);

static void BM_ConvolutionalNetwork_Keras_CUDA(benchmark::State &state)
{
    TString architecture("GPU");

    // Benchmarking
    for (auto _ : state) {
        CNN_Keras_benchmark(architecture);
    }
}
BENCHMARK(BM_ConvolutionalNetwork_Keras_CUDA);

BENCHMARK_MAIN();
