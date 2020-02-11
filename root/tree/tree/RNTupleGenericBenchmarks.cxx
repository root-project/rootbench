#include <benchmark/benchmark.h>

#include <ROOT/RDataFrame.hxx>
#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleDS.hxx>
#include <ROOT/RNTupleModel.hxx>
#include <ROOT/RNTupleOptions.hxx>
#include <ROOT/RNTupleView.hxx>

#include <TFile.h>
#include <TRandom3.h>

#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#include <memory>
#include <cmath>

using RNTupleModel = ROOT::Experimental::RNTupleModel;
using RNTupleReader = ROOT::Experimental::RNTupleReader;
using RNTupleWriter = ROOT::Experimental::RNTupleWriter;

uint64_t constexpr mix(char m, uint64_t s)
{
   return ((s << 7) + ~(s >> 3)) + ~m;
}

uint64_t constexpr hash(const char *m)
{
   return (*m) ? mix(*m, hash(m + 1)) : 0;
}

// an assert implementation that is not no-op for optimized builds
void ensure(bool b)
{
   if (!b)
      std::abort();
}

static int getROOTCompressionAlgorithm(const char *algorithm)
{
   int compressionAlg = 0;
   switch (hash(algorithm)) {
   case hash("lz4"): compressionAlg = ROOT::RCompressionSetting::EDefaults::kUseAnalysis; break;
   case hash("zstd"): compressionAlg = ROOT::RCompressionSetting::EDefaults::kUseGeneralPurpose; break;
   case hash("zlib"): compressionAlg = ROOT::RCompressionSetting::EDefaults::kUseCompiledDefault; break;
   case hash("lzma"): compressionAlg = ROOT::RCompressionSetting::EDefaults::kUseSmallest; break;
   case hash("none"): compressionAlg = ROOT::RCompressionSetting::EDefaults::kUseGlobal; break;
   default: std::cerr << "Invalid compression algorithm: " << algorithm << std::endl; return 1;
   }
   return compressionAlg;
}

static int getROOTCompressionLevel(const char *algorithm)
{
   int compressionLevel = 0;
   switch (hash(algorithm)) {
   case hash("lz4"): compressionLevel = ROOT::RCompressionSetting::ELevel::kDefaultLZ4; break;
   case hash("zstd"): compressionLevel = ROOT::RCompressionSetting::ELevel::kDefaultZSTD; break;
   case hash("zlib"): compressionLevel = ROOT::RCompressionSetting::ELevel::kDefaultZLIB; break;
   case hash("lzma"): compressionLevel = ROOT::RCompressionSetting::ELevel::kDefaultLZMA; break;
   case hash("none"): compressionLevel = ROOT::RCompressionSetting::ELevel::kUncompressed; break;
   default: std::cerr << "Invalid compression algorithm: " << algorithm << std::endl; return 1;
   }
   return compressionLevel;
}

static double PrepareRandomRNtuple(const char *compressionAlgorithm)
{
   std::string alg(compressionAlgorithm);
   std::string fileName = "test_rntuple_world_rnd_" + alg + ".root";

   auto ROOTCompAlg = getROOTCompressionAlgorithm(compressionAlgorithm);
   auto ROOTCompLevel = getROOTCompressionLevel(compressionAlgorithm);
   auto ROOTCompressionSettings = ROOTCompAlg * 100 + ROOTCompLevel;

   auto options = ROOT::Experimental::RNTupleWriteOptions();
   options.SetCompression(ROOTCompressionSettings);

   auto modelWrite = RNTupleModel::Create();
   auto &wrEvent = *modelWrite->MakeField<std::uint32_t>("event");
   auto &wrSignal = *modelWrite->MakeField<bool>("signal");
   auto &wrEnergy = *modelWrite->MakeField<double>("energy");
   auto &wrTimes = *modelWrite->MakeField<std::vector<double>>("times");
   auto &wrIndices = *modelWrite->MakeField<std::vector<std::uint32_t>>("indices");

   TRandom3 rnd(42);
   double chksumWrite = 0.0;

   auto ntuple = RNTupleWriter::Recreate(std::move(modelWrite), "f", fileName, options);
   constexpr unsigned int nEvents = 5000;
   for (unsigned int i = 0; i < nEvents; ++i) {
      wrEvent = i;
      wrEnergy = rnd.Rndm() * 1000.;
      wrSignal = i % 2;
      chksumWrite += double(wrEvent);
      chksumWrite += double(wrSignal);
      chksumWrite += wrEnergy;
      auto nTimes = 1 + floor(rnd.Rndm() * 1000.);
      wrTimes.resize(nTimes);
      for (unsigned int n = 0; n < nTimes; ++n) {
         wrTimes[n] = 1 + rnd.Rndm() * 1000. - 500.;
         chksumWrite += wrTimes[n];
      }
      auto nIndices = 1 + floor(rnd.Rndm() * 1000.);
      wrIndices.resize(nIndices);
      for (unsigned int n = 0; n < nIndices; ++n) {
         wrIndices[n] = 1 + floor(rnd.Rndm() * 1000.);
         chksumWrite += double(wrIndices[n]);
      }
      ntuple->Fill();
   }
   return chksumWrite;
}

