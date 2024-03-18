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
#include <fstream>
#include <stdlib.h>

#include "TMath.h"

#include "lwtnn/LightweightNeuralNetwork.hh"
#include "lwtnn/LightweightGraph.hh"
#include "lwtnn/parse_json.hh"

bool verbose = false;

void BM_LWTNN_Inference_model(benchmark::State &state, std::string model_name, size_t inputSize, size_t outputSize = 1)
{


   std::map<std::string, double> inputs;
   std::vector<std::string> names;

   std::string model_filename = model_name + ".json";
   std::ifstream config_file(model_filename);

   auto config = lwt::parse_json(config_file);

   // Set up neural network model from config
   auto model = std::make_unique<lwt::LightweightNeuralNetwork>(config.inputs, config.layers, config.outputs);

   config_file.close();

   // Initialize input
   //std::cout << "input size is " << config.inputs.size() << std::endl;
   if (config.inputs.size() != inputSize ) {
      throw std::runtime_error("Bad input size - it is " + std::to_string(inputSize) + 
      " and should be " + std::to_string(config.inputs.size()));
   }
   for (size_t n = 0; n < inputSize; n++) {
      inputs[config.inputs.at(n).name] = 0.0;
      names.push_back(config.inputs.at(n).name);
   }


   // size_t inputSize = state.range(0); // input size (without batch size)
   size_t bsize = 1; // bsize is always 1 for lwtnn
   size_t nevts = 64;
   size_t nrep = nevts / bsize;

   std::vector<float> input(inputSize * nevts);

   static std::uniform_real_distribution<float> distribution(-1, 1);
   static std::default_random_engine generator;
   std::generate(input.begin(), input.end(), []() { return distribution(generator); });

   double totDuration = 0;
   int ntimes = 0;
   std::vector<float> y(outputSize);
   for (auto _ : state) {
      auto t1 = std::chrono::high_resolution_clock::now();
      for (size_t i = 0; i < nevts; i += bsize) {
         for (size_t j = 0; j < inputSize; j++)
            //inputs["node_0"]["variable_" + std::to_string(j)] = input[i * inputSize + j];
           inputs[names[j]] = input[i * inputSize + j];

         auto outputs = model->compute(inputs);
         y[0] = outputs.begin()->second;
         // for (int i = 0; i < outputSize; i++)
         //    y[i] = outputs["out_" + std::to_string(i)];
      }

      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      totDuration += duration / 1.E3; // in milliseconds
      ntimes++;
   }

   state.counters["time/evt(ms)"] = totDuration / double(ntimes * nevts);
}

void BM_LWTNN_Inference_graph(benchmark::State &state, std::string model_name, size_t inputSize, size_t outputSize = 1 )
{

   typedef std::map<std::string, std::map<std::string, double>> NetworkInputs;
   typedef std::map<std::string, double> NetworkOutputs;

   //std::map<std::string, double> inputs;
   NetworkInputs inputs; 
   std::vector<std::string> names;

   std::string model_filename = model_name + ".json";
   std::ifstream config_file(model_filename);
   auto graph = std::make_unique<lwt::LightweightGraph>(lwt::parse_json_graph(config_file));
   config_file.close();

 

   //size_t inputSize = state.range(0); // input size (without batch size)
   size_t bsize = 1;                  // bsize is always 1 for lwtnn
   size_t nevts = 64;
   size_t nrep = nevts / bsize;

   std::vector<float> input(inputSize * nevts);

   static std::uniform_real_distribution<float> distribution(-1, 1);
   static std::default_random_engine generator;
   std::generate(input.begin(), input.end(), []() { return distribution(generator); });


   double totDuration = 0;
   int ntimes = 0;
   std::vector<float> y(outputSize);
   for (auto _ : state) {
      auto t1 = std::chrono::high_resolution_clock::now();
      for (size_t i = 0; i < nevts; i += bsize) {
         for (size_t j = 0; j < inputSize; j++)
            inputs["node_0"]["variable_" + std::to_string(j)] = input[i * inputSize + j];
            // inputs[names[j]] = input[i * inputSize + j];

         auto outputs = graph->compute(inputs);
         for (int i = 0; i < outputSize; i++)
            y[i] = outputs["out_" + std::to_string(i)];
      }
   

      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      totDuration += duration / 1.E3;  // in milliseconds
      ntimes++;
   }

   state.counters["time/evt(ms)"] = totDuration / double(ntimes * nevts);
}

//LWTNN benchmarks 
// use B<_CAPTURE to pass string of file, second parameter is name of test and is arbitrary
BENCHMARK_CAPTURE(BM_LWTNN_Inference_model,higgs_model_dense, "higgs_model_dense",7)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_LWTNN_Inference_graph, generator, "Generator",14)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
