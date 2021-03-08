// Author: Stephan Hageboeck, CERN  10 Jul 2019

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
 * Run 6 different workflows:
 * 0. Evaluate fit model for 2 M data events with batch data loading and SIMD (if compiler flags activated).
 * 1. As above, but use old RooFit strategy of single-value data loading.
 * 2. Compute probabilities for each data event. That is, run step 0 and normalise values.
 * 3. As above, but use old RooFit strategy.
 * 4. Compute log-likelihoods, i.e. run step 2 and apply -log(LH).
 * 5. As above, but use old RooFit strategy.
 *
 */

#include "benchmark/benchmark.h"

#include "RooRealVar.h"
#include "RooAddPdf.h"
#include "RooGaussian.h"
#include "RooPoisson.h"
#include "RooExponential.h"
#include "RooDataSet.h"
#include "RunContext.h"

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

enum RunConfig_t {runBatchUnnorm = 0, runSingleUnnorm = 1,
  runBatchNorm, runSingleNorm,
  runBatchNormLogs, runSingleNormLogs};



static void benchAddPdfGaussExp(benchmark::State& state) {
  RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
  constexpr std::size_t nParamSets = 30;
  constexpr std::size_t nEvents = 2000000;

  // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
  RooRealVar x("x", "x", -1.5, 40.5);

  RooRealVar mean("mean", "mean of gaussian", 20., -10, 30);
  RooRealVar sigma("sigma", "width of gaussian", 4., 0.5, 10);

  // Build gaussian p.d.f in terms of x,mean and sigma
  RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

  RooRealVar c1("c1", "Decay constant", -0.5, -10, -0.001);
  RooExponential ex("Pois", "Poisson PDF", x, c1);

  RooRealVar fractionGaus("fractionGaus", "Fraction of Gauss component", 0.5, 0., 1.);
  RooAddPdf pdf("SumGausPois", "Sum of Gaus and Poisson", RooArgSet(gauss, ex), fractionGaus);
  // to avoid a warning when computing the   unnormalized RooAddPdf values
  pdf.fixCoefNormalization(x);

  auto data = pdf.generate(RooArgSet(x), nEvents);

  RooArgSet& observables = *pdf.getObservables(data);
  RooArgSet& parameters = *pdf.getParameters(data);
  if (runConfig % 2 == 0)
    data->attachBuffers(observables);

  RooBatchCompute::RunContext evalData;
  std::vector<double> results(nEvents);

  for (auto _ : state) {
    for (unsigned int paramSetIndex=0; paramSetIndex < nParamSets; ++paramSetIndex) {
      state.PauseTiming();
      randomiseParameters(parameters, 1337+paramSetIndex);
      state.ResumeTiming();

      evalData.clear();
      data->getBatches(evalData, 0, data->numEntries());
      runConfig = static_cast<RunConfig_t>(runConfig % 6);

      if (runConfig == runBatchUnnorm) {
        auto batchResult = pdf.getValues(evalData, nullptr);
        if (batchResult.size() != (std::size_t) data->numEntries())
          throw std::runtime_error("Batch computation failed.");
      } else if (runConfig == runBatchNorm) {
        auto batchResult = pdf.getValues(evalData, &observables);
        if (batchResult.size() != (std::size_t) data->numEntries())
          throw std::runtime_error("Batch computation failed.");
      } else if (runConfig == runBatchNormLogs) {
        auto batchResult = pdf.getLogProbabilities(evalData, &observables);
        if (batchResult.size() != (std::size_t) data->numEntries())
          throw std::runtime_error("Batch computation failed.");
      } else if (runConfig == runSingleUnnorm) {
        for (unsigned int i=0; i < data->sumEntries(); ++i) {
          observables = *data->get(i);
          results[i] = pdf.getVal();
        }
      } else if (runConfig == runSingleNorm) {
        for (unsigned int i=0; i < data->sumEntries(); ++i) {
          observables = *data->get(i);
          results[i] = pdf.getVal(&observables);
        }
      } else if (runConfig == runSingleNormLogs) {
        for (unsigned int i=0; i < data->sumEntries(); ++i) {
          observables = *data->get(i);
          results[i] = pdf.getLogVal(&observables);
        }
      }
    }
  }
};

BENCHMARK(benchAddPdfGaussExp)->Unit(benchmark::kMillisecond)
        ->Args({runBatchUnnorm})
        ->Args({runSingleUnnorm})
        ->Args({runBatchNorm})
        ->Args({runSingleNorm})
        ->Args({runBatchNormLogs})
        ->Args({runSingleNormLogs})
    ;


BENCHMARK_MAIN();
