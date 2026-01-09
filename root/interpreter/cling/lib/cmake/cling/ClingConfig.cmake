# This file allows users to call find_package(Cling) and pick up our targets.



find_package(Clang REQUIRED CONFIG
             HINTS "")

set(CLING_EXPORTED_TARGETS "clingInterpreter;clingMetaProcessor;clingUtils;clingDemoPlugin")
set(CLING_CMAKE_DIR "/Users/abhiacherjee/Documents/rootbench/root/interpreter/cling/lib/cmake/cling")
set(CLING_INCLUDE_DIRS "/Users/abhiacherjee/Documents/root_src/interpreter/cling/include;/Users/abhiacherjee/Documents/rootbench/root/interpreter/cling/include")

# Provide all our library targets to users.
include("/Users/abhiacherjee/Documents/rootbench/root/interpreter/cling/lib/cmake/cling/ClingTargets.cmake")

# By creating cling-tablegen-targets here, subprojects that depend on Cling's
# tablegen-generated headers can always depend on this target whether building
# in-tree with Cling or not.
if(NOT TARGET cling-tablegen-targets)
  add_custom_target(cling-tablegen-targets)
endif()
