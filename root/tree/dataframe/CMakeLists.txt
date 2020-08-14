RB_ADD_GBENCHMARK(RDFBenchmarks
    RDataFrameBenchmarks.cxx
    RDataFrameSumBenchmarks.cxx
    LABEL short
    LIBRARIES Core Hist Imt RIO Tree TreePlayer ROOTDataFrame ROOTVecOps)

if(NUMPY_FOUND)
    RB_ADD_PYTESTBENCHMARK(pytest-rdataframe-asnumpy rdataframe_asnumpy.py LABEL short)
endif()

if(rootbench-datafiles)
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

    # FIXME there will be no need to check CMAKE_CXX_FLAGS when ROOT exports CMAKE_CXX_STANDARD
    # (see https://github.com/root-project/rootbench/issues/156)
    if (CMAKE_CXX_FLAGS MATCHES "-std=c\\+\\+14" OR CMAKE_CXX_STANDARD GREATER_EQUAL 14)
        RB_ADD_GBENCHMARK(ZPeak
           zpeak.cxx
           LIBRARIES Core Hist Imt RIO MathCore Physics Tree TreePlayer ROOTDataFrame ROOTVecOps
           DOWNLOAD_DATAFILES zpeak_data_small.root
           LABEL long)
    endif()
endif()

add_subdirectory(LoopSUSYFrame)
add_subdirectory(wmass)
