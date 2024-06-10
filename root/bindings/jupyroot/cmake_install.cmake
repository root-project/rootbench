# Install script for directory: /Users/abhiacherjee/Documents/root_src/bindings/jupyroot

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
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/cppcompleter.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/cppcompleter.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/handlers.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/handlers.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/utils.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/helpers/utils.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/html/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/html/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/html/cpphighlighter.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/html/cpphighlighter.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/rootkernel.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/rootkernel.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/utils.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/utils.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/magics/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/magics/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/magics/cppmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/magics/cppmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/magics/jsrootmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/kernel/magics/jsrootmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/magics/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/magics/__init__.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/magics/cppmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/magics/cppmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/magics/jsrootmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /opt/anaconda3/bin/python3.11 -O -m py_compile /Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT/magics/jsrootmagic.py)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/abhiacherjee/Documents/rootbench/root/lib/libJupyROOT3_11.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJupyROOT3_11.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJupyROOT3_11.so")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/abhiacherjee/Documents/rootbench/root/lib"
      -add_rpath "@loader_path/../lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJupyROOT3_11.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libJupyROOT3_11.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE DIRECTORY FILES "/Users/abhiacherjee/Documents/rootbench/root/lib/JupyROOT")
endif()

