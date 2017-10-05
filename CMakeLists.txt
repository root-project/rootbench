# CMakeLists.txt for rootbench package. It creates a number of benchmarks executables to monitor 
# the performance of ROOT.
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
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

#---Add ROOT include direcories and used compilation flags
include_directories(${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})

#---Removing -Woverloaded-virtual from inherited ROOT compilation flags (gbenchmark is crashing)
string(REPLACE "-Woverloaded-virtual" "" GBENCHMARK_CMAKE_CXX_FLAGS ${ROOT_CXX_FLAGS})

#---Find and install google benchmark
ExternalProject_Add(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG master
  UPDATE_COMMAND ""
  # TIMEOUT 10
  # # Force separate output paths for debug and release builds to allow easy
  # # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
  # CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
  #            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
  #            -Dgtest_force_shared_crt=ON
  CMAKE_ARGS -G ${CMAKE_GENERATOR}
  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
  -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
  -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
  -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
  -DCMAKE_CXX_FLAGS=${GBENCHMARK_CMAKE_CXX_FLAGS}
  -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
  # Disable install step
  INSTALL_COMMAND ""
  BUILD_BYPRODUCTS "${CMAKE_CURRENT_BINARY_DIR}/googletest-prefix/src/libbenchmark.a"
  # Wrap download, configure and build steps in a script to log output
  LOG_DOWNLOAD ON
  LOG_CONFIGURE ON
  LOG_BUILD ON)

# Specify include dirs for googlebenchmark
ExternalProject_Get_Property(googlebenchmark source_dir)
set(GBENCHMARK_INCLUDE_DIR ${source_dir}/include)

# Libraries
ExternalProject_Get_Property(googlebenchmark binary_dir)
set(_GBENCH_LIBRARY_PATH ${binary_dir}/)

# Register googlebenchmark
add_library(gbenchmark IMPORTED STATIC GLOBAL)
set_property(TARGET gbenchmark PROPERTY IMPORTED_LOCATION ${_GBENCH_LIBRARY_PATH}/src/libbenchmark.a)
add_dependencies(gbenchmark googlebenchmark)

# Enable and setup CTest.
include(RootBenchCTest)

#---Add the now all the sub-directories on this repository
add_subdirectory(root)
