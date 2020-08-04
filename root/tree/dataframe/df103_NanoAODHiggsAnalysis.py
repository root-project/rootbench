# This test is an adaption of the RDataFrame tutorial df103 using only the 4el and 4mu channels

import ROOT
import os
ROOT.gROOT.SetBatch(True)
import pytest

def reco_higgs_to_4mu(df):
    """Reconstruct Higgs from four muons"""
    # Filter interesting events
    df_base = selection_4mu(df)

    # Reconstruct Z systems
    df_z_idx = df_base.Define("Z_idx", "reco_zz_to_4l(Muon_pt, Muon_eta, Muon_phi, Muon_mass, Muon_charge)")

    # Cut on distance between muons building Z systems
    df_z_dr = df_z_idx.Filter("filter_z_dr(Z_idx, Muon_eta, Muon_phi)", "Delta R separation of muons building Z system")

    # Compute masses of Z systems
    df_z_mass = df_z_dr.Define("Z_mass", "compute_z_masses_4l(Z_idx, Muon_pt, Muon_eta, Muon_phi, Muon_mass)")

    # Cut on mass of Z candidates
    df_z_cut = filter_z_candidates(df_z_mass)

    # Reconstruct H mass
    df_h_mass = df_z_cut.Define("H_mass", "compute_higgs_mass_4l(Z_idx, Muon_pt, Muon_eta, Muon_phi, Muon_mass)")

    return df_h_mass


def selection_4mu(df):
    """Select interesting events with four muons"""
    df_ge4m = df.Filter("nMuon>=4", "At least four muons")

    df_iso = df_ge4m.Filter("All(abs(Muon_pfRelIso04_all)<0.40)", "Require good isolation")
    df_kin = df_iso.Filter("All(Muon_pt>5) && All(abs(Muon_eta)<2.4)", "Good muon kinematics")
    df_ip3d = df_kin.Define("Muon_ip3d", "sqrt(Muon_dxy*Muon_dxy + Muon_dz*Muon_dz)")
    df_sip3d = df_ip3d.Define("Muon_sip3d", "Muon_ip3d/sqrt(Muon_dxyErr*Muon_dxyErr + Muon_dzErr*Muon_dzErr)")
    df_pv = df_sip3d.Filter("All(Muon_sip3d<4) && All(abs(Muon_dxy)<0.5) && All(abs(Muon_dz)<1.0)",
                            "Track close to primary vertex with small uncertainty")
    df_2p2n = df_pv.Filter("nMuon==4 && Sum(Muon_charge==1)==2 && Sum(Muon_charge==-1)==2",
                           "Two positive and two negative muons")

    return df_2p2n


def filter_z_candidates(df):
    """Apply selection on reconstructed Z candidates"""
    df_z1_cut = df.Filter("Z_mass[0] > 40 && Z_mass[0] < 120", "Mass of first Z candidate in [40, 120]")
    df_z2_cut = df_z1_cut.Filter("Z_mass[1] > 12 && Z_mass[1] < 120", "Mass of second Z candidate in [12, 120]")

    return df_z2_cut


