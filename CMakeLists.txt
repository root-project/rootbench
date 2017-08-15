# CMakeLists.txt for rootbench package. It creates a number of benchmarks executables to monitor 
# the performance of ROOT.
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(rootbench)

include(CMakeToolsHelpers OPTIONAL)

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

#---Add the now all the sub-directories on this repository
add_subdirectory(event)

