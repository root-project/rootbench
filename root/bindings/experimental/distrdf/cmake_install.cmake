# Install script for directory: /Users/abhiacherjee/Documents/root_src/bindings/experimental/distrdf

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
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/_graph_cache.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/_graph_cache.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/ComputationGraphGenerator.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/ComputationGraphGenerator.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/DataFrame.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/DataFrame.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/HeadNode.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/HeadNode.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Node.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Node.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Operation.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Operation.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Proxy.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Proxy.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/PythonMergeables.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/PythonMergeables.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Ranges.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Ranges.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Base.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Base.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Utils.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Utils.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Spark/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Spark/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Spark/Backend.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Spark/Backend.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Dask/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Dask/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Dask/Backend.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/Backends/Dask/Backend.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/LiveVisualize.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF/LiveVisualize.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE DIRECTORY FILES "/Users/abhiacherjee/Documents/rootbench/root/lib/DistRDF")
endif()

