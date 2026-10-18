# To get the data to produce this plot, run benchmark with:
#     ./benchRooFitBackends -n 1000000 --benchmark_format=json --benchmark_out=benchRooFitBackends.json

import ROOT
import numpy as np
import json
import sys
from collections import defaultdict

ROOT.gROOT.SetBatch(True)

json_name = sys.argv[1]
base_name = json_name.split(".")[0]

f = open(json_name, "rb")
json_object = json.load(f)["benchmarks"]
f.close()

timing_dict = defaultdict(dict)

labels_in_json = []

for bm in json_object:
    name, backend = bm["name"].split("/")[0].split("_Fit")
    timing_dict[name][backend] = bm["real_time"]
    if len(labels_in_json) == 0 or labels_in_json[-1] != name:
        labels_in_json.append(name)

# labels_in_json = [
# "Gaus",
# "GausXS",
# "AddPdf",
# "ProdPdf",
# "FitModel",
# ]

backends = ["CUDA"]
reference_backend = "CPU"

timings = {}

print(timing_dict)

for b in backends + [reference_backend]:
    l = list()

    for label in labels_in_json:
        l.append(timing_dict[label][b])

    timings[b] = np.array(l)

# normalize to ratios
for b in backends:
    timings[b] = timings[reference_backend] / timings[b]

print(timings)

labels_dict = {
    "Gaus": "Gaussian",
    "GausXS": "#splitline{Gaussian}{(with #sigma as observable)}",
    "AddPdf": "#splitline{Gaussian}{plus exponential}",
    "ProdPdf": "#splitline{Mixture 1:}{#splitline{(gauss + gauss)}{#splitline{x (gauss + poly)}{ x gamma}}}",
    "FitModel": "#splitline{#splitline{Mixture 2:}{gamma + gamma}}{ + gauss + gauss + poly}",
    "BDecayWithMixing": "#splitline{RooBMixDecay}{perfect resolution}",
    "BDecayGaussResolution": "#splitline{RooBMixDecay}{Gaussian res.}",
    "BDecayDoubleGauss": "#splitline{RooBMixDecay}{Double-Gaussian res.}",
}

labels = [labels_dict[l] for l in labels_in_json]

nx = len(timings[reference_backend])
nb = len(backends)

# cb = ROOT.TCanvas("cb","cb",900,400)
cb = ROOT.TCanvas("cb", "cb", int(180 * len(labels) * 2), int(400 * 2))
cb.SetGrid()
cb.SetBottomMargin(0.16)

# ROOT.gROOT.GetColor(9).SetRGB(12.2  / 100, 46.7 / 100, 70.6 / 100)
# ROOT.gROOT.GetColor(46).SetRGB(100.0 / 100, 49.8 / 100,  5.5 / 100)
# ROOT.gROOT.GetColor(9).SetRGB(17.3  / 100, 62.7 / 100, 17.3 / 100)

y_max = 1
for b in backends:
    y_max = max(y_max, np.max(timings[b]) + 3)

ROOT.gStyle.SetHistMinimumZero()

h1b = ROOT.TH1F(
    "h1b", "RooFit: speedup in benchmark fits with the CUDA backend relative to the CPU backend (1 million events)", nx, 0, nx
)
h1b.SetFillColor(9)
h1b.SetBarWidth(0.8 / nb)
h1b.SetBarOffset(0.1)
h1b.SetStats(0)
h1b.SetMinimum(-0.1)
h1b.SetMaximum(y_max)

h1b.GetYaxis().SetTitle("Relative Speedup")
h1b.GetYaxis().SetTitleSize(0.045)
h1b.GetXaxis().SetLabelSize(0.055)
# h1b.GetXaxis().SetLabelOffset(0.1)

for i in range(nx):
    h1b.SetBinContent(i + 1, timings["CUDA"][i])
    h1b.GetXaxis().SetBinLabel(i + 1, labels[i])

h1b.Draw("b")

legend = ROOT.TLegend(0.1, 0.7, 0.46, 0.9)
legend.AddEntry(h1b, "CUDA relative to CPU (single thread)", "f")
legend.Draw()

cb.SaveAs(base_name + ".png")
cb.SaveAs(base_name + ".pdf")
