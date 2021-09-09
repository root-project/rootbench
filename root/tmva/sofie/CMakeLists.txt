# @author Federico Sossai (fsossai)

if(ROOT_tmva_FOUND AND ROOT_tmva-sofie_FOUND)

  # Checking that all required model exist
  if (NOT ONNX_MODELS_DIR)
    set(ONNX_MODELS_DIR input_models)
  endif()
  file(GLOB ONNX_MODELS "${ONNX_MODELS_DIR}/*.onnx")

  # Copying every ONNX model in the input directory to the build directory.
  set(out_dir ${CMAKE_CURRENT_BINARY_DIR}/${ONNX_MODELS_DIR})
  file(MAKE_DIRECTORY ${out_dir})
  foreach(model ${ONNX_MODELS})
    get_filename_component(fname ${model} NAME)
    configure_file(${model} ${out_dir}/${fname} COPYONLY)
  endforeach()
  
  # Looking for ONNXRuntime
  find_package(ONNXRuntime QUIET)
  if(ONNXRuntime_FOUND)
    message(STATUS "Found ONNXRuntime (build type: ${ONNXRuntime_BUILD_TYPE}, version: ${ONNXRuntime_VERSION_STRING})")
    
    # Configuring ONNXRuntimeInference_Template.cxx.in
    set(FUNC_NAME "BM_ONNXRuntime_Inference")
    set(CAPTURE_STR "BENCHMARK_CAPTURE(${FUNC_NAME}, @1,\t@2)@3")
    set(HEAD_COMMENT "Automatically configured by CMake")
    set(ALL_CAPTURES "")
    set(ONNX_MODEL_NAMES "")
    foreach(model ${ONNX_MODELS})
      get_filename_component(fname ${model} NAME)
      get_filename_component(fname_we ${model} NAME_WE)
      string(REPLACE "@1" ${fname_we} cap ${CAPTURE_STR})
      string(REPLACE "@2" "\"${ONNX_MODELS_DIR}/${fname}\"" cap ${cap})
      list(APPEND ALL_CAPTURES ${cap})
    endforeach()
    string(REPLACE ";" "\n" BENCHMARK_CAPTURES "${ALL_CAPTURES}")         # String[] -> String
    string(REPLACE "@3" ";" BENCHMARK_CAPTURES "${BENCHMARK_CAPTURES}")   # Adding semicolon
    configure_file(ONNXRuntimeInference_Template.cxx.in ONNXRuntimeInference.cxx @ONLY)

    RB_ADD_GBENCHMARK(ONNXRuntimeInference
      ONNXRuntimeInference.cxx
      LABEL short
      LIBRARIES TMVA onnxruntime
    )
    target_link_directories(ONNXRuntimeInference PRIVATE ${ONNXRuntime_LIBRARIES})
    target_include_directories(ONNXRuntimeInference PRIVATE ${ONNXRuntime_INCLUDE_DIR})

  endif()
    
  # Checking the SOFIE compiler
  if(NOT EXISTS ${ROOTSYS}/tmva/sofie/test/emitFromONNX)
    message(FATAL_ERROR "SOFIE compiler not found")
  endif()

  # Benchmark for models emitted by SOFIE
  RB_ADD_GBENCHMARK(SOFIEInference
    SOFIEInference.cxx
    LABEL short
    LIBRARIES TMVA blas
  )

  # Benchmark for models emitted by SOFIE (with RModelProfiler)
  # This should be useful in measuring profiler's overhead
  RB_ADD_GBENCHMARK(SOFIEInferenceProfiler
    SOFIEInferenceProfiler.cxx
    LABEL short
    LIBRARIES TMVA blas
  )
  
endif()

