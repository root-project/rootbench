# To get the data to produce this plot, run benchmark with:
#     ./benchRooFitBackends -n 1000000 --benchmark_format=json --benchmark_out=benchRooFitBackends.json

import ROOT
import numpy as np
import json

ROOT.gROOT.SetBatch(True)

f = open("benchRooFitBackends.json", "rb")
json_object = json.load(f)["benchmarks"]
f.close()

labels_in_json = [
    "Gaus_",
    "GausXS_",
    "AddPdf_",
    "ProdPdf_",
    "FitModel_",
]

scalar_time = []
vector_st_time = []
cuda_time = []

# Old values for ACAT 2021
# scalar_time = np.array([2632, 1069, 9784, 112000, 93000])
# vector_st_time = np.array([234, 116, 908, 12000, 15000])
# vector_mt_time = np.array([82, 39, 238, 3350, 4800])
# cuda_time = np.array([109, 63, 197, 2280, 3550])

for bm in json_object:
    name = bm["name"]
    if "FitLegacy" in name:
        scalar_time.append(bm["real_time"])
    if "FitCPU" in name:
        vector_st_time.append(bm["real_time"])
    if "FitCUDA" in name:
        cuda_time.append(bm["real_time"])

scalar_time = np.array(scalar_time)
vector_st_time = np.array(vector_st_time)
cuda_time = np.array(cuda_time)

labels = [
    "Gaussian",
    "Gaussian\n(with $\sigma$ as observable)",
    "Gaussian\nplus exponential",
    "Mixture 1:\n(gauss + gauss)\nx (gauss + poly)\n x gamma",
    "Mixture 2:\ngamma + gamma\n + gauss + gauss + poly",
]

# We don't benchmark BatchMode("cpu") with multithreading, as this is not
# implemented properly yet. Set results to zeros.
vector_mt_time = np.zeros_like(vector_st_time)

# normalize to ratios
vector_st_time = scalar_time / vector_st_time
# vector_mt_time = scalar_time / vector_mt_time
cuda_time = scalar_time / cuda_time
scalar_time = scalar_time / scalar_time

nx = len(vector_st_time)
labels = [
    "Gaussian",
    "#splitline{Gaussian}{(with #sigma as observable)}",
    "#splitline{Gaussian}{plus exponential}",
    "#splitline{Mixture 1:}{#splitline{(gauss + gauss)}{#splitline{x (gauss + poly)}{ x gamma}}}",
    "#splitline{#splitline{Mixture 2:}{gamma + gamma}}{ + gauss + gauss + poly}",
]

# cb = ROOT.TCanvas("cb","cb",900,400)
cb = ROOT.TCanvas("cb", "cb", int(900 * 2), int(400 * 2))
cb.SetGrid()
cb.SetBottomMargin(0.16)

# ROOT.gROOT.GetColor(9).SetRGB(12.2  / 100, 46.7 / 100, 70.6 / 100)
# ROOT.gROOT.GetColor(46).SetRGB(100.0 / 100, 49.8 / 100,  5.5 / 100)
# ROOT.gROOT.GetColor(9).SetRGB(17.3  / 100, 62.7 / 100, 17.3 / 100)

y_max = 35

ROOT.gStyle.SetHistMinimumZero()

h1b = ROOT.TH1F("h1b", "RooFit: speedup in benchmark fits relative to scalar mode (1 million events)", nx, 0, nx)
h1b.SetFillColor(9)
h1b.SetBarWidth(0.8 / 3)
h1b.SetBarOffset(0.1)
h1b.SetStats(0)
h1b.SetMinimum(-0.1)
h1b.SetMaximum(y_max)

h1b.GetYaxis().SetTitle("Relative Speedup")
h1b.GetYaxis().SetTitleSize(0.045)
h1b.GetXaxis().SetLabelSize(0.055)
# h1b.GetXaxis().SetLabelOffset(0.1)

for i in range(len(vector_st_time) + 1):
    h1b.SetBinContent(i, vector_st_time[i - 1])
    h1b.GetXaxis().SetBinLabel(i, labels[i - 1])
    # h1b.GetXaxis().ChangeLabel(
    # labNum = i,
    # labAngle = -1.,
    # labSize = -1.,
    # labAlign = -1,
    # labColor = -1,
    # labFont = -1,
    # labText = "")
    # # labText = labels[i-1])

h1b.Draw("b")

h2b = ROOT.TH1F("h2b", "h2b", nx, 0, nx)

h2b.SetFillColor(46)
h2b.SetBarWidth(0.8 / 3)
h2b.SetBarOffset(0.1 + 0.8 / 3)
h2b.SetStats(0)
h2b.SetMinimum(-1)
h2b.SetMaximum(y_max)
for i in range(len(vector_mt_time) + 1):
    h2b.SetBinContent(i, vector_mt_time[i - 1])
h2b.Draw("b same")

h3b = ROOT.TH1F("h3b", "h3b", nx, 0, nx)

h3b.SetFillColor(8)
h3b.SetBarWidth(0.8 / 3)
h3b.SetBarOffset(0.1 + 2 * 0.8 / 3)
h3b.SetStats(0)
h3b.SetMinimum(-1)
h3b.SetMaximum(y_max)
for i in range(len(vector_mt_time) + 1):
    h3b.SetBinContent(i, cuda_time[i - 1])

h3b.Draw("b same")

legend = ROOT.TLegend(0.1, 0.7, 0.46, 0.9)
# legend->SetHeader("The Legend Title","C"); // option "C" allows to center the heade
legend.AddEntry(h1b, "Vectorized (single thread)", "f")
legend.AddEntry(h2b, "Vectorized (24 threads)", "f")
legend.AddEntry(h3b, "CUDA (RTX 3070 gaming GPU)", "f")
legend.Draw()

cb.SaveAs("benchRooFitBackends.png")
cb.SaveAs("benchRooFitBackends.pdf")
