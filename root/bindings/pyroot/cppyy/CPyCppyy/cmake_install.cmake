# Install script for directory: /Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/CPyCppyy

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/abhiacherjee/Documents/rootbench/root/lib/libcppyy3_11.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcppyy3_11.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcppyy3_11.so")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/abhiacherjee/Documents/rootbench/root/lib"
      -add_rpath "@loader_path/../lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcppyy3_11.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcppyy3_11.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CPyCppyy" TYPE FILE FILES
    "/Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/CPyCppyy/inc/CPyCppyy/API.h"
    "/Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/CPyCppyy/inc/CPyCppyy/Reflex.h"
    "/Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/CPyCppyy/inc/CPyCppyy/PyResult.h"
    "/Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/CPyCppyy/inc/CPyCppyy/CommonDefs.h"
    "/Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/CPyCppyy/inc/CPyCppyy/PyException.h"
    "/Users/abhiacherjee/Documents/root_src/bindings/pyroot/cppyy/CPyCppyy/inc/CPyCppyy/DispatchPtr.h"
    )
endif()

