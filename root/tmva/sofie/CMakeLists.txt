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

  else()
    message(WARNING "ONNXRuntime not found")
  endif()
    
  # Configuring SOFIEInference_Template.cxx.in
  set(FUNC_NAME "BM_SOFIE_Inference")
  set(CAPTURE_STR "BENCHMARK_CAPTURE(${FUNC_NAME}, @1,\t@2)@3")
  set(INCLUDES_STR "#include @1")
  set(FUNCS_STR "\t\t{ @1,\t{@2,\t@3} }")
  set(HEAD_COMMENT "Automatically configured by CMake")
  set(ALL_CAPTURES "")
  set(ALL_INCLUDES "")
  set(ALL_FUNCS "")
  set(COMPILED_MODELS_DIR ${ONNX_MODELS_DIR}/compiled)
  file(GLOB COMPILED_MODELS "${COMPILED_MODELS_DIR}/*.hxx")
  set(inc "")
  set(cap "")
  set(funcs "")
  foreach(model ${COMPILED_MODELS})
    get_filename_component(fname ${model} NAME)
    get_filename_component(fname_we ${model} NAME_WE)
    # Fixing the string for the include headers
    string(REPLACE "@1" "\"${COMPILED_MODELS_DIR}/${fname}\"" inc ${INCLUDES_STR})
    list(APPEND ALL_INCLUDES ${inc})
    # Fixing the string for the GBenchmark captures
    string(REPLACE "@1" ${fname_we} cap ${CAPTURE_STR})
    string(REPLACE "@2" "\"${fname_we}\"" cap ${cap})
    list(APPEND ALL_CAPTURES ${cap})
    # Fixing the string for the actual infer function that each capture will call
    string(REPLACE "@1" "\"${fname_we}\"" funcs ${FUNCS_STR})
    string(REPLACE "@2" "TMVA_SOFIE_${fname_we}::infer" funcs ${funcs})
    string(REPLACE "@3" "0" funcs ${funcs})
    list(APPEND ALL_FUNCS ${funcs})
  endforeach()

  # Transforming list of strings into a single multi-line string
  string(REPLACE ";" "\n" BENCHMARK_CAPTURES "${ALL_CAPTURES}")         # String[] -> String
  string(REPLACE "@3" ";" BENCHMARK_CAPTURES "${BENCHMARK_CAPTURES}")   # Adding semicolon
  string(REPLACE ";" "\n" INCLUDE_HEADERS "${ALL_INCLUDES}")            # String[] -> String
  string(REPLACE ";" ",\n" FUNC_TUPLES "${ALL_FUNCS}")            # String[] -> String
  configure_file(SOFIEInference_Template.cxx.in SOFIEInference.cxx @ONLY)
  
  # Benchmark for models emitted by SOFIE
  RB_ADD_GBENCHMARK(SOFIEInference
    SOFIEInference.cxx
    LABEL short
    LIBRARIES TMVA openblas
  )
  target_include_directories(SOFIEInference PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

endif()

