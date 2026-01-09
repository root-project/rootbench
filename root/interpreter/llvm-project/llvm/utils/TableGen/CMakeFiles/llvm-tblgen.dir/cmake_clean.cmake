file(REMOVE_RECURSE
  "../../bin/llvm-tblgen"
  "../../bin/llvm-tblgen.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/llvm-tblgen.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
