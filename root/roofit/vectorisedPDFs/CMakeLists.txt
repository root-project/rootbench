RB_ADD_GBENCHMARK(benchAddPdf
  benchAddPdf.cxx
  LABEL long
  LIBRARIES Core MathCore RooFitCore RooFit)
RB_ADD_GBENCHMARK(benchGauss
  benchGauss.cxx
  LABEL long
  LIBRARIES Core MathCore RooFitCore RooFit)
RB_ADD_GBENCHMARK(benchJohnson
  benchJohnson.cxx
  LABEL long
  LIBRARIES Core MathCore RooFitCore RooFit)

