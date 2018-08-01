RB_ADD_GBENCHMARK(CrossValidationBenchmarks
  CrossValidationBenchmarks.cxx
  LABEL short
  LIBRARIES Core Tree MathCore TMVA)

RB_ADD_GBENCHMARK(ConvNetCpuBenchmarks
        ConvNetCpuBenchmarks.cxx
  LABEL short
  LIBRARIES Core Tree MathCore TMVA)

if (CUDA_FOUND AND tmva-gpu)

set(DNN_CUDA_LIBRARIES dnn_cuda ${CUDA_CUBLAS_LIBRARIES})

RB_ADD_GBENCHMARK(ConvNetCudaBenchmarks
        ConvNetCudaBenchmarks.cxx
  LABEL short
  LIBRARIES Core Tree MathCore TMVA ${DNN_CUDA_LIBRARIES})

endif()
