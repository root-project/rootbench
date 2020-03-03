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

// Create array for x coordinates
double * MakeXCoorVec(int nbOfDataPoints) 
{
   double * vec = new double[nbOfDataPoints];
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec[j] = d / nbOfDataPoints;
   }
   return vec;
}

// Create array for y coordinates
double * MakeYCoorVec(int nbOfDataPoints) 
{
   double * vec = new double[nbOfDataPoints];
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec[j] = d / (nbOfDataPoints / 10);
   }
   return vec;
}

// Create array for weights
double * MakeWeightVec(int nbOfDataPoints) 
{
   double * vec = new double[nbOfDataPoints];
   for (int j = 0; j < nbOfDataPoints; ++j) {
      double d = static_cast< double >(j);
      vec[j] = d;
   }
   return vec;
}

// Arrays of coordinates and weights
double * xCoords = MakeXCoorVec(3000000);
double * yCoords = MakeYCoorVec(3000000);
double * weights = MakeWeightVec(3000000);

// Histograms with different bin configurations for Fill
TH2D hist1{"hist1", "", 10, 0., 1., 10 / 2, 0., 10.};
TH2D hist2{"hist2", "", 10, 0., 1., 100 / 2, 0., 10.};
TH2D hist3{"hist3", "", 10, 0., 1., 1000 / 2, 0., 10.};
TH2D hist4{"hist4", "", 100, 0., 1., 10 / 2, 0., 10.};
TH2D hist5{"hist5", "", 100, 0., 1., 100 / 2, 0., 10.};
TH2D hist6{"hist6", "", 100, 0., 1., 1000 / 2, 0., 10.};
TH2D hist7{"hist7", "", 1000, 0., 1., 10 / 2, 0., 10.};
TH2D hist8{"hist8", "", 1000, 0., 1., 100 / 2, 0., 10.};
TH2D hist9{"hist9", "", 1000, 0., 1., 1000 / 2, 0., 10.};

// Benchmark for simple Fill on 2D hist
static void BM_THist_Fill(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   for (auto _ : state) {
      if (nbOfBinsForFirstAxis == 10) {
         if (nbOfBinsForSecondAxis == 5) {
            // Fill without weight
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist1.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            // Fill with weights
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist1.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
         if (nbOfBinsForSecondAxis == 50) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist2.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist2.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
         if (nbOfBinsForSecondAxis == 500) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist3.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist3.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
      } else if (nbOfBinsForFirstAxis == 100) {
         if (nbOfBinsForSecondAxis == 5) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist4.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist4.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
         if (nbOfBinsForSecondAxis == 50) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist5.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist5.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
         if (nbOfBinsForSecondAxis == 500) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist6.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist6.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
      } else {
         if (nbOfBinsForSecondAxis == 5) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist7.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist7.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
         if (nbOfBinsForSecondAxis == 50) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist8.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist8.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
         if (nbOfBinsForSecondAxis == 500) {
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist9.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10));
            }
            for (int i = 0; i < nbOfDataPoints; ++i) {
               double d = static_cast< double >(i);
               hist9.Fill(d / nbOfDataPoints, d / (nbOfDataPoints / 10), d);
            }
         }
      }
   }
}
BENCHMARK(BM_THist_Fill) -> Apply(FillArguments);

// Histograms with different bin configurations for FillN
TH2D hist11{"hist11", "", 10, 0., 1., 10 / 2, 0., 10.};
TH2D hist12{"hist12", "", 10, 0., 1., 100 / 2, 0., 10.};
TH2D hist13{"hist13", "", 10, 0., 1., 1000 / 2, 0., 10.};
TH2D hist14{"hist14", "", 100, 0., 1., 10 / 2, 0., 10.};
TH2D hist15{"hist15", "", 100, 0., 1., 100 / 2, 0., 10.};
TH2D hist16{"hist16", "", 100, 0., 1., 1000 / 2, 0., 10.};
TH2D hist17{"hist17", "", 1000, 0., 1., 10 / 2, 0., 10.};
TH2D hist18{"hist18", "", 1000, 0., 1., 100 / 2, 0., 10.};
TH2D hist19{"hist19", "", 1000, 0., 1., 1000 / 2, 0., 10.};

// Benchmark for simple FillN on 2D hist
static void BM_THist_FillN(benchmark::State &state)
{
   int nbOfDataPoints = state.range(0); 
   int nbOfBinsForFirstAxis = state.range(1);
   int nbOfBinsForSecondAxis = state.range(2);

   for (auto _ : state) {
      if (nbOfBinsForFirstAxis == 10) {
         if (nbOfBinsForSecondAxis == 5) {
            // FillN without weight
            hist11.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            // FillN with weights
            hist11.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
         if (nbOfBinsForSecondAxis == 50) {
            hist12.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist12.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
         if (nbOfBinsForSecondAxis == 500) {
            hist13.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist13.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
      } else if (nbOfBinsForFirstAxis == 100) {
         if (nbOfBinsForSecondAxis == 5) {
            hist14.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist14.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
         if (nbOfBinsForSecondAxis == 50) {
            hist15.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist15.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
         if (nbOfBinsForSecondAxis == 500) {
            hist16.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist16.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
      } else {
         if (nbOfBinsForSecondAxis == 5) {
            hist17.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist17.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
         if (nbOfBinsForSecondAxis == 50) {
            hist18.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist18.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
         if (nbOfBinsForSecondAxis == 500) {
            hist19.FillN(nbOfDataPoints, xCoords, yCoords, weights, 1);
            hist19.FillN(nbOfDataPoints, xCoords, yCoords, NULL, 1);
         }
      }
   }
}
BENCHMARK(BM_THist_FillN) -> Apply(FillArguments);

// Call main()
BENCHMARK_MAIN();
