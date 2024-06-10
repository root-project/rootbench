# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if("/Users/abhiacherjee/Documents/root_src/documentation/doxygen/mathjax.tar.gz" STREQUAL "")
  message(FATAL_ERROR "LOCAL can't be empty")
endif()

if(NOT EXISTS "/Users/abhiacherjee/Documents/root_src/documentation/doxygen/mathjax.tar.gz")
  message(FATAL_ERROR "File not found: /Users/abhiacherjee/Documents/root_src/documentation/doxygen/mathjax.tar.gz")
endif()

if("SHA256" STREQUAL "")
  message(WARNING "File will not be verified since no URL_HASH specified")
  return()
endif()

if("c5e22e60430a65963a87ab4dcc8856b9be5bd434d3b3871f27ee65b584c3c3ea" STREQUAL "")
  message(FATAL_ERROR "EXPECT_VALUE can't be empty")
endif()

message(STATUS "verifying file...
     file='/Users/abhiacherjee/Documents/root_src/documentation/doxygen/mathjax.tar.gz'")

file("SHA256" "/Users/abhiacherjee/Documents/root_src/documentation/doxygen/mathjax.tar.gz" actual_value)

if(NOT "${actual_value}" STREQUAL "c5e22e60430a65963a87ab4dcc8856b9be5bd434d3b3871f27ee65b584c3c3ea")
  message(FATAL_ERROR "error: SHA256 hash of
  /Users/abhiacherjee/Documents/root_src/documentation/doxygen/mathjax.tar.gz
does not match expected value
  expected: 'c5e22e60430a65963a87ab4dcc8856b9be5bd434d3b3871f27ee65b584c3c3ea'
    actual: '${actual_value}'
")
endif()

message(STATUS "verifying file... done")
