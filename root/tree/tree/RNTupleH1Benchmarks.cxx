#include <benchmark/benchmark.h>

#include <ROOT/RDataFrame.hxx>
#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleDS.hxx>
#include <ROOT/RNTupleOptions.hxx>
#include <ROOT/RNTupleView.hxx>

#include <TCanvas.h>
#include <TChain.h>
#include <TF1.h>
#include <TFile.h>
#include <TH1.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH1D.h>
#include <TLine.h>
#include <TMath.h>
#include <TPaveStats.h>
#include <TStyle.h>
#include <TSystem.h>

#include <rootbench/RBConfig.h>


static void BM_RNTuple_H1(benchmark::State &state, const std::string &comprAlgorithm)
{
   using RNTupleReader = ROOT::Experimental::RNTupleReader;
   gSystem->Load("./libh1event");
   // Open RNtuple file with RNTuple reader
   std::string path = RB::GetDataDir() + "/h1dst-" + comprAlgorithm + ".ntuple";
   auto ntuple = RNTupleReader::Open("h42", path);
   // Creating RNTuple views
   auto dm_dView = ntuple->GetView<float>("event.dm_d");
   auto rpd0_tView = ntuple->GetView<float>("event.rpd0_t");
   auto ptd0_dView = ntuple->GetView<float>("event.ptd0_d");
   auto ptds_dView = ntuple->GetView<float>("event.ptds_d");
   auto etads_dView = ntuple->GetView<float>("event.etads_d");
   auto ikView = ntuple->GetView<std::int32_t>("event.ik");
   auto ipiView = ntuple->GetView<std::int32_t>("event.ipi");
   auto ipisView = ntuple->GetView<std::int32_t>("event.ipis");
   auto md0_dView = ntuple->GetView<float>("event.md0_d");
   auto trackView = ntuple->GetViewCollection("event.tracks");
   auto nhitrpView = ntuple->GetView<std::int32_t>("event.tracks.H1Event::Track.nhitrp");
   auto rstartView = ntuple->GetView<float>("event.tracks.H1Event::Track.rstart");
   auto rendView = ntuple->GetView<float>("event.tracks.H1Event::Track.rend");
   auto nlhkView = ntuple->GetView<float>("event.tracks.H1Event::Track.nlhk");
   auto nlhpiView = ntuple->GetView<float>("event.tracks.H1Event::Track.nlhpi");
   auto njetsView = ntuple->GetViewCollection("event.jets");
   // Check print info (minitest)
   std::ostringstream os;
   ntuple->PrintInfo(ROOT::Experimental::ENTupleInfo::kSummary, os);
   // Benchmark loop
   for (auto _ : state) {
      // TH1D & TH2D histograms to be filled with data
      auto hdmd = new TH1D("hdmd", "dm_d", 40, 0.13, 0.17);
      auto h2 = new TH2D("h2", "ptD0 vs dm_d", 30, 0.135, 0.165, 30, -3, 6);
      for (auto i : ntuple->GetEntryRange()) {
         if (i == 0) {
            state.PauseTiming();
         } else if (i == 1) {
            state.ResumeTiming();
         }

         auto ik = ikView(i) - 1;
         auto ipi = ipiView(i) - 1;
         auto ipis = ipisView(i) - 1;

         if (TMath::Abs(md0_dView(i) - 1.8646) >= 0.04)
            continue;
         if (ptds_dView(i) <= 2.5)
            continue;
         if (TMath::Abs(etads_dView(i)) >= 1.5)
            continue;

         if (nhitrpView(*trackView.GetCollectionRange(i).begin() + ik) *
                nhitrpView(*trackView.GetCollectionRange(i).begin() + ipi) <=
             1)
            continue;
         if (rendView(*trackView.GetCollectionRange(i).begin() + ik) - rstartView(*trackView.GetCollectionRange(i).begin() + ik) <=
             22)
            continue;
         if (rendView(*trackView.GetCollectionRange(i).begin() + ipi) -
                rstartView(*trackView.GetCollectionRange(i).begin() + ipi) <=
             22)
            continue;
         if (nlhkView(*trackView.GetCollectionRange(i).begin() + ik) <= 0.1)
            continue;
         if (nlhpiView(*trackView.GetCollectionRange(i).begin() + ipi) <= 0.1)
            continue;
         if (nlhpiView(*trackView.GetCollectionRange(i).begin() + ipis) <= 0.1)
            continue;
         if (njetsView(i) < 1)
            continue;
         hdmd->Fill(dm_dView(i));
         h2->Fill(dm_dView(i), rpd0_tView(i) / 0.029979 * 1.8646 / ptd0_dView(i));
      }
      delete hdmd;
      delete h2;
   }
}
BENCHMARK_CAPTURE(BM_RNTuple_H1, BM_RNTuple_H1LZ4, "lz4")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_H1, BM_RNTuple_H1ZLIB, "zlib")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_H1, BM_RNTuple_H1LZMA, "lzma")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_H1, BM_RNTuple_H1ZSTD, "zstd")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_H1, BM_RNTuple_H1FLZMA2, "flzma2")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_H1, BM_RNTuple_H1None, "none")->Unit(benchmark::kMicrosecond)->Iterations(5);

