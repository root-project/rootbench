RB_ADD_GBENCHMARK(RoofitBinnedBenchmark
  RooFitBinnedBenchmarks.cxx
  LABEL short
  LIBRARIES Core Hist MathCore RIO RooFit RooStats RooFitCore HistFactory)

RB_ADD_GBENCHMARK(RoofitUnBinnedBenchmark
  RooFitUnBinnedBenchmarks.cxx
  LIBRARIES Core Hist MathCore RIO RooFit RooStats RooFitCore HistFactory)
