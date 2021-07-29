file(REMOVE_RECURSE
  "Another.exe"
  "Another.exe.manifest"
  "Another.lib"
  "Another.pdb"
  "CMakeFiles/Another.dir/main.cpp.obj"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/Another.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
