# Install script for directory: /Users/abhiacherjee/Documents/root_src/interpreter/llvm-project/llvm/lib

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
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/IR/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/FuzzMutate/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/FileCheck/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/InterfaceStub/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/IRPrinter/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/IRReader/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/CodeGen/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/BinaryFormat/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Bitcode/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Bitstream/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/DWARFLinker/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/DWARFLinkerParallel/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Extensions/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Frontend/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Transforms/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Linker/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Analysis/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/LTO/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/MC/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/MCA/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/ObjCopy/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Object/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/ObjectYAML/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Option/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Remarks/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Debuginfod/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/DebugInfo/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/DWP/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/ExecutionEngine/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Target/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/AsmParser/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/LineEditor/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/ProfileData/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/Passes/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/TargetParser/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/TextAPI/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/ToolDrivers/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/XRay/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/WindowsDriver/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/llvm-project/llvm/lib/WindowsManifest/cmake_install.cmake")

endif()

