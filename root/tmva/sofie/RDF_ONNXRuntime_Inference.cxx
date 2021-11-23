#include "higgs_model_dense.hxx"
#include <iostream>
#include "TROOT.h"
#include "TSystem.h"
#include "ROOT/RDataFrame.hxx"

#include <onnxruntime_cxx_api.h>


#include <string>
#include <fstream>
#include <stdlib.h>

#include <benchmark/benchmark.h>

// template <typename Func>
struct ONNXFunctor {

   // std::vector<float> input;
   // std::vector<std::shared_ptr<Func>> sessions;

   std::map<std::string, double> inputs;
   std::vector<std::string> names;

   std::shared_ptr<Ort::Session> session;

   //td::vector<Ort::Value>  input_tensors;

   //Ort::Value  * ort_input = nullptr;

   //float *input_arr = nullptr;

   std::vector<const char *> input_node_names;
   std::vector<const char *> output_node_names;

   std::vector<float> input_tensor_values;

   std::vector<int64_t> input_node_dims;
   std::vector<int64_t> output_node_dims;

   ONNXFunctor(unsigned nslots)
   {

      Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "benchmark");

      std::string model_path = "higgs_model_dense.onnx";

      Ort::SessionOptions session_options;
      session_options.SetIntraOpNumThreads(1);
      session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);

      // std::cout << "benchmarking model " << model_path << std::endl;
      session = std::make_shared<Ort::Session>(env, model_path.c_str(), session_options);

     

      Ort::AllocatorWithDefaultOptions allocator;
      input_node_names.push_back(session->GetInputName(0, allocator));
      output_node_names.push_back( session->GetOutputName(0, allocator));

      // Getting the shapes

      input_node_dims = session->GetInputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
      output_node_dims = session->GetOutputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();

      // Calculating the dimension of the input tensor
     
      //int bsize = input_node_dims[0];
      // std::cout << "Using bsize = " << bsize << std::endl;
      //int nbatches = nevt / bsize;

      size_t input_tensor_size = std::accumulate(input_node_dims.begin(), input_node_dims.end(), 1, std::multiplies<int>());
      //std::vector<float> input_tensor_values(input_tensor_size );

      input_tensor_values.resize(input_tensor_size);

      auto memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);

      //input_tensors.push_back(Ort::Value::CreateTensor<float>(
      //   memory_info, input_tensor_values.data(), input_tensor_size, input_node_dims.data(), input_node_dims.size()) );

      
      // Ort::Value
      // Ort::Value *ort_input = new Ort::Value(nullptr);
      // // input_tensor =
      // *ort_input = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_values.size(),
      //                                 input_node_dims.data(), input_node_dims.size());

      //input_arr = input_tensor.GetTensorMutableData<float>();

      // Running the model
      //input_arr = input_tensors[0].GetTensorMutableData<float>();
     
      ///////


      // // Load inputs from argv
      // std::cout << "input size is " << config.inputs.size() << std::endl;
      // for (size_t n = 0; n < config.inputs.size(); n++) {
      //    inputs[config.inputs.at(n).name] = 0.0;
      //    names.push_back(config.inputs.at(n).name);
      // }
   }

   double operator()(unsigned nslots, float x0, float x1, float x2, float x3, float x4, float x5, float x6)
   {

      // not sure how to cache input ort tensor
      auto memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
      Ort::Value 
      input_tensor = Ort::Value::CreateTensor<float>(
         memory_info, input_tensor_values.data(), input_tensor_values.size(), input_node_dims.data(), input_node_dims.size());
      float * input_arr = input_tensor.GetTensorMutableData<float>();

      int off = 0;
      input_arr[off] = x0;
      input_arr[off + 1] = x1;
      input_arr[off + 2] = x2;
      input_arr[off + 3] = x3;
      input_arr[off + 4] = x4;
      input_arr[off + 5] = x5;
      input_arr[off + 6] = x6;

      

      auto output_tensors = session->Run(Ort::RunOptions{nullptr}, input_node_names.data(), &input_tensor, 1, output_node_names.data(), 1);
      float * floatarr = output_tensors.front().GetTensorMutableData<float>();
      return floatarr[0];
   }
};

void BM_RDF_ONNX_Inference(benchmark::State &state)
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

   ONNXFunctor functor(nslot);

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


BENCHMARK(BM_RDF_ONNX_Inference)->Unit(benchmark::kMillisecond);
BENCHMARK_MAIN();