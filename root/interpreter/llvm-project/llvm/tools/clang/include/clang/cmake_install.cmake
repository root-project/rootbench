# Install script for directory: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/clang/include/clang

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/AST/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/Basic/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/Driver/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/Parse/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/Sema/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/Serialization/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/StaticAnalyzer/Checkers/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/tools/clang/include/clang/Tooling/Syntax/cmake_install.cmake")

endif()

