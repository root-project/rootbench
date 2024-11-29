# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if("/Users/abhiacherjee/Documents/root_src/builtins/rendercore/RenderCore-1.1.tar.gz" STREQUAL "")
  message(FATAL_ERROR "LOCAL can't be empty")
endif()

if(NOT EXISTS "/Users/abhiacherjee/Documents/root_src/builtins/rendercore/RenderCore-1.1.tar.gz")
  message(FATAL_ERROR "File not found: /Users/abhiacherjee/Documents/root_src/builtins/rendercore/RenderCore-1.1.tar.gz")
endif()

if("SHA256" STREQUAL "")
  message(WARNING "File will not be verified since no URL_HASH specified")
  return()
endif()

if("2cb8c722193ae0ddffde3b1c4b24fc877c9bb2c9ebacdaa6f3860b81991e8737" STREQUAL "")
  message(FATAL_ERROR "EXPECT_VALUE can't be empty")
endif()

message(STATUS "verifying file...
     file='/Users/abhiacherjee/Documents/root_src/builtins/rendercore/RenderCore-1.1.tar.gz'")

file("SHA256" "/Users/abhiacherjee/Documents/root_src/builtins/rendercore/RenderCore-1.1.tar.gz" actual_value)

if(NOT "${actual_value}" STREQUAL "2cb8c722193ae0ddffde3b1c4b24fc877c9bb2c9ebacdaa6f3860b81991e8737")
  message(FATAL_ERROR "error: SHA256 hash of
  /Users/abhiacherjee/Documents/root_src/builtins/rendercore/RenderCore-1.1.tar.gz
does not match expected value
  expected: '2cb8c722193ae0ddffde3b1c4b24fc877c9bb2c9ebacdaa6f3860b81991e8737'
    actual: '${actual_value}'
")
endif()

message(STATUS "verifying file... done")
