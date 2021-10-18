if(rootbench-datafiles)
   RB_ADD_GBENCHMARK(LoopSUSYFrameBench
                     src/main.cxx
                     src/cppnn.cxx
                     src/GenericHelpers.cxx
                     src/LeptonHelpers.cxx
                     src/LoopSUSYFrame.cxx
                     src/LoopSUSYThTh.cxx
                     src/readFFXML.cxx
                     LABEL long
                     LIBRARIES RIO Core Tree Matrix Physics TreePlayer ROOTDataFrame ROOTVecOps XMLIO
                     DOWNLOAD_DATAFILES user.anon.436647.MGPy8EG_A14N23LO_T1T1_onestepN2N2_950_350_1L20.mc16e_stopH_v67_output.root)
   target_include_directories(LoopSUSYFrameBench PUBLIC inc)

   foreach(fname biases.txt  fake_factor3D.xml  fake_factors_Stop2L.root  FNPFF.xml  norm.txt  weights.txt)
     configure_file(data/${fname} . COPYONLY)
   endforeach()
endif(rootbench-datafiles)
