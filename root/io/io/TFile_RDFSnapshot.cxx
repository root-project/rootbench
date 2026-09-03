#include "ROOT/RDataFrame.hxx"
#include "ROOT/RSnapshotOptions.hxx"
#include "TFile.h"
#include "TRandom3.h"
#include "TSystem.h"

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"

#include <memory>
#include <string>
#include <vector>

// Number of doubles written per snapshot: large enough that the compression
// dominates over the fixed overheads of the snapshot, small enough to keep
// the total runtime of the benchmarks reasonable.
constexpr ULong64_t kNEntries = 10000000;

// The input data is generated only once, so that the random number generation
// does not contribute to the benchmarked snapshot time.
static const std::vector<double> &GetInputData()
{
   static const std::vector<double> data = [] {
      std::vector<double> v(kNEntries);
      TRandom3 rng(1);
      for (auto &x : v)
         x = rng.Gaus();
      return v;
   }();
   return data;
}

static void BM_TFile_RDFSnapshot(benchmark::State &state, ROOT::RCompressionSetting::EAlgorithm::EValues algo,
                                 const std::string &algoName)
{
   const auto &data = GetInputData();

   ROOT::RDataFrame df(kNEntries);
   auto dfWithCol = df.Define("rnd", [&data](ULong64_t entry) { return data[entry]; }, {"rdfentry_"});

   ROOT::RDF::RSnapshotOptions options;
   options.fCompressionAlgorithm = algo;
   options.fCompressionLevel = state.range(0);

   const std::string fileName =
      RB::GetTempFs() + "/rdfsnapshot_" + algoName + "_" + std::to_string(state.range(0)) + ".root";

   for (auto _ : state) {
      // And we write out the dataset on disk
      dfWithCol.Snapshot("randomNumbers", fileName, {"rnd"}, options);
   }

   {
      std::unique_ptr<TFile> file{TFile::Open(fileName.c_str())};
      state.counters["comp_size"] = file->GetSize();
   }
   // Reports the throughput of uncompressed input bytes as bytes_per_second.
   state.SetBytesProcessed(state.iterations() * kNEntries * sizeof(double));

   gSystem->Unlink(fileName.c_str());
}

BENCHMARK_CAPTURE(BM_TFile_RDFSnapshot, ZLIB, ROOT::RCompressionSetting::EAlgorithm::kZLIB, "zlib")
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_TFile_RDFSnapshot, LZMA, ROOT::RCompressionSetting::EAlgorithm::kLZMA, "lzma")
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_TFile_RDFSnapshot, LZ4, ROOT::RCompressionSetting::EAlgorithm::kLZ4, "lz4")
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_TFile_RDFSnapshot, ZSTD, ROOT::RCompressionSetting::EAlgorithm::kZSTD, "zstd")
->Arg(1)->Arg(6)->Arg(9)
->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