ROOT.gInterpreter.Declare("""\
using namespace ROOT::VecOps;
using RNode = ROOT::RDF::RNode;
using rvec_f = const RVec<float> &;
using rvec_i = const RVec<int> &;
const auto z_mass = 91.2;

// Reconstruct two Z candidates from four leptons of the same kind
RVec<RVec<size_t>> reco_zz_to_4l(rvec_f pt, rvec_f eta, rvec_f phi, rvec_f mass, rvec_i charge)
{
   RVec<RVec<size_t>> idx(2);
   idx[0].reserve(2); idx[1].reserve(2);

   // Find first lepton pair with invariant mass closest to Z mass
   auto idx_cmb = Combinations(pt, 2);
   auto best_mass = -1;
   size_t best_i1 = 0; size_t best_i2 = 0;
   for (size_t i = 0; i < idx_cmb[0].size(); i++) {
      const auto i1 = idx_cmb[0][i];
      const auto i2 = idx_cmb[1][i];
      if (charge[i1] != charge[i2]) {
         ROOT::Math::PtEtaPhiMVector p1(pt[i1], eta[i1], phi[i1], mass[i1]);
         ROOT::Math::PtEtaPhiMVector p2(pt[i2], eta[i2], phi[i2], mass[i2]);
         const auto this_mass = (p1 + p2).M();
         if (std::abs(z_mass - this_mass) < std::abs(z_mass - best_mass)) {
            best_mass = this_mass;
            best_i1 = i1;
            best_i2 = i2;
         }
      }
   }
   idx[0].emplace_back(best_i1);
   idx[0].emplace_back(best_i2);

   // Reconstruct second Z from remaining lepton pair
   for (size_t i = 0; i < 4; i++) {
      if (i != best_i1 && i != best_i2) {
         idx[1].emplace_back(i);
      }
   }

   // Return indices of the pairs building two Z bosons
   return idx;
}

// Compute Z masses from four leptons of the same kind and sort ascending in distance to Z mass
RVec<float> compute_z_masses_4l(const RVec<RVec<size_t>> &idx, rvec_f pt, rvec_f eta, rvec_f phi, rvec_f mass)
{
   RVec<float> z_masses(2);
   for (size_t i = 0; i < 2; i++) {
      const auto i1 = idx[i][0]; const auto i2 = idx[i][1];
      ROOT::Math::PtEtaPhiMVector p1(pt[i1], eta[i1], phi[i1], mass[i1]);
      ROOT::Math::PtEtaPhiMVector p2(pt[i2], eta[i2], phi[i2], mass[i2]);
      z_masses[i] = (p1 + p2).M();
   }
   if (std::abs(z_masses[0] - z_mass) < std::abs(z_masses[1] - z_mass)) {
      return z_masses;
   } else {
      return Reverse(z_masses);
   }
}

// Compute mass of Higgs from four leptons of the same kind
float compute_higgs_mass_4l(const RVec<RVec<size_t>> &idx, rvec_f pt, rvec_f eta, rvec_f phi, rvec_f mass)
{
   const auto i1 = idx[0][0]; const auto i2 = idx[0][1];
   const auto i3 = idx[1][0]; const auto i4 = idx[1][1];
   ROOT::Math::PtEtaPhiMVector p1(pt[i1], eta[i1], phi[i1], mass[i1]);
   ROOT::Math::PtEtaPhiMVector p2(pt[i2], eta[i2], phi[i2], mass[i2]);
   ROOT::Math::PtEtaPhiMVector p3(pt[i3], eta[i3], phi[i3], mass[i3]);
   ROOT::Math::PtEtaPhiMVector p4(pt[i4], eta[i4], phi[i4], mass[i4]);
   return (p1 + p2 + p3 + p4).M();
}

bool filter_z_dr(const RVec<RVec<size_t>> &idx, rvec_f eta, rvec_f phi)
{
   for (size_t i = 0; i < 2; i++) {
      const auto i1 = idx[i][0];
      const auto i2 = idx[i][1];
      const auto dr = DeltaR(eta[i1], eta[i2], phi[i1], phi[i2]);
      if (dr < 0.02) {
         return false;
      }
   }
   return true;
};

bool pt_cuts(rvec_f mu_pt, rvec_f el_pt)
{
   auto mu_pt_sorted = Reverse(Sort(mu_pt));
   if (mu_pt_sorted[0] > 20 && mu_pt_sorted[1] > 10) {
      return true;
   }
   auto el_pt_sorted = Reverse(Sort(el_pt));
   if (el_pt_sorted[0] > 20 && el_pt_sorted[1] > 10) {
      return true;
   }
   return false;
}

bool dr_cuts(rvec_f mu_eta, rvec_f mu_phi, rvec_f el_eta, rvec_f el_phi)
{
   auto mu_dr = DeltaR(mu_eta[0], mu_eta[1], mu_phi[0], mu_phi[1]);
   auto el_dr = DeltaR(el_eta[0], el_eta[1], el_phi[0], el_phi[1]);
   if (mu_dr < 0.02 || el_dr < 0.02) {
      return false;
   }
   return true;
}
""")

def reco_higgs_to_4el(df):
    """Reconstruct Higgs from four electrons"""
    # Filter interesting events
    df_base = selection_4el(df)

    # Reconstruct Z systems
    df_z_idx = df_base.Define("Z_idx",
                              "reco_zz_to_4l(Electron_pt, Electron_eta, Electron_phi, Electron_mass, Electron_charge)")

    # Cut on distance between Electrons building Z systems
    df_z_dr = df_z_idx.Filter("filter_z_dr(Z_idx, Electron_eta, Electron_phi)",
                              "Delta R separation of Electrons building Z system")

    # Compute masses of Z systems
    df_z_mass = df_z_dr.Define("Z_mass",
                               "compute_z_masses_4l(Z_idx, Electron_pt, Electron_eta, Electron_phi, Electron_mass)")

    # Cut on mass of Z candidates
    df_z_cut = filter_z_candidates(df_z_mass)

    # Reconstruct H mass
    df_h_mass = df_z_cut.Define("H_mass",
                                "compute_higgs_mass_4l(Z_idx, Electron_pt, Electron_eta, Electron_phi, Electron_mass)")

    return df_h_mass


