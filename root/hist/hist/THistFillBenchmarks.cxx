#include "TH2.h"
#include "TH2D.h"

#include "benchmark/benchmark.h"

#include <map>
#include <vector>

// Define benchmark arguments
static void FillArguments(benchmark::internal::Benchmark *b)
{
   // Number of data points
   for(int i = 3; i <= 3000000; i *= 100)
      // Number of bins
      for(int j = 10; j <= 1000; j *= 10)
         b->Args({i, j, j / 2});
}

// Create array for x coordinates
std::vector<double> MakeXCoorVec(int nbOfDataPoints) 
{
   std::vector<double> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec.push_back(d / nbOfDataPoints);
   }
   return vec;
}

// Create array for y coordinates
std::vector<double> MakeYCoorVec(int nbOfDataPoints) 
{
   std::vector<double> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec.push_back(d / (nbOfDataPoints / 10));
   }
   return vec;
}

// Create array for weights
std::vector<double> MakeWeightVec(int nbOfDataPoints) 
{
   std::vector<double> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec.push_back(d);
   }
   return vec;
}

// Arrays of coordinates and weights
std::vector<double> xCoords = MakeXCoorVec(3000000);
std::vector<double> yCoords = MakeYCoorVec(3000000);
std::vector<double> weights = MakeWeightVec(3000000);

// Histograms with different bin configurations for Fill
TH2D hist1{"hist1", "", 10, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist2{"hist2", "", 10, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist3{"hist3", "", 10, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist4{"hist4", "", 100, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist5{"hist5", "", 100, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist6{"hist6", "", 100, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist7{"hist7", "", 1000, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist8{"hist8", "", 1000, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist9{"hist9", "", 1000, 0.1, 1., 1000 / 2, 0., 10.};

std::map<int, std::map<int, TH2D*>> histFill = { { 10, { { 5, &hist1 }, { 50, &hist2 }, { 500, &hist3} } },
                                    { 100, { { 5, &hist4 }, { 50, &hist5 }, { 500, &hist6 } } },
                                    { 1000, { { 5, &hist7 }, { 50, &hist8 }, { 500, &hist9 } } } };

static void FillHist(int nbOfDataPoints, TH2D * hist) 
{
   // Fill without weight
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
   }
   // Fill with weights
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
   }
}

// Benchmark for simple Fill on 2D hist
static void BM_THist_Fill(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFill[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state)
      FillHist(nbOfDataPoints, hist);
}
BENCHMARK(BM_THist_Fill) -> Apply(FillArguments);

// Histograms with different bin configurations for FillN
TH2D hist11{"hist11", "", 10, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist12{"hist12", "", 10, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist13{"hist13", "", 10, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist14{"hist14", "", 100, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist15{"hist15", "", 100, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist16{"hist16", "", 100, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist17{"hist17", "", 1000, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist18{"hist18", "", 1000, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist19{"hist19", "", 1000, 0.1, 1., 1000 / 2, 0., 10.};

std::map<int, std::map<int, TH2D*>> histFillN = { { 10, { { 5, &hist11 }, { 50, &hist12 }, { 500, &hist13} } },
                                    { 100, { { 5, &hist14 }, { 50, &hist15 }, { 500, &hist16 } } },
                                    { 1000, { { 5, &hist17 }, { 50, &hist18 }, { 500, &hist19 } } } };
                                    
// Benchmark for simple FillN on 2D hist
static void BM_THist_FillN(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillN[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state) {
      // FillN without weight
      hist->FillN(nbOfDataPoints, &xCoords[0], &yCoords[0], &weights[0], 1);
      // FillN with weights
      hist->FillN(nbOfDataPoints, &xCoords[0], &yCoords[0], nullptr, 1);
   }
}
BENCHMARK(BM_THist_FillN) -> Apply(FillArguments);

// Call main()
BENCHMARK_MAIN();
