#----------------------------------------------------------------------------
# function RB_ADD_DOWNLOAD_FIXTURE(<benchmark> DOWNLOAD_DATAFILES filenames)
#----------------------------------------------------------------------------
function(RB_ADD_DOWNLOAD_FIXTURE benchmark)
  cmake_parse_arguments(ARG "" "" "DOWNLOAD_DATAFILES" ${ARGN})
  # Add fixture to download required dataset files from https://root.cern.ch/files/rootbench
  add_test(NAME rootbench-fixture-download-${benchmark}
           COMMAND ${PROJECT_BINARY_DIR}/tools/download_files.sh
           ${RB_DATASETDIR} ${ARG_DOWNLOAD_DATAFILES})
  set_tests_properties(rootbench-fixture-download-${benchmark} PROPERTIES FIXTURES_SETUP download-${benchmark}-datafiles)
endfunction(RB_ADD_DOWNLOAD_FIXTURE)


#----------------------------------------------------------------------------
# function RB_ADD_SETUP_FIXTURE(<benchmark> SETUP commands)
#----------------------------------------------------------------------------
function(RB_ADD_SETUP_FIXTURE benchmark)
  cmake_parse_arguments(ARG "" "" "SETUP" ${ARGN})
  set(COUNTER 0)
  foreach(CMD ${ARG_SETUP})
    separate_arguments(CMD UNIX_COMMAND ${CMD})
    add_test(NAME rootbench-fixture-setup-${benchmark}-${COUNTER} COMMAND ${CMD})
    set_tests_properties(rootbench-fixture-setup-${benchmark}-${COUNTER} PROPERTIES
                         FIXTURES_SETUP setup-${benchmark}
                         FIXTURES_REQUIRED download-${benchmark}-datafiles)
    MATH(EXPR COUNTER "${COUNTER}+1")
  endforeach()
  unset(COUNTER)
endfunction(RB_ADD_SETUP_FIXTURE)


