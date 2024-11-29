# Install script for directory: /Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/cppyy

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
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_stdcpp_fix.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_stdcpp_fix.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_cpython_cppyy.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_cpython_cppyy.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_pypy_cppyy.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_pypy_cppyy.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_pythonization.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_pythonization.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_typemap.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_typemap.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_version.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/_version.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/interactive.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/interactive.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/ll.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/ll.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/numba_ext.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/numba_ext.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/reflex.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/reflex.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/types.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/cppyy/types.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE DIRECTORY FILES "/Users/abhiacherjee/Documents/rootbench/root/lib/cppyy")
endif()

