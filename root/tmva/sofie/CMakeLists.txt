# @author Federico Sossai (fsossai)


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
  ## to find OONX run time configure cmake with
  ## -DONNXRuntime_INCLUDE_DIRS=..onxruntime_location.../include -DONNXRuntime_LIBRARIES=.../lib
  find_package(ONNXRuntime)
  if(ONNXRuntime_FOUND)
    message(STATUS "Found ONNXRuntime (library is  ${ONNXRuntime_LIBRARY}, libraries ${ONNXRuntime_LIBRARIES})")
    
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
    string(REPLACE "@3" "->Unit(benchmark::kMillisecond);" BENCHMARK_CAPTURES "${BENCHMARK_CAPTURES}")   # Adding semicolon
    configure_file(ONNXRuntimeInference_Template.cxx.in ONNXRuntimeInference.cxx @ONLY)

    RB_ADD_GBENCHMARK(ONNXRuntimeInference
      ONNXRuntimeInference.cxx
      LABEL short
      LIBRARIES TMVA ${ONNXRuntime_LIBRARIES}
    )
    target_link_directories(ONNXRuntimeInference PRIVATE ${ONNXRuntime_LIBRARIES})
    target_include_directories(ONNXRuntimeInference PRIVATE ${ONNXRuntime_INCLUDE_DIR})

  else()
    message(STATUS "ONNXRuntime not found")
  endif()



#---TMVA-/SOFIE
if(ROOT_tmva_FOUND AND ROOT_tmva-sofie_FOUND)


### this is not used 
if (Use_SOFIE_TEMPLATE)
    
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
  
  
endif()


#   configure_file(input_models/compiled/Linear_event.hxx Linear_event.hxx COPYONLY)
#   configure_file(input_models/compiled/Linear_event.dat Linear_event.dat COPYONLY)

#   configure_file(input_models/compiled/Linear_16.hxx Linear_16.hxx COPYONLY)
#   configure_file(input_models/compiled/Linear_16.dat Linear_16.dat COPYONLY)
  
#   configure_file(input_models/compiled/Linear_32.hxx Linear_32.hxx COPYONLY)
#   configure_file(input_models/compiled/Linear_32.dat Linear_32.dat COPYONLY)
  
#   configure_file(input_models/compiled/Linear_64.hxx Linear_64.hxx COPYONLY)
#   configure_file(input_models/compiled/Linear_64.dat Linear_64.dat COPYONLY)
  
  
#   configure_file(input_models/compiled/Conv_d100_L1_B1.hxx Conv_d100_L1_B1.hxx COPYONLY)
#   configure_file(input_models/compiled/Conv_d100_L1_B1.dat Conv_d100_L1_B1.dat COPYONLY)
  
#   configure_file(input_models/compiled/Conv_d100_L14_B1.hxx Conv_d100_L14_B1.hxx COPYONLY)
#   configure_file(input_models/compiled/Conv_d100_L14_B1.dat Conv_d100_L14_B1.dat COPYONLY)
#   configure_file(input_models/compiled/Conv_d100_L14_B32.hxx Conv_d100_L14_B32.hxx COPYONLY)
#   #use file B1 as B32 for weights : it is the same
#   configure_file(input_models/compiled/Conv_d100_L14_B32.dat Conv_d100_L14_B32.dat COPYONLY)

#   configure_file(input_models/compiled/resnet18v1.hxx resnet18v1.hxx COPYONLY)
#   configure_file(input_models/compiled/resnet18v1.dat resnet18v1.dat COPYONLY)


