#include "RDataFrameBench.h"
#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include <TFile.h>
#include <TSystem.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <stdio.h>
#include <benchmark/benchmark.h>

#include <cstdlib> // abort
#include <vector>
#include <cstring>


using ROOT::RVec;

static constexpr auto treeName = "Events";
static constexpr auto fileName = "data.root";
static constexpr auto scalarBranch = "x";
static constexpr auto vectorBranch = "vec";
static constexpr auto nEntries = 100000;
static const auto pathToFile = scratchDir + "/" + fileName;


void MakeDataIfNeeded()
{
   const bool hasData = gSystem->AccessPathName(pathToFile.c_str()) == 0;
   if (!hasData)
      ROOT::RDataFrame(nEntries)
         .Define(scalarBranch, [] { return 42; })
         .Define(vectorBranch, [] { return std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}; })
         .Snapshot<int, std::vector<int>>(treeName, pathToFile.c_str(), {scalarBranch, vectorBranch});
}

static void BM_TTreeSum_SumScalarTBranchGetEntry(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   auto b = t->GetBranch(scalarBranch);
   b->SetAddress(&x);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         b->GetEntry(e);
         sum += x;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == 42 * nEntries);
}
BENCHMARK(BM_TTreeSum_SumScalarTBranchGetEntry);

static void BM_TTreeSum_SumScalarTTreeGetEntry(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchStatus("*", false);
   t->SetBranchStatus(scalarBranch, true);
   t->SetBranchAddress(scalarBranch, &x);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         t->GetEntry(e);
         sum += x;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == 42 * nEntries);
}
BENCHMARK(BM_TTreeSum_SumScalarTTreeGetEntry);

static void BM_TTreeSum_SumScalarTTreeReader(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   TTreeReader r(t);
   TTreeReaderValue<int> x(r, scalarBranch);
   int sum = 0;
   for (auto _ : state) {
      sum = 0;
      r.Restart();
      while (r.Next())
         sum += *x;
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == 42 * nEntries);
}
BENCHMARK(BM_TTreeSum_SumScalarTTreeReader);

static void BM_TTreeSum_SumVectorTBranchGetEntry(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   auto vec = new std::vector<int>;
   auto b = t->GetBranch(vectorBranch);
   b->SetAddress(&vec);
   int sum = 0;
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      sum = 0;
      for (Long64_t e = 0ll; e < nEntries; ++e) {
         b->GetEntry(e);
         for (auto el : *vec)
            sum += el;
      }
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(BM_TTreeSum_SumVectorTBranchGetEntry);

static void BM_TTreeSum_SumVectorTTreeReader(benchmark::State &state)
{
   MakeDataIfNeeded();
   TFile f(pathToFile.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   TTreeReader r(t);
   TTreeReaderArray<int> vec(r, vectorBranch);
   int sum = 0;
   for (auto _ : state) {
      sum = 0;
      r.Restart();
      while (r.Next())
         for (auto e : vec)
            sum += e;
      benchmark::DoNotOptimize(sum);
   }
   ensure(sum == (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) * nEntries);
}
BENCHMARK(BM_TTreeSum_SumVectorTTreeReader);
