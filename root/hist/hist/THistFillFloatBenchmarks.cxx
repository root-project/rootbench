#include "TH2.h"
#include "TH2F.h"

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
static std::vector<double> xCoords = MakeXCoorVec(3000000);
static std::vector<double> yCoords = MakeYCoorVec(3000000);
std::vector<float> weightsFloat = MakeFloatWeightVec(3000000);

// Histograms with different bin configurations for Fill
TH2F hist1Float{"hist1Float", "", 10, 0.1, 1., 10 / 2, 0., 10.};
TH2F hist2Float{"hist2Float", "", 10, 0.1, 1., 100 / 2, 0., 10.};
TH2F hist3Float{"hist3Float", "", 10, 0.1, 1., 1000 / 2, 0., 10.};
TH2F hist4Float{"hist4Float", "", 100, 0.1, 1., 10 / 2, 0., 10.};
TH2F hist5Float{"hist5Float", "", 100, 0.1, 1., 100 / 2, 0., 10.};
TH2F hist6Float{"hist6Float", "", 100, 0.1, 1., 1000 / 2, 0., 10.};
TH2F hist7Float{"hist7Float", "", 1000, 0.1, 1., 10 / 2, 0., 10.};
TH2F hist8Float{"hist8Float", "", 1000, 0.1, 1., 100 / 2, 0., 10.};
TH2F hist9Float{"hist9Float", "", 1000, 0.1, 1., 1000 / 2, 0., 10.};

std::map<int, std::map<int, TH2F*>> histFillFloat = { { 10, { { 5, &hist1Float }, { 50, &hist2Float }, { 500, &hist3Float} } },
                                    { 100, { { 5, &hist4Float }, { 50, &hist5Float }, { 500, &hist6Float } } },
                                    { 1000, { { 5, &hist7Float }, { 50, &hist8Float }, { 500, &hist9Float } } } };

static void FillHist(int nbOfDataPoints, TH2F * hist) 
{
   // Fill without weight
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      hist->Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
   }
   // Fill with weights
   for (int i = 0; i < nbOfDataPoints; ++i) {
      double d = static_cast< double >(i);
      float w = static_cast< float >(i);
      hist->Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), w);
   }
}

// Benchmark for simple Fill on 2D hist
static void BM_THist_Fill_Float(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillFloat[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state)
      FillHist(nbOfDataPoints, hist);
}
BENCHMARK(BM_THist_Fill_Float) -> Apply(FillArguments);

// Histograms with different bin configurations for FillN
TH2F hist11Float{"hist11Float", "", 10, 0.1, 1., 10 / 2, 0., 10.};
TH2F hist12Float{"hist12Float", "", 10, 0.1, 1., 100 / 2, 0., 10.};
TH2F hist13Float{"hist13Float", "", 10, 0.1, 1., 1000 / 2, 0., 10.};
TH2F hist14Float{"hist14Float", "", 100, 0.1, 1., 10 / 2, 0., 10.};
TH2F hist15Float{"hist15Float", "", 100, 0.1, 1., 100 / 2, 0., 10.};
TH2F hist16Float{"hist16Float", "", 100, 0.1, 1., 1000 / 2, 0., 10.};
TH2F hist17Float{"hist17Float", "", 1000, 0.1, 1., 10 / 2, 0., 10.};
TH2F hist18Float{"hist18Float", "", 1000, 0.1, 1., 100 / 2, 0., 10.};
TH2F hist19Float{"hist19Float", "", 1000, 0.1, 1., 1000 / 2, 0., 10.};

std::map<int, std::map<int, TH2F*>> histFillNFloat = { { 10, { { 5, &hist11Float }, { 50, &hist12Float }, { 500, &hist13Float} } },
                                    { 100, { { 5, &hist14Float }, { 50, &hist15Float }, { 500, &hist16Float } } },
                                    { 1000, { { 5, &hist17Float }, { 50, &hist18Float }, { 500, &hist19Float } } } };
                                    
// Benchmark for simple FillN on 2D hist
static void BM_THist_FillN_Float(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   auto hist = histFillNFloat[nbOfBinsForFirstAxis][nbOfBinsForSecondAxis];

   for (auto _ : state) {
      // FillN with weights
      hist->FillN(nbOfDataPoints, &xCoords[0], &yCoords[0], (double*) &weightsFloat[0], 1);
      // FillN without weight
      hist->FillN(nbOfDataPoints, &xCoords[0], &yCoords[0], NULL, 1);
   }
}
BENCHMARK(BM_THist_FillN_Float) -> Apply(FillArguments);

// // Call main()
// BENCHMARK_MAIN();
