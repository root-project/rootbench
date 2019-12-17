if(ROOT_tmva_FOUND)
   RB_ADD_GBENCHMARK(CrossValidationBenchmarks
      CrossValidationBenchmarks.cxx
      LABEL short
      LIBRARIES Core Tree MathCore TMVA)
endif()

if(ROOT_tmva_FOUND AND ROOT_tmva-cpu_FOUND AND ROOT_imt_FOUND)
   RB_ADD_GBENCHMARK(ConvNetCpuBenchmarks
      ConvNetCpuBenchmarks.cxx
      LABEL short
      LIBRARIES Core Tree MathCore RIO Hist TMVA)
endif()

if (ROOT_cuda_FOUND AND ROOT_tmva-gpu_FOUND)
   set(DNN_CUDA_LIBRARIES dnn_cuda ${CUDA_CUBLAS_LIBRARIES})
   RB_ADD_GBENCHMARK(ConvNetCudaBenchmarks
      ConvNetCudaBenchmarks.cxx
      LABEL short
      LIBRARIES Core Tree MathCore RIO Hist TMVA ${DNN_CUDA_LIBRARIES})
endif()
