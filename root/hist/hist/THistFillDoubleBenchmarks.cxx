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
static std::vector<double> MakeXCoorVec(int nbOfDataPoints) 
{
   std::vector<double> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec.push_back(d / nbOfDataPoints);
   }
   return vec;
}

// Create array for y coordinates
static std::vector<double> MakeYCoorVec(int nbOfDataPoints) 
{
   std::vector<double> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec.push_back(d / (nbOfDataPoints / 10));
   }
   return vec;
}

// Create array for weights
std::vector<double> MakeDoubleWeightVec(int nbOfDataPoints) 
{
   std::vector<double> vec;
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec.push_back(d);
   }
   return vec;
}

// Arrays of coordinates and weights
static std::vector<double> xCoords = MakeXCoorVec(3000000);
static std::vector<double> yCoords = MakeYCoorVec(3000000);
std::vector<double> weightsDouble = MakeDoubleWeightVec(3000000);

// Histograms with different bin configurations for Fill
TH2D hist1Double{"hist1Double", "", 10, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist2Double{"hist2Double", "", 10, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist3Double{"hist3Double", "", 10, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist4Double{"hist4Double", "", 100, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist5Double{"hist5Double", "", 100, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist6Double{"hist6Double", "", 100, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist7Double{"hist7Double", "", 1000, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist8Double{"hist8Double", "", 1000, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist9Double{"hist9Double", "", 1000, 0.1, 1., 1000 / 2, 0., 10.};

std::map<int, std::map<int, TH2D*>> histFillDouble = { { 10, { { 5, &hist1Double }, { 50, &hist2Double }, { 500, &hist3Double} } },
                                    { 100, { { 5, &hist4Double }, { 50, &hist5Double }, { 500, &hist6Double } } },
                                    { 1000, { { 5, &hist7Double }, { 50, &hist8Double }, { 500, &hist9Double } } } };

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
static void BM_THist_Fill_Double(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillDouble[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state)
      FillHist(nbOfDataPoints, hist);
}
BENCHMARK(BM_THist_Fill_Double) -> Apply(FillArguments);

// Histograms with different bin configurations for FillN
TH2D hist11Double{"hist11Double", "", 10, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist12Double{"hist12Double", "", 10, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist13Double{"hist13Double", "", 10, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist14Double{"hist14Double", "", 100, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist15Double{"hist15Double", "", 100, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist16Double{"hist16Double", "", 100, 0.1, 1., 1000 / 2, 0., 10.};
TH2D hist17Double{"hist17Double", "", 1000, 0.1, 1., 10 / 2, 0., 10.};
TH2D hist18Double{"hist18Double", "", 1000, 0.1, 1., 100 / 2, 0., 10.};
TH2D hist19Double{"hist19Double", "", 1000, 0.1, 1., 1000 / 2, 0., 10.};

std::map<int, std::map<int, TH2D*>> histFillNDouble = { { 10, { { 5, &hist11Double }, { 50, &hist12Double }, { 500, &hist13Double} } },
                                    { 100, { { 5, &hist14Double }, { 50, &hist15Double }, { 500, &hist16Double } } },
                                    { 1000, { { 5, &hist17Double }, { 50, &hist18Double }, { 500, &hist19Double } } } };
                                    
// Benchmark for simple FillN on 2D hist
static void BM_THist_FillN_Double(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillNDouble[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state) {
      // FillN without weight
      hist->FillN(nbOfDataPoints, &xCoords[0], &yCoords[0], &weightsDouble[0], 1);
      // FillN with weights
      hist->FillN(nbOfDataPoints, &xCoords[0], &yCoords[0], NULL, 1);
   }
}
BENCHMARK(BM_THist_FillN_Double) -> Apply(FillArguments);

// Call main()
BENCHMARK_MAIN();
