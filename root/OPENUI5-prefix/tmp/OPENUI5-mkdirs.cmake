# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/abhiacherjee/Documents/rootbench/root/ui5/distribution"
  "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix/src/OPENUI5-build"
  "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix"
  "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix/tmp"
  "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix/src/OPENUI5-stamp"
  "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix/src"
  "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix/src/OPENUI5-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix/src/OPENUI5-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/abhiacherjee/Documents/rootbench/root/OPENUI5-prefix/src/OPENUI5-stamp${cfgdir}") # cfgdir has leading slash
endif()
