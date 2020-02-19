#include "TH2.h"
#include "TH2D.h"

#include "benchmark/benchmark.h"




// Define benchmark arguments
static void FillArguments(benchmark::internal::Benchmark *b)
{
   // Number of data points
   for(int i = 3; i <= 3000000; i *= 100)
      // Number of bins
      for(int j = 10; j <= 1000; j *= 10)
         b->Args({i, j, j / 2});
}



// Benchmark for simple Fill on 2D hist
static void BM_THist_Fill(benchmark::State &state)
{
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   TH2D hist{"hist", "", nbOfBinsForFirstAxis, 0., 1., nbOfBinsForSecondAxis, 0., 10.};

   int nbOfDataPoints = state.range(0); 
   for (auto _ : state) {
      // Fill without weight
      for (int i = 0; i < nbOfDataPoints; ++i) {
         double d = static_cast< double >(i);
         hist.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
      }

      // Fill with weights
      for (int i = 0; i < nbOfDataPoints; ++i) {
         double d = static_cast< double >(i);
         hist.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
      }
   }
}
BENCHMARK(BM_THist_Fill) -> Apply(FillArguments);



// Benchmark for simple FillN on 2D hist
static void BM_THist_FillN(benchmark::State &state)
{
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   TH2D hist{"hist", "", nbOfBinsForFirstAxis, 0., 1., nbOfBinsForSecondAxis, 0., 10.};

   int nbOfDataPoints = state.range(0); 
   double * xCoords = new double[nbOfDataPoints];
   double * yCoords = new double[nbOfDataPoints];
   double * weights = new double[nbOfDataPoints];

   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      xCoords[i] = d / nbOfDataPoints;
      yCoords[i] = d / (nbOfDataPoints / 10);
      weights[i] = d;
   }

   for (auto _ : state) {
      // FillN without weight
      hist.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
      // FillN with weights
      hist.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
   }

   delete[] xCoords;
   delete[] yCoords;
   delete[] weights;
}
BENCHMARK(BM_THist_FillN) -> Apply(FillArguments);



// Call main()
BENCHMARK_MAIN();
