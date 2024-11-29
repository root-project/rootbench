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
      LIBRARIES Core Tree MathCore RIO Hist TMVA PyMVA)
endif()

if (ROOT_cuda_FOUND AND ROOT_tmva-gpu_FOUND)
   set(DNN_CUDA_LIBRARIES ${CUDA_CUBLAS_LIBRARIES} ${CUDNN_LIBRARIES})
   RB_ADD_GBENCHMARK(ConvNetCudaBenchmarks
      ConvNetCudaBenchmarks.cxx
      LABEL short
      LIBRARIES Core Tree MathCore RIO Hist TMVA PyMVA ${DNN_CUDA_LIBRARIES})
endif()

if(ROOT_tmva_FOUND AND ROOT_tmva-cpu_FOUND AND ROOT_imt_FOUND)
   RB_ADD_GBENCHMARK(RNNCpuBenchmarks
      RNNCpuBenchmarks.cxx
      LABEL short
      LIBRARIES Core Tree MathCore Gpad RIO Hist TMVA PyMVA)
endif()

if (ROOT_cuda_FOUND AND ROOT_tmva-gpu_FOUND)
   set(DNN_CUDA_LIBRARIES ${CUDA_CUBLAS_LIBRARIES} ${CUDNN_LIBRARIES})
   RB_ADD_GBENCHMARK(RNNCudaBenchmarks
      RNNCudaBenchmarks.cxx
      LABEL short
      LIBRARIES Core Tree MathCore Gpad RIO Hist TMVA PyMVA ${DNN_CUDA_LIBRARIES})
endif()
