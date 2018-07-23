// @(#)root/mathcore:$Id$
// Author: L. Moneta Tue Nov 14 14:38:48 2006

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2006  LCG ROOT Math Team, CERN/PH-SFT                *
 *                                                                    *
 *                                                                    *
 **********************************************************************/

// Defines Forward declaration for template IFunction class and useful typedefs

#ifndef ROOT_Math_IFunctionExternalGradientfwd
#define ROOT_Math_IFunctionExternalGradientfwd

#include "Math/Types.h"

namespace ROOT {

   namespace Math {

      class IBaseFunctionOneDimGrad;
      class IGradientFunctionOneDimGrad;
      template<class T>
      class IBaseFunctionMultiDimTemplGrad;
      template <class T>
      class IGradientFunctionMultiDimTemplGrad;
      template <class T>
      class IGradientMultiDimTemplGrad;

      template<class T>
      using IMultiGenFunctionTemplGrad = IBaseFunctionMultiDimTemplGrad<T>;
      using IBaseFunctionMultiDimGrad = IBaseFunctionMultiDimTemplGrad<double>;
      using IMultiGenFunctionGrad = IMultiGenFunctionTemplGrad<double>;

      using IGradientFunctionMultiDimGrad = IGradientFunctionMultiDimTemplGrad<double>;
      using IGradientMultiDimGrad = IGradientMultiDimTemplGrad<double>;

      typedef IBaseFunctionOneDimGrad        IGenFunctionGrad;
      typedef IBaseFunctionMultiDimGrad      IMultiGenFunctionGrad;

      typedef IGradientFunctionOneDimGrad        IGradFunctionGrad;
      typedef IGradientFunctionMultiDimGrad      IMultiGradFunctionGrad;


   } // end namespace Math

} // end namespace ROOT


#endif /* ROOT_Math_IFunctionfwd */
