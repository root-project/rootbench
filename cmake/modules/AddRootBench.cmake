#----------------------------------------------------------------------------
# function RB_ADD_GBENCHMARK(<benchmark> source1 source2... LIBRARIES libs)
#----------------------------------------------------------------------------
function(RB_ADD_GBENCHMARK benchmark)
  cmake_parse_arguments(ARG "" "" "DOWNLOAD_DATAFILES;DEPENDS;LABEL;LIBRARIES;" ${ARGN})
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
  # Prepare data files for benchmarks!
  # All datafiles generated or downloaded on different step (configuration step) 
  foreach(file ${ARG_DOWNLOAD_DATAFILES})
    set(list_files ${file} ${list_files})
    if(EXISTS ${PROJECT_BINARY_DIR}/rootbench-datafiles/${file})
      file(COPY ${PROJECT_BINARY_DIR}/rootbench-datafiles/${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    else()
      get_file(${file})
      file(COPY ${PROJECT_BINARY_DIR}/rootbench-datafiles/${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    endif()
  endforeach(file ${ARG_DOWNLOAD_DATAFILES})

   # Add dependencies to benchmark
  if(ARG_DEPENDS)
    add_dependencies(${benchmark} ${ARG_DEPENDS})
  endif()
  # Add benchmark as a CTest
  add_test(NAME rootbench-${benchmark}
          COMMAND ${benchmark} --benchmark_out_format=csv --benchmark_out=rootbench-${benchmark}.csv --benchmark_color=false
          )
  set_tests_properties(rootbench-${benchmark} PROPERTIES
                                              ENVIRONMENT LD_LIBRARY_PATH=${ROOT_LIBRARY_DIR}:$ENV{LD_LIBRARY_PATH}
                                              TIMEOUT "${TIMEOUT_VALUE}" LABELS "${ARG_LABEL}" RUN_SERIAL TRUE)
endfunction(RB_ADD_GBENCHMARK)


#----------------------------------------------------------------------------
# function RB_ADD_PYTESTBENCHMARK(file_name)
#
# Dependency: pytest with pytest-benchmark and PyROOT modules
#
#----------------------------------------------------------------------------
function(RB_ADD_PYTESTBENCHMARK file_name)
  if(ROOT_pyroot_experimental_FOUND)
    set(ROOT_ENV ROOTSYS=${ROOTSYS}
        PATH=${ROOTSYS}/bin:$ENV{PATH}
        LD_LIBRARY_PATH=${ROOTSYS}/lib:${ROOTSYS}/lib/${python_dir}:$ENV{LD_LIBRARY_PATH}
        PYTHONPATH=${ROOTSYS}/lib:${ROOTSYS}/lib/${python_dir}:$ENV{PYTHONPATH})
  elseif(ROOT_pyroot_FOUND)
    set(ROOT_ENV ROOTSYS=${ROOTSYS}
        PATH=${ROOTSYS}/bin:$ENV{PATH}
        LD_LIBRARY_PATH=${ROOTSYS}/lib:$ENV{LD_LIBRARY_PATH}
        PYTHONPATH=${ROOTSYS}/lib:$ENV{PYTHONPATH})
  else()
    message(STATUS "ROOT was configured without PyROOT support. Python benchmarks will be disabled!")
  endif()
  if(PYTEST_FOUND AND (ROOT_pyroot_experimental_FOUND OR ROOT_pyroot_FOUND))
    #string(REGEX REPLACE "[_]" "-" good_name "${name}")
    ROOT_ADD_TEST(rootbench-${file_name}
                COMMAND ${PYTHON_EXECUTABLE} -B -m pytest ${CMAKE_CURRENT_SOURCE_DIR}/${file_name}.py -v
                ENVIRONMENT ${ROOT_ENV})
  endif()
endfunction()


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

#----------------------------------------------------------------------------
# function RB_ADD_TOOL(<binary> source1 source2... LIBRARIES libs)
#----------------------------------------------------------------------------
function(RB_ADD_TOOL binary)
  cmake_parse_arguments(ARG "" "" "LIBRARIES;DEPENDENCIES" ${ARGN})
  set(sources ${ARG_UNPARSED_ARGUMENTS})
  include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  add_executable(${binary} ${sources})
  if (ARG_LIBRARIES OR ARG_DEPENDENCIES)
    target_link_libraries(${binary} ${ARG_LIBRARIES} ${ARG_DEPENDENCIES})
  endif()
endfunction(RB_ADD_TOOL)

#-------------------------------------------------------------------------------
#
# macro RB_GENERATE_DICTIONARY(<dictname>
#                                    [LINKDEF linkdef]
#                                    [DEPENDS deps]
#                                    [OPTIONS opts]
#                                    [files ...]      )
#
# It is a trimmed version of ROOTTEST_GENERATE_DICTIONARY() from roottest.git.
# This macro generates a dictionary <dictname> from the provided <files>.
# A test that performs the dictionary generation is created.  The target name of
# the created test is stored in the variable GENERATE_DICTIONARY_TEST which can
# be accessed by the calling CMakeLists.txt in order to manage dependencies.
#
# IMPORTANT: it works only for mixed mode: ROOT pcms and here it is still old non-module style.
# [something to be fixed on ROOT CMake side]
#
# Requires:  ROOT_GENERATE_DICTIONARY()
#-------------------------------------------------------------------------------
function(RB_GENERATE_DICTIONARY dictname)
  CMAKE_PARSE_ARGUMENTS(ARG "" "" "LINKDEF;DEPENDS;OPTIONS" ${ARGN})
  set(ROOT_LIBRARIES Core RIO Net Hist Gpad Tree Rint Matrix MathCore)
  set(FULL_PATH_HEADERS )
  foreach(hdr ${ARG_UNPARSED_ARGUMENTS})
    if(IS_ABSOLUTE ${hdr})
      list(APPEND FULL_PATH_HEADERS ${hdr})
    else()
      list(APPEND FULL_PATH_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/${hdr})
    endif()
  endforeach()
  ROOT_GENERATE_DICTIONARY(${dictname} ${FULL_PATH_HEADERS}
                           MODULE ${dictname}
                           LINKDEF ${ARG_LINKDEF}
                           OPTIONS ${ARG_OPTIONS}
                           DEPENDENCIES ${ARG_DEPENDS})
  set(targetname_libgen ${dictname}libgen)
  add_library(${targetname_libgen} EXCLUDE_FROM_ALL SHARED ${dictname}.cxx)
  set_target_properties(${targetname_libgen} PROPERTIES  ${ROOT_LIBRARY_PROPERTIES} )
  target_link_libraries(${targetname_libgen} ${ROOT_LIBRARIES})
  set_target_properties(${targetname_libgen} PROPERTIES PREFIX "")
  set_property(TARGET ${targetname_libgen}
               PROPERTY OUTPUT_NAME ${dictname})
  set_property(TARGET ${targetname_libgen}
               APPEND PROPERTY INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
  add_dependencies(${targetname_libgen} ${dictname})
endfunction(RB_GENERATE_DICTIONARY)
