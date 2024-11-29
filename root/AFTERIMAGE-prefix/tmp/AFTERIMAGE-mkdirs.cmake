# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/src/AFTERIMAGE"
  "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/src/AFTERIMAGE-build"
  "/Users/abhiacherjee/Documents/rootbench/root"
  "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/tmp"
  "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/src/AFTERIMAGE-stamp"
  "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/src"
  "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/src/AFTERIMAGE-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/src/AFTERIMAGE-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/AFTERIMAGE-prefix/src/AFTERIMAGE-stamp${cfgdir}") # cfgdir has leading slash
endif()
