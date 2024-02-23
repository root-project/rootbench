RB_ADD_GBENCHMARK(RDFBenchmarks
    RDataFrameBenchmarks.cxx
    RDataFrameSumBenchmarks.cxx
    LABEL short
    LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

if(NUMPY_FOUND AND rootbench-datafiles)
    RB_ADD_PYTESTBENCHMARK(pytest-rdataframe-asnumpy
        rdataframe_asnumpy.py
        DOWNLOAD_DATAFILES Run2012BC_DoubleMuParked_Muons.root data_A.GamGam.root
        LABEL long)
endif()

if(rootbench-datafiles)
    RB_ADD_GBENCHMARK(gbenchmark-OpenDataBenchmarks
        RDataFrameOpenDataBenchmarks.cxx
        DOWNLOAD_DATAFILES Run2012B_SingleMu_1M.root Run2012B_SingleMu_10M.root
        LABEL long
        LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps Gpad Graf)

    RB_ADD_GBENCHMARK(gbenchmark-df102_NanoAODDimuonAnalysis
        df102_NanoAODDimuonAnalysis.C
        DOWNLOAD_DATAFILES Run2012BC_DoubleMuParked_Muons.root
        LABEL long
        LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps Gpad Graf)

    RB_ADD_GBENCHMARK(RDataFrameh1Analysis
        RDataFrameh1Analysis.cxx
        LABEL long
        DOWNLOAD_DATAFILES h1analysis.root
        LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

    RB_ADD_PYTESTBENCHMARK(pytest-df102_NanoAODDimuonAnalysis
        df102_NanoAODDimuonAnalysis.py
        DOWNLOAD_DATAFILES Run2012BC_DoubleMuParked_Muons.root
        LABEL long)

    RB_ADD_GBENCHMARK(gbenchmark-df103_NanoAODHiggsAnalysis
        df103_NanoAODHiggsAnalysis.C
        DOWNLOAD_DATAFILES Run2012B_DoubleMuParked.root Run2012C_DoubleMuParked.root Run2012B_DoubleElectron.root Run2012C_DoubleElectron.root SMHiggsToZZTo4L.root ZZTo4mu.root ZZTo4e.root
        LABEL long
        LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps Gpad Graf)

    RB_ADD_PYTESTBENCHMARK(pytest-df103_NanoAODHiggsAnalysis
        df103_NanoAODHiggsAnalysis.py
        DOWNLOAD_DATAFILES Run2012B_DoubleMuParked.root Run2012C_DoubleMuParked.root Run2012B_DoubleElectron.root Run2012C_DoubleElectron.root SMHiggsToZZTo4L.root ZZTo4mu.root ZZTo4e.root
        LABEL long)

    RB_ADD_PYTESTBENCHMARK(pytest-df104_HiggsToTwoPhotons
        df104_HiggsToTwoPhotons.py
        DOWNLOAD_DATAFILES data_A.GamGam.root data_B.GamGam.root data_C.GamGam.root data_D.GamGam.root mc_343981.ggH125_gamgam.GamGam.root mc_345041.VBFH125_gamgam.GamGam.root
        LABEL long)

    if (CMAKE_CXX_FLAGS MATCHES "-std=c\\+\\+17" OR CMAKE_CXX_STANDARD GREATER 14)
        RB_ADD_GBENCHMARK(ZPeak
           zpeak.cxx
           LIBRARIES Core Hist Imt RIO MathCore Physics Tree TreePlayer ROOTDataFrame ROOTVecOps
           DOWNLOAD_DATAFILES zpeak_data_small.root
           LABEL long)
    endif()

   if (ROOT_root7_FOUND)
      RB_ADD_GBENCHMARK(RNTupleDSBenchmarks
         RNTupleDSBenchmarks.cxx
         LIBRARIES Core Hist RIO TreePlayer ROOTNTuple ROOTDataFrame
         DOWNLOAD_DATAFILES B2HHH~none.rc2.ntuple
         LABEL short)
   endif()
endif()

add_subdirectory(LoopSUSYFrame)
add_subdirectory(wmass)
