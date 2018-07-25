set(headers
   IFunctionExternalGradient.h
   IFunctionExternalGradientFwd.h
   NumericalDerivatorMinuit2.h
   RooGradMinimizerFcn.h
   RooGradMinimizer.h
   SinParameterTransformationGrad.h
   SqrtLowParameterTransformationGrad.h
   SqrtUpParameterTransformationGrad.h
   RooGradientFunction.h
   RooFitResultGrad.h)

set(sources NumericalDerivatorMinuit2.cxx
   RooGradMinimizerFcn.cxx
   RooGradMinimizer.cxx
   SinParameterTransformationGrad.cxx
   SqrtLowParameterTransformationGrad.cxx
   SqrtUpParameterTransformationGrad.cxx
   RooGradientFunction.cxx
   RooFitResultGrad.cxx)

ROOT_STANDARD_LIBRARY_PACKAGE(RooFitdev
            NO_INSTALL_HEADERS
            HEADERS ${headers}
            SOURCES ${sources}
            DICTIONARY_OPTIONS "-writeEmptyRootPCM"
            LIBRARIES Core Matrix Minuit Minuit2 MathCore RooFit RooFitCore Hist Graf)

RB_ADD_GBENCHMARK(RooFitdevGradientBench
  RooFitdevGradientBench.cxx
  LABEL long
  LIBRARIES Core Matrix Hist Graf MathCore RIO RooFit RooStats RooFitCore HistFactory RooFitdev)
