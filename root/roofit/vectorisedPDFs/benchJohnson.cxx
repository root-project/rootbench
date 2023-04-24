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
 * Benchmark a simple mock fit model
 *    sum(x) = a * JohnsonDistribution(x) + (1-a) * Exponential(x)
 *
 * Run 6 different workflows:
 * 0. Evaluate fit model for 500k data events with batch data loading and SIMD (if compiler flags activated).
 * 1. As above, but use old RooFit strategy of single-value data loading.
 * 2. Compute probabilities for each data event. That is, run step 0 and normalise values.
 * 3. As above, but use old RooFit strategy.
 * 4. Compute log-likelihoods, i.e. run step 2 and apply -log(LH).
 * 5. As above, but use old RooFit strategy.
 *
 */

#include <RooAddPdf.h>
#include <RooDataSet.h>
#include <RooExponential.h>
#include <RooJohnson.h>
#include <RooRandom.h>
#include <RooRealVar.h>

#include <benchmark/benchmark.h>

void randomiseParameters(const RooArgSet &parameters, ULong_t seed = 0)
{
   auto random = RooRandom::randomGenerator();
   if (seed != 0)
      random->SetSeed(seed);

   for (auto param : parameters) {
      auto par = static_cast<RooAbsRealLValue *>(param);
      const double uni = random->Uniform();
      const double min = par->getMin();
      const double max = par->getMax();
      par->setVal(min + uni * (max - min));
   }
}

enum JohnsonRunConfig_t { runBatchNorm, runSingleNorm };

static void benchJohnsonPlusExp(benchmark::State &state)
{
   JohnsonRunConfig_t runConfig = static_cast<JohnsonRunConfig_t>(state.range(0));
   constexpr std::size_t nParamSets = 30;
   constexpr std::size_t nEvents = 500000;

   RooRealVar mass("mass", "mass", 0., 10., 400.);
   RooRealVar mu("mu", "Location parameter of normal distribution", 100., 50., 200.);
   RooRealVar sigma("sigma", "Two sigma of normal distribution", 2., 1.E-3, 100.);
   RooRealVar gamma("gamma", "gamma", -10., -100., 100.);
   RooRealVar delta("delta", "delta", 3., 1.E-3, 100.);
   RooJohnson johnson("johnson", "johnson", mass, mu, sigma, gamma, delta, -1.E300);

   RooRealVar c("c", "c", -0.2, -1., -0.0001);
   RooExponential exp("exp", "exp falling background", mass, c);

   RooRealVar a("a", "a", 0.5, 0., 1.);
   RooAddPdf sum("sum", "Johnson+exp", johnson, exp, a);
   // to avoid a warning when computing the unnormalized RooAddPdf values
   sum.fixCoefNormalization(mass);

   RooAbsPdf &pdf = sum;

   std::unique_ptr<RooDataSet> data{pdf.generate(mass, nEvents)};

   RooArgSet &observables = *pdf.getObservables(data.get());
   RooArgSet &parameters = *pdf.getParameters(data.get());
   if (runConfig == runSingleNorm)
      data->attachBuffers(observables);

   std::vector<double> results(nEvents);

   for (auto _ : state) {
      for (unsigned int paramSetIndex = 0; paramSetIndex < nParamSets; ++paramSetIndex) {
         state.PauseTiming();
         randomiseParameters(parameters, 1337 + paramSetIndex);
         state.ResumeTiming();

         runConfig = static_cast<JohnsonRunConfig_t>(runConfig % 6);

         if (runConfig == runBatchNorm) {
            auto batchResult = pdf.getValues(*data);
            if (batchResult.size() != (std::size_t)data->numEntries())
               throw std::runtime_error("Batch computation failed.");
         } else if (runConfig == runSingleNorm) {
            for (unsigned int i = 0; i < data->sumEntries(); ++i) {
               observables = *data->get(i);
               results[i] = pdf.getVal(&observables);
            }
         }
      }
   }
};

BENCHMARK(benchJohnsonPlusExp)->Unit(benchmark::kMillisecond)->Args({runBatchNorm})->Args({runSingleNorm});

BENCHMARK_MAIN();