static double PrepareFloatRNtuple(const char *compressionAlgorithm)
{
   std::string alg(compressionAlgorithm);
   std::string fileName = "test_rntuple_world_float_" + alg + ".root";

   auto ROOTCompAlg = getROOTCompressionAlgorithm(compressionAlgorithm);
   auto ROOTCompLevel = getROOTCompressionLevel(compressionAlgorithm);
   auto ROOTCompressionSettings = ROOTCompAlg * 100 + ROOTCompLevel;

   auto options = ROOT::Experimental::RNTupleWriteOptions();
   options.SetCompression(ROOTCompressionSettings);

   auto modelWrite = RNTupleModel::Create();
   double mass  = 0.137;
   auto &wrEvent = *modelWrite->MakeField<std::uint32_t>("event");
   auto &wx = *modelWrite->MakeField<float>("x");
   auto &wy = *modelWrite->MakeField<float>("y");
   auto &wz = *modelWrite->MakeField<float>("z");
   auto &wp = *modelWrite->MakeField<float>("p");
   auto &wrEnergyTot = *modelWrite->MakeField<float>("energytot");
   auto &wrEkin = *modelWrite->MakeField<float>("energykin");
   auto &wrTimes = *modelWrite->MakeField<std::vector<float>>("times");
   auto &wrIndices = *modelWrite->MakeField<std::vector<std::uint32_t>>("indices");

   TRandom3 rnd(42);
   double chksumWrite = 0.0;

   auto ntuple = RNTupleWriter::Recreate(std::move(modelWrite), "f", fileName, options);
   constexpr unsigned int nEvents = 5000;
   for (unsigned int i = 0; i < nEvents; ++i) {
      wrEvent = i;
      chksumWrite += double(wrEvent);
      wx = rnd.Gaus(10,1);
      chksumWrite += wx;
      wy = rnd.Gaus(20,2);
      chksumWrite += wy;
      wz = rnd.Landau(2,1);
      chksumWrite += wz;
      wp  = std::sqrt(wx*wx + wy*wy + wz*wz);
      chksumWrite += wz;
      wrEnergyTot = std::sqrt(wp*wp + mass*mass);
      chksumWrite +=wrEnergyTot;
      wrEkin = wrEnergyTot - mass;
      chksumWrite += wrEkin;
      auto nTimes = 1 + floor(rnd.Rndm() * 1000.);
      wrTimes.resize(nTimes);
      for (unsigned int n = 0; n < nTimes; ++n) {
         wrTimes[n] = 1 + rnd.Rndm() * 1000. - 500.;
         chksumWrite += wrTimes[n];
      }
      auto nIndices = 1 + floor(rnd.Rndm() * 1000.);
      wrIndices.resize(nIndices);
      for (unsigned int n = 0; n < nIndices; ++n) {
         wrIndices[n] = 1 + floor(rnd.Rndm() * 1000.);
         chksumWrite += double(wrIndices[n]);
      }
      ntuple->Fill();
   }
   return chksumWrite;
}

