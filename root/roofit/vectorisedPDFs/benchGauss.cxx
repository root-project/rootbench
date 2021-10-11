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
#include "RunContext.h"
#include "RooWorkspace.h"

#include "RooRandom.h"

enum RunConfig_t { runScalar, runCpu, runCuda, fitScalar, fitCpu, fitCuda };

const size_t nEvents = 100000;
const size_t nParamSets = 30;

class GausModel {

public:
private:
   std::unique_ptr<RooWorkspace> w;
   std::unique_ptr<RooAbsData> data;
   RooAbsPdf *pdf;
   std::string obsName;
   std::vector<double> results;

public:
   GausModel(std::string obsName, size_t nEvts)
   {

      RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

      w = std::make_unique<RooWorkspace>("w");

      // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
      RooRealVar x("x", "x", -1.5, 40.5);

      RooRealVar mean("mean", "mean of gaussian", 20., 15., 25.);
      RooRealVar sigma("sigma", "width of gaussian", 10., 8., 12.);

      // Build gaussian p.d.f in terms of x,mean and sigma
      RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

      w->import(gauss);

      w->defineSet("obs", obsName.c_str());

      pdf = w->pdf("gauss");
      //w->Print();
      generateData(nEvents);
   }
   RooAbsPdf &GetPdf() { return *pdf; }
   RooAbsData &GetData() { return *data; }

   void randomiseParameters(ULong_t seed = -1)
   {
      auto parameters = pdf->getParameters(data.get());
      auto random = RooRandom::randomGenerator();
      if (seed != -1)
         random->SetSeed(seed);

      for (auto param : *parameters) {
         auto par = static_cast<RooAbsRealLValue *>(param);
         const double uni = random->Uniform();
         const double min = par->getMin();
         const double max = par->getMax();
         par->setVal(min + uni * (max - min));
      }
      delete parameters;
   }

   void generateData(size_t nEvts)
   {
      data = std::unique_ptr<RooAbsData>(pdf->generate(*w->set("obs"), nEvts) );
      // allocate here output vector
      results = std::vector<double>(nEvts);
   }
   void EvalScalar()
   {
      for (unsigned int i = 0; i < data->sumEntries(); ++i) {
         auto observables = data->get(i);
         results[i] = pdf->getLogVal(observables);
      }
   }
   void EvalBatchCpu()
   {
      results = pdf->getValues(*data, RooFit::BatchModeOption::Cpu);
   }
   void EvalBatchCuda()
   {
      results = pdf->getValues(*data, RooFit::BatchModeOption::Cuda);
   }
};

static void benchEvalGauss(benchmark::State &state)
{
   //std::cout << state.range(0) << " " << state.range(1) << "  " << state.range(2) << std::endl;
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   GausModel model("x",nEvents);

   for (auto _ : state) {
      for (unsigned int paramSetIndex = 0; paramSetIndex < nParamSets; ++paramSetIndex) {

         state.PauseTiming();
         model.randomiseParameters();
         state.ResumeTiming();

         if (runConfig == runScalar) {
            model.EvalScalar();
         } else if (runConfig == runCpu) {
            model.EvalBatchCpu();
         } else if (runConfig == runCuda) {
            model.EvalBatchCuda();
         }
      }
   }
}

static void benchEvalGaussXSigma(benchmark::State &state)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   GausModel model("x,sigma", nEvents);

   for (auto _ : state) {
      for (unsigned int paramSetIndex = 0; paramSetIndex < nParamSets; ++paramSetIndex) {

         state.PauseTiming();
         model.randomiseParameters();
         state.ResumeTiming();

         if (runConfig == runScalar) {
            model.EvalScalar();
         } else if (runConfig == runCpu) {
            model.EvalBatchCpu();
         } else if (runConfig == runCuda) {
            model.EvalBatchCuda();
         }
      }
   }
}

static void benchFitGauss(benchmark::State &state)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   GausModel model("x", nEvents);
   auto &pdf = model.GetPdf();
   auto &data = model.GetData();

   for (auto _ : state) {
      if (runConfig == fitScalar) {
         auto r = pdf.fitTo(data, RooFit::Save(1), RooFit::Minimizer("Minuit2"), RooFit::PrintLevel(-1));
      } else if (runConfig == fitCpu) {
         auto r = pdf.fitTo(data, RooFit::BatchMode("cpu"), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(-1));
      } else if (runConfig == fitCuda) {
         auto r = pdf.fitTo(data, RooFit::BatchMode("cuda"), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(-1));
      }
   }
}

static void benchFitGaussXSigma(benchmark::State &state)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   GausModel model("x,sigma", nEvents);
   auto &pdf = model.GetPdf();
   auto &data = model.GetData();

   for (auto _ : state) {
      if (runConfig == fitScalar) {
         auto r = pdf.fitTo(data, RooFit::Save(1), RooFit::Minimizer("Minuit2"), RooFit::PrintLevel(-1));
      } else if (runConfig == fitCpu) {
         auto r = pdf.fitTo(data, RooFit::BatchMode("cpu"), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(-1));
      } else if (runConfig == fitCuda) {
         auto r = pdf.fitTo(data, RooFit::BatchMode("cuda"), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(-1));
      }
   }
}

BENCHMARK(benchEvalGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_EvalScalar")->Args({runScalar});
BENCHMARK(benchEvalGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_EvalBatchCPU")->Args({runCpu});
//BENCHMARK(benchEvalGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_EvalBatchCUDA")->Args({runCuda});

BENCHMARK(benchEvalGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_EvalScalar")->Args({runScalar});
BENCHMARK(benchEvalGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_EvalBatchCPU")->Args({runCpu});
//BENCHMARK(benchEvalGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_EvalBatchCUDA")->Args({runCuda});

BENCHMARK(benchFitGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_FitScalar")->Args({fitScalar});
BENCHMARK(benchFitGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_FitBatchCPU")->Args({fitCpu});
//BENCHMARK(benchFitGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_FitBatchCUDA")->Args({fitCuda});

BENCHMARK(benchFitGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_FitScalar")->Args({fitScalar});
BENCHMARK(benchFitGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_FitBatchCPU")->Args({fitCpu});
//BENCHMARK(benchFitGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_FitBatchCUDA")->Args({fitCuda});


BENCHMARK_MAIN();
