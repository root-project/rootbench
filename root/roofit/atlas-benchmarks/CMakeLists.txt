RB_ADD_GBENCHMARK(roofitAtlasHiggsBenchmark
  roofitAtlasHiggsBenchmark.cxx
  LABEL long
  DOWNLOAD_DATAFILES atlas-higgs-workspaces-2021/WS-Comb-STXS_toy.root
                     atlas-higgs-workspaces-2021/WS-HGam-STXS_xs_toy.root
                     atlas-higgs-workspaces-2021/WS-VHbb-STXS_mu_toy.root
                     atlas-higgs-workspaces-2021/WS-VHbb-STXS_mu_toy_new.root
                     atlas-higgs-workspaces-2021/WS-boostedHbb-glob_xs_toy.root
  LIBRARIES Core Hist MathCore RIO RooFit RooStats RooFitCore HistFactory)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/download_workspaces.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/run_benchmarks.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
