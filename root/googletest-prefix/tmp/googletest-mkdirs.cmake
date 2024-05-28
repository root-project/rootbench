# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/src/googletest"
  "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/src/googletest-build"
  "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix"
  "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/tmp"
  "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/src/googletest-stamp"
  "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/src"
  "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/googletest-prefix/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
