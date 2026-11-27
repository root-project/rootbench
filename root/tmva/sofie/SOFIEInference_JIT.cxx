// Author: Federico Sossai (fsossai), 2021

#include <benchmark/benchmark.h>

#include <fstream>
#include <thread>
#include <chrono>
#include <utility>
#include <vector>
#include <memory>
#include <functional>
#include <map>
#include <random>
#include <stdexcept>
#include <string>

#include "TInterpreter.h"
#include "TMath.h"


using namespace std;
bool verbose = false;
// use fixed instead of random input data, so that inference outputs are reproducible
bool testOutput = true;
// write the first inference output of each model to a file (for validating
// the results across ROOT versions)
bool writeOutput = false;

using InferFunc = std::vector<float> (*)(float const *);

// JIT-compile the inference code that SOFIE emitted for the model at build
// time, like in the TMVA_SOFIE_RDataFrame_JIT tutorial. The Session reads the
// weights from <model>.dat in the working directory. Each model is compiled
// once, as the benchmark function is called several times. The wrapper must
// be in the same Declare as the pragma: the inline Session::infer() is
// emitted where it is first used, and a separate Declare compiles it
// unoptimized.
InferFunc JitModel(std::string const &modelName)
{
   static std::map<std::string, InferFunc> cache;
   auto found = cache.find(modelName);
   if (found != cache.end())
      return found->second;

   std::string ns = "rootbench_jit_" + modelName;
   std::string code = "#pragma cling optimize(2)\n";
   code += "#include \"" + modelName + ".hxx\"\n";
   code += "namespace " + ns + " {\n";
   code += "TMVA_SOFIE_" + modelName + "::Session session;\n";
   code += "std::vector<float> infer(float const *x) { return session.infer(x); }\n";
   code += "}";
   if (!gInterpreter->Declare(code.c_str()))
      throw std::runtime_error("Failed to JIT-compile the SOFIE model " + modelName);
   auto infer = reinterpret_cast<InferFunc>(gInterpreter->Calc(("&" + ns + "::infer").c_str()));
   cache[modelName] = infer;
   return infer;
}


void BM_SOFIE_Inference(benchmark::State &state, std::string model_name)
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


   InferFunc infer = JitModel(model_name);

   double totDuration = 0;
   int ntimes = 0;
   std::vector<float> yOut;
   bool first = true;
   bool doWrite = writeOutput;
   for (auto _ : state) {
      auto t1 = std::chrono::high_resolution_clock::now();
      for (int i = 0; i < nevts; i += bsize) {
         auto y = infer(input.data() + inputSize*i);
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
         std::string filename = model_name + ".out";
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
#if 0
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

   S s("");

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
#endif

// Some models from PR #239 are not benchmarked because they are not
// supported by the current version of SOFIE:
//   * RNN_d10_L20_h8_B1, GRU_d10_L20_h8_B1, LSTM_d10_L20_h8_B1, DDB_B1:
//     the generated code does not compile
//   * Conv2DTranspose_Relu_Sigmoid: dynamic tensor error when parsing
//   * resnet18v1: "intermediate tensor already exists" error when parsing

BENCHMARK_CAPTURE(BM_SOFIE_Inference,higgs_model_dense,"higgs_model_dense")->Args({7, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, ConvTModel_G4,"ConvTModel_G4")->Args({15,1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, ConvTrans2dModel_B1,"ConvTrans2dModel_B1")->Args({4*4*4,1})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, SimpleNN_Alice,"SimpleNN_Alice")->Args({16,1})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_16,"Linear_16")->Args({100, 16})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_32,"Linear_32")->Args({100, 32})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_64,"Linear_64")->Args({100, 64})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_event,"Linear_event")->Args({100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Generator_B1,"Generator_B1")->Args({14, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Generator_B64,"Generator_B64")->Args({14, 64})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_d100_L14_B1,"Conv_d100_L14_B1")->Args({100*100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_d100_L14_B32,"Conv_d100_L14_B32")->Args({100*100, 32})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_d100_L1_B1,"Conv_d100_L1_B1")->Args({100*100, 1})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv3d_d32_L4_B1,"Conv3d_d32_L4_B1")->Args({32*32*32, 1})->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
