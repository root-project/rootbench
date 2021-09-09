// Author: Federico Sossai (fsossai), 2021

#include <benchmark/benchmark.h>

#include <iostream>
#include <thread>
#include <chrono>
#include <utility>
#include <vector>
#include <memory>
#include <functional>

#include "input_models/compiled/Linear_16_prof.hxx"
#include "input_models/compiled/Linear_32_prof.hxx"
#include "input_models/compiled/Linear_64_prof.hxx"

using namespace std;

static void BM_SOFIE_Inference(benchmark::State& state, std::string model_name)
{
    vector<float> input;
    vector<float> (*infer_func)(float*);

    if (model_name == "Linear_16") {
        input.resize(1600);
        infer_func = TMVA_SOFIE_Linear_16::infer;
    } else if (model_name == "Linear_32") {
        input.resize(3200);
        infer_func = TMVA_SOFIE_Linear_32::infer;
    } else if (model_name == "Linear_64") {
        input.resize(6400);
        infer_func = TMVA_SOFIE_Linear_64::infer;
    }
    
    float *input_ptr = input.data();
    for (auto _ : state) {
        infer_func(input_ptr);
    }
    cout << TMVA_SOFIE_Linear_16::profiler_results.size() << endl;
    cout << TMVA_SOFIE_Linear_32::profiler_results.size() << endl;
    cout << TMVA_SOFIE_Linear_64::profiler_results.size() << endl;
}
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_16, "Linear_16");
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_32, "Linear_32");
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_64, "Linear_64");

BENCHMARK_MAIN();