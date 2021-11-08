#include "ROOT/TBufferMerger.hxx"

#include "TROOT.h" // For EnableThreadSafety

#include "TTree.h"

#include "benchmark/benchmark.h"

#include <memory>
#include <random>
#include <string>
#include <sstream>
#include <thread>
#include <sys/stat.h>

using ROOT::TBufferMerger;

int GetNumberHardwareThreads()
{
   return std::thread::hardware_concurrency();
}

static void BM_TBufferFile_CreateEmpty(benchmark::State &state)
{
   const char *filename = "empty.root";
   for (auto _ : state) {
      TBufferMerger m(std::make_unique<TMemFile>(filename, "RECREATE"));
   }
}
BENCHMARK(BM_TBufferFile_CreateEmpty)->Unit(benchmark::kMicrosecond);

TBufferMerger *Merger = nullptr;
static void BM_TBufferFile_GetFile(benchmark::State &state)
{
   ROOT::EnableThreadSafety();
   if (state.thread_index == 0) {
      // Setup code here.
      // FIXME: We should have a way to pass an externally constructed file or stream to
      // TFile*, this would allow us to create in-memory files and avoid killing disks
      // when we benchmark IO.
      Merger = new TBufferMerger(std::make_unique<TMemFile>("virtual_file.root", "RECREATE"));
   }
   for (auto _ : state) {
      // Run the test as normal.
      auto myFile = Merger->GetFile();
   }
   if (state.thread_index == 0) {
      // Teardown code here.
      delete Merger;
   }
}
BENCHMARK(BM_TBufferFile_GetFile)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_TBufferFile_GetFile)->Unit(benchmark::kMicrosecond)->UseRealTime()->ThreadPerCpu();
BENCHMARK(BM_TBufferFile_GetFile)
   ->Unit(benchmark::kMicrosecond)
   ->UseRealTime()
   ->ThreadRange(1, GetNumberHardwareThreads() * 2);

/// Creates a TMemFile, fills a TTree with random numbers. The data is written if it exceeds 32MB.
inline void FillTreeWithRandomData(TBufferMerger &merger, size_t nEntriesPerWorker = 24 * 1024, int flush = 32)
{
   thread_local std::default_random_engine g;
   std::uniform_real_distribution<double> dist(0.0, 1.0);

   auto f = merger.GetFile();
   auto t = new TTree("random", "random");
   t->ResetBit(kMustCleanup);
   t->SetAutoFlush(-(flush) * 1024 * 1024); // Flush at exceeding 32MB

   double rng;

   t->Branch("random", &rng);

   long entries = 0;
   for (size_t i = 0; i < nEntriesPerWorker; ++i) {
      rng = dist(g);
      t->Fill();
      ++entries;
      auto atflush = t->GetAutoFlush();
      if (entries == atflush) {
         entries = 0;
         f->Write();
      }
   }
   f->Write();
}

static void BM_TBufferFile_FillTreeWithRandomData(benchmark::State &state)
{
   ROOT::EnableThreadSafety();
   if (state.thread_index == 0) {
      // Setup code here.
      Merger = new TBufferMerger(std::make_unique<TMemFile>("virtual_file.root", "RECREATE"));
   }
   long size = 0;
   int flush = state.range(0);
   for (auto _ : state) {
      FillTreeWithRandomData(*Merger, flush);
      size = Merger->GetFile()->GetSize();
   }
   std::stringstream ss;
   ss << size;
   state.SetLabel(ss.str());
   if (state.thread_index == 0) {
      // Teardown code here.
      delete Merger;
   }
}
BENCHMARK(BM_TBufferFile_FillTreeWithRandomData)->Unit(benchmark::kMicrosecond)->Arg(32);
BENCHMARK(BM_TBufferFile_FillTreeWithRandomData)->Unit(benchmark::kMicrosecond)->Arg(32)->UseRealTime()->ThreadPerCpu();
BENCHMARK(BM_TBufferFile_FillTreeWithRandomData)
   ->Unit(benchmark::kMicrosecond)
   ->Range(1, 32)
   ->UseRealTime()
   ->ThreadRange(1, GetNumberHardwareThreads() * 2);

// Define our main.
BENCHMARK_MAIN();
