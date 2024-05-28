# Install script for directory: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/abhiacherjee/Documents/install_root")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "llvm-headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES
    "/Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm"
    "/Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/include/llvm-c"
    FILES_MATCHING REGEX "/[^/]*\\.def$" REGEX "/[^/]*\\.h$" REGEX "/[^/]*\\.td$" REGEX "/[^/]*\\.inc$" REGEX "/license\\.txt$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "llvm-headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES
    "/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/include/llvm"
    "/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/include/llvm-c"
    FILES_MATCHING REGEX "/[^/]*\\.def$" REGEX "/[^/]*\\.h$" REGEX "/[^/]*\\.gen$" REGEX "/[^/]*\\.inc$" REGEX "/cmakefiles$" EXCLUDE REGEX "/config\\.h$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "cmake-exports" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/llvm" TYPE FILE FILES "/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/./lib/cmake/llvm/LLVMConfigExtensions.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Demangle/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Support/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/TableGen/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/TableGen/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/include/llvm/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/FileCheck/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/PerfectShuffle/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/count/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/not/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/UnicodeData/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/yaml-bench/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/split-file/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/projects/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/runtimes/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/docs/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/cmake/modules/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/llvm-lit/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/utils/llvm-locstats/cmake_install.cmake")

endif()

