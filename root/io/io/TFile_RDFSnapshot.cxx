#include "ROOT/RDataFrame.hxx"
#include "ROOT/RSnapshotOptions.hxx"
#include "TRandom3.h"

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"


static void BM_TFile_RDFSnapshot_ZLIB(benchmark::State &state) {
   ROOT::EnableImplicitMT();
   ROOT::RDF::RSnapshotOptions options;
   options.fCompressionAlgorithm = ROOT::ECompressionAlgorithm::kZLIB;

   // We create an empty data frame
   ROOT::RDataFrame tdf(100000);
   // We now fill it with random numbers
   gRandom->SetSeed(1);
   auto tdf_1 = tdf.Define("rnd", []() { return gRandom->Gaus(); });

   for (auto _ : state) {
      //And we write out the dataset on disk
      tdf_1.Snapshot("randomNumbers", "bench_data.root", "", options);
   }
}
BENCHMARK(BM_TFile_RDFSnapshot_ZLIB)->Unit(benchmark::kMicrosecond);


static void BM_TFile_RDFSnapshot_LZ4(benchmark::State &state) {
   ROOT::EnableImplicitMT();
   ROOT::RDF::RSnapshotOptions options;
   options.fCompressionAlgorithm = ROOT::ECompressionAlgorithm::kLZ4;

   // We create an empty data frame
   ROOT::RDataFrame tdf(100000);
   // We now fill it with random numbers
   gRandom->SetSeed(1);
   auto tdf_1 = tdf.Define("rnd", []() { return gRandom->Gaus(); });

   for (auto _ : state) {
      //And we write out the dataset on disk
      tdf_1.Snapshot("randomNumbers", "bench_data.root", "", options);
   }
}
BENCHMARK(BM_TFile_RDFSnapshot_LZ4)->Unit(benchmark::kMicrosecond);


static void BM_TFile_RDFSnapshot_LZMA (benchmark::State &state) {
   ROOT::EnableImplicitMT();
   ROOT::RDF::RSnapshotOptions options;
   options.fCompressionAlgorithm = ROOT::ECompressionAlgorithm::kLZMA;

   // We create an empty data frame
   ROOT::RDataFrame tdf(100000);
   // We now fill it with random numbers
   gRandom->SetSeed(1);
   auto tdf_1 = tdf.Define("rnd", []() { return gRandom->Gaus(); });

   for (auto _ : state) {
      //And we write out the dataset on disk
      tdf_1.Snapshot("randomNumbers", "bench_data.root", "", options);
   }
}
BENCHMARK(BM_TFile_RDFSnapshot_LZMA)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
