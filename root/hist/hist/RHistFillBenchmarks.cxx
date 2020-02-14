#include "ROOT/RHist.hxx"
#include "ROOT/RHistConcurrentFill.hxx"

#include "benchmark/benchmark.h"

#include <iostream>
#include <future>



// Benchmark for simple Fill on 2D hist
static void BM_RHist_Fill(benchmark::State &state)
{
   ROOT::Experimental::RH2D hist{{100, 0., 1.}, {{0., 1., 2., 3., 10.}}};

   for (auto _ : state) {
      // Fill without weight
      for (int i = 0; i < 3000; ++i) {
         hist.Fill({(double)i / 100, (double)i / 10});
      }

      // Fill with weights
      for (int i = 0; i < 3000; ++i) {
         hist.Fill({(double)i / 100, (double)i / 10});
      }
   }
}
BENCHMARK(BM_RHist_Fill);



using Filler_t = ROOT::Experimental::RHistConcurrentFiller<ROOT::Experimental::RH2D, 1024>;

// Functions for benchmarking ConcurrentFill
void fillWithoutWeight(Filler_t filler)
{
   for (int i = 0; i < 3000; ++i) {
      filler.Fill({(double)i / 100, (double)i / 10});
   }
}

void fillWithWeights(Filler_t filler)
{
   for (int i = 0; i < 3000; ++i) {
      filler.Fill({(double)i / 100, (double)i / 10}, (float)i);
   }
}



// Benchmark for ConcurrentFill on 2D hist
static void BM_RHist_ConcurrentFill(benchmark::State &state)
{
   ROOT::Experimental::RH2D hist{{100, 0., 1.}, {{0., 1., 2., 3., 10.}}};

   ROOT::Experimental::RHistConcurrentFillManager<ROOT::Experimental::RH2D> fillMgr(hist);
      
   std::array<std::thread, 2> threads;

   for (auto _ : state) {
      // ConcurrentFill without weight
      for (auto &thr : threads) {
         thr = std::thread(fillWithoutWeight, fillMgr.MakeFiller());
      }

      for (auto &thr : threads)
         thr.join();

      // ConcurrentFill with weights
      for (auto &thr : threads) {
         thr = std::thread(fillWithWeights, fillMgr.MakeFiller());
      }

      for (auto &thr : threads)
         thr.join();
   }
}
BENCHMARK(BM_RHist_ConcurrentFill);



// Call main()
BENCHMARK_MAIN();