#!/usr/bin/env python
# coding: utf-8

# https://github.com/root-project/root/pull/17926

import argparse
import json
import os
import sys

import numpy as np

parser = argparse.ArgumentParser(
    description="Plot the timing breakdown of the RooFit evaluation backends."
)
parser.add_argument(
    "experiments",
    nargs="*",
    default=["atlas"],
    metavar="DIR",
    help="directory holding {legacy,cpu,codegen}.log (default: atlas)",
)
parser.add_argument(
    "--json",
    action="store_true",
    help="write the parsed timings to stdout as JSON instead of plotting; the "
    "result is a tidy table that pandas reads directly with pd.read_json()",
)
# Parsed before importing ROOT, so that --help stays instant and PyROOT never
# gets a look at sys.argv.
args = parser.parse_args()

# Only the plot needs ROOT, so --json also works without PyROOT available.
if not args.json:
    import ROOT

    # ROOT style
    ROOT.gROOT.SetBatch(True)
    ROOT.gStyle.SetOptStat(0)


def info(*args_):
    """Progress output, on stderr so that --json keeps stdout to itself."""
    print(*args_, file=sys.stderr)


def time_string_to_seconds(s):
    s = s.replace("ms", "*1e-3")
    s = s.replace("s", "")
    s = s.replace("min", "*60+")
    s = s.replace("m", "*60+")
    s = s.replace("μ", "*1e-6")

    return float(eval(s))


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


def parse_output(filename):
    """Parse output generated like
    sh -c { time root -q -b 'atlasHiggsBackendComparison.C("cpu")'; } &> filename
    """

    info(f"--- {filename} ---")

    with open(filename, "r") as f:
        lines = f.read().split("\n")

    relevant_lines = {}

    for line in lines:
        for key, val in steps.items():
            if val in line:
                time_str = line.split(val)[-1]
                relevant_lines[key] = time_string_to_seconds(time_str)

    # Without the "user" line from the surrounding `time` there is no bar height
    # to subtract the measured steps from, and "Other" would come out negative.
    if "Total" not in relevant_lines:
        info(f"{filename}: no 'user' line from `time`, dropping this backend")
        return None

    # Replace Total with other:
    measured = 0.0
    for key, val in relevant_lines.items():
        if key != "Total":
            measured = measured + val

    # Fill irrelevant steps with zeros:
    for key in steps:
        if key not in relevant_lines:
            relevant_lines[key] = 0.0

    # merge NegativeG2LineSearch into Seeding step
    relevant_lines["Seeding step"] += relevant_lines["NegativeG2LineSearch"]
    del relevant_lines["NegativeG2LineSearch"]

    relevant_lines["Other"] = relevant_lines["Total"] - measured
    del relevant_lines["Total"]

    # We don't care of measuring Hesse (for now)
    del relevant_lines["Hesse"]

    for (
        k,
        v,
    ) in relevant_lines.items():
        info(f"{k}  : {v}")

    return relevant_lines


# Bars appear left to right in this order. A backend whose log is absent is
# dropped rather than being an error, so a run without the legacy backend simply
# yields a two-bar plot.
backend_names = {"RooFit legacy": "legacy", "RooFit": "cpu", "RooFit AD": "codegen"}

# The legacy backend no longer exists in recent ROOT, so out of the box this
# produces a two-bar plot. To compare ROOT versions instead of backends, relabel:
# backend_names = {"ROOT 6.32": "legacy", "ROOT 6.40": "cpu", "ROOT 6.40 AD": "codegen"}

# One row per (run, backend, step) for --json: a tidy table stays easy to
# concatenate across runs and to pivot downstream.
records = []

