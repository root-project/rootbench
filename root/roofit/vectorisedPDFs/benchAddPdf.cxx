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
#include "RooAddPdf.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooWorkspace.h"
#include "RooRandom.h"

#include "SlowRooExponential.h"

enum RunConfig_t { runScalar, runCpu, runCuda, fitScalar, fitCpu, fitCuda };

size_t nEvents = 100000;
const size_t nParamSets = 30;

int printLevel = 0;

class TestModelPdf {

public:
private:
   std::unique_ptr<RooWorkspace> w;
   std::unique_ptr<RooAbsData> data;
   RooAbsPdf *pdf;
   std::string obsName;
   std::vector<double> results;

public:
   TestModelPdf(bool useUserExponential, size_t nEvts)
   {

      if (printLevel == 0) RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

      w = std::make_unique<RooWorkspace>("w");

      // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
      RooRealVar x("x", "x", -1.5, 40.5);

      RooRealVar mean("mean", "mean of gaussian", 20., -10, 30);
      RooRealVar sigma("sigma", "width of gaussian", 4., 0.5, 10);

      // Build gaussian p.d.f in terms of x,mean and sigma
      RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

      RooRealVar c1("c1", "Decay constant", -0.5, -10, -0.001);
      std::unique_ptr<RooAbsPdf> ex;
      // test with a user exponential to test case of user pdf evaluations
      if (useUserExponential) {
         ex = std::make_unique<SlowRooExponential>("Expo", "Exponential PDF", x, c1);
      } else {
         ex = std::make_unique<RooExponential>("Expo", "Exponential PDF", x, c1);
      }

      RooRealVar fractionGaus("fractionGaus", "Fraction of Gauss component", 0.5, 0., 1.);
      RooAddPdf addPdf("SumGausExpo", "Sum of Gaus and Exponential", RooArgSet(gauss, *ex), fractionGaus);
      // to avoid a warning when computing the   unnormalized RooAddPdf values
      addPdf.fixCoefNormalization(x);

      w->import(addPdf);

      w->defineSet("obs", "x");

      pdf = w->pdf("SumGausExpo");
      if (printLevel > 1) w->Print();
      generateData(nEvents);

      if (printLevel > 1) data->Print();
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
      auto r = pdf->getValues(*data, rbc::Cpu);
      std::copy(r.get(), r.get() + results.size(), results.begin());
   }
   void EvalBatchCuda()
   {
      auto r = pdf->getValues(*data, rbc::Cuda);
      std::copy(r.get(), r.get() + results.size(), results.begin());
   }
};

static void benchEval(benchmark::State &state)
{
   //std::cout << state.range(0) << " " << state.range(1) << "  " << state.range(2) << std::endl;
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   TestModelPdf model(false,nEvents);

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

// test using user function
static void benchEvalUser(benchmark::State &state)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   TestModelPdf model(true, nEvents);

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

static void benchFit(benchmark::State &state)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   TestModelPdf model(false, nEvents);
   auto &pdf = model.GetPdf();
   auto &data = model.GetData();

   for (auto _ : state) {
      if (runConfig == fitScalar) {
         auto r = pdf.fitTo(data, RooFit::Save(1), RooFit::Minimizer("Minuit2"), RooFit::PrintLevel(printLevel-1));
      } else if (runConfig == fitCpu) {
         auto r = pdf.fitTo(data, RooFit::BatchMode(rbc::Cpu), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(printLevel-1));
      } else if (runConfig == fitCuda) {
         auto r = pdf.fitTo(data, RooFit::BatchMode(rbc::Cuda), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(printLevel-1));
      }
   }
}

static void benchFitUser(benchmark::State &state)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   TestModelPdf model(true, nEvents);
   auto &pdf = model.GetPdf();
   auto &data = model.GetData();

   for (auto _ : state) {
      if (runConfig == fitScalar) {
         auto r = pdf.fitTo(data, RooFit::Save(1), RooFit::Minimizer("Minuit2"), RooFit::PrintLevel(printLevel-1));
      } else if (runConfig == fitCpu) {
         auto r = pdf.fitTo(data, RooFit::BatchMode(rbc::Cpu), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(printLevel-1));
      } else if (runConfig == fitCuda) {
         auto r = pdf.fitTo(data, RooFit::BatchMode(rbc::Cuda), RooFit::Save(1), RooFit::Minimizer("Minuit2"),
                            RooFit::PrintLevel(printLevel-1));
      }
   }
}

BENCHMARK(benchEval)->Unit(benchmark::kMillisecond)->Name("benchAddPdf_EvalScalar")->Args({runScalar});
BENCHMARK(benchEval)->Unit(benchmark::kMillisecond)->Name("benchAddPdf_EvalBatchCPU")->Args({runCpu});
BENCHMARK(benchEval)->Unit(benchmark::kMillisecond)->Name("benchAddPdf_EvalBatchCUDA")->Args({runCuda});

BENCHMARK(benchEvalUser)->Unit(benchmark::kMillisecond)->Name("benchAddPdfWithUserExp_EvalScalar")->Args({runScalar});
BENCHMARK(benchEvalUser)->Unit(benchmark::kMillisecond)->Name("benchAddPddWithUserExp_EvalBatchCPU")->Args({runCpu});
BENCHMARK(benchEvalUser)->Unit(benchmark::kMillisecond)->Name("benchAddPdfWithUserExp_EvalBatchCUDA")->Args({runCuda});

BENCHMARK(benchFit)->Unit(benchmark::kMillisecond)->Name("benchAddPdf_FitScalar")->Args({fitScalar});
BENCHMARK(benchFit)->Unit(benchmark::kMillisecond)->Name("benchAddPdf_FitBatchCPU")->Args({fitCpu});
BENCHMARK(benchFit)->Unit(benchmark::kMillisecond)->Name("benchAddPdf_FitBatchCUDA")->Args({fitCuda});

BENCHMARK(benchFitUser)->Unit(benchmark::kMillisecond)->Name("benchAddPdfWithUserExp_FitScalar")->Args({fitScalar});
BENCHMARK(benchFitUser)->Unit(benchmark::kMillisecond)->Name("benchAddPdfWithUserExp_FitBatchCPU")->Args({fitCpu});
BENCHMARK(benchFitUser)->Unit(benchmark::kMillisecond)->Name("benchAddPdfWithUserExp_FitBatchCUDA")->Args({fitCuda});

//BENCHMARK_MAIN();

int main(int argc, char **argv)
{

   // Parse command line arguments
   for (Int_t i = 1; i < argc; i++) {
      std::string arg = argv[i];
      if (arg == "-v") {
         std::cout << "---running in verbose mode" << std::endl;
         printLevel = 1;
      } else if (arg == "-vv") {
         std::cout << "---running in very verbose mode" << std::endl;
         printLevel = 2;
      }
      if (arg == "-n") {
         nEvents = atoi(argv[++i]);
      }
   }

   std::cout << "Using nEvents = " << nEvents << std::endl;

   benchmark::Initialize(&argc, argv);
   benchmark::RunSpecifiedBenchmarks();
}
