file(REMOVE_RECURSE
  "../../../../bin/clang-tblgen"
  "../../../../bin/clang-tblgen.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/clang-tblgen.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