def selection_4el(df):
    """Select interesting events with four electrons"""
    df_ge4el = df.Filter("nElectron>=4", "At least our electrons")
    df_iso = df_ge4el.Filter("All(abs(Electron_pfRelIso03_all)<0.40)", "Require good isolation")
    df_kin = df_iso.Filter("All(Electron_pt>7) && All(abs(Electron_eta)<2.5)", "Good Electron kinematics")
    df_ip3d = df_kin.Define("Electron_ip3d", "sqrt(Electron_dxy*Electron_dxy + Electron_dz*Electron_dz)")
    df_sip3d = df_ip3d.Define("Electron_sip3d",
                              "Electron_ip3d/sqrt(Electron_dxyErr*Electron_dxyErr + Electron_dzErr*Electron_dzErr)")
    df_pv = df_sip3d.Filter("All(Electron_sip3d<4) && All(abs(Electron_dxy)<0.5) && All(abs(Electron_dz)<1.0)",
                            "Track close to primary vertex with small uncertainty")
    df_2p2n = df_pv.Filter("nElectron==4 && Sum(Electron_charge==1)==2 && Sum(Electron_charge==-1)==2",
                           "Two positive and two negative electrons")

    return df_2p2n


def plot(sig, bkg, data, x_label, filename):
    """
    Plot invariant mass for signal and background processes from simulated
    events overlay the measured data.
    """
    # Canvas and general style options
    ROOT.gStyle.SetOptStat(0)
    ROOT.gStyle.SetTextFont(42)
    d = ROOT.TCanvas("d", "", 800, 700)
    # Make sure the canvas stays in the list of canvases after the macro execution
    ROOT.SetOwnership(d, False)
    d.SetLeftMargin(0.15)

    # Get signal and background histograms and stack them to show Higgs signal
    # on top of the background process
    h_bkg = bkg
    h_cmb = sig.Clone()

    h_cmb.Add(h_bkg)
    h_cmb.SetTitle("")
    h_cmb.GetXaxis().SetTitle(x_label)
    h_cmb.GetXaxis().SetTitleSize(0.04)
    h_cmb.GetYaxis().SetTitle("N_{Events}")
    h_cmb.GetYaxis().SetTitleSize(0.04)
    h_cmb.SetLineColor(ROOT.kRed)
    h_cmb.SetLineWidth(2)
    h_cmb.SetMaximum(18)
    h_bkg.SetLineWidth(2)
    h_bkg.SetFillStyle(1001)
    h_bkg.SetLineColor(ROOT.kBlack)
    h_bkg.SetFillColor(ROOT.kAzure - 9)

    # Get histogram of data points
    h_data = data
    h_data.SetLineWidth(1)
    h_data.SetMarkerStyle(20)
    h_data.SetMarkerSize(1.0)
    h_data.SetMarkerColor(ROOT.kBlack)
    h_data.SetLineColor(ROOT.kBlack)

    # Draw histograms
    h_cmb.DrawCopy("HIST")
    h_bkg.DrawCopy("HIST SAME")
    h_data.DrawCopy("PE1 SAME")

    # Add legend
    legend = ROOT.TLegend(0.62, 0.70, 0.82, 0.88)
    legend.SetFillColor(0)
    legend.SetBorderSize(0)
    legend.SetTextSize(0.03)
    legend.AddEntry(h_data, "Data", "PE1")
    legend.AddEntry(h_bkg, "ZZ", "f")
    legend.AddEntry(h_cmb, "m_{H} = 125 GeV", "f")
    legend.Draw()

    # Add header
    cms_label = ROOT.TLatex()
    cms_label.SetTextSize(0.04)
    cms_label.DrawLatexNDC(0.16, 0.92, "#bf{CMS Open Data}")
    header = ROOT.TLatex()
    header.SetTextSize(0.03)
    header.DrawLatexNDC(0.63, 0.92, "#sqrt{s} = 8 TeV, L_{int} = 11.6 fb^{-1}")

    # Save plot
    d.SaveAs(filename)


