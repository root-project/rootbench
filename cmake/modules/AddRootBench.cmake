#----------------------------------------------------------------------------
# function RB_ADD_GBENCHMARK(<benchmark> source1 source2... LIBRARIES libs)
#----------------------------------------------------------------------------
function(RB_ADD_GBENCHMARK benchmark)
  cmake_parse_arguments(ARG "" "" "LABEL;LIBRARIES;DATAFILES" ${ARGN})
  # FIXME: Move to target_include_directories.
  include_directories(BEFORE ${ROOTBENCH_SOURCE_DIR}/include)
  include_directories(${CMAKE_CURRENT_BINARY_DIR} ${GBENCHMARK_INCLUDE_DIR})
  set(source_files ${ARG_UNPARSED_ARGUMENTS})
  add_executable(${benchmark} ${source_files})
  set_property(TARGET ${benchmark} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  # Note we cannot use ROOT_EXECUTABLE without user-specified set of LIBRARIES to link with.
  # The test suites should choose this in their specific CMakeLists.txt file.
  # FIXME: For better coherence we could restrict the libraries the test suite could link
  # against. For example, tests in Core should link only against libCore. This could be tricky
  # to implement because some ROOT components create more than one library.
  target_link_libraries(${benchmark} ${ARG_LIBRARIES} gbenchmark RBSupport)
  #ROOT_PATH_TO_STRING(mangled_name ${benchmark} PATH_SEPARATOR_REPLACEMENT "-")
  #ROOT_ADD_TEST(gbench${mangled_name}
  #  COMMAND ${benchmark}
  #  WORKING_DIR ${CMAKE_CURRENT_BINARY_DIR}
  #  LABELS "benchmark")
  if(${ARG_LABEL} STREQUAL "long")
    set(${TIMEOUT_VALUE} 1200)
  elseif($ARG_LABEL STREQUAL "short")
    set(${TIMEOUT_VALUE} 3600)
  endif()
  # Prepare data files for benchmarks
  foreach(file ${ARG_DATAFILES})
    set(list_files ${file} ${list_files})
    if(EXISTS ${CMAKE_BINARY_DIR}/rootbench_datafiles/${file})
      file(COPY ${CMAKE_BINARY_DIR}/rootbench_datafiles/${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    else()
      message(ERROR "You are missing some ROOT data files. Please rerun CMake with option -Drootbench_datafiles=ON.")
    endif()
  endforeach(file ${ARG_DATAFILES})
  # Add benchmark as a CTest
  add_test(NAME rootbench-${benchmark} COMMAND ${benchmark} --benchmark_out_format=csv --benchmark_out=rootbench-${benchmark}.csv --benchmark_color=false)
  set_tests_properties(rootbench-${benchmark} PROPERTIES
                                              ENVIRONMENT LD_LIBRARY_PATH=${ROOT_LIBRARY_DIR}:$ENV{LD_LIBRARY_PATH}
                                              TIMEOUT "${TIMEOUT_VALUE}" LABELS "${ARG_LABEL}" RUN_SERIAL TRUE)
endfunction(RB_ADD_GBENCHMARK)

#----------------------------------------------------------------------------
# function RB_ADD_LIBRARY(<library> source1 source2... LIBRARIES libs)
#----------------------------------------------------------------------------
function(RB_ADD_LIBRARY library)
  cmake_parse_arguments(ARG "" "" "LIBRARIES;DEPENDENCIES" ${ARGN})
  set(sources ${ARG_UNPARSED_ARGUMENTS})
  include_directories(BEFORE ${ROOTBENCH_SOURCE_DIR}/include)
  add_library(${library} STATIC ${sources})
  if (ARG_LIBRARIES OR ARG_DEPENDENCIES)
    target_link_libraries(${library} ${ARG_LIBRARIES} ${ARG_DEPENDENCIES})
  endif()
endfunction(RB_ADD_LIBRARY)
