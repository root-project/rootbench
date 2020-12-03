#include "ROOT/RHist.hxx"
#include "ROOT/span.hxx"

#include "benchmark/benchmark.h"

#include <iostream>
#include <future>
#include <thread>
#include <map>
#include <vector>

// Define benchmark arguments
static void FillArguments(benchmark::internal::Benchmark *b)
{
   // Number of data points
   for(int i = 3; i <= 3000000; i *= 100)
      // Number of bins
      for(int k = 10; k <= 1000; k *= 10)
         b->Args({i, k, k / 2});
}

using CoordArray_t = ROOT::Experimental::Hist::RCoordArray<2>;

// Create array for x coordinates
static std::vector<CoordArray_t> MakeCoorVec(int nbOfDataPoints)
{
   std::vector<CoordArray_t> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec.push_back({ d / nbOfDataPoints, d / (nbOfDataPoints / 10) });
   }
   return vec;
}

// Create array for weights
std::vector<int> MakeIntWeightVec(int nbOfDataPoints)
{
   std::vector<int> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      int d = static_cast< int >(j);
      vec.push_back(d);
   }
   return vec;
}

// Arrays of coordinates and weights
static std::vector<CoordArray_t> coords = MakeCoorVec(3000000);
std::vector<int> weightsInt = MakeIntWeightVec(3000000);

// Histograms with different bin configurations for Fill
ROOT::Experimental::RH2I hist1Int{{10, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist2Int{{10, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist3Int{{10, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist4Int{{100, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist5Int{{100, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist6Int{{100, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist7Int{{1000, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist8Int{{1000, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist9Int{{1000, 0.1, 1.}, {1000 / 2, 0., 10.}};

std::map<int, std::map<int, ROOT::Experimental::RH2I*>> histFillInt = { { 10, { { 5, &hist1Int }, { 50, &hist2Int }, { 500, &hist3Int} } },
                                                               { 100, { { 5, &hist4Int }, { 50, &hist5Int }, { 500, &hist6Int } } },
                                                               { 1000, { { 5, &hist7Int }, { 50, &hist8Int }, { 500, &hist9Int } } } };

static void FillHist(int nbOfDataPoints, ROOT::Experimental::RH2I * hist)
{
   // Fill without weight
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)});
   }
   // Fill with weights
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      int w = static_cast< int >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)}, w);
   }
}

// Benchmark for simple Fill on 2D hist
static void BM_RHist_Fill_Int(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0);
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillInt[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state)
      FillHist(nbOfDataPoints, hist);
}
BENCHMARK(BM_RHist_Fill_Int) -> Apply(FillArguments);

// Histograms with different bin configurations for FillN
ROOT::Experimental::RH2I hist11Int{{10, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist12Int{{10, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist13Int{{10, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist14Int{{100, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist15Int{{100, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist16Int{{100, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist17Int{{1000, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist18Int{{1000, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2I hist19Int{{1000, 0.1, 1.}, {1000 / 2, 0., 10.}};

std::map<int, std::map<int, ROOT::Experimental::RH2I*>> histFillNInt = { { 10, { { 5, &hist11Int }, { 50, &hist12Int }, { 500, &hist13Int} } },
                                    { 100, { { 5, &hist14Int }, { 50, &hist15Int }, { 500, &hist16Int } } },
                                    { 1000, { { 5, &hist17Int }, { 50, &hist18Int }, { 500, &hist19Int } } } };

// Benchmark for simple FillN on 2D hist
static void BM_RHist_FillN_Int(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0);
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillNInt[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state) {
      // FillN with weights
      hist->FillN(std::span<const CoordArray_t>(&coords[0], nbOfDataPoints), std::span<const int>(&weightsInt[0], nbOfDataPoints));
      // FillN without weight
      hist->FillN(std::span<const CoordArray_t>(&coords[0], nbOfDataPoints));
   }
}
BENCHMARK(BM_RHist_FillN_Int) -> Apply(FillArguments);

// // Call main()
// BENCHMARK_MAIN();
