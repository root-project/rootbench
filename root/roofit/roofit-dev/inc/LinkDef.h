
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#ifdef USE_FOR_AUTLOADING
#pragma link C++ class RooFit;
#else
#pragma link C++ namespace RooFit;
#endif

#pragma link C++ class RooFitResultGrad-;
#pragma link C++ class SqrtUpParameterTransformationGrad;
#pragma link C++ class SqrtLowParameterTransformationGrad;
#pragma link C++ class SinParameterTransformationGrad;
#pragma link C++ class RooGradMinimizerFcn;
#pragma link C++ class RooGradMinimizer;
#pragma link C++ class NumericalDerivatorMinuit2;
#pragma link C++ class IBaseFunctionMultiDimTemplGrad;

#endif
