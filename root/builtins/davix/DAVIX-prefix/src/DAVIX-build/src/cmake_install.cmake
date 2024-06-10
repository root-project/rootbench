# Install script for directory: /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix")
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
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/lib/libdavix.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/lib" TYPE STATIC_LIBRARY FILES "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/src/libdavix.a")
  if(EXISTS "$ENV{DESTDIR}/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/lib/libdavix.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/lib/libdavix.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/lib/libdavix.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/src/CMakeFiles/libdavix_static.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/src/modules/copy/cmake_install.cmake")

endif()

