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

#include <RooDataSet.h>
#include <RooGaussian.h>
#include <RooRandom.h>
#include <RooRealVar.h>
#include <RooWorkspace.h>

#include <benchmark/benchmark.h>

enum RunConfig_t { runScalar, runCpu, runCuda, fitScalar, fitCpu, fitCuda };

const size_t nEvents = 100000;
const size_t nParamSets = 30;
const auto minimizerName = "Minuit2";

class GausModel {

private:
   std::unique_ptr<RooWorkspace> _w;
   std::unique_ptr<RooAbsData> _data;
   RooAbsPdf *_pdf;
   std::string _obsName;
   std::vector<double> _results;

public:
   GausModel(std::string const &obsName, size_t nEvts)
   {

      RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

      _w = std::make_unique<RooWorkspace>("w");

      // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
      RooRealVar x("x", "x", -1.5, 40.5);

      RooRealVar mean("mean", "mean of gaussian", 20., 15., 25.);
      RooRealVar sigma("sigma", "width of gaussian", 10., 8., 12.);

      // Build gaussian p.d.f in terms of x,mean and sigma
      RooGaussian gauss("gauss", "gaussian PDF", x, mean, sigma);

      _w->import(gauss);

      _w->defineSet("obs", obsName.c_str());

      _pdf = _w->pdf("gauss");

      generateData(nEvts);
   }
   RooAbsPdf &GetPdf() { return *_pdf; }
   RooAbsData &GetData() { return *_data; }

   void randomiseParameters(ULong_t seed = 0)
   {
      RooArgSet parameters;
      _pdf->getParameters(_data->get(), parameters);
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

   void generateData(size_t nEvts)
   {
      _data = std::unique_ptr<RooAbsData>(_pdf->generate(*_w->set("obs"), nEvts));
      // allocate here output vector
      _results = std::vector<double>(nEvts);
   }
   void EvalScalar()
   {
      for (unsigned int i = 0; i < _data->sumEntries(); ++i) {
         auto observables = _data->get(i);
         _results[i] = _pdf->getLogVal(observables);
      }
   }
   void EvalBatchCpu() { _results = _pdf->getValues(*_data, RooFit::BatchModeOption::Cpu); }
   void EvalBatchCuda() { _results = _pdf->getValues(*_data, RooFit::BatchModeOption::Cuda); }
};

static void benchEvalGauss(benchmark::State &state)
{
   RunConfig_t runConfig = static_cast<RunConfig_t>(state.range(0));

   GausModel model("x", nEvents);

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
      using namespace RooFit;

      if (runConfig == fitScalar) {
         pdf.fitTo(data, BatchMode("off"), Minimizer(minimizerName), PrintLevel(-1));
      } else if (runConfig == fitCpu) {
         pdf.fitTo(data, BatchMode("cpu"), Minimizer(minimizerName), PrintLevel(-1));
      } else if (runConfig == fitCuda) {
         pdf.fitTo(data, BatchMode("cuda"), Minimizer(minimizerName), PrintLevel(-1));
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
      using namespace RooFit;

      if (runConfig == fitScalar) {
         pdf.fitTo(data, BatchMode("off"), Minimizer(minimizerName), RooFit::PrintLevel(-1));
      } else if (runConfig == fitCpu) {
         pdf.fitTo(data, BatchMode("cpu"), Minimizer(minimizerName), PrintLevel(-1));
      } else if (runConfig == fitCuda) {
         pdf.fitTo(data, BatchMode("cuda"), Minimizer(minimizerName), PrintLevel(-1));
      }
   }
}

BENCHMARK(benchEvalGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_EvalScalar")->Args({runScalar});
BENCHMARK(benchEvalGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_EvalBatchCPU")->Args({runCpu});
#ifdef R__HAS_CUDA
BENCHMARK(benchEvalGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_EvalBatchCUDA")->Args({runCuda});
#endif

BENCHMARK(benchEvalGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_EvalScalar")->Args({runScalar});
BENCHMARK(benchEvalGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_EvalBatchCPU")->Args({runCpu});
#ifdef R__HAS_CUDA
BENCHMARK(benchEvalGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_EvalBatchCUDA")->Args({runCuda});
#endif

BENCHMARK(benchFitGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_FitScalar")->Args({fitScalar});
BENCHMARK(benchFitGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_FitBatchCPU")->Args({fitCpu});
#ifdef R__HAS_CUDA
BENCHMARK(benchFitGauss)->Unit(benchmark::kMillisecond)->Name("benchGaus_FitBatchCUDA")->Args({fitCuda});
#endif

BENCHMARK(benchFitGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_FitScalar")->Args({fitScalar});
BENCHMARK(benchFitGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_FitBatchCPU")->Args({fitCpu});
#ifdef R__HAS_CUDA
BENCHMARK(benchFitGaussXSigma)->Unit(benchmark::kMillisecond)->Name("benchGausXS_FitBatchCUDA")->Args({fitCuda});
#endif

BENCHMARK_MAIN();
