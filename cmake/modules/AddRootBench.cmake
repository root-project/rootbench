#----------------------------------------------------------------------------
# function RB_ADD_GBENCHMARK(<benchmark> source1 source2... LIBRARIES)
#----------------------------------------------------------------------------
function(RB_ADD_GBENCHMARK benchmark)
  CMAKE_PARSE_ARGUMENTS(ARG "" "" "LIBRARIES" ${ARGN})
  include_directories(${CMAKE_CURRENT_BINARY_DIR} ${GBENCHMARK_INCLUDE_DIR})

  set(source_files ${ARG_UNPARSED_ARGUMENTS})
  add_executable(${benchmark} ${source_files})
  set_property(TARGET ${benchmark} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  # Note we cannot use ROOT_EXECUTABLE without user-specified set of LIBRARIES to link with.
  # The test suites should choose this in their specific CMakeLists.txt file.
  # FIXME: For better coherence we could restrict the libraries the test suite could link
  # against. For example, tests in Core should link only against libCore. This could be tricky
  # to implement because some ROOT components create more than one library.
  target_link_libraries(${benchmark} ${ARG_LIBRARIES} gbenchmark)
  #ROOT_PATH_TO_STRING(mangled_name ${benchmark} PATH_SEPARATOR_REPLACEMENT "-")
  #ROOT_ADD_TEST(gbench${mangled_name}
  #  COMMAND ${benchmark}
  #  WORKING_DIR ${CMAKE_CURRENT_BINARY_DIR}
  #  LABELS "benchmark")
endfunction(RB_ADD_GBENCHMARK)

#----------------------------------------------------------------------------
# function RB_ADD_GBENCHMARK(<benchmark> source1 source2... LIBRARIES)
#----------------------------------------------------------------------------
#function(RB_ADD_GBENCHMARK benchmark)
#endfunction(RB_ADD_GBENCHMARK)
