#include "ROOT/RHist.hxx"
#include "ROOT/span.hxx"

#include "benchmark/benchmark.h"

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
std::vector<long long> MakeLongLongWeightVec(int nbOfDataPoints)
{
   std::vector<long long> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      long long d = static_cast< long long >(j);
      vec.push_back(d);
   }
   return vec;
}

// Arrays of coordinates and weights
static std::vector<CoordArray_t> coords = MakeCoorVec(3000000);
std::vector<long long> weightsLongLong = MakeLongLongWeightVec(3000000);

// Histograms with different bin configurations for Fill
ROOT::Experimental::RH2LL hist1LongLong{{10, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist2LongLong{{10, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist3LongLong{{10, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist4LongLong{{100, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist5LongLong{{100, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist6LongLong{{100, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist7LongLong{{1000, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist8LongLong{{1000, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist9LongLong{{1000, 0.1, 1.}, {1000 / 2, 0., 10.}};

std::map<int, std::map<int, ROOT::Experimental::RH2LL*>> histFill = { { 10, { { 5, &hist1LongLong }, { 50, &hist2LongLong }, { 500, &hist3LongLong} } },
                                                               { 100, { { 5, &hist4LongLong }, { 50, &hist5LongLong }, { 500, &hist6LongLong } } },
                                                               { 1000, { { 5, &hist7LongLong }, { 50, &hist8LongLong }, { 500, &hist9LongLong } } } };

static void FillHist(int nbOfDataPoints, ROOT::Experimental::RH2LL * hist)
{
   // Fill without weight
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)});
   }
   // Fill with weights
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      long long w = static_cast< long long >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)}, w);
   }
}

// Benchmark for simple Fill on 2D hist
static void BM_RHist_Fill_LongLong(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0);
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFill[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state)
      FillHist(nbOfDataPoints, hist);
}
BENCHMARK(BM_RHist_Fill_LongLong) -> Apply(FillArguments);

// Histograms with different bin configurations for FillN
ROOT::Experimental::RH2LL hist11LongLong{{10, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist12LongLong{{10, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist13LongLong{{10, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist14LongLong{{100, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist15LongLong{{100, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist16LongLong{{100, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist17LongLong{{1000, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist18LongLong{{1000, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2LL hist19LongLong{{1000, 0.1, 1.}, {1000 / 2, 0., 10.}};

std::map<int, std::map<int, ROOT::Experimental::RH2LL*>> histFillNLongLong = { { 10, { { 5, &hist11LongLong }, { 50, &hist12LongLong }, { 500, &hist13LongLong} } },
                                    { 100, { { 5, &hist14LongLong }, { 50, &hist15LongLong }, { 500, &hist16LongLong } } },
                                    { 1000, { { 5, &hist17LongLong }, { 50, &hist18LongLong }, { 500, &hist19LongLong } } } };

// Benchmark for simple FillN on 2D hist
static void BM_RHist_FillN_LongLong(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0);
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillNLongLong[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state) {
      // FillN with weights
      hist->FillN(std::span<const CoordArray_t>(&coords[0], nbOfDataPoints), std::span<const long long>(&weightsLongLong[0], nbOfDataPoints));
      // FillN without weight
      hist->FillN(std::span<const CoordArray_t>(&coords[0], nbOfDataPoints));
   }
}
BENCHMARK(BM_RHist_FillN_LongLong) -> Apply(FillArguments);

// // Call main()
// BENCHMARK_MAIN();
