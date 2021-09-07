#include <benchmark/benchmark.h>
#include <onnxruntime/core/session/onnxruntime_cxx_api.h>

#include <iostream>
#include <vector>
#include <numeric>

// Directory where ONNX models are placed, this must be consistent with
// the directory specified in the CMakeLists.txt.
#define INPUT_MODELS_DIR "input_models/"

static void BM_Onnxruntime_Inference(benchmark::State& state)
{
   const std::string model_path = INPUT_MODELS_DIR "Linear_64.onnx";

   Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "benchmark");
   
   Ort::SessionOptions session_options;
   session_options.SetIntraOpNumThreads(1);
   session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);

   Ort::Session session(env, model_path.c_str(), session_options);

   std::vector<const char*> input_node_names(1);
   std::vector<const char*> output_node_names(1);
   
   Ort::AllocatorWithDefaultOptions allocator;
   input_node_names[0] = session.GetInputName(0, allocator);
   output_node_names[0] = session.GetOutputName(0, allocator);

   // Getting the shapes

   std::vector<int64_t> input_node_dims = session
      .GetInputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
   std::vector<int64_t> output_node_dims = session
      .GetOutputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
   
   // Displaying input tensor shape

   std::cout << "Input shape: [ ";
   for (auto& i: input_node_dims)
      std::cout << i << " ";
   std::cout << "]" << std::endl;

   // Displaying output tensor shape

   std::cout << "Output shape: [ ";
   for (auto& i: output_node_dims)
      std::cout << i << " ";
   std::cout << "]" << std::endl;

   // Calculating the dimension of the input tensor

   size_t input_tensor_size = std::accumulate(input_node_dims.begin(),
      input_node_dims.end(), 1, std::multiplies<int>());
   std::vector<float> input_tensor_values(input_tensor_size);

   // Input tensor initialization
   std::fill_n(input_tensor_values.begin(), input_tensor_size, 1.0);

   auto memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
   Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info,
      input_tensor_values.data(), input_tensor_size,
      input_node_dims.data(), input_node_dims.size());

   // Running the model
   
   for (auto _ : state) {
      session.Run(Ort::RunOptions{nullptr}, input_node_names.data(),
         &input_tensor, 1, output_node_names.data(), 1);
   }
}
BENCHMARK(BM_Onnxruntime_Inference);

BENCHMARK_MAIN();