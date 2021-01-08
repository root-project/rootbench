RB_ADD_GBENCHMARK(TFormulaBenchmarks
  TFormulaBenchmarks.cxx
  TFormulaGradientBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist MathCore)

if(ROOT_minuit2_FOUND)
RB_ADD_GBENCHMARK(FitGradBenchmarks
  FitGradBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist MathCore)
endif()

RB_ADD_GBENCHMARK(THistBenchmarks
   THistFillBenchmarks.cxx
   LABEL short
   LIBRARIES Hist Core)

if(ROOT_root7_FOUND)
RB_ADD_GBENCHMARK(RHistBenchmarks
   RHistFillBenchmarks.cxx
   LABEL short
   LIBRARIES ROOTHist Core)
endif()
