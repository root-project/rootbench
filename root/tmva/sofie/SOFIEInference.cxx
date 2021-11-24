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

#include "Linear_event.hxx"
#include "Linear_16.hxx"
#include "Linear_32.hxx"
#include "Linear_64.hxx"
#include "Conv_d100_L1_B1.hxx"
#include "Conv_d100_L14_B1.hxx"
#include "Conv_d100_L14_B32.hxx"

#include "resnet18v1.hxx"
#include "TMath.h"


using namespace std;
bool verbose = false; 
template <class S>
void BM_SOFIE_Inference(benchmark::State &state)
{ 
   size_t inputSize = state.range(0);
   size_t bsize = (state.range(1) > 0) ? state.range(1) : 0;
   size_t nevts = 64;
   size_t nrep = nevts / bsize;

   vector<float> input(inputSize*nevts);

   static std::uniform_real_distribution<float> distribution(-1, 1);
   static std::default_random_engine generator;
   std::generate(input.begin(), input.end(), []() { return distribution(generator); });

   float *input_ptr = input.data();
   S s("");

   double totDuration = 0;
   int ntimes = 0;
   for (auto _ : state) {
      auto t1 = std::chrono::high_resolution_clock::now();
      for (int i = 0; i < nevts; i += bsize)
         auto y = s.infer(input.data()+ inputSize*i);

      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      totDuration += duration / 1.E3;  // in milliseconds
      ntimes++;
   }

   state.counters["time/evt(ms)"] = totDuration / double(ntimes * nevts);
   // input[0] = -999;
   // s.inf
   // std::cout << "number of times " << s.itime << std::endl;
   // int n = s.itime - 1;
   // for (size_t i = 0; i < 5; ++i) {
   //    double mean = TMath::Mean(n, resTimes[i].data());
   //    double rms = TMath::RMS(n, resfTimes[i].data());
   //    std::cout << "elapsed time for " << i << " : " << mean << " +/- " << rms / sqrt(n) << std::endl;
   //  }
    //if (verbose) std::cout << "output : " << output.size() << " : " << output.front() << " ......" << output.back() << std::endl;
}
//typedef TMVA_SOFIE_Conv_d100_L1_B1::Session S1;
//BENCHMARK(BM_SOFIE_Inference<S1>);//->Name( "Conv_d100_L1_B1");
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L1_B1::Session)->Name( "Conv_d100_L1_B1")->Args({100*100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L14_B1::Session)->Name( "Conv_d100_L14_B1")->Args({100*100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L14_B32::Session)->Name("Conv_d100_L14_B32")->Args({100*100, 32})->Unit(benchmark::kMillisecond);

BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_resnet18v1::Session)->Name("resnet18v1")->Args({3 * 224 * 224, 1})->Unit(benchmark::kMillisecond);
//Gemm benchmarks
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_event::Session)->Name("Linear_event")->Args({100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_16::Session)->Name("Linear_16")->Args({100, 16})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_32::Session)->Name("Linear_32")->Args({100, 32})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_64::Session)->Name("Linear_64")->Args({100, 64})->Unit(benchmark::kMillisecond);
BENCHMARK_MAIN();