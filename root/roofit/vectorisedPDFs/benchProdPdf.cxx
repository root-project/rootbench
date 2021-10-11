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

#include "benchmark/benchmark.h"

#include "RooWorkspace.h"
#include "RooAbsPdf.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooRandom.h"


void randomiseParameters(const RooArgSet& parameters, ULong_t seed=0) {
  auto random = RooRandom::randomGenerator();
  if (seed != 0)
    random->SetSeed(seed);

  for (auto param : parameters) {
    auto par = static_cast<RooAbsRealLValue*>(param);
    const double uni = random->Uniform();
    const double min = par->getMin();
    const double max = par->getMax();
    par->setVal(min + uni*(max-min));
  }
}

enum RunConfig_t { 
   fitScalar, fitCpu, fitCuda};


bool first = true; 

static void benchProdPdf(benchmark::State& state) {
  const RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
  const int printLevel = state.range(1);
  const int nParamSets = 1;//state.range(2) > 1 : state.range(2) ? 1;
  const std::size_t nEvents = 100000;

  // Declare variables x,mean,sigma with associated name, title, initial value and allowed range


  RooWorkspace w;
  w.factory("Gaussian::g1(x[0,20],mx1[10,0,20],sx1[3,0,10])");
  w.factory("Gaussian::g2(x,mx2[10,0,20],sx2[1,0,10])");
  w.factory("Gaussian::g3(y[0,20],my[10,0,20],sy[2,0,10])");
  w.factory("Polynomial::pol(y,a[-0.01,-0.05,0.1])");
  w.factory("Gamma::gpdf(z[0,10],g[2,0,10],b[2,0,10],m0[0])");
  

  w.factory("SUM::pdfx(fx[0.2,0,1]*g1,g2)");
  w.factory("SUM::pdfy(fy[0.4,0.,1.]*g3,pol)");
  w.factory("PROD::model(pdfx,pdfy,gpdf)");

  if (first) {
     w.Print();
     first = false;
  }

  // set coeffients
  // w.var("ns1")->setVal(0.2*nEvents);
  // w.var("ns2")->setVal(0.3*nEvents);
  // w.var("ng2")->setVal(0.1*nEvents);
  // w.var("ng3")->setVal(0.1*nEvents);
  // w.var("npol")->setVal(0.3*nEvents);

  auto & pdf = *(w.pdf("model"));
  auto & x = *(w.var("x"));
  auto & y = *(w.var("y"));
  auto & z = *(w.var("z"));
            
  auto data = pdf.generate(RooArgSet(x,y,z), nEvents);

  // RooArgSet& observables = *pdf.getObservables(data);
  // RooArgSet& parameters = *pdf.getParameters(data);
  

  // std::array<RooArgSet, nParamSets> paramSets;
  // unsigned int seed = 1337;
  // for (auto& paramSet : paramSets) {
  //   randomiseParameters(parameters, seed++);
  //   parameters.snapshot(paramSet);
  // }

  for (auto _ : state) {
     if (runConfig == fitScalar) {
        auto r = pdf.fitTo(*data, RooFit::Save(1),RooFit::Minimizer("Minuit2"),RooFit::PrintLevel(-1));
     } else if (runConfig == fitCpu) {
        auto r = pdf.fitTo(*data, RooFit::BatchMode(rbc::Cpu), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                              RooFit::PrintLevel(-1));
     } else if (runConfig == fitCuda) {
           auto r = pdf.fitTo(*data, RooFit::BatchMode(rbc::Cuda), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                              RooFit::PrintLevel(-1));
     }
  }
  
}


BENCHMARK(benchProdPdf)->Name("fit_Scalar")->Unit(benchmark::kMillisecond)->Args({fitScalar});

BENCHMARK(benchProdPdf)->Name("fit_CPU")->Unit(benchmark::kMillisecond)->Args({fitCpu});

BENCHMARK(benchProdPdf)->Name("fit_Cuda")->Unit(benchmark::kMillisecond)->Args({fitCuda});

BENCHMARK_MAIN();
