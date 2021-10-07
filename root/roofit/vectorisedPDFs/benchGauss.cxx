// Author: Stephan Hageboeck, CERN  12 Jul 2019

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
 * Benchmark ia simple mock fit model
 *    model(x) = Gauss( x | mean, sigma )
 *
 * Run the following workflows:
 * 0. Evaluate fit model for 500k data events with batch data loading and SIMD (if compiler flags activated).
 * 1. As above, but use old RooFit strategy of single-value data loading.
 * 2. Compute probabilities for each data event. That is, run step 0 and normalise values.
 * 3. As above, but use old RooFit strategy.
 * 4. Compute log-likelihoods, i.e. run step 2 and apply -log(LH).
 * 5. As above, but use old RooFit strategy.
 *
 * 6. Similar to step 0, but dataset contains entries for both x and sigma. This invokes
 *    a less-optimised implementation of the Gaussian distribution, as it's a rare use case.
 * 7. as 1., but for less optimised implementation.
 * 8. as 2., but ...
 * 9. as 3., but ...
 */

#include "benchmark/benchmark.h"

#include "RooRealVar.h"
#include "RooGaussian.h"
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

enum RunConfig_t {runSingleUnnorm = 0,
  runBatchNorm, runSingleNorm,
  runSingleNormLogs, runCpu, runCuda,
  runSingleUnnormDataInXAndSigma,
  runBatchNormDataInXAndSigma, runSingleNormDataInXAndSigma};

static void benchGauss(benchmark::State& state) {
  RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));
  constexpr std::size_t nParamSets = 30;
  constexpr std::size_t nEvents = 500000;

  RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

  // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
  RooRealVar x("x", "x", -1.5, 40.5);

  RooRealVar mean("mean", "mean of gaussian", 20., 15., 25.);
  RooRealVar sigma("sigma", "width of gaussian", 10., 8., 12.);

  // Build gaussian p.d.f in terms of x,mean and sigma
  RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);


  RooAbsPdf& pdf = gauss;
  RooDataSet* data;
  if (runConfig < runSingleUnnormDataInXAndSigma) {
     data = pdf.generate(RooArgSet(x), nEvents);
  } else {
     data = pdf.generate(RooArgSet(x, sigma), nEvents);
  }

  RooArgSet& observables = *pdf.getObservables(data);
  RooArgSet& parameters = *pdf.getParameters(data);
  if (runConfig % 2 == 0)
    data->attachBuffers(observables);

  std::vector<double> results(nEvents);

  runConfig = static_cast<RunConfig_t>(runConfig % 6);

  for (auto _ : state) {
     for (unsigned int paramSetIndex = 0; paramSetIndex < nParamSets; ++paramSetIndex) {
        state.PauseTiming();
        randomiseParameters(parameters, 1337 + paramSetIndex);
        state.ResumeTiming();

      runConfig = static_cast<RunConfig_t>(runConfig % 6);

      if (runConfig == runBatchNorm || runConfig == runBatchNormDataInXAndSigma) {
        auto batchResult = pdf.getValues(*data);
        if (batchResult.size() != (std::size_t) data->numEntries())
          throw std::runtime_error("Batch computation failed.");
      } else if (runConfig == runSingleUnnorm || runConfig == runSingleUnnormDataInXAndSigma) {
        for (unsigned int i=0; i < data->sumEntries(); ++i) {
          observables = *data->get(i);
          results[i] = pdf.getVal();
        }
      } else if (runConfig == runSingleNorm || runConfig == runSingleNormDataInXAndSigma) {
        for (unsigned int i=0; i < data->sumEntries(); ++i) {
          observables = *data->get(i);
          results[i] = pdf.getVal(&observables);
        }
      } else if (runConfig == runSingleNormLogs) {
        for (unsigned int i=0; i < data->sumEntries(); ++i) {
          observables = *data->get(i);
          results[i] = pdf.getLogVal(&observables);
        }
      } else if (runConfig == runCpu) {
        auto r = pdf.getValues(*data, RooFit::BatchModeOption::Cpu);
      } else if (runConfig == runCuda) {
         auto r = pdf.getValues(*data, RooFit::BatchModeOption::Cuda);
      }
    }
  }
};

BENCHMARK(benchGauss)->Unit(benchmark::kMillisecond)
    ->Args({runSingleUnnorm})
    ->Args({runBatchNorm})
    ->Args({runSingleNorm})
    ->Args({runSingleNormLogs})
    ->Args({runSingleUnnormDataInXAndSigma})
    ->Args({runBatchNormDataInXAndSigma})
    ->Args({runSingleNormDataInXAndSigma});


BENCHMARK(benchGauss)->Name("benchGaus_CPU")->Unit(benchmark::kMillisecond)->Args({runCpu});
BENCHMARK(benchGauss)->Name("benchGaus_Cuda")->Unit(benchmark::kMillisecond)->Args({runCuda});

BENCHMARK_MAIN();
