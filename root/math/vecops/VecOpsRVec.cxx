#include "ROOT/RVec.hxx"
#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"

using namespace ROOT::VecOps;


static void GetArguments(benchmark::internal::Benchmark* b)
{
   for (const auto i : {1, 2, 4, 8, 16, 32, 64})
      b->Arg(i);
}


template <class T>
static void RVecAssign(benchmark::State &state)
{
   const auto size = state.range(0);
   RVec<T> v1(size);
   RVec<T> v2(size);
   for (auto _ : state) {
      v2 = v1;
      benchmark::DoNotOptimize(v2);
   }
}
BENCHMARK_TEMPLATE(RVecAssign, float)->Apply(GetArguments);


template <class T>
static void RVecAdd(benchmark::State &state)
{
   const auto size = state.range(0);
   RVec<T> v1(size);
   RVec<T> v2(size);
   for (auto _ : state) {
      benchmark::DoNotOptimize(v1 + v2);
   }
}
BENCHMARK_TEMPLATE(RVecAdd, float)->Apply(GetArguments);


template <class T>
static void RVecSquareAddSqrt(benchmark::State &state)
{
   const auto size = state.range(0);
   RVec<T> v1(size);
   RVec<T> v2(size);
   for (auto _ : state) {
      benchmark::DoNotOptimize(sqrt(pow(v1, 2) + pow(v2, 2)));
   }
}
BENCHMARK_TEMPLATE(RVecSquareAddSqrt, float)->Apply(GetArguments);


template <class T>
static void RVecDeltaR(benchmark::State &state)
{
   const auto size = state.range(0);
   RVec<T> eta1(size);
   RVec<T> eta2(size);
   RVec<T> phi1(size);
   RVec<T> phi2(size);
   for (auto _ : state) {
      benchmark::DoNotOptimize(DeltaR(eta1, eta2, phi1, phi2));
   }
}
BENCHMARK_TEMPLATE(RVecDeltaR, float)->Apply(GetArguments);


template <class T>
static void RVecInvariantMass(benchmark::State &state)
{
   const auto size = state.range(0);
   RVec<T> pt(size);
   RVec<T> eta(size);
   RVec<T> phi(size);
   RVec<T> mass(size);
   for (auto _ : state) {
      benchmark::DoNotOptimize(InvariantMass(pt, eta, phi, mass));
   }
}
BENCHMARK_TEMPLATE(RVecInvariantMass, float)->Apply(GetArguments);


template <class T>
static void RVecInvariantMasses(benchmark::State &state)
{
   const auto size = state.range(0);
   RVec<T> pt1(size);
   RVec<T> pt2(size);
   RVec<T> eta1(size);
   RVec<T> eta2(size);
   RVec<T> phi1(size);
   RVec<T> phi2(size);
   RVec<T> mass1(size);
   RVec<T> mass2(size);
   for (auto _ : state) {
      benchmark::DoNotOptimize(InvariantMasses(pt1, eta1, phi1, mass1, pt2, eta2, phi2, mass2));
   }
}
BENCHMARK_TEMPLATE(RVecInvariantMasses, float)->Apply(GetArguments);


template <class T>
RVec<T> GenerateSeq(const unsigned int size)
{
   RVec<T> v(size);
   for (auto i = 0u; i < size; i++)
      v[i] = i;
   return v;
}


template <class T>
static void RVecMaskingSimple(benchmark::State &state)
{
   const auto size = state.range(0);
   auto v = GenerateSeq<T>(size);
   for (auto _ : state) {
      benchmark::DoNotOptimize(v[v > 0.5 * size]);
   }
}
BENCHMARK_TEMPLATE(RVecMaskingSimple, float)->Apply(GetArguments);


template <class T>
static void RVecMaskingComplex(benchmark::State &state)
{
   const auto size = state.range(0);
   auto v1 = GenerateSeq<T>(size);
   auto v2 = GenerateSeq<T>(size);
   for (auto _ : state) {
      benchmark::DoNotOptimize(v2[v1 > 0.5 * size && v2 < 0.75 * size && v1 + v2 > 0]);
   }
}
BENCHMARK_TEMPLATE(RVecMaskingComplex, float)->Apply(GetArguments);


BENCHMARK_MAIN();
