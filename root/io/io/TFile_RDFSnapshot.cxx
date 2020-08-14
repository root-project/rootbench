#include "ROOT/RDataFrame.hxx"
#include "ROOT/RSnapshotOptions.hxx"
#include "TRandom3.h"

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"


auto SetupRDF() {
   // We create an empty data frame
   ROOT::RDataFrame tdf(100000);
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
  auto tdf = SetupRDF();
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kZLIB, 1);
  for (auto _ : state) {
     //And we write out the dataset on disk
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_ZLIB)->Unit(benchmark::kMicrosecond);


static void BM_TFile_RDFSnapshot_LZ4(benchmark::State &state) {
  auto tdf = SetupRDF();
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kLZ4, 4);
  for (auto _ : state) {
     //And we write out the dataset on disk
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_LZ4)->Unit(benchmark::kMicrosecond);


static void BM_TFile_RDFSnapshot_LZMA (benchmark::State &state) {
  auto tdf = SetupRDF();
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kLZMA, 8);
  for (auto _ : state) {
     //And we write out the dataset on disk
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_LZMA)->Unit(benchmark::kMicrosecond);

static void BM_TFile_RDFSnapshot_ZSTD (benchmark::State &state) {
  auto tdf = SetupRDF();
  auto options = SetupRDFOptions(ROOT::ECompressionAlgorithm::kZSTD, 6);
  for (auto _ : state) {
     //And we write out the dataset on disk
     tdf.Snapshot<double>("randomNumbers", "bench_data.root", {"rnd"}, options);
  }
}
BENCHMARK(BM_TFile_RDFSnapshot_ZSTD)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
