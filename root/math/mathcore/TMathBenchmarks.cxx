#include <cmath>
#include <random>

#include "TMath.h"
#include "VectorizedTMath.h"

#include "benchmark/benchmark.h"

#include <sstream>

inline Double_t uniform_random(Double_t a, Double_t b)
{
    return a + (b - a) * drand48();
}

#define BENCHMARK_TMATH_FUNCTION(tmathfunc, a, b)              \
  static void BM_TMath##_##tmathfunc(benchmark::State &state)  \
  {                                                            \
      Double_t input_array1[16384];                            \
      Double_t output_array[16384];                            \
                                                               \
      for(int i = 0;i < 16384;i++)                             \
          input_array1[i] = uniform_random(a, b);              \
                                                               \
      while(state.KeepRunning()) {                             \
          for(int i = 0;i < 16384;i++)                         \
              output_array[i] = TMath::tmathfunc(input_array1[i]);   \
      }                                                        \
  }

#define BENCHMARK_VECTORIZED_TMATH_FUNCTION(tmathfunc, a, b)             \
  static void BM_VectorizedTMath##_##tmathfunc(benchmark::State &state)  \
  {                                                                      \
      size_t kVs = vecCore::VectorSize<ROOT::Double_v>();                \
      Double_t input_array1[16384] __attribute__((aligned(VECCORE_SIMD_ALIGN))); \
      Double_t output_array[16384] __attribute__((aligned(VECCORE_SIMD_ALIGN))); \
                                                               \
      for(int i = 0;i < 16384;i++)                             \
          input_array1[i] = uniform_random(a, b);            \
                                                               \
      while(state.KeepRunning()) {                             \
          for(int i = 0;i < 16384;i+=kVs) {                        \
              ROOT::Double_v x;                                    \
              vecCore::Load<ROOT::Double_v>(x, &input_array1[i]);  \
              vecCore::Store<ROOT::Double_v>(TMath::tmathfunc(x), &output_array[i]); \
          }                                                        \
      }                                                            \
  }

BENCHMARK_TMATH_FUNCTION(Log2, 1, FLT_MAX);
BENCHMARK_TMATH_FUNCTION(BreitWigner, -1e10, 1e10);
BENCHMARK_TMATH_FUNCTION(Gaus, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_TMATH_FUNCTION(LaplaceDist, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_TMATH_FUNCTION(LaplaceDistI, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_TMATH_FUNCTION(Freq, -6, 6);
BENCHMARK_TMATH_FUNCTION(BesselI0, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_TMATH_FUNCTION(BesselI1, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_TMATH_FUNCTION(BesselJ0, 0, 1e5);
BENCHMARK_TMATH_FUNCTION(BesselJ1, 0, 1e5);

BENCHMARK(BM_TMath_Log2);
BENCHMARK(BM_TMath_BreitWigner);
BENCHMARK(BM_TMath_Gaus);
BENCHMARK(BM_TMath_LaplaceDist);
BENCHMARK(BM_TMath_LaplaceDistI);
BENCHMARK(BM_TMath_Freq);
BENCHMARK(BM_TMath_BesselI0);
BENCHMARK(BM_TMath_BesselI1);
BENCHMARK(BM_TMath_BesselJ0);
BENCHMARK(BM_TMath_BesselJ1);

BENCHMARK_VECTORIZED_TMATH_FUNCTION(Log2, 1, FLT_MAX);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(BreitWigner, -1e10, 1e10);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(Gaus, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(LaplaceDist, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(LaplaceDistI, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(Freq, -6, 6);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(BesselI0, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(BesselI1, FLT_MIN_10_EXP, FLT_MAX_10_EXP);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(BesselJ0, 0, 1e5);
BENCHMARK_VECTORIZED_TMATH_FUNCTION(BesselJ1, 0, 1e5);

BENCHMARK(BM_VectorizedTMath_Log2);
BENCHMARK(BM_VectorizedTMath_BreitWigner);
BENCHMARK(BM_VectorizedTMath_Gaus);
BENCHMARK(BM_VectorizedTMath_LaplaceDist);
BENCHMARK(BM_VectorizedTMath_LaplaceDistI);
BENCHMARK(BM_VectorizedTMath_Freq);
BENCHMARK(BM_VectorizedTMath_BesselI0);
BENCHMARK(BM_VectorizedTMath_BesselI1);
BENCHMARK(BM_VectorizedTMath_BesselJ0);
BENCHMARK(BM_VectorizedTMath_BesselJ1);

BENCHMARK_MAIN();