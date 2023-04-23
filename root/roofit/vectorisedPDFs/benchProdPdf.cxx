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
 * Benchmark a RooProdPdf mock fit model
 *    p(x) = (Gauss(x) + Gaus(x)) * (Gauss(x) + polynomial(x)) * gamma(x)
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
#include <RooAbsPdf.h>
#include <RooDataSet.h>

constexpr bool verbose = false;
bool first = true;

static void benchProdPdf(benchmark::State &state)
{
   RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

   const RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
   // const int printLevel = state.range(1);
   // const int nParamSets = 1; // state.range(2) > 1 : state.range(2) ? 1;
   const std::size_t nEvents = 100000;

   // Declare variables x,mean,sigma with associated name, title, initial value and allowed range

   RooWorkspace w;
   w.factory("Gaussian::g1(x[0,20],mx1[10,0,20],sx1[3,0.1,10])");
   w.factory("Gaussian::g2(x,mx2[10,0,20],sx2[1,0.1,10])");
   w.factory("Gaussian::g3(y[0,20],my[10,0,20],sy[2,0.1,10])");
   w.factory("Polynomial::pol(y,a[-0.01,-0.05,0.1])");
   w.factory("Gamma::gpdf(z[0,10],g[2,0.1,10],b[2,0.1,10],m0[-1,-20,0])");

   w.factory("SUM::pdfx(fx[0.2,0,1]*g1,g2)");
   w.factory("SUM::pdfy(fy[0.4,0.,1.]*g3,pol)");
   w.factory("PROD::model(pdfx,pdfy,gpdf)");

   if (first) {
      if (verbose) {
         w.Print();
      }
      first = false;
   }

   // set coeffients
   // w.var("ns1")->setVal(0.2*nEvents);
   // w.var("ns2")->setVal(0.3*nEvents);
   // w.var("ng2")->setVal(0.1*nEvents);
   // w.var("ng3")->setVal(0.1*nEvents);
   // w.var("npol")->setVal(0.3*nEvents);

   auto &pdf = *(w.pdf("model"));
   auto &x = *(w.var("x"));
   auto &y = *(w.var("y"));
   auto &z = *(w.var("z"));

   std::unique_ptr<RooDataSet> data{pdf.generate({x, y, z}, nEvents)};

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

BENCHMARK(benchProdPdf)->Name("fit_Scalar")->Unit(benchmark::kMillisecond)->Args({fitScalar});

BENCHMARK(benchProdPdf)->Name("fit_CPU")->Unit(benchmark::kMillisecond)->Args({fitCpu});

#ifdef R__HAS_CUDA
BENCHMARK(benchProdPdf)->Name("fit_CUDA")->Unit(benchmark::kMillisecond)->Args({fitCuda});
#endif

BENCHMARK_MAIN();
