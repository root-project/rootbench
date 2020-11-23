if(ROOT_veccore_FOUND)
   RB_ADD_GBENCHMARK(MathcoreBenchmarks
     TMathBenchmarks.cxx
     LABEL short
     LIBRARIES MathCore)
endif()
