# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if("/Users/abhiacherjee/Documents/root_src/builtins/openui5/openui5.tar.gz" STREQUAL "")
  message(FATAL_ERROR "LOCAL can't be empty")
endif()

if(NOT EXISTS "/Users/abhiacherjee/Documents/root_src/builtins/openui5/openui5.tar.gz")
  message(FATAL_ERROR "File not found: /Users/abhiacherjee/Documents/root_src/builtins/openui5/openui5.tar.gz")
endif()

if("SHA256" STREQUAL "")
  message(WARNING "File will not be verified since no URL_HASH specified")
  return()
endif()

if("cc6791ac9c064c3e3f8281870063c549fa5e3f1252095ccc5d542c33db9cf8b2" STREQUAL "")
  message(FATAL_ERROR "EXPECT_VALUE can't be empty")
endif()

message(STATUS "verifying file...
     file='/Users/abhiacherjee/Documents/root_src/builtins/openui5/openui5.tar.gz'")

file("SHA256" "/Users/abhiacherjee/Documents/root_src/builtins/openui5/openui5.tar.gz" actual_value)

if(NOT "${actual_value}" STREQUAL "cc6791ac9c064c3e3f8281870063c549fa5e3f1252095ccc5d542c33db9cf8b2")
  message(FATAL_ERROR "error: SHA256 hash of
  /Users/abhiacherjee/Documents/root_src/builtins/openui5/openui5.tar.gz
does not match expected value
  expected: 'cc6791ac9c064c3e3f8281870063c549fa5e3f1252095ccc5d542c33db9cf8b2'
    actual: '${actual_value}'
")
endif()

message(STATUS "verifying file... done")
