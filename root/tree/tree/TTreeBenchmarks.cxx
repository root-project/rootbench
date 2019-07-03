#include "../dataframe/RDataFrameBench.h"
#include <TFile.h>
#include <TSystem.h>
#include <TTree.h>

#include <benchmark/benchmark.h>

#include <vector>
#include "rootbench/RBConfig.h"

const std::string scratchDir = RB::GetTempFs();

static constexpr auto treeName = "Events";
static constexpr auto fileNameOneBranch = "dataonebranch.root";
static constexpr auto fileNameTwoBranches = "datatwobranches.root";
static constexpr auto branchOne = "x";
static constexpr auto branchTwo = "y";
static constexpr auto nEntries = 8000;
static auto pathOneBranch = scratchDir + "/" + fileNameOneBranch;
static auto pathTwoBranches = scratchDir + "/" + fileNameTwoBranches;



// an assert implementation that is not no-op for optimized builds
void ensure(bool b)
{
   if (!b)
      std::abort();
}

void MakeDataOneBranch()
{
   const bool hasData = gSystem->AccessPathName(fileNameOneBranch) == 0;
   if (hasData)
      return;
   TFile f(pathOneBranch.c_str(), "recreate");
   TTree t(treeName, treeName);
   int x = 42;
   t.Branch(branchOne, &x);
   for (auto i = 0; i < nEntries; ++i)
      t.Fill();
   t.Write();
}

void MakeDataTwoBranches()
{
   const bool hasData = gSystem->AccessPathName(fileNameTwoBranches) == 0;
   if (hasData)
      return;
   TFile f(pathTwoBranches.c_str(), "recreate");
   TTree t(treeName, treeName);
   int x = 42;
   int y = 84;
   t.Branch(branchOne, &x);
   t.Branch(branchTwo, &y);
   for (auto i = 0; i < nEntries; ++i)
      t.Fill();
   t.Write();
}

static void BM_TTree_GetEntryReadOneOfOne(benchmark::State &state)
{
   MakeDataOneBranch();
   TFile f(pathOneBranch.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchStatus("*", false);
   t->SetBranchStatus(branchOne, true);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(BM_TTree_GetEntryReadOneOfOne);

static void BM_TTree_GetEntryReadNoneOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(pathTwoBranches.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   t->SetBranchStatus("*", kFALSE);
   const auto nEntries = t->GetEntries();
   for (auto _ : state) {
      for (Long64_t e = 0ll; e < nEntries; ++e)
         t->GetEntry(e);
   }
}
BENCHMARK(BM_TTree_GetEntryReadNoneOfTwo);

static void BM_TTree_GetEntryReadOneOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(pathTwoBranches.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchStatus("*", false);
   t->SetBranchStatus(branchOne, true);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(BM_TTree_GetEntryReadOneOfTwo);

static void BM_TTree_GetEntryReadTwoOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(pathTwoBranches.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(BM_TTree_GetEntryReadTwoOfTwo);

static void BM_TTree_BranchGetEntryReadOneOfOne(benchmark::State &state)
{
   MakeDataOneBranch();
   TFile f(pathOneBranch.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   auto b = t->GetBranch(branchOne);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(BM_TTree_BranchGetEntryReadOneOfOne);

static void BM_TTree_BranchGetEntryReadOneOfTwo(benchmark::State &state)
{
   MakeDataTwoBranches();
   TFile f(pathTwoBranches.c_str());
   auto t = static_cast<TTree *>(f.Get(treeName));
   int x;
   auto b = t->GetBranch(branchOne);
   t->SetBranchAddress(branchOne, &x);
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
BENCHMARK(BM_TTree_BranchGetEntryReadOneOfTwo);

BENCHMARK_MAIN();
