RB_ADD_GBENCHMARK(RDFBenchmarks
    RDataFrameBenchmarks.cxx
    RDataFrameSumBenchmarks.cxx
    LABEL short
    LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

if(NUMPY_FOUND)
  RB_ADD_PYTESTBENCHMARK(pytest_rdataframe)
endif()