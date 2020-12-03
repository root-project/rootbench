RB_ADD_GBENCHMARK(HistBenchmarks
  TFormulaBenchmarks.cxx
  TFormulaGradientBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist MathCore)

RB_ADD_GBENCHMARK(THistBenchmarks
  THistFillDoubleBenchmarks.cxx
  THistFillFloatBenchmarks.cxx
  THistFillIntBenchmarks.cxx
  LABEL short
  LIBRARIES Hist Core)

if(ROOT_root7_FOUND)
RB_ADD_GBENCHMARK(RHistBenchmarks
   RHistFillDoubleBenchmarks.cxx
   RHistFillFloatBenchmarks.cxx
   RHistFillIntBenchmarks.cxx
   RHistFillLongLongBenchmarks.cxx
   LABEL short
   LIBRARIES ROOTHist Core)
endif()
