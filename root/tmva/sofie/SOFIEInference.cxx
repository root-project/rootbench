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
#include <filesystem>

#include "Linear_event.hxx"
#include "Linear_16.hxx"
#include "Linear_32.hxx"
#include "Linear_64.hxx"
#include "Generator_B1.hxx"
#include "Generator_B64.hxx"
#include "Conv_d100_L1_B1.hxx"
#include "Conv_d100_L14_B1.hxx"
#include "Conv_d100_L14_B32.hxx"
#include "Conv3d_d32_L4_B1.hxx"
#include "higgs_model_dense.hxx"
#include "ConvTrans2dModel_B1.hxx"
#include "ConvTModel_G4.hxx"
#include "SimpleNN_Alice.hxx"

// The following models from PR #239 are not benchmarked because they are
// not supported by the current version of SOFIE:
//   * RNN_d10_L20_h8_B1, GRU_d10_L20_h8_B1, LSTM_d10_L20_h8_B1, DDB_B1:
//     the generated code does not compile
//   * Conv2DTranspose_Relu_Sigmoid: dynamic tensor error when parsing
//   * resnet18v1: "intermediate tensor already exists" error when parsing

#include "TMath.h"


using namespace std;
bool verbose = false;
// use fixed instead of random input data, so that inference outputs are reproducible
bool testOutput = true;
// write the first inference output of each model to a file (for validating
// the results across ROOT versions), enabled with the -o command line option
bool writeOutput = false;


template <class S>
void BM_SOFIE_Inference(benchmark::State &state)
{
   size_t inputSize = state.range(0);  // input size (without batch size)
   size_t bsize = (state.range(1) > 0) ? state.range(1) : 1;
   size_t nevts = 64;
   size_t nrep = nevts / bsize;

   vector<float> input(inputSize*nevts);

   if (testOutput) {
      input = std::vector<float>(input.size(),1.);
   }
   else {
      static std::uniform_real_distribution<float> distribution(-1, 1);
      static std::default_random_engine generator;
      std::generate(input.begin(), input.end(), []() { return distribution(generator); });
   }
   float *input_ptr = input.data();
   // construct session (no need to pass filename, use default value)
   S s;

   double totDuration = 0;
   int ntimes = 0;
   std::vector<float> yOut;
   bool first = true;
   bool doWrite = writeOutput;
   for (auto _ : state) {
      auto t1 = std::chrono::high_resolution_clock::now();
      for (int i = 0; i < nevts; i += bsize) {
         auto y = s.infer(input.data()+ inputSize*i);
         if (first) {
            //std::cout << std::string(typeid(s).name()) << " :  " << y[0] << "  " << y[1] << std::endl;
            yOut = y;
            first = false;
         }
      }
      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      totDuration += duration / 1.E3;  // in milliseconds
      ntimes++;
      if (doWrite) {
         // write output for test
         //std::cout << "write output " << std::endl;
         std::ofstream f;
         std::string filename = std::string(typeid(s).name()) + ".out";
         f.open(filename);
         f << yOut.size();
         for (size_t i = 0; i < yOut.size(); i++) {
            if ((i % 10) == 0) f << "\n"; // add endline every 10
            f << yOut[i] << "  ";
         }
         f << std::endl;
         f.close();
         doWrite = false;
      }
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

// inference for model with 3 inputs
template <class S>
void BM_SOFIE_Inference_3(benchmark::State &state)
{
   size_t bsize = state.range(0);  // batch size
   size_t inputSize1 = state.range(1);  // input 1 size
   size_t inputSize2 = state.range(2);  // input 2 size
   size_t inputSize3 = state.range(3);

   size_t nevts = 64;
   size_t nrep = nevts / bsize;

   size_t eventSize = inputSize1 + inputSize2+inputSize3;

   vector<float> input1(inputSize1*nevts);
   vector<float> input2(inputSize2*nevts);
   vector<float> input3(inputSize3*nevts);

   if (!testOutput) {
   static std::uniform_real_distribution<float> distribution(-1, 1);
   static std::default_random_engine generator;
   std::generate(input1.begin(), input1.end(), []() { return distribution(generator); });
   std::generate(input2.begin(), input2.end(), []() { return distribution(generator); });
   std::generate(input3.begin(), input3.end(), []() { return distribution(generator); });
   }
   else {
      // generate fixed data
      input1 = vector<float>(input1.size(),1.);
      input2 = vector<float>(input2.size(),2.);
      input3 = vector<float>(input3.size(),3.);
   }

   // create session with default filename
   S s{};

   //std::cout << "init done - do benchmark \n";

   double totDuration = 0;
   int ntimes = 0;
   for (auto _ : state) {
      auto t1 = std::chrono::high_resolution_clock::now();
      for (int i = 0; i < nevts; i += bsize) {
         float * p1 = input1.data()+ inputSize1*i;
         float * p2 = input2.data()+ inputSize2*i;
         float * p3 = input3.data()+ inputSize3*i;
         auto y = s.infer(p1,p2,p3);
      }
      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      totDuration += duration / 1.E3;  // in milliseconds
      ntimes++;
   }

   state.counters["time/evt(ms)"] = totDuration / double(ntimes * nevts);
}

// Conv Transpose
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_ConvTModel_G4::Session)->Name("ConvTModel_G4")->Args({15,1})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_ConvTrans2dModel_B1::Session)->Name("ConvTrans2dModel_B1")->Args({4*4*4,1})->Unit(benchmark::kMillisecond);

BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_SimpleNN_Alice::Session)->Name("SimpleNN_Alice")->Args({16,1})->Unit(benchmark::kMillisecond);

//Gemm benchmarks
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_16::Session)->Name("Linear_16")->Args({100, 16})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_32::Session)->Name("Linear_32")->Args({100, 32})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_64::Session)->Name("Linear_64")->Args({100, 64})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Linear_event::Session)->Name("Linear_event")->Args({100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Generator_B1::Session)->Name("Generator_B1")->Args({14, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Generator_B64::Session)->Name("Generator_B64")->Args({14, 64})->Unit(benchmark::kMillisecond);

BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_higgs_model_dense::Session)->Name("higgs_model_dense")->Args({7, 1})->Unit(benchmark::kMillisecond);

BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L14_B1::Session)->Name( "Conv_d100_L14_B1")->Args({100*100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L14_B32::Session)->Name("Conv_d100_L14_B32")->Args({100*100, 32})->Unit(benchmark::kMillisecond);
BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv_d100_L1_B1::Session)->Name( "Conv_d100_L1_B1")->Args({100*100, 1})->Unit(benchmark::kMillisecond);

BENCHMARK_TEMPLATE(BM_SOFIE_Inference, TMVA_SOFIE_Conv3d_d32_L4_B1::Session)->Name( "Conv3d_d32_L4_B1")->Args({32*32*32, 1})->Unit(benchmark::kMillisecond);

// default main
//BENCHMARK_MAIN();

// define main to pass some convenient command line parameters
int main(int argc, char **argv) {

   // Parse command line arguments
   for (Int_t i = 1; i < argc; i++) {
      std::string arg = argv[i];
      if (arg == "-v") {
         std::cout << "---running in verbose mode" << std::endl;
         verbose = true;
      } else if (arg == "-o") {
         std::cout << "---writing inference outputs to files" << std::endl;
         writeOutput = true;
      } else if ((arg == "-d" || arg == "--dir") && argc > i+1) {
         std::string pathDir = argv[i+1];
         std::filesystem::path path(pathDir);
         std::filesystem::current_path(path);
         i++;
      }
   }

   std::cout << "running benchmark from current directory " << std::filesystem::current_path()  << std::endl;

   ::benchmark::Initialize(&argc, argv);
   ::benchmark::RunSpecifiedBenchmarks();

   return 0;
}
