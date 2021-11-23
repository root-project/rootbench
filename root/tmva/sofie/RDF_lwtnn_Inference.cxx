#include "higgs_model_dense.hxx"
#include <iostream>
#include "TROOT.h"
#include "TSystem.h"
#include "ROOT/RDataFrame.hxx"

#include "lwtnn/LightweightNeuralNetwork.hh"
#include "lwtnn/parse_json.hh"

#include <string>
#include <fstream>
#include <stdlib.h>

#include <benchmark/benchmark.h>

// template <typename Func>
struct LWTNNFunctor {

   // std::vector<float> input;
   // std::vector<std::shared_ptr<Func>> sessions;

   std::map<std::string, double> inputs;
   std::vector<std::string> names;

   std::shared_ptr<lwt::LightweightNeuralNetwork> model;

   LWTNNFunctor(unsigned nslots)
   {
      std::string config_filename("higgs_model_dense.json");
      std::ifstream config_file(config_filename);
      auto config = lwt::parse_json(config_file);

      // Set up neural network model from config
      model = std::make_shared<lwt::LightweightNeuralNetwork>(config.inputs, config.layers, config.outputs);

      // Load inputs from argv
      std::cout << "input size is " << config.inputs.size() << std::endl;
      for (size_t n = 0; n < config.inputs.size(); n++) {
         inputs[config.inputs.at(n).name] = 0.0;
         names.push_back(config.inputs.at(n).name);
      }
   }

   double operator()(unsigned nslots, float x0, float x1, float x2, float x3, float x4, float x5, float x6)
   {
      // int off = 0;//nslots*7;
      inputs[names[0]] = x0;
      inputs[names[1]] = x1;
      inputs[names[2]] = x2;
      inputs[names[3]] = x3;
      inputs[names[4]] = x4;
      inputs[names[5]] = x5;
      inputs[names[6]] = x6;

      auto y = model->compute(inputs);
      return y.begin()->second;
   }
};

void BM_RDF_LWTNN_Inference(benchmark::State &state)
{

   int nslot = 1;
   if (nslot > 1)
      ROOT::EnableImplicitMT(nslot);

   auto fileName = "Higgs_data_full.root";
   // file is available at "https://cernbox.cern.ch/index.php/s/YuSHwTXBa0UBEhD/download";
   // do curl https://cernbox.cern.ch/index.php/s/XaPBtaGrnN38wU0 -o Higgs_data_full.root
   if (gSystem->AccessPathName(fileName)) {
      std::string cmd = "curl https://cernbox.cern.ch/index.php/s/YuSHwTXBa0UBEhD/download -o ";
      cmd += fileName;
      gSystem->Exec(cmd.c_str());
   }
   auto treeName = "test_tree";
   ROOT::RDataFrame df(treeName, fileName);

   LWTNNFunctor functor(nslot);

   for (auto _ : state) {

      auto h1 = df.DefineSlot("DNN_Value", functor, {"m_jj", "m_jjj", "m_lv", "m_jlv", "m_bb", "m_wbb", "m_wwbb"})
                   .Histo1D("DNN_Value");

      auto t1 = std::chrono::high_resolution_clock::now();

      auto n = h1->GetEntries();
      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

      std::cout << " Processed " << n << " entries "
                << " time = " << duration / 1.E6 << " (sec)  time/event = " << duration / double(n) << " musec"
                << std::endl;

      // h1->DrawClone();
   }
}


BENCHMARK(BM_RDF_LWTNN_Inference)->Unit(benchmark::kMillisecond);
BENCHMARK_MAIN();