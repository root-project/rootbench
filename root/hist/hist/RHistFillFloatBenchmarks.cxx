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
std::vector<float> MakeFloatWeightVec(int nbOfDataPoints)
{
   std::vector<float> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      float d = static_cast< float >(j);
      vec.push_back(d);
   }
   return vec;
}

// Arrays of coordinates and weights
static std::vector<CoordArray_t> coords = MakeCoorVec(3000000);
std::vector<float> weightsFloat = MakeFloatWeightVec(3000000);

// Histograms with different bin configurations for Fill
ROOT::Experimental::RH2F hist1Float{{10, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist2Float{{10, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist3Float{{10, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist4Float{{100, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist5Float{{100, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist6Float{{100, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist7Float{{1000, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist8Float{{1000, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist9Float{{1000, 0.1, 1.}, {1000 / 2, 0., 10.}};

std::map<int, std::map<int, ROOT::Experimental::RH2F*>> histFillFloat = { { 10, { { 5, &hist1Float }, { 50, &hist2Float }, { 500, &hist3Float} } },
                                                               { 100, { { 5, &hist4Float }, { 50, &hist5Float }, { 500, &hist6Float } } },
                                                               { 1000, { { 5, &hist7Float }, { 50, &hist8Float }, { 500, &hist9Float } } } };

static void FillHist(int nbOfDataPoints, ROOT::Experimental::RH2F * hist)
{
   // Fill without weight
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)});
   }
   // Fill with weights
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      float w = static_cast< float >(i);
      hist->Fill({d / nbOfDataPoints, d / (nbOfDataPoints / 10)}, w);
   }
}

// Benchmark for simple Fill on 2D hist
static void BM_RHist_Fill_Float(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0);
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillFloat[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state)
      FillHist(nbOfDataPoints, hist);
}
BENCHMARK(BM_RHist_Fill_Float) -> Apply(FillArguments);

// Histograms with different bin configurations for FillN
ROOT::Experimental::RH2F hist11Float{{10, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist12Float{{10, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist13Float{{10, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist14Float{{100, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist15Float{{100, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist16Float{{100, 0.1, 1.}, {1000 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist17Float{{1000, 0.1, 1.}, {10 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist18Float{{1000, 0.1, 1.}, {100 / 2, 0., 10.}};
ROOT::Experimental::RH2F hist19Float{{1000, 0.1, 1.}, {1000 / 2, 0., 10.}};

std::map<int, std::map<int, ROOT::Experimental::RH2F*>> histFillNFloat = { { 10, { { 5, &hist11Float }, { 50, &hist12Float }, { 500, &hist13Float} } },
                                    { 100, { { 5, &hist14Float }, { 50, &hist15Float }, { 500, &hist16Float } } },
                                    { 1000, { { 5, &hist17Float }, { 50, &hist18Float }, { 500, &hist19Float } } } };

// Benchmark for simple FillN on 2D hist
static void BM_RHist_FillN_Float(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0);
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillNFloat[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state) {
      // FillN with weights
      hist->FillN(std::span<const CoordArray_t>(&coords[0], nbOfDataPoints), std::span<const float>(&weightsFloat[0], nbOfDataPoints));
      // FillN without weight
      hist->FillN(std::span<const CoordArray_t>(&coords[0], nbOfDataPoints));
   }
}
BENCHMARK(BM_RHist_FillN_Float) -> Apply(FillArguments);

// // Call main()
// BENCHMARK_MAIN();
