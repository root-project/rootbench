# CMakeLists.txt for rootbench package. It creates a number of benchmarks executables to monitor
# the performance of ROOT.

if(APPLE)
  cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
else()
  cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
endif()

project(rootbench)

option(cuda "Build benchmarks that run on CUDA GPUs" OFF)

include(CMakeToolsHelpers OPTIONAL)
include(ExternalProject)

# Add path for custom modules
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
  )

#Define ROOTbench source tree
set(ROOTBENCH_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(AddRootBench)

# You need first to tell CMake where to find the ROOT installation. This can either be the
# final ROOT installation or a local build directory. In both cases it is using
# the $ROOTSYS environment variable to locate it.
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED CONFIG)

#---In case of ROOT C++ modules, we need to know where are PCMs and add them in LD_LIBRARY_PATH
# through setting up environment properties in set_tests_properties().
if(NOT DEFINED ROOTSYS)
  set(ROOTSYS $ENV{ROOTSYS})
  if(NOT DEFINED ROOTSYS)
    message(FATAL_ERROR "ROOTSYS is not set!")
  endif()
endif()
get_filename_component(ROOT_LIBRARY_DIR "${ROOTSYS}/lib" ABSOLUTE)

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(default_build_type "Release")
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

include(GoogleBenchmark)
include(PytestBenchmark)

#---Add ROOT include direcories and used compilation flags
include_directories(${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})

#---Include rootbench options
include(RootBenchOptions)

#---Enable test coverage -----------------------------------------------------------------------
if(coverage)
  set(GCC_COVERAGE_COMPILE_FLAGS "-g -fprofile-arcs -ftest-coverage")
  set(GCC_COVERAGE_LINK_FLAGS    "--coverage")
  set(CMAKE_CXX_FLAGS            "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS     "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
  set(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHAREDLINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
  set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif()

#---Enable data download ----------------------------------------------------------------------
if(rootbench-datafiles)
  message(STATUS "INFO: rootbench-datafiles option is ON. Multiple data files are getting pulled from https://root.cern.ch/files/rootbench")
endif(rootbench-datafiles)
set(RB_DATASETDIR ${PROJECT_BINARY_DIR}/rootbench-datafiles)

#---Enable and setup CTest.
include(RootBenchCTest)

#---Add the support libraries.
add_subdirectory(include)
add_subdirectory(lib)

#---Add tools directory (executables for data generation and etc.)
add_subdirectory(tools)

#---Add the now all the benchmark sub-directories on this repository
add_subdirectory(root)
