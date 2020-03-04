#include "ROOT/RHist.hxx"
#include "ROOT/RHistConcurrentFill.hxx"

#include "benchmark/benchmark.h"

#include <iostream>
#include <future>
#include <thread>
#include <map>

// Define benchmark arguments
static void FillArguments(benchmark::internal::Benchmark *b)
{
   // Number of data points
   for(int i = 3; i <= 3000000; i *= 100)
      // Number of bins
      for(int k = 10; k <= 1000; k *= 10)
         b->Args({i, k, k / 2});
}

static void ConcurrentFillArguments(benchmark::internal::Benchmark *b)
{
   // Number of data points
   for(int i = 3; i <= 3000000; i *= 1000)
      // Number of threads
      for(int j = 1; j <= 64; j *= 8)
         // Number of bins
         for(int k = 10; k <= 1000; k *= 10)
            b->Args({i, j, k, k / 2});
}


// Histograms with different bin configurations for Fill
ROOT::Experimental::RH2D hist1{{10, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist2{{10, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist3{{10, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist4{{100, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist5{{100, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist6{{100, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist7{{1000, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist8{{1000, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2D hist9{{1000, 0.1, 1.}, {1000 / 2, 0., 10.}};

std::map<int, std::map<int, ROOT::Experimental::RH2D*>> histFill = { { 10, { { 5, &hist1 }, { 50, &hist2 }, { 500, &hist3} } },
                                                               { 100, { { 5, &hist4 }, { 50, &hist5 }, { 500, &hist6 } } },
                                                               { 1000, { { 5, &hist7 }, { 50, &hist8 }, { 500, &hist9 } } } };

static void FillHist(int nbOfDataPoints, ROOT::Experimental::RH2D * hist)
{
   // Fill without weight
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)});
   }
   // Fill with weights
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)}, d);
   }
}

// Benchmark for simple Fill on 2D hist
static void BM_RHist_Fill(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0);
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   for (auto _ : state)
      FillHist(nbOfDataPoints, histFill[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis]);
}
BENCHMARK(BM_RHist_Fill) -> Apply(FillArguments);



using Filler_t = ROOT::Experimental::RHistConcurrentFiller<ROOT::Experimental::RH2D, 1024>;

// Functions for benchmarking ConcurrentFill
void fillWithoutWeight(Filler_t filler, int nbOfDataPoints)
{
   for (int i = 0; i < nbOfDataPoints; ++i) {
      float d = static_cast< float >(i);
      filler.Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)});
   }
}

void fillWithWeights(Filler_t filler, int nbOfDataPoints)
{
   for (int i = 0; i < nbOfDataPoints; ++i) {
      float d = static_cast< float >(i);
      filler.Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)}, d);
   }
}



// Benchmark for ConcurrentFill on 2D hist
static void BM_RHist_ConcurrentFill(benchmark::State &state)
{
   int nbOfBinsForFirstAxis = state.range(2);
   int nbOfBinsForSecondAxis = state.range(3);
   ROOT::Experimental::RH2D hist{{nbOfBinsForFirstAxis, 0., 1.}, {nbOfBinsForSecondAxis, 0., 10.}};

   ROOT::Experimental::RHistConcurrentFillManager<ROOT::Experimental::RH2D> fillMgr(hist);
      
   std::size_t nbOfThreads = state.range(1);
   std::thread threads[nbOfThreads];

   for (auto _ : state) {
      // ConcurrentFill without weight
      for (auto &thr : threads) {
         thr = std::thread(fillWithoutWeight, fillMgr.MakeFiller(), state.range(0));
      }

      for (auto &thr : threads)
         thr.join();

      // ConcurrentFill with weights
      for (auto &thr : threads) {
         thr = std::thread(fillWithWeights, fillMgr.MakeFiller(), state.range(0));
      }

      for (auto &thr : threads)
         thr.join();
   }
}
BENCHMARK(BM_RHist_ConcurrentFill) -> Apply(ConcurrentFillArguments);



// Call main()
BENCHMARK_MAIN();
