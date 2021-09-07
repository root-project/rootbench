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
    
    # Creating an ONNXRuntime inference benchmark for every model
    foreach(fname ${ONNX_MODELS})
      get_filename_component(fname ${fname} NAME_WE)
      set(target_name ONNXRuntime_${fname})
      configure_file(ONNXRuntimeInference.cxx.in ${target_name}.cxx)

      RB_ADD_GBENCHMARK(${target_name}
        ${target_name}.cxx
        LABEL short
        LIBRARIES TMVA onnxruntime
      )
      target_link_directories(${target_name} PRIVATE ${ONNXRuntime_LIBRARIES})
      target_include_directories(${target_name} PRIVATE ${ONNXRuntime_INCLUDE_DIR})
    endforeach()
  endif()
    
  # Checking the SOFIE compiler
  if(NOT EXISTS ${ROOTSYS}/tmva/sofie/test/emitFromONNX)
    message(FATAL_ERROR "SOFIE compiler not found")
  endif()

  # Creating an inference benchmark for SOFIE
  RB_ADD_GBENCHMARK(SOFIEInference
    SOFIEInference.cxx
    LABEL short
    LIBRARIES TMVA blas
  )
  
endif()