static void BM_TTree_H1(benchmark::State &state, const std::string &comprAlgorithm)
{
   std::string path = RB::GetDataDir() + "/h1dst-" + comprAlgorithm + ".root";
   auto file = TFile::Open(path.c_str());
   auto tree = file->Get<TTree>("h42");
   float md0_d;
   float ptds_d;
   float etads_d;
   float dm_d;
   float rpd0_t;
   float ptd0_d;
   Int_t ik;
   Int_t ipi;
   Int_t ipis;
   Int_t ntracks;
   Int_t njets;
   Int_t nhitrp[200];
   float rend[200];
   float rstart[200];
   float nlhk[200];
   float nlhpi[200];

   TBranch *br_md0_d = nullptr;
   TBranch *br_ptds_d = nullptr;
   TBranch *br_etads_d = nullptr;
   TBranch *br_dm_d = nullptr;
   TBranch *br_rpd0_t = nullptr;
   TBranch *br_ptd0_d = nullptr;
   TBranch *br_ik = nullptr;
   TBranch *br_ipi = nullptr;
   TBranch *br_ipis = nullptr;
   TBranch *br_ntracks = nullptr;
   TBranch *br_njets = nullptr;
   TBranch *br_nhitrp = nullptr;
   TBranch *br_rend = nullptr;
   TBranch *br_rstart = nullptr;
   TBranch *br_nlhk = nullptr;
   TBranch *br_nlhpi = nullptr;

   tree->SetBranchAddress("md0_d", &md0_d, &br_md0_d);
   tree->SetBranchAddress("ptds_d", &ptds_d, &br_ptds_d);
   tree->SetBranchAddress("etads_d", &etads_d, &br_etads_d);
   tree->SetBranchAddress("dm_d", &dm_d, &br_dm_d);
   tree->SetBranchAddress("rpd0_t", &rpd0_t, &br_rpd0_t);
   tree->SetBranchAddress("ptd0_d", &ptd0_d, &br_ptd0_d);
   tree->SetBranchAddress("ik", &ik, &br_ik);
   tree->SetBranchAddress("ipi", &ipi, &br_ipi);
   tree->SetBranchAddress("ipis", &ipis, &br_ipis);
   tree->SetBranchAddress("ntracks", &ntracks, &br_ntracks);
   tree->SetBranchAddress("njets", &njets, &br_njets);
   tree->SetBranchAddress("nhitrp", nhitrp, &br_nhitrp);
   tree->SetBranchAddress("rend", rend, &br_rend);
   tree->SetBranchAddress("rstart", rstart, &br_rstart);
   tree->SetBranchAddress("nlhk", nlhk, &br_nlhk);
   tree->SetBranchAddress("nlhpi", nlhpi, &br_nlhpi);

   auto nEntries = tree->GetEntries();
   for (auto _ : state) {
      auto hdmd = new TH1D("hdmd", "dm_d", 40, 0.13, 0.17);
      auto h2 = new TH2D("h2", "ptD0 vs dm_d", 30, 0.135, 0.165, 30, -3, 6);
      for (decltype(nEntries) entryId = 0; entryId < nEntries; ++entryId) {
         if (entryId == 0) {
            state.PauseTiming();
         } else if (entryId == 1) {
            state.ResumeTiming();
         }

         tree->LoadTree(entryId);

         br_md0_d->GetEntry(entryId);
         if (TMath::Abs(md0_d - 1.8646) >= 0.04)
            continue;
         br_ptds_d->GetEntry(entryId);
         if (ptds_d <= 2.5)
            continue;
         br_etads_d->GetEntry(entryId);
         if (TMath::Abs(etads_d) >= 1.5)
            continue;

         br_ntracks->GetEntry(entryId);
         br_ik->GetEntry(entryId);
         ik--; // original ik used f77 convention starting at 1
         br_ipi->GetEntry(entryId);
         ipi--;
         br_nhitrp->GetEntry(entryId);
         if (nhitrp[ik] * nhitrp[ipi] <= 1)
            continue;

         br_rend->GetEntry(entryId);
         br_rstart->GetEntry(entryId);
         if (rend[ik] - rstart[ik] <= 22)
            continue;
         if (rend[ipi] - rstart[ipi] <= 22)
            continue;

         br_nlhk->GetEntry(entryId);
         if (nlhk[ik] <= 0.1)
            continue;
         br_nlhpi->GetEntry(entryId);
         if (nlhpi[ipi] <= 0.1)
            continue;
         br_ipis->GetEntry(entryId);
         ipis--;
         if (nlhpi[ipis] <= 0.1)
            continue;

         br_njets->GetEntry(entryId);
         if (njets < 1)
            continue;

         br_dm_d->GetEntry(entryId);
         br_rpd0_t->GetEntry(entryId);
         br_ptd0_d->GetEntry(entryId);
         hdmd->Fill(dm_d);
         h2->Fill(dm_d, rpd0_t / 0.029979 * 1.8646 / ptd0_d);
      }
      delete hdmd;
      delete h2;
   }
}
BENCHMARK_CAPTURE(BM_TTree_H1, BM_TTree_H1LZ4, "lz4")->Unit(benchmark::kMicrosecond)->Iterations(3);
BENCHMARK_CAPTURE(BM_TTree_H1, BM_TTree_H1ZLIB, "zlib")->Unit(benchmark::kMicrosecond)->Iterations(3);
BENCHMARK_CAPTURE(BM_TTree_H1, BM_TTree_H1LZMA, "lzma")->Unit(benchmark::kMicrosecond)->Iterations(3);
BENCHMARK_CAPTURE(BM_TTree_H1, BM_TTree_H1ZSTD, "zstd")->Unit(benchmark::kMicrosecond)->Iterations(3);
BENCHMARK_CAPTURE(BM_TTree_H1, BM_TTree_H1FLZMA2, "flzma2")->Unit(benchmark::kMicrosecond)->Iterations(3);
BENCHMARK_CAPTURE(BM_TTree_H1, BM_TTree_H1None, "none")->Unit(benchmark::kMicrosecond)->Iterations(3);

BENCHMARK_MAIN();
