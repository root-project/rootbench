file(REMOVE_RECURSE
  "../../../lib/libCling.pdb"
  "../../../lib/libCling.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/Cling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