add_executable(emitFromONNX
   EmitFromONNX.cxx
)
#target_include_directories(emitFromONNX PRIVATE )
target_link_libraries(emitFromONNX ${Protobuf_LIBRARIES} Core ROOTTMVASofie ROOTTMVASofieParser)
set_target_properties(emitFromONNX PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

if (NOT ONNX_MODELS_DIR)
  set(ONNX_MODELS_DIR input_models)
endif()

add_custom_target(SofieCompileModels)
add_dependencies(SofieCompileModels emitFromONNX)


file(GLOB ONNX_FILES "${ONNX_MODELS_DIR}/*.onnx")
foreach(onnx_file ${ONNX_FILES})
	#get_filename_component(fname ${onnx_file} NAME_WE)
	#get_filename_component(fdir ${onnx_file} DIRECTORY)
	add_custom_command(TARGET SofieCompileModels POST_BUILD
		COMMAND ./emitFromONNX ${onnx_file} 
		USES_TERMINAL
	)
endforeach()

find_package(BLAS)
if(BLAS_FOUND)
    message(STATUS "Found BLAS ( libraries ${BLAS_LIBRARIES})")

#set(SOFIE_BLAS_LIBS /home/moneta/intel/mkl/lib/intel64/libmkl_intel_lp64.so   /home/moneta/intel/mkl/lib/intel64/libmkl_sequential.so /home/moneta/intel/mkl/lib/intel64/libmkl_core.so -lpthread)
#set(SOFIE_BLAS_LIBS /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/Accelerate.framework)

#
# to set specific BLAS do : cmake -DBLA_Vendor=OpenBLAS, Intel10_64lp_seq or INtel64lp
# for Intel MKL need to set also MKLROOT env variable (see documentation of cmake FindBlas)
# need to source for example  . $dir/intel/mkl/bin/mklvars.sh intel64

set(SOFIE_BLAS_LIBS ${BLAS_LIBRARIES})


# Benchmark for models emitted by SOFIE
RB_ADD_GBENCHMARK(SOFIEInference
    SOFIEInference.cxx
    LABEL short
    LIBRARIES TMVA  ROOTTMVASofie ${SOFIE_BLAS_LIBS}  
)

add_dependencies(SOFIEInference SofieCompileModels)

RB_ADD_GBENCHMARK(RDF_SOFIE_Inference
    RDF_SOFIE_Inference.cxx
    LABEL short
    LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps TMVA  ROOTTMVASofie ${SOFIE_BLAS_LIBS} 
)
  
add_dependencies(RDF_SOFIE_Inference SofieCompileModels)

#
# add optimization flags for best performances (factor 3 on simple Conv1 test) 
#
#if (ROOT_PLATFORM MATCHES "linux|macosx" AND CMAKE_SYSTEM_PROCESSOR MATCHES x86_64 AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
## assume we run only on linux/macos with gnu or gcc
set(gnu-flags $<$<CXX_COMPILER_ID:GNU>:-fno-signaling-nans>)
if ($APPLE)
target_compile_options(SOFIEInference  PRIVATE   ${gnu-flags} -ffast-math -fno-trapping-math -O3)
target_compile_options(RDF_SOFIE_Inference  PRIVATE  ${gnu-flags} -ffast-math -fno-trapping-math -O3)
else()
target_compile_options(SOFIEInference  PRIVATE   ${gnu-flags} -march=native -ffast-math -fno-trapping-math -O3)
target_compile_options(RDF_SOFIE_Inference  PRIVATE  ${gnu-flags} -march=native -ffast-math -fno-trapping-math -O3)
endif()

endif()  # endif blas 
endif()  # endif TMVA/SOFIE

find_package(LWTNN QUIET)
if (LWTNN_FOUND)
  
   message(STATUS "Found LWTNN (library is  ${LWTNN_LIBRARY}, libraries ${LWTNN_LIBRARIES})")
   configure_file(input_models/higgs_model_dense.json higgs_model_dense.json COPYONLY)
   configure_file(input_models/Generator.json.gz Generator.json.gz COPYONLY)
   execute_process(COMMAND gunzip -f ${CMAKE_CURRENT_BINARY_DIR}/Generator.json.gz)
#   set(LWTNN_INCLUDE_DIR /home/moneta/cernbox/root/tests/tmva/sofie/lwtnn-build/include)
#   set(LWTNN_LIBS /home/moneta/cernbox/root/tests/tmva/sofie/lwtnn-build/lib/liblwtnn.so)
   RB_ADD_GBENCHMARK(LWTNNInference
       LWTNNInference.cxx
      LABEL short
      LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps TMVA  ROOTTMVASofie  ${LWTNN_LIBRARY})
   target_include_directories(LWTNNInference PRIVATE ${LWTNN_INCLUDE_DIR})

    RB_ADD_GBENCHMARK(RDF_lwtnn_Inference
       RDF_lwtnn_Inference.cxx
      LABEL short
      LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps TMVA  ROOTTMVASofie  ${LWTNN_LIBRARY})
   target_include_directories(RDF_lwtnn_Inference PRIVATE ${LWTNN_INCLUDE_DIR})
else()
   message(STATUS "LWTNN not found")
endif()

if (ONNXRuntime_FOUND)
   configure_file(input_models/higgs_model_dense.onnx higgs_model_dense.onnx COPYONLY)
   RB_ADD_GBENCHMARK(RDF_ONNXRuntime_Inference
       RDF_ONNXRuntime_Inference.cxx
      LABEL short
      LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps TMVA  ROOTTMVASofie ${ONNXRuntime_LIBRARIES}
   )
   target_link_directories(RDF_ONNXRuntime_Inference PRIVATE ${ONNXRuntime_LIBRARIES})
   target_include_directories(RDF_ONNXRuntime_Inference PRIVATE ${ONNXRuntime_INCLUDE_DIR})
endif()
