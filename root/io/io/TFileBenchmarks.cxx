#include "TROOT.h"   // ROOT::EnableImplicitMT

#include "TFile.h"	
#include "TFrame.h"
#include "TRandom3.h"
#include "TBenchmark.h"

#include "ROOT/RDataFrame.hxx"
#include "ROOT/RSnapshotOptions.hxx"

#include "benchmark/benchmark.h"
#include "rootbench/RBConfig.h"


static void BM_TFile_Write(benchmark::State &state) {
	ROOT::EnableImplicitMT();
	ROOT::RDF::RSnapshotOptions options;
	options.fCompressionAlgorithm = ROOT::ECompressionAlgorithm::kZLIB;
	//RCompressionSetting::EAlgorithm::EValues::kZLIB

	for (auto _ : state) {
		// We create an empty data frame
	   ROOT::RDataFrame tdf(100000);
	   // We now fill it with random numbers
	   gRandom->SetSeed(1);
	   auto tdf_1 = tdf.Define("rnd", []() { return gRandom->Gaus(); });
	   //And we write out the dataset on disk
	   tdf_1.Snapshot("randomNumbers", "bench_data.root", "", options);
	}
}
BENCHMARK(BM_TFile_Write)->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();
