if(ROOT_tmva_FOUND AND ROOT_tmva-sofie_FOUND)

  # Looking for ONNXRuntime
  find_package(ONNXRuntime REQUIRED)
  if(ONNXRuntime_FOUND)
    message(STATUS "Found ONNXRuntime (build type: ${ONNXRuntime_BUILD_TYPE}, version: ${ONNXRuntime_VERSION_STRING})")
  endif()

  #[======================================================================[
  
    REQUIRED MODELS
  
    The following models are required because are loaded by at least
    one or more benchmarks.
    The abscence of at least one of the following models from the
    ${ONNX_MODELS_DIR} will cause CMake to throw a fatal error message.

  #]======================================================================]
  set(REQUIRED_MODELS
    "Linear_64.onnx"
  )
  
  # Checking that all required model exist
  if (NOT ONNX_MODELS_DIR)
    set(ONNX_MODELS_DIR input_models)
  endif()
  foreach(model ${REQUIRED_MODELS})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${ONNX_MODELS_DIR}/${model})
      message(FATAL_ERROR "Missing a required ONNX input model. "
        "\"${model}\" is missing from ${CMAKE_CURRENT_SOURCE_DIR}/${ONNX_MODELS_DIR}")
    endif()
  endforeach()

  # Copying every ONNX model in the input directory to the build directory.
  set(out_dir ${CMAKE_CURRENT_BINARY_DIR}/${ONNX_MODELS_DIR})
  file(MAKE_DIRECTORY ${out_dir})
  foreach(model ${REQUIRED_MODELS})
    configure_file(${ONNX_MODELS_DIR}/${model} ${out_dir}/${model} COPYONLY)
  endforeach()
  
  # Creating an inference benchmark
  RB_ADD_GBENCHMARK(ONNXRuntimeInference
    ONNXRuntimeInference.cxx
    LABEL short
    LIBRARIES TMVA onnxruntime
  )
  target_link_directories(ONNXRuntimeInference PRIVATE ${ONNXRuntime_LIBRARIES})
  target_include_directories(ONNXRuntimeInference PRIVATE ${ONNXRuntime_INCLUDE_DIR})
  
endif()

