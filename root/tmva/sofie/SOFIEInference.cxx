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

#include "input_models/compiled/Linear_16.hxx"
#include "input_models/compiled/Linear_32.hxx"
#include "input_models/compiled/Linear_64.hxx"
//#include "input_models/compiled/Linear_event_blas.hxx" // old file 
#include "input_models/compiled/Linear_event.hxx"   // generated from Linear_event.onnx
#include "input_models/compiled/Conv_d100_L1_B1_opt.hxx"
//#include "input_models/compiled/Conv_d100_L14_B1.hxx"

using namespace std;
bool verbose = false; 
static void BM_SOFIE_Inference(benchmark::State &state, std::string model_name)
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
    } else if (model_name == "Linear_event") {
        input.resize(100);
        infer_func = TMVA_SOFIE_Linear_event::infer;
    } else if (model_name == "Conv_d100_L1_B1") {
        input.resize(100*100);
        infer_func = TMVA_SOFIE_Conv_d100_L1_B1::infer;
        TMVA_SOFIE_Conv_d100_L1_B1::init();
    } /*else if (model_name == "Conv_d100_L1_B14") {
       input.resize(100 * 100);
       infer_func = TMVA_SOFIE_Conv_d100_L1_B14::infer;
   }*/

    static std::uniform_real_distribution<float> distribution(-1, 1);
    static std::default_random_engine generator;
    std::generate(input.begin(), input.end(), []() { return distribution(generator); });

    float *input_ptr = input.data();
    if (model_name == "Conv_d100_L1_B1_temp") {
       std::vector<float> output(2 * 100 * 100);
       for (auto _ : state) {
          //std::cout << "run for output " << output.size() << std::endl;
          //TMVA_SOFIE_Conv_d100_L1_B1::infer(input_ptr, &output[0]);
          // infer_func(input_ptr, &output[0];
       }
    }
    else {
       std::vector<float> output; 
       for (auto _ : state) {
          output = infer_func(input_ptr);
        }
    }
    //if (verbose) std::cout << "output : " << output.size() << " : " << output.front() << " ......" << output.back() << std::endl;
}
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_event, "Linear_event");
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_16, "Linear_16");
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_32, "Linear_32");
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_64, "Linear_64");
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_100_L1, "Conv_d100_L1_B1");
//BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_100_L14, "Conv_d100_L14_B1");

BENCHMARK_MAIN();