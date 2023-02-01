// Author: Federico Sossai (fsossai), 2021

#include <benchmark/benchmark.h>

#include <fstream>
#include <thread>
#include <chrono>
#include <utility>
#include <vector>
#include <memory>
#include <functional>
#include <random>

#include "TMVA/RSofieReader.hxx"

#include "TMath.h"


using namespace std;
bool verbose = false;
bool testOutput = true;


void BM_SOFIE_Inference(benchmark::State &state, std::string model_file)
{
   std::string model_path = "input_models/" + model_file;
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


   // parse the model
   TMVA::Experimental::RSofieReader r(model_path);

   double totDuration = 0;
   int ntimes = 0;
   std::vector<float> yOut;
   bool first = true;
   bool doWrite = testOutput;
   for (auto _ : state) {
      auto t1 = std::chrono::high_resolution_clock::now();
      for (int i = 0; i < nevts; i += bsize) {
         std::vector<float> x(input.begin()+inputSize*i, input.begin()+inputSize*(i+1));
         auto y = r.Compute(x);
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
         std::string filename = std::string(model_file) + ".out";
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

BENCHMARK_CAPTURE(BM_SOFIE_Inference,higgs_model_dense,"higgs_model_dense.onnx")->Args({7, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference,Conv2DTranspose_Relu_Sigmoid,"Conv2DTranspose_Relu_Sigmoid.onnx")->Args({15,1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, ConvTrans2dModel_B1,"ConvTrans2dModel_B1.onnx")->Args({4*4*4,1})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, SimpleNN_Alice,"SimpleNN_Alice.onnx")->Args({16,1})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_16,"Linear_16.onnx")->Args({100, 16})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_32,"Linear_32.onnx")->Args({100, 32})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_64,"Linear_64.onnx")->Args({100, 64})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Linear_event,"Linear_event.onnx")->Args({100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Generator_B1,"Generator_B1.onnx")->Args({14, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Generator_B64,"Generator_B64.onnx")->Args({14, 64})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_d100_L14_B1,"Conv_d100_L14_B1.onnx")->Args({100*100, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_d100_L14_B32,"Conv_d100_L14_B32.onnx")->Args({100*100, 32})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv_d100_L1_B1,"Conv_d100_L1_B1.onnx")->Args({100*100, 1})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, Conv3d_d32_L4_B1,"Conv3d_d32_L4_B1.onnx")->Args({32*32*32, 1})->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_SOFIE_Inference, resnet18v1,"resnet18v1.onnx")->Args({3 * 224 * 224, 1})->Unit(benchmark::kMillisecond);

//Recurrent benchmark
BENCHMARK_CAPTURE(BM_SOFIE_Inference, RNN_d10_L20_h8_B1,"RNN_d10_L20_h8_B1.onnx")->Args({3 * 5, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, GRU_d10_L20_h8_B1,"GRU_d10_L20_h8_B1.onnx")->Args({3 * 5, 1})->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_SOFIE_Inference, LSTM_d10_L20_h8_B1,"LSTM_d10_L20_h8_B1.onnx")->Args({1 * 1, 1})->Unit(benchmark::kMillisecond);


BENCHMARK_MAIN();
