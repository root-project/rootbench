# Install script for directory: /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX

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
   "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/include/davix/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/include/davix" TYPE DIRECTORY FILES "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX/include/davix/" REGEX "/[^/]*\\.in$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/share/doc/davix/RELEASE-NOTES.md;/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/share/doc/davix/LICENSE")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/share/doc/davix" TYPE FILE FILES
    "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX/RELEASE-NOTES.md"
    "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX/LICENSE"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/deps/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/src/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/doc/cmake_install.cmake")
  include("/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/dist/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
