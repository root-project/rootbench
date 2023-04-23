// Author: Lorenzo Moneta Oct 2021

/*****************************************************************************
 * RooFit
 * Authors:                                                                  *
 *   WV, Wouter Verkerke, UC Santa Barbara, verkerke@slac.stanford.edu       *
 *   DK, David Kirkby,    UC Irvine,         dkirkby@uci.edu                 *
 *                                                                           *
 * Copyright (c) 2000-2019, Regents of the University of California          *
 *                          and Stanford University. All rights reserved.    *
 *                                                                           *
 * Redistribution and use in source and binary forms,                        *
 * with or without modification, are permitted according to the terms        *
 * listed in LICENSE (http://roofit.sourceforge.net/license.txt)             *
 *****************************************************************************/

/**
 * \file
 * Benchmark a simple mock fit model
 *    sum(x) = frac * Gauss(x) + (1-frac) * Exponential(x)
 *
 * We can run 6 different workflows:
 * 0. Evaluate fit model for 1 M data events with batch data loading and SIMD (if compiler flags activated).
 * 1. As above, but use old RooFit strategy of single-value data loading.
 * 2. Compute probabilities for each data event. That is, run step 0 and normalise values.
 * 3. As above, but use old RooFit strategy.
 * 4. Compute log-likelihoods, i.e. run step 2 and apply -log(LH).
 * 5. As above, but use old RooFit strategy.
 *
 */

#include "helpers.h"

#include <RooWorkspace.h>
#include <RooDataSet.h>

static void benchModel(benchmark::State &state)
{
   RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

   const RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
   // const int printLevel = state.range(1);
   // const int nParamSets = 1; // state.range(2) > 1 : state.range(2) ? 1;
   const std::size_t nEvents = 100000;

   // Declare variables x,mean,sigma with associated name, title, initial value and allowed range

   RooWorkspace w;
   //  w.factory("Voigtian::vpdf(x[-10,10],m0[0,-10,10],width[0.5,0,10],s0[0.5,0,10])");
   //  w.factory("Gaussian::vpdf(x[0,20],m0[10,0,20],s0[0.5,0,10])");
   w.factory("Gamma::vpdf(x[0,20],g[20,0.1,40],b[0.5,0.01,10],m0[-1,-20,0])");
   w.factory("Gaussian::gpdf(x,m1[10,0,20],s1[2,0.1,10])");
   w.factory("Gaussian::g2(x,m2[5,0,20],s2[0.3,0.01,10])");
   w.factory("Gaussian::g3(x,m3[15,0,20],s3[0.4,0.01,10])");
   w.factory("Polynomial::pol(x,a[-0.01,-0.05,0.1])");

   w.factory("SUM::model(ns1[0,1000000000]*vpdf,ns2[0,10000000000]*gpdf,ng2[0,1000000000]*g2,ng3[0,10000000000]*g3, "
             "npol[0,10000000000]*pol)");

   // set coeffients
   w.var("ns1")->setVal(0.2 * nEvents);
   w.var("ns2")->setVal(0.3 * nEvents);
   w.var("ng2")->setVal(0.1 * nEvents);
   w.var("ng3")->setVal(0.1 * nEvents);
   w.var("npol")->setVal(0.3 * nEvents);

   auto &pdf = *(w.pdf("model"));
   auto &x = *(w.var("x"));

   std::unique_ptr<RooDataSet> data{pdf.generate({x}, nEvents)};

   RooArgSet parameters;
   pdf.getParameters(data->get(), parameters);
   // We need to change the parameters so we don't start already at the minimum
   // (the parameter values for which the dataset was created). This time, we
   // don't randomize them because the fit has many parameter and is not stable
   // from many initial points. That's why they are only shifted away a little
   // bit from their true value.
   for (auto *param : static_range_cast<RooRealVar *>(parameters)) {
      double val = param->getVal();
      val = val + 0.05 * (param->getMax() - val);
      param->setVal(val);
   }

   runFitBenchmark(state, pdf, *data);
}

BENCHMARK(benchModel)->Name("fit_Scalar")->Unit(benchmark::kMillisecond)->Args({fitScalar});

BENCHMARK(benchModel)->Name("fit_CPU")->Unit(benchmark::kMillisecond)->Args({fitCpu});

#ifdef R__HAS_CUDA
BENCHMARK(benchModel)->Name("fit_CUDA")->Unit(benchmark::kMillisecond)->Args({fitCuda});
#endif

BENCHMARK_MAIN();