static void BM_RNTuple_RealWorld(benchmark::State &state, const char *compressionAlgorithm)
{
   double chksumWrite = PrepareRandomRNtuple(compressionAlgorithm);

   std::string alg(compressionAlgorithm);
   std::string fileName = "test_rntuple_world_rnd_" + alg + ".root";

   auto ROOTCompAlg = getROOTCompressionAlgorithm(compressionAlgorithm);
   auto ROOTCompLevel = getROOTCompressionLevel(compressionAlgorithm);
   auto ROOTCompressionSettings = ROOTCompAlg * 100 + ROOTCompLevel;

   auto options = ROOT::Experimental::RNTupleWriteOptions();
   options.SetCompression(ROOTCompressionSettings);

   auto modelRead = RNTupleModel::Create();
   auto &rdEvent = *modelRead->MakeField<std::uint32_t>("event");
   auto &rdSignal = *modelRead->MakeField<bool>("signal");
   auto &rdEnergy = *modelRead->MakeField<double>("energy");
   auto &rdTimes = *modelRead->MakeField<std::vector<double>>("times");
   auto &rdIndices = *modelRead->MakeField<std::vector<std::uint32_t>>("indices");
   
   auto ntuple = RNTupleReader::Open(std::move(modelRead), "f", fileName);
   for (auto _ : state) {
      double chksumRead = 0.0;
      for (auto entryId : *ntuple) {
         ntuple->LoadEntry(entryId);
         chksumRead += double(rdEvent) + double(rdSignal) + rdEnergy;
         for (auto t : rdTimes)
            chksumRead += t;
         for (auto ind : rdIndices)
            chksumRead += double(ind);
         benchmark::DoNotOptimize(chksumRead);
         benchmark::ClobberMemory();
      }
      ensure(chksumRead == chksumWrite);
   }
}
BENCHMARK_CAPTURE(BM_RNTuple_RealWorld, BM_RNTuple_RealWorldLZ4, "lz4")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_RealWorld, BM_RNTuple_RealWorldZLIB, "zlib")
   ->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_RealWorld, BM_RNTuple_RealWorldLZMA, "lzma")
   ->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_RealWorld, BM_RNTuple_RealWorldZSTD, "zstd")
   ->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_RealWorld, BM_RNTuple_RealWorldNone, "none")
   ->Unit(benchmark::kMicrosecond);

static void BM_RNTuple_Float_RealWorld(benchmark::State &state, const char *compressionAlgorithm)
{
   double chksumWrite = PrepareFloatRNtuple(compressionAlgorithm);

   std::string alg(compressionAlgorithm);
   std::string fileName = "test_rntuple_world_float_" + alg + ".root";

   auto ROOTCompAlg = getROOTCompressionAlgorithm(compressionAlgorithm);
   auto ROOTCompLevel = getROOTCompressionLevel(compressionAlgorithm);
   auto ROOTCompressionSettings = ROOTCompAlg * 100 + ROOTCompLevel;

   auto options = ROOT::Experimental::RNTupleWriteOptions();
   options.SetCompression(ROOTCompressionSettings);

   auto modelRead = RNTupleModel::Create();
   auto &rdEvent = *modelRead->MakeField<std::uint32_t>("event");
   auto &rdx = *modelRead->MakeField<float>("x");
   auto &rdy = *modelRead->MakeField<float>("y");
   auto &rdz = *modelRead->MakeField<float>("z");
   auto &rdp = *modelRead->MakeField<float>("p");
   auto &rdEnergyTot = *modelRead->MakeField<float>("energytot");
   auto &rdEkin = *modelRead->MakeField<float>("energykin");
   auto &rdTimes = *modelRead->MakeField<std::vector<float>>("times");
   auto &rdIndices = *modelRead->MakeField<std::vector<std::uint32_t>>("indices");
   
   auto ntuple = RNTupleReader::Open(std::move(modelRead), "f", fileName);
   for (auto _ : state) {
      double chksumRead = 0.0;
      for (auto entryId : *ntuple) {
         ntuple->LoadEntry(entryId);
         chksumRead += double(rdEvent) + rdx + rdy  + rdz  + rdp  + rdEnergyTot + rdEkin;
         for (auto t : rdTimes)
            chksumRead += t;
         for (auto ind : rdIndices)
            chksumRead += double(ind);
         benchmark::DoNotOptimize(chksumRead);
         benchmark::ClobberMemory();
      }
      ensure(chksumRead == chksumWrite);
   }
}
BENCHMARK_CAPTURE(BM_RNTuple_Float_RealWorld, BM_RNTuple_Float_RealWorldLZ4, "lz4")->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_Float_RealWorld, BM_RNTuple_Float_RealWorldZLIB, "zlib")
   ->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_Float_RealWorld, BM_RNTuple_Float_RealWorldLZMA, "lzma")
   ->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_Float_RealWorld, BM_RNTuple_Float_RealWorldZSTD, "zstd")
   ->Unit(benchmark::kMicrosecond);
BENCHMARK_CAPTURE(BM_RNTuple_Float_RealWorld, BM_RNTuple_Float_RealWorldNone, "none")
   ->Unit(benchmark::kMicrosecond);

// Replace BENCHMARK_MAIN();
int main(int argc, char** argv)
{
   std::unique_ptr<benchmark::MemoryManager> mm;
   ::benchmark::Initialize(&argc, argv);
   ::benchmark::RegisterMemoryManager(mm.get());
   ::benchmark::RunSpecifiedBenchmarks();
   ::benchmark::RegisterMemoryManager(nullptr);
}