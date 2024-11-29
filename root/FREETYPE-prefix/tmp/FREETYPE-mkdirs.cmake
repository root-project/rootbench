# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE"
  "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE-build"
  "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix"
  "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/tmp"
  "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE-stamp"
  "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src"
  "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/FREETYPE-prefix/src/FREETYPE-stamp${cfgdir}") # cfgdir has leading slash
endif()
