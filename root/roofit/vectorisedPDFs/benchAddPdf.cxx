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

#include "RooRealVar.h"
#include "RooAddPdf.h"
#include "RooGaussian.h"
#include "RooPoisson.h"
#include "RooExponential.h"
#include "RooDataSet.h"
#include "RooRandom.h"

#include "SlowRooExponential.h"

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

enum RunConfig_t {runSingleUnnorm = 0,
  runBatchNorm, runSingleNorm,
  runSingleNormLogs,
   fitScalar, fitCpu, fitCuda};



static void benchAddPdfGaussExp(benchmark::State& state) {
  const RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
  const bool useSlowRooExponential = state.range(1);
  constexpr std::size_t nParamSets = 1;
  constexpr std::size_t nEvents = 1000000;

  // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
  RooRealVar x("x", "x", -1.5, 40.5);

  RooRealVar mean("mean", "mean of gaussian", 20., -10, 30);
  RooRealVar sigma("sigma", "width of gaussian", 4., 0.5, 10);

  // Build gaussian p.d.f in terms of x,mean and sigma
  RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

  RooRealVar c1("c1", "Decay constant", -0.5, -10, -0.001);
  std::unique_ptr<RooAbsPdf> ex;
  if (useSlowRooExponential) {
    ex = std::make_unique<SlowRooExponential>("Pois", "Poisson PDF", x, c1);
  } else {
    ex = std::make_unique<RooExponential>("Pois", "Poisson PDF", x, c1);
  }

  RooRealVar fractionGaus("fractionGaus", "Fraction of Gauss component", 0.5, 0., 1.);
  RooAddPdf pdf("SumGausPois", "Sum of Gaus and Poisson", RooArgSet(gauss, *ex), fractionGaus);
  // to avoid a warning when computing the   unnormalized RooAddPdf values
  pdf.fixCoefNormalization(x);

  auto data = pdf.generate(RooArgSet(x), nEvents);

  RooArgSet& observables = *pdf.getObservables(data);
  RooArgSet& parameters = *pdf.getParameters(data);
  if (runConfig % 2 == 0)
    data->attachBuffers(observables);

  std::vector<double> results(nEvents);

  std::array<RooArgSet, nParamSets> paramSets;
  unsigned int seed = 1337;
  for (auto& paramSet : paramSets) {
    randomiseParameters(parameters, seed++);
    parameters.snapshot(paramSet);
  }

  for (auto _ : state) {
    for (const auto& paramSet : paramSets) {
      parameters = paramSet;

      if (runConfig == runBatchNorm) {
        auto batchResult = pdf.getValues(*data);
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
      } else if (runConfig == fitScalar) {
           auto r = pdf.fitTo(*data, RooFit::Save(1),RooFit::Minimizer("Minuit2"),RooFit::PrintLevel(-1));
      } else if (runConfig == fitCpu) {
           auto r = pdf.fitTo(*data, RooFit::BatchMode("cpu"), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                              RooFit::PrintLevel(-1));
      } else if (runConfig == fitCuda) {
           auto r = pdf.fitTo(*data, RooFit::BatchMode("cuda"), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                              RooFit::PrintLevel(1));
      }
    }
  }
};

BENCHMARK(benchAddPdfGaussExp)->Name("Gauss+Exp")->Unit(benchmark::kMillisecond)
        ->Args({runBatchNorm, false})
        ->Args({runSingleNorm, false})
        ->Args({runSingleNormLogs, false});
BENCHMARK(benchAddPdfGaussExp)->Name("Gauss+Exp(evaluateSpan fallback)")->Unit(benchmark::kMillisecond)
        ->Args({runBatchNorm, true})
        ->Args({runSingleNorm, true})
        ->Args({runSingleNormLogs, true});

BENCHMARK(benchAddPdfGaussExp)->Name("fitGausExp_Scalar")->Unit(benchmark::kMillisecond)->Args({fitScalar, false});
BENCHMARK(benchAddPdfGaussExp)->Name("fitGausExp_CPU")->Unit(benchmark::kMillisecond)->Args({fitCpu, false});
BENCHMARK(benchAddPdfGaussExp)->Name("fitGausExp_Cuda")->Unit(benchmark::kMillisecond)->Args({fitCuda, false});

BENCHMARK_MAIN();
