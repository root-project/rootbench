if(rootbench-datafiles)
   ROOT_GENERATE_DICTIONARY(G__SignalAnalysis inc/classes.h LINKDEF LinkDef.h)

   file(COPY RDFprocessor/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR} FILES_MATCHING PATTERN "*.py")
   file(COPY python/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR} FILES_MATCHING PATTERN "*.py")
   file(COPY inc/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/inc)

   add_library(SignalAnalysis SHARED
      src/TH3weightsHelper.cpp
      src/TH2weightsHelper.cpp
      src/TH1weightsHelper.cpp
      src/getAccMap.cpp
      src/getWeights.cpp
      src/dataObs.cpp
      src/defineSystWeight.cpp
      src/templateBuilder.cpp
      src/defineHarmonics.cpp
      src/module.cpp
      src/AngCoeff.cpp
      src/getACValues.cpp
      G__SignalAnalysis.cxx)
   add_dependencies(SignalAnalysis G__SignalAnalysis)
   target_include_directories(SignalAnalysis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
   target_link_libraries(SignalAnalysis PUBLIC ROOT::Hist ROOT::ROOTDataFrame)

   RB_ADD_PYTESTBENCHMARK(wmassAnalysis
      runSignalAnalysis.py
      LABEL long
      DOWNLOAD_DATAFILES wmass_repeated_10k_events_800kevents.root)
endif(rootbench-datafiles)
