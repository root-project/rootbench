// Author: Federico Sossai (fsossai), 2021

#include <benchmark/benchmark.h>

#include <iostream>
#include <thread>
#include <chrono>
#include <utility>
#include <vector>
#include <memory>
#include <functional>
#include <random>

#include "Conv_d100_L14_B1.hxx"
#include "Conv_d100_L1_B1.hxx"
//#include "input_models/compiled/Linear_16.hxx"
///#include "input_models/compiled/Linear_32.hxx"
//#include "input_models/compiled/Linear_64.hxx"
//#include "input_models/compiled/Linear_event_blas.hxx" // old file 
//#include "input_models/compiled/Linear_event.hxx"   // generated from Linear_event.onnx
//#include "input_models/compiled/Conv_d100_L1_B1_opt.hxx"
//#include "input_models/compiled/Conv_d100_L14_B1.hxx"

using namespace std;
bool verbose = false; 
template <class S>
void BM_SOFIE_Inference(benchmark::State &state)
{
    vector<float> input;
    input.resize(10000);

    static std::uniform_real_distribution<float> distribution(-1, 1);
    static std::default_random_engine generator;
    std::generate(input.begin(), input.end(), []() { return distribution(generator); });

    float *input_ptr = input.data();
    S s("");

    
    for (auto _ : state) {
           s.infer(input.data());
    }
    //if (verbose) std::cout << "output : " << output.size() << " : " << output.front() << " ......" << output.back() << std::endl;
}
//typedef TMVA_SOFIE_Conv_d100_L1_B1::Session S1;
//BENCHMARK(BM_SOFIE_Inference<S1>);//->Name( "Conv_d100_L1_B1");
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L1_B1::Session)->Name( "Conv_d100_L1_B1");
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L14_B1::Session)->Name( "Conv_d100_L14_B1");

BENCHMARK_MAIN();