def payload(nthreads):
    # Enable multi-threading
    if nthreads > 1:
        ROOT.ROOT.EnableImplicitMT(nthreads)
    else:
        ROOT.ROOT.DisableImplicitMT()

    # Take files from the rootbench data directory
    path = os.environ["RB_DATASETDIR"]

    # Create dataframes for signal, background and data samples

    # Signal: Higgs -> 4 leptons
    df_sig_4l = ROOT.RDataFrame("Events", os.path.join(path, "SMHiggsToZZTo4L.root"))

    # Background: ZZ -> 4 leptons
    # Note that additional background processes from the original paper
    # with minor contribution were left out for this
    # tutorial.
    df_bkg_4mu = ROOT.RDataFrame("Events", os.path.join(path, "ZZTo4mu.root"))
    df_bkg_4el = ROOT.RDataFrame("Events", os.path.join(path, "ZZTo4e.root"))

    # CMS data taken in 2012 (11.6 fb^-1 integrated luminosity)
    df_data_doublemu = ROOT.RDataFrame("Events", (os.path.join(path, f) for f in ["Run2012B_DoubleMuParked.root", "Run2012C_DoubleMuParked.root"]))
    df_data_doubleel = ROOT.RDataFrame("Events", (os.path.join(path, f) for f in ["Run2012B_DoubleElectron.root", "Run2012C_DoubleElectron.root"]))

    # Number of bins for all histograms
    nbins = 36

    # Weights
    luminosity = 11580.0  # Integrated luminosity of the data samples

    xsec_ZZTo4mu = 0.077  # ZZ->4mu: Standard Model cross-section
    nevt_ZZTo4mu = 1499064.0  # ZZ->4mu: Number of simulated events

    xsec_ZZTo4el = 0.077  # ZZ->4el: Standard Model cross-section
    nevt_ZZTo4el = 1499093.0  # ZZ->4el: Number of simulated events

    xsec_SMHiggsToZZTo4L = 0.0065  # H->4l: Standard Model cross-section
    nevt_SMHiggsToZZTo4L = 299973.0  # H->4l: Number of simulated events
    scale_ZZTo4l = 1.386  # ZZ->4l: Scale factor for ZZ to four leptons

    weight_sig_4mu = luminosity * xsec_SMHiggsToZZTo4L / nevt_SMHiggsToZZTo4L
    weight_bkg_4mu = luminosity * xsec_ZZTo4mu * scale_ZZTo4l / nevt_ZZTo4mu

    weight_sig_4el = luminosity * xsec_SMHiggsToZZTo4L / nevt_SMHiggsToZZTo4L
    weight_bkg_4el = luminosity * xsec_ZZTo4el * scale_ZZTo4l / nevt_ZZTo4el

    # Reconstruct Higgs to 4 muons
    df_sig_4mu_reco = reco_higgs_to_4mu(df_sig_4l)

    df_h_sig_4mu = df_sig_4mu_reco.Define("weight", "{}".format(weight_sig_4mu))\
                                  .Histo1D(("h_sig_4mu", "", nbins, 70, 180), "H_mass", "weight")

    df_bkg_4mu_reco = reco_higgs_to_4mu(df_bkg_4mu)

    df_h_bkg_4mu = df_bkg_4mu_reco.Define("weight", "{}".format(weight_bkg_4mu))\
                                  .Histo1D(("h_bkg_4mu", "", nbins, 70, 180), "H_mass", "weight")

    df_data_4mu_reco = reco_higgs_to_4mu(df_data_doublemu)

    df_h_data_4mu = df_data_4mu_reco.Define("weight", "1.0")\
                                    .Histo1D(("h_data_4mu", "", nbins, 70, 180), "H_mass", "weight")

    # Reconstruct Higgs to 4 electrons
    df_sig_4el_reco = reco_higgs_to_4el(df_sig_4l)

    df_h_sig_4el = df_sig_4el_reco.Define("weight", "{}".format(weight_sig_4el))\
                                  .Histo1D(("h_sig_4el", "", nbins, 70, 180), "H_mass", "weight")

    df_bkg_4el_reco = reco_higgs_to_4el(df_bkg_4el)

    df_h_bkg_4el = df_bkg_4el_reco.Define("weight", "{}".format(weight_bkg_4el))\
                                  .Histo1D(("h_bkg_4el", "", nbins, 70, 180), "H_mass", "weight")

    df_data_4el_reco = reco_higgs_to_4el(df_data_doubleel)

    df_h_data_4el = df_data_4el_reco.Define("weight", "1.0")\
                                    .Histo1D(("h_data_4el", "", nbins, 70, 180), "H_mass", "weight")

    # Trigger event loops and retrieve histograms
    signal_4mu = df_h_sig_4mu.GetValue()
    background_4mu = df_h_bkg_4mu.GetValue()
    data_4mu = df_h_data_4mu.GetValue()

    signal_4el = df_h_sig_4el.GetValue()
    background_4el = df_h_bkg_4el.GetValue()
    data_4el = df_h_data_4el.GetValue()

    # Make plots
    plot(signal_4mu, background_4mu, data_4mu, "m_{4#mu} (GeV)", "higgs_4mu.pdf")
    plot(signal_4el, background_4el, data_4el, "m_{4e} (GeV)", "higgs_4el.pdf")


def test_df103_NanoAODHiggsAnalysis_imt(benchmark):
    benchmark.pedantic(payload, kwargs={'nthreads': 8}, iterations=1, rounds=1)


def test_df103_NanoAODHiggsAnalysis_noimt(benchmark):
    benchmark.pedantic(payload, kwargs={'nthreads': 1}, iterations=1, rounds=1)
