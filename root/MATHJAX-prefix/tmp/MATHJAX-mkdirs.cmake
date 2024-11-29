# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/abhiacherjee/Documents/rootbench/root/js/mathjax"
  "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix/src/MATHJAX-build"
  "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix"
  "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix/tmp"
  "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix/src/MATHJAX-stamp"
  "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix/src"
  "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix/src/MATHJAX-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix/src/MATHJAX-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/MATHJAX-prefix/src/MATHJAX-stamp${cfgdir}") # cfgdir has leading slash
endif()
