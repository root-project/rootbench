if(ROOFIT_ATLAS_BENCHMARKS)
  # Can only be enabled is you have the ATLAS RooFit extensions installed and you
  # set unlimited stack size with `ulimit -S -s unlimited`:
  add_subdirectory(atlas-benchmarks)
endif()

add_subdirectory(histfactory)
add_subdirectory(roofit)
