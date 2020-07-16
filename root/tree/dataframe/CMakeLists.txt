RB_ADD_GBENCHMARK(RDFBenchmarks
    RDataFrameBenchmarks.cxx
    RDataFrameSumBenchmarks.cxx
    LABEL short
    LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

if(rootbench-datafiles)
    RB_ADD_GBENCHMARK(gbenchmark-df102_NanoAODDimuonAnalysis
        df102_NanoAODDimuonAnalysis.C
        DOWNLOAD_DATAFILES Run2012B_DoubleMuParked.root Run2012C_DoubleMuParked.root
        LABEL long
        LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps Gpad Graf)
endif()

if(NUMPY_FOUND)
    RB_ADD_PYTESTBENCHMARK(pytest-rdataframe-asnumpy rdataframe_asnumpy.py LABEL short)
endif()

if(rootbench-datafiles)
    RB_ADD_PYTESTBENCHMARK(pytest-df102_NanoAODDimuonAnalysis
        df102_NanoAODDimuonAnalysis.py
        DOWNLOAD_DATAFILES Run2012B_DoubleMuParked.root Run2012C_DoubleMuParked.root
        LABEL long)

    RB_ADD_PYTESTBENCHMARK(pytest-df104_HiggsToTwoPhotons
        df104_HiggsToTwoPhotons.py
        DOWNLOAD_DATAFILES data_A.GamGam.root data_B.GamGam.root data_C.GamGam.root data_D.GamGam.root mc_343981.ggH125_gamgam.GamGam.root mc_345041.VBFH125_gamgam.GamGam.root
        LABEL long)
endif()

add_subdirectory(LoopSUSYFrame)

if(rootbench-datafiles AND ROOT_root7_FOUND) # using ROOT_root7_FOUND as a proxy for "c++ standard >= 14"
   RB_ADD_GBENCHMARK(ZPeak
      zpeak.cxx
      LIBRARIES Core Hist Imt RIO MathCore Physics Tree TreePlayer ROOTDataFrame ROOTVecOps
      DOWNLOAD_DATAFILES zpeak_data_small.root
      LABEL long)
endif()
