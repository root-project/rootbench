# CMakeLists.txt for rootbench package. It creates a number of benchmarks executables to monitor 
# the performance of ROOT.
cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(rootbench)

include(CMakeToolsHelpers OPTIONAL)
include(ExternalProject)

# Add path for custom modules
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
  )

include(AddRootBench)

# You need first to tell CMake where to find the ROOT installation. This can either be the 
# final ROOT installation or a local build directory. In both cases it is using
# the $ROOTSYS environment variable to locate it.
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED)

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

include(GoogleBenchmark)

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

# Enable and setup CTest.
include(RootBenchCTest)

#---Add the now all the sub-directories on this repository
add_subdirectory(root)
