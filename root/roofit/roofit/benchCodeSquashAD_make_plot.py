#!/usr/bin/env python
# coding: utf-8


# Run on the output of benchCodeSquashAD piped into a file:
# $ ./benchCodeSquashAD &> benchCodeSquashAD.out
filename = "benchCodeSquashAD.out"


import numpy as np
import pandas as pd


steps = {
    "NLL creation": "Creation of NLL object took ",
    "Function JIT": "Function JIT time: ",
    "Gradient generation": "Gradient generation time: ",
    "Gradient to machine code": "Gradient IR to machine code time: ",
    "Seeding step": "MnSeedGenerator Evaluated function and gradient in ",
    "NegativeG2LineSearch": "NegativeG2LineSearch Done after ",
    "Minimization": "VariableMetricBuilder Stop iterating after ",
    "Hesse": "MnHesse Done after ",
    "Total": "user	",
}


def time_string_to_seconds(s):
    s = s.replace("ms", "*1e-3")
    s = s.replace("s", "")
    s = s.replace("min", "*60+")
    s = s.replace("m", "*60+")
    s = s.replace("μ", "*1e-6")

    return float(eval(s))


with open(filename, "r") as f:
    lines = f.read().split("\n")


def is_relevant(line):
    if "NegativeG2LineSearch" in line:
        return False
    if "iterations" in line:
        return True
    if "nparams" in line:
        return True
    if "FVAL  = " in line:
        return True
    for key, val in steps.items():
        if val in line:
            return True
    return False


lines = list(filter(is_relevant, lines))


names = ["NllReferenceMinimization", "NllBatchModeMinimization", "NllCodeSquash_NumDiff", "NllCodeSquash_AD"]

backends = {
    "NllReferenceMinimization": "legacy",
    "NllBatchModeMinimization": "RooFit",
    "NllCodeSquash_NumDiff": "Hardcoded",
    "NllCodeSquash_AD": "RooFit AD",
}

nll_line = {
    "NllReferenceMinimization": 1,
    "NllBatchModeMinimization": 2,
    "NllCodeSquash_NumDiff": 3,
    "NllCodeSquash_AD": 7,
}


def analyze_block(lines):
    # print(lines)
    data = dict()

    name = lines[12].split("/")[0]

    data["backend"] = backends[name]

    def line_to_seconds(l):
        l = l.replace(" min ", "min")
        return time_string_to_seconds(" ".join(l.split(" ")[-2:]))

    data["create_nll"] = line_to_seconds(lines[nll_line[name]])
    data["seeding"] = line_to_seconds(lines[9])
    data["migrad"] = line_to_seconds(lines[10])
    data["nparams"] = int(lines[0].split(" ")[-1]) - 1
    data["fval"] = float(lines[11].split(" ")[-1])

    data["jitting"] = sum(line_to_seconds(lines[i]) for i in [4, 5, 6])

    return data


m_block = 13


datas = []
i = 0
while i < len(lines):
    datas.append(analyze_block(lines[i : i + m_block]))
    i += m_block


df = pd.DataFrame(datas)
df = df.query("nparams > 10 and nparams < 2500 and backend != 'legacy'")

dfs = dict()

for backend, df_g in df.groupby("backend"):
    dfs[backend] = df_g
    nparams = df_g["nparams"]
    vals = df_g.eval("migrad + seeding")
    # vals = df_g.eval("fval")
    if backend == "codegen_no_grad":
        continue

nparams = dfs["RooFit"]["nparams"]

# Plotting with ROOT

import ROOT

# ----------------------------------------------------------------------
# ROOT setup
# ----------------------------------------------------------------------
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(0)

# c = ROOT.TCanvas("c", "Scaling study", 800, 900)
c = ROOT.TCanvas("c", "Scaling study", 800, 700)
# c = ROOT.TCanvas("c", "Scaling study", int(0.75 * 800), int(0.75 * 700))
c.Divide(1, 2)

pad_top = c.cd(1)
pad_top.SetPad(0.0, 0.32, 1.0, 1.0)
pad_top.SetBottomMargin(0.15)

pad_bottom = c.cd(2)
pad_bottom.SetPad(0.0, 0.0, 1.0, 0.32)
pad_bottom.SetTopMargin(0.05)
pad_bottom.SetBottomMargin(0.25)

# ----------------------------------------------------------------------
# Convert grouped data to ROOT TGraphs
# ----------------------------------------------------------------------
graphs = {}
jit_graphs = {}

colors = {
    "RooFit": ROOT.kBlue + 1,
    "Hardcoded": ROOT.kRed + 1,
    "RooFit AD": ROOT.kGreen + 2,
}

for backend, df_g in df.groupby("backend"):
    x = df_g["nparams"].to_numpy()
    y = df_g.eval("migrad + seeding").to_numpy()

    g = ROOT.TGraph(len(x), x.astype("float64"), y.astype("float64"))
    g.SetLineColor(colors.get(backend, ROOT.kBlack))
    g.SetLineWidth(3)
    # g.SetMarkerStyle(20)
    g.SetTitle("")
    graphs[backend] = g

    if backend == "RooFit AD":
        yjit = df_g["jitting"].to_numpy()
        gj = ROOT.TGraph(len(x), x.astype("float64"), yjit.astype("float64"))
        gj.SetLineColor(ROOT.kBlack)
        gj.SetLineStyle(2)
        gj.SetLineWidth(2)
        jit_graphs[backend] = gj

# ----------------------------------------------------------------------
# Draw top pad (timing)
# ----------------------------------------------------------------------
pad_top.cd()
frame = pad_top.DrawFrame(0, 0, df["nparams"].max(), 30, ";Number of parameters;Minimization time [s]")

frame.GetXaxis().SetLabelSize(0.05)
frame.GetXaxis().SetTitleSize(0.06)
frame.GetYaxis().SetLabelSize(0.05)
frame.GetYaxis().SetTitleSize(0.06)

legend = ROOT.TLegend(0.15, 0.65, 0.55, 0.88)
legend.SetTextSize(0.05)

for backend, g in graphs.items():
    g.Draw("LP SAME")
    legend.AddEntry(g, backend, "LP")

    if backend == "RooFit AD":
        jit_graphs[backend].Draw("L SAME")
        legend.AddEntry(jit_graphs[backend], "JIT time", "L")

legend.Draw()

# ----------------------------------------------------------------------
# Compute speedup curve
# ----------------------------------------------------------------------
df_R = dfs["RooFit"]
df_AD = dfs["RooFit AD"]

x = df_R["nparams"].to_numpy()
speedup = df_R["migrad"].values / df_AD["migrad"].values

g_speed = ROOT.TGraph(len(x), x.astype("float64"), speedup.astype("float64"))
g_speed.SetLineWidth(2)
g_speed.SetLineColor(ROOT.kBlack)

# ----------------------------------------------------------------------
# Draw bottom pad (speedup)
# ----------------------------------------------------------------------
pad_bottom.cd()
frame2 = pad_bottom.DrawFrame(0, 1, df["nparams"].max(), 4.2, ";Number of parameters;AD speedup")

# Make font sizes match the top panel
frame2.GetXaxis().SetLabelSize(0.09)
frame2.GetXaxis().SetTitleSize(0.10)
frame2.GetYaxis().SetLabelSize(0.09)
frame2.GetYaxis().SetTitleSize(0.10)

frame2.GetYaxis().SetTitleOffset(0.4)  # closer to the axis

g_speed.Draw("L SAME")

# ----------------------------------------------------------------------
# Save result
# ----------------------------------------------------------------------
c.SaveAs("scaling_study_root.png")
c.SaveAs("scaling_study_root.pdf")