for experiment in args.experiments:

    # The directory may be given as a path, but the plot is named after it.
    tag = os.path.basename(experiment.rstrip("/")) or experiment

    parsed = {}
    for backend, name in backend_names.items():
        filename = os.path.join(experiment, f"{name}.log")
        if not os.path.exists(filename):
            info(f"{filename}: missing, dropping the '{backend}' bar")
            continue
        result = parse_output(filename)
        if result is not None:
            parsed[backend] = result

    # Only the backends that actually produced a log, in the order above.
    backends = list(parsed)

    if not backends:
        info(f"{experiment}: no usable logs, skipping")
        continue

    if args.json:
        # Every backend carries the same steps (the ones it does not have are
        # zero-filled), so the first one fixes a stable step order.
        for backend in backends:
            for step in parsed[backends[0]]:
                records.append(
                    {
                        "run": tag,
                        "backend": backend,
                        "step": step,
                        "seconds": parsed[backend][step],
                    }
                )
        continue

    data = {}
    for key in parsed[backends[0]]:
        data[key] = np.array([parsed[backend][key] for backend in backends])

    jit_color = np.array([0.06, 0.21, 0.70])

    colors = {
        "NLL creation": [0.30, 0.70, 0.50],
        "Function JIT": (1.0 - 0.3 * (1.0 - jit_color)),
        "Gradient generation": (1.0 - 0.6 * (1.0 - jit_color)),
        "Gradient to machine code": (1.0 - (1.0 - jit_color)),
        "Seeding step": [0.70, 0.05, 0.70],
        "Minimization": [1.0, 0.2, 0.2],
        "Hesse": [1.0, 0.9, 0.3],
        "Other": [0.8, 0.8, 0.8],
    }

    # Convert color float to ROOT TColor index
    root_colors = {}
    for label, (r, g, b) in colors.items():
        root_colors[label] = ROOT.TColor.GetColor(int(r * 255), int(g * 255), int(b * 255))

    # ROOT histogram stack
    stack = ROOT.THStack("stack", "")
    histos = {}

    nbins = len(backends)

    for label, values in data.items():
        h = ROOT.TH1F(label, label, nbins*2 + 1, 0, nbins*2 + 1)

        for i, v in enumerate(values):
            h.SetBinContent(2*i+1 + 1, v)   # fill every second bin

        h.SetFillColor(root_colors[label])

        # invisible outline
        h.SetLineColor(0)
        h.SetLineWidth(0)

        histos[label] = h

        stack.Add(h)

    # Legend geometry in NDC, also used below to keep bars out from under it.
    leg_x1, leg_y1, leg_x2, leg_y2 = 0.40, 0.55, 0.90, 0.88

    # Canvas
    c = ROOT.TCanvas(f"c_{tag}", "c", 2 * 800, 2 * 500)

    # Draw stack
    stack.Draw("hist")

    # The legend is filled opaque, so a bar drawn underneath it is simply hidden
    # above its lower edge. That does not show up while the tallest backend sits
    # to the left of the legend, but as soon as it is dropped the axis rescales
    # and the remaining bars run into the legend. Give the y axis enough headroom
    # that every bar the legend spans horizontally stays below it.
    margin_lo, margin_hi = 0.1, 0.9  # default pad margins, same on both axes
    totals = np.array(list(data.values())).sum(axis=0)
    bar_x = [
        margin_lo + (2 * i + 1.5) / (2 * nbins + 1) * (margin_hi - margin_lo)
        for i in range(nbins)
    ]
    under_legend = [t for t, x in zip(totals, bar_x) if leg_x1 <= x <= leg_x2]
    if under_legend:
        needed = max(under_legend) * (margin_hi - margin_lo) / (leg_y1 - margin_lo)
        if needed > 1.05 * totals.max():  # otherwise ROOT's own scaling is fine
            stack.SetMaximum(needed)

    stack.GetYaxis().SetTitle("Time [s]")
    # stack.GetXaxis().SetTitle("Evaluation backend")
    xaxis = stack.GetXaxis()
    xaxis.SetLabelSize(0.05)
    # xaxis.RotateTitle(False)
    xaxis.SetTitleOffset(1.5)  # closer to the axis

    # Set backend labels on x-axis
    axis = stack.GetXaxis()
    for i, backend in enumerate(backends):
        axis.SetBinLabel(2*i+1 + 1, backend)

    # Legend
    legend = ROOT.TLegend(leg_x1, leg_y1, leg_x2, leg_y2)
    legend.SetNColumns(2)
    legend.SetBorderSize(0)
    for label, h in histos.items():
        legend.AddEntry(h, label, "f")
    legend.SetBorderSize(0)
    legend.Draw()

    # Optional grid
    c.SetGrid()

    # c.SaveAs(f"plot_{tag}_root.png")
    c.SaveAs(f"plot_roofit_ad_{tag}_root.pdf")

if args.json:
    json.dump(records, sys.stdout, indent=2)
    sys.stdout.write("\n")
