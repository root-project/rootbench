#include <benchmark/benchmark.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <future>
#include <memory>
#include <string>
#include <vector>

#include <ROOT/RDataFrame.hxx>
#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleDS.hxx>
#include <ROOT/RNTupleOptions.hxx>
#include <Compression.h>
#include <TApplication.h>
#include <TBranch.h>
#include <TCanvas.h>
#include <TClassTable.h>
#include <TF1.h>
#include <TFile.h>
#include <TH1D.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreePerfStats.h>

#include <Math/Vector4D.h>

#include <rootbench/RBConfig.h>


static float ComputeInvariantMass(float pt0, float pt1, float eta0, float eta1, float phi0, float phi1, float e0, float e1)
{
    ROOT::Math::PtEtaPhiEVector p1(pt0, eta0, phi0, e0);
    ROOT::Math::PtEtaPhiEVector p2(pt1, eta1, phi1, e1);
    return (p1 + p2).mass() / 1000.0;
}


static void ProcessNTuple(ROOT::Experimental::RNTupleReader *ntuple, TH1D *hMass, bool isMC)
{

    auto viewTrigP           = ntuple->GetView<bool>("trigP");
    auto viewPhotonN         = ntuple->GetView<std::uint32_t>("photon_n");
    auto viewPhotonIsTightId = ntuple->GetView<std::vector<bool>>("photon_isTightID");
    auto viewPhotonPt        = ntuple->GetView<std::vector<float>>("photon_pt");
    auto viewPhotonEta       = ntuple->GetView<std::vector<float>>("photon_eta");
    auto viewPhotonPhi       = ntuple->GetView<std::vector<float>>("photon_phi");
    auto viewPhotonE         = ntuple->GetView<std::vector<float>>("photon_E");
    auto viewPhotonPtCone30  = ntuple->GetView<std::vector<float>>("photon_ptcone30");
    auto viewPhotonEtCone20  = ntuple->GetView<std::vector<float>>("photon_etcone20");

    auto viewScaleFactorPhoton        = ntuple->GetView<float>("scaleFactor_PHOTON");
    auto viewScaleFactorPhotonTrigger = ntuple->GetView<float>("scaleFactor_PhotonTRIGGER");
    auto viewScaleFactorPileUp        = ntuple->GetView<float>("scaleFactor_PILEUP");
    auto viewMcWeight                 = ntuple->GetView<float>("mcWeight");

    unsigned nevents = 0;
    for (auto e : ntuple->GetEntryRange()) {
        nevents++;

        if (!viewTrigP(e)) continue;

        std::vector<size_t> idxGood;
        auto isTightId = viewPhotonIsTightId(e);
        auto pt = viewPhotonPt(e);
        auto eta = viewPhotonEta(e);

        for (size_t i = 0; i < viewPhotonN(e); ++i) {
            if (!isTightId[i]) continue;
            if (pt[i] <= 25000.) continue;
            if (abs(eta[i]) >= 2.37) continue;
            if (abs(eta[i]) >= 1.37 && abs(eta[i]) <= 1.52) continue;
            idxGood.push_back(i);
        }
        if (idxGood.size() != 2) continue;

        auto ptCone30 = viewPhotonPtCone30(e);
        auto etCone20 = viewPhotonEtCone20(e);

        bool isIsolatedPhotons = true;
        for (int i = 0; i < 2; ++i) {
            if ((ptCone30[idxGood[i]] / pt[idxGood[i]] >= 0.065) ||
                (etCone20[idxGood[i]] / pt[idxGood[i]] >= 0.065))
            {
            isIsolatedPhotons = false;
            break;
            }
        }
        if (!isIsolatedPhotons) continue;

        auto phi = viewPhotonPhi(e);
        auto E = viewPhotonE(e);

        float myy = ComputeInvariantMass(
            pt[idxGood[0]], pt[idxGood[1]],
            eta[idxGood[0]], eta[idxGood[1]],
            phi[idxGood[0]], phi[idxGood[1]],
            E[idxGood[0]], E[idxGood[1]]);

        if (pt[idxGood[0]] / 1000. / myy <= 0.35) continue;
        if (pt[idxGood[1]] / 1000. / myy <= 0.25) continue;
        if (myy <= 105) continue;
        if (myy >= 160) continue;

        if (isMC) {
            auto weight = viewScaleFactorPhoton(e) * viewScaleFactorPhotonTrigger(e) *
                        viewScaleFactorPileUp(e) * viewMcWeight(e);
            hMass->Fill(myy, weight);
        } else {
            hMass->Fill(myy);
        }
    }
}


static void BM_RNTuple_ATLAS(benchmark::State &state, const std::string &comprAlgorithm)
{
    using RNTupleReader = ROOT::Experimental::RNTupleReader;
    std::string path = RB::GetDataDir() + "/atlas-" + comprAlgorithm + ".ntuple";

    for (auto _ : state) {
        auto hData = new TH1D("", "Diphoton invariant mass; m_{#gamma#gamma} [GeV];Events", 30, 105, 160);

        auto ntuple = RNTupleReader::Open("mini", path);
        ProcessNTuple(ntuple.get(), hData, false /* isMC */);

        delete hData;
    }
}
BENCHMARK_CAPTURE(BM_RNTuple_ATLAS, BM_RNTuple_ATLAS_LZ4, "lz4")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_ATLAS, BM_RNTuple_ATLAS_ZLIB, "zlib")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_ATLAS, BM_RNTuple_ATLAS_LZMA, "lzma")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_ATLAS, BM_RNTuple_ATLAS_ZSTD, "zstd")->Unit(benchmark::kMicrosecond)->Iterations(5);
BENCHMARK_CAPTURE(BM_RNTuple_ATLAS, BM_RNTuple_ATLAS_None, "none")->Unit(benchmark::kMicrosecond)->Iterations(5);

BENCHMARK_MAIN(); 