#----------------------------------------------------------------------------
# function RB_ADD_GBENCHMARK(<benchmark> source1 source2... LIBRARIES libs)
#----------------------------------------------------------------------------
function(RB_ADD_GBENCHMARK benchmark)
  cmake_parse_arguments(ARG "" "LABEL" "SETUP;DOWNLOAD_DATAFILES;DEPENDS;LIBRARIES" ${ARGN})
  set(source_files ${ARG_UNPARSED_ARGUMENTS})
  add_executable(${benchmark} ${source_files})
  target_include_directories(${benchmark} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${GBENCHMARK_INCLUDE_DIR})
  set_property(TARGET ${benchmark} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  # Note we cannot use ROOT_EXECUTABLE without user-specified set of LIBRARIES to link with.
  # The test suites should choose this in their specific CMakeLists.txt file.
  # FIXME: For better coherence we could restrict the libraries the test suite could link
  # against. For example, tests in Core should link only against libCore. This could be tricky
  # to implement because some ROOT components create more than one library.
  target_link_libraries(${benchmark} PUBLIC ${ARG_LIBRARIES} gbenchmark RBSupport)
  if (NOT APPLE)
    target_link_libraries(${benchmark} PUBLIC rt)
  endif()
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
   # Add dependencies to benchmark
  if(ARG_DEPENDS)
    add_dependencies(${benchmark} ${ARG_DEPENDS})
  endif()

  if(ARG_DOWNLOAD_DATAFILES)
      RB_ADD_DOWNLOAD_FIXTURE(${benchmark} DOWNLOAD_DATAFILES ${ARG_DOWNLOAD_DATAFILES})
  endif()

  if(ARG_SETUP)
     RB_ADD_SETUP_FIXTURE(${benchmark} SETUP ${ARG_SETUP})
  endif()

  # Add benchmark as a CTest
  add_test(NAME rootbench-${benchmark}
           COMMAND ${benchmark} --benchmark_out_format=csv --benchmark_out=rootbench-gbenchmark-${benchmark}.csv --benchmark_color=false)
  set_tests_properties(rootbench-${benchmark} PROPERTIES
                       ENVIRONMENT LD_LIBRARY_PATH=${ROOT_LIBRARY_DIR}:$ENV{LD_LIBRARY_PATH}
                       TIMEOUT "${TIMEOUT_VALUE}" LABELS "${ARG_LABEL}" RUN_SERIAL TRUE
                       FIXTURES_REQUIRED "setup-${benchmark};download-${benchmark}-datafiles")
endfunction(RB_ADD_GBENCHMARK)


#----------------------------------------------------------------------------
# function RB_ADD_PYTESTBENCHMARK(<benchmark> filename)
#
# Dependency: pytest with pytest-benchmark and PyROOT modules
#
#----------------------------------------------------------------------------
function(RB_ADD_PYTESTBENCHMARK benchmark)
  cmake_parse_arguments(ARG "" "LABEL" "SETUP;DOWNLOAD_DATAFILES" ${ARGN})
  if(ROOT_pyroot_experimental_FOUND OR ROOT_pyroot_FOUND)
    if(${ARG_LABEL} STREQUAL "long")
      set(${TIMEOUT_VALUE} 1200)
    elseif($ARG_LABEL STREQUAL "short")
      set(${TIMEOUT_VALUE} 3600)
    endif()
    set(filename ${ARG_UNPARSED_ARGUMENTS})

    if(PYTEST_FOUND)
      if(ARG_DOWNLOAD_DATAFILES)
          RB_ADD_DOWNLOAD_FIXTURE(${benchmark} DOWNLOAD_DATAFILES ${ARG_DOWNLOAD_DATAFILES})
      endif()

      if(ARG_SETUP)
         RB_ADD_SETUP_FIXTURE(${benchmark} SETUP ${ARG_SETUP})
      endif()

      file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${filename} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${benchmark} USE_SOURCE_PERMISSIONS)

      add_test(NAME rootbench-${benchmark}
               COMMAND ${PYTHON_EXECUTABLE} -B -m pytest ${CMAKE_CURRENT_SOURCE_DIR}/${filename} -v --csv rootbench-pytest-${benchmark}.csv)
      set_tests_properties(rootbench-${benchmark} PROPERTIES
                           ENVIRONMENT "LD_LIBRARY_PATH=${ROOT_LIBRARY_DIR}:$ENV{LD_LIBRARY_PATH};PYTHONPATH=${ROOTSYS}/lib:$ENV{PYTHONPATH};RB_DATASETDIR=${RB_DATASETDIR}"
                           TIMEOUT "${TIMEOUT_VALUE}" LABELS "${ARG_LABEL}" RUN_SERIAL TRUE
                           FIXTURES_REQUIRED "setup-${benchmark};download-${benchmark}-datafiles")
    else()
      message(STATUS "pytest was not found, benchmark " ${benchmark} " will be ignored")
    endif()

  else()
    message(STATUS "ROOT was configured without PyROOT support. Python benchmarks will be disabled!")
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
  cmake_parse_arguments(ARG "" "" "LIBRARIES;DEPENDS" ${ARGN})
  set(sources ${ARG_UNPARSED_ARGUMENTS})
  include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  add_executable(${binary} ${sources})
  # Add dependencies to binary
  if(ARG_DEPENDS)
     add_dependencies(${binary} ${ARG_DEPENDS})
  endif()
  if (ARG_LIBRARIES)
    target_link_libraries(${binary} ${ARG_LIBRARIES})
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
  set(targetname_libgen lib${dictname})
  add_library(${targetname_libgen} EXCLUDE_FROM_ALL SHARED ${dictname}.cxx)
  set_target_properties(${targetname_libgen} PROPERTIES  ${ROOT_LIBRARY_PROPERTIES} )
  target_link_libraries(${targetname_libgen} ${ROOT_LIBRARIES})
  set_target_properties(${targetname_libgen} PROPERTIES PREFIX "")
  set_property(TARGET ${targetname_libgen}
               PROPERTY OUTPUT_NAME lib${dictname})
  set_property(TARGET ${targetname_libgen}
               APPEND PROPERTY INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
  add_dependencies(${targetname_libgen} ${dictname})
endfunction(RB_GENERATE_DICTIONARY)
