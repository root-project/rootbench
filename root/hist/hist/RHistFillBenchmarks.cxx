#include "ROOT/RHist.hxx"
#include "ROOT/RHistConcurrentFill.hxx"

#include "benchmark/benchmark.h"

#include <iostream>
#include <future>
#include <thread>




// Define benchmark arguments
static void FillArguments(benchmark::internal::Benchmark *b)
{
   // Number of data points
   for(int i = 3; i <= 3000000; i *= 10)
      // Number of bins
      for(int k = 10; k <= 10000; k *= 10)
         b->Args({i, k, k / 2});
}

static void ConcurrentFillArguments(benchmark::internal::Benchmark *b)
{
   // Number of data points
   for(int i = 3; i <= 3000000; i *= 100)
      // Number of threads
      for(int j = 1; j <= 512; j *= 8)
         // Number of bins
         for(int k = 10; k <= 1000; k *= 10)
            b->Args({i, j, k, k / 2});
}



// Benchmark for simple Fill on 2D hist
static void BM_RHist_Fill(benchmark::State &state)
{
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   ROOT::Experimental::RH2D hist{{nbOfBinsForFirstAxis, 0., 1.}, {nbOfBinsForSecondAxis, 0., 10.}};

   int nbOfDataPoints = state.range(0); 
   for (auto _ : state) {
      // Fill without weight
      for (int i = 0; i < nbOfDataPoints; ++i) {
         float d = static_cast< float >(i);
         hist.Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)});
      }

      // Fill with weights
      for (int i = 0; i < nbOfDataPoints; ++i) {
         float d = static_cast< float >(i);
         hist.Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)}, d);
      }
   }
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
