#include "ROOT/RDataFrame.hxx"
#include "ROOT/RSnapshotOptions.hxx"
#include "TRandom3.h"
#include "TStopwatch.h"

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"


auto SetupRDF(int size) {
   // We create an empty data frame
   ROOT::RDataFrame tdf(size);
   // We now fill it with random numbers
   gRandom->SetSeed(1);
   auto tdf_1 = tdf.Define("rnd", []() { return gRandom->Gaus(); });
   return tdf_1;
}

auto SetupRDFOptions(ROOT::ECompressionAlgorithm alg, int level) {
  ROOT::RDF::RSnapshotOptions options;
  options.fCompressionAlgorithm = alg;
  options.fCompressionLevel = level;
  return options;
}


static void BM_TFile_RDFSnapshot_ZLIB(benchmark::State &state) {
  TStopwatch timer;
  int size = 50000000;
  auto tdf = SetupRDF(size);
  int comp_level = state.range(0);
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kZLIB, comp_level);
  for (auto _ : state) {
     //And we write out the dataset on disk
     timer.Start();
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
     timer.Stop();
     auto file = TFile::Open("bench_data.root");
     state.counters["comp_size"] = file->GetSize();
     double rtime = timer.RealTime();
     double ctime = timer.CpuTime();
     state.counters["mb_rts"] = file->GetSize()/rtime;
     state.counters["mb_cts"] = file->GetSize()/ctime;
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_ZLIB)->Arg(1)->Arg(6)->Arg(9)->Unit(benchmark::kMicrosecond);


static void BM_TFile_RDFSnapshot_LZ4(benchmark::State &state) {
  TStopwatch timer;
  int size = 50000000;
  auto tdf = SetupRDF(size);
  int comp_level = state.range(0);
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kLZ4, comp_level);
  for (auto _ : state) {
     //And we write out the dataset on disk
     timer.Start();
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
     timer.Stop();
     auto file = TFile::Open("bench_data.root");
     state.counters["comp_size"] = file->GetSize();
     double rtime = timer.RealTime();
     double ctime = timer.CpuTime();
     state.counters["mb_rts"] = file->GetSize()/rtime;
     state.counters["mb_cts"] = file->GetSize()/ctime;
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_LZ4)->Arg(1)->Arg(6)->Arg(9)->Unit(benchmark::kMicrosecond);


static void BM_TFile_RDFSnapshot_LZMA (benchmark::State &state) {
  TStopwatch timer;
  int size = 50000000;
  auto tdf = SetupRDF(size);
  int comp_level = state.range(0);
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kLZMA, comp_level);
  for (auto _ : state) {
     //And we write out the dataset on disk
     timer.Start();
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
     timer.Stop();
     auto file = TFile::Open("bench_data.root");
     state.counters["comp_size"] = file->GetSize();
     double rtime = timer.RealTime();
     double ctime = timer.CpuTime();
     state.counters["mb_rts"] = file->GetSize()/rtime;
     state.counters["mb_cts"] = file->GetSize()/ctime;
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_LZMA)->Arg(1)->Arg(6)->Arg(9)->Unit(benchmark::kMicrosecond);

static void BM_TFile_RDFSnapshot_FLZMA2 (benchmark::State &state) {
  TStopwatch timer;
  int size = 50000000;
  auto tdf = SetupRDF(size);
  int comp_level = state.range(0);
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kFLZMA2, comp_level);
  for (auto _ : state) {
     //And we write out the dataset on disk
     timer.Start();
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
     timer.Stop();
     auto file = TFile::Open("bench_data.root");
     state.counters["comp_size"] = file->GetSize();
     double rtime = timer.RealTime();
     double ctime = timer.CpuTime();
     state.counters["mb_rts"] = file->GetSize()/rtime;
     state.counters["mb_cts"] = file->GetSize()/ctime;
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_FLZMA2)->Arg(1)->Arg(6)->Arg(9)->Unit(benchmark::kMicrosecond);

static void BM_TFile_RDFSnapshot_ZSTD (benchmark::State &state) {
  TStopwatch timer;
  int size = 50000000;
  auto tdf = SetupRDF(size);
  int comp_level = state.range(0);
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kZSTD, comp_level);
  for (auto _ : state) {
     //And we write out the dataset on disk
     timer.Start();
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
     timer.Stop();
     auto file = TFile::Open("bench_data.root");
     state.counters["comp_size"] = file->GetSize();
     double rtime = timer.RealTime();
     double ctime = timer.CpuTime();
     state.counters["mb_rts"] = file->GetSize()/rtime;
     state.counters["mb_cts"] = file->GetSize()/ctime;
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_ZSTD)->Arg(1)->Arg(6)->Arg(9)->Arg(20)->Arg(22)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
