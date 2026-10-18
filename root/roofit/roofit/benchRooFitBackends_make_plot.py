# Plots the speedup of the multi-threaded CPU and the CUDA evaluation backends
# relative to the single-threaded CPU backend for all models of
# benchRooFitBackends, together with the information about the run.
#
# To get the data, run the benchmark with the RooBatchCompute library for the
# CPU architecture: the default is the generic one without vectorization, and
# "auto" picks the fastest library that the CPU supports. The setting is read
# from the ROOT configuration, e.g. a .rootrc file in the working directory:
#
#     echo "RooFit.BatchCompute: auto" > .rootrc
#     ./benchRooFitBackends --benchmark_filter='Fit(CPU|CPUMT|CUDA)/' \
#         --benchmark_repetitions=3 \
#         --benchmark_format=json --benchmark_out=benchRooFitBackends.json
#     python3 benchRooFitBackends_make_plot.py benchRooFitBackends.json
#
# Add for example --events=1000000 to fit 1M events instead of the default
# 100k. The slower fits run for a single iteration, so the repetitions give a
# spread estimate; the plot uses the median over the repetitions when the
# file has one. The plot is written next to the JSON file as PDF and PNG,
# and the timings and speedups are printed as a table.

import argparse
import json
import os
import sys

parser = argparse.ArgumentParser(description="Plot the speedups of the RooFit evaluation backends from benchRooFitBackends.")
parser.add_argument("json_file", help="JSON output of benchRooFitBackends")
parser.add_argument("--output", help="base name of the PDF and PNG files (default: like the JSON file)")
parser.add_argument("--xmax", type=float, default=30.0, help="upper end of the speedup axis (default: 30)")
# Parsed before importing ROOT, so that --help stays instant and PyROOT never
# gets a look at sys.argv.
args = parser.parse_args()

import ROOT  # noqa: E402

ROOT.gROOT.SetBatch(True)

json_name = args.json_file
base_name = args.output or os.path.splitext(json_name)[0]

with open(json_name) as f:
    results = json.load(f)

context = results["context"]

# Timings per model and backend, in the order of the benchmarks in the file.
# With --benchmark_repetitions, the file has one entry per repetition and the
# aggregates (mean, median, ...); then the median is used.
timings = {}
for bm in results["benchmarks"]:
    if bm.get("run_type", "iteration") == "aggregate" and bm.get("aggregate_name") != "median":
        continue
    model, backend = bm["name"].split("/")[0].split("_Fit")
    entry = timings.setdefault(model, {})
    if bm.get("run_type") == "aggregate" or backend not in entry:
        entry[backend] = bm["real_time"]

# The thread count of the multi-threaded CPU backend: from the context, or
# from the counter of the benchmark for older files.
num_threads = context.get("threads")
if num_threads is None:
    for bm in results["benchmarks"]:
        if "_FitCPUMT" in bm["name"] and bm.get("num_threads"):
            num_threads = int(bm["num_threads"])
            break
num_threads = int(num_threads) if num_threads else None

reference_backend = "CPU"
# Bars from top to bottom per model, with the legend entries.
backend_labels = {"CPUMT": "CPU, multi-threaded", "CUDA": "CUDA"}  # CPUMT gets the thread count in the legend
backends = [b for b in backend_labels if any(b in t for t in timings.values())]

models = [m for m in timings if reference_backend in timings[m]]
if not models:
    sys.exit(f"no {reference_backend} results in {json_name}")
if not backends:
    sys.exit(f"no {' or '.join(backend_labels)} results in {json_name}")


def speedup(model, backend):
    """Speedup of a backend relative to the reference, or None if it was not run."""
    time = timings[model].get(backend)
    return timings[model][reference_backend] / time if time else None


speedups = {b: [speedup(m, b) for m in models] for b in backends}

# Print the timings and speedups as a table.
columns = [reference_backend] + backends
print(f"{'model':24s}" + "".join(f"{c + ' [ms]':>14s}" for c in columns) + "".join(f"{c + ' x':>10s}" for c in backends))
for model in models:
    line = f"{model:24s}"
    for c in columns:
        time = timings[model].get(c)
        line += f"{time:14.1f}" if time else f"{'-':>14s}"
    for b in backends:
        value = speedup(model, b)
        line += f"{value:10.1f}" if value else f"{'-':>10s}"
    print(line)

labels_dict = {
    "Gaus": "Gaussian",
    "GausXS": "#splitline{Gaussian}{(with #sigma as observable)}",
    "AddPdf": "#splitline{Gaussian}{plus exponential}",
    "ProdPdf": "#splitline{(gauss + gauss)}{#splitline{#times (gauss + poly)}{#times gamma}}",
    "FitModel": "#splitline{gamma + 3 gauss}{+ poly, extended}",
    "BDecayWithMixing": "#splitline{RooBMixDecay}{perfect resolution}",
    "BDecayGaussResolution": "#splitline{RooDecay}{Gaussian res.}",
    "BDecayDoubleGauss": "#splitline{RooDecay}{double-Gaussian res.}",
}

# Run information, shown as a two-column table above the plot.
events = context.get("events", "")
events = f"{int(events):,}" if events.isdigit() else "unknown"
info_rows = [
    ("CPU", context.get("cpu", "unknown")),
    ("GPU", context.get("gpu", "none")),
    ("Events per fit", events),
    ("CPU threads", (str(num_threads) + " (multi-threaded CPU backend)") if num_threads else "unknown"),
    ("Software", "ROOT " + context.get("root_version", "unknown") + ", RooBatchCompute "
     + context.get("batchcompute_library", "unknown") + ", VDT: " + context.get("vdt", "unknown")),
    ("Run", context.get("date", "")[:10] + " on " + context.get("host_name", "unknown")),
]

n_models = len(models)
n_backends = len(backends)
# The range of the speedup axis is fixed, such that plots from different runs
# can be compared visually.
x_max = args.xmax

# Horizontal bars: the models are on the vertical axis (the "x" axis of the
# histogram drawn with the "hbar" option) and the speedup on the horizontal
# one. The first model is drawn at the top. The top margin holds the title and
# the run information.
canvas = ROOT.TCanvas("canvas", "canvas", 1400, 420 + 120 * n_models)
left_margin = 0.25
top_margin = 0.26
canvas.SetLeftMargin(left_margin)
canvas.SetRightMargin(0.03)
canvas.SetTopMargin(top_margin)
canvas.SetBottomMargin(0.10)
canvas.SetGridx()

ROOT.gStyle.SetHistMinimumZero()
colors = {"CPUMT": ROOT.kAzure + 1, "CUDA": ROOT.kGreen + 2}

hists = []
bar_width = 0.8 / n_backends
for i_backend, backend in enumerate(backends):
    h = ROOT.TH1F(f"h_{backend}", "", n_models, 0, n_models)
    for i_model, model in enumerate(models):
        # Reverse the order such that the first model is at the top.
        h.SetBinContent(n_models - i_model, speedups[backend][i_model] or 0.0)
        h.GetXaxis().SetBinLabel(n_models - i_model, labels_dict.get(model, model))
    h.SetFillColor(colors.get(backend, ROOT.kGray))
    h.SetBarWidth(bar_width)
    h.SetBarOffset(0.1 + (n_backends - 1 - i_backend) * bar_width)
    h.SetStats(False)
    h.SetMinimum(0.0)
    h.SetMaximum(x_max)
    hists.append(h)

first = hists[0]
first.GetXaxis().SetLabelSize(0.038)
first.GetYaxis().SetTitle("Migrad speedup relative to the single-threaded CPU backend")
first.GetYaxis().SetLabelSize(0.038)
first.GetYaxis().SetTitleSize(0.038)
first.GetYaxis().SetTitleOffset(1.1)
first.Draw("hbar")
for h in hists[1:]:
    h.Draw("hbar same")

# Print the speedup next to each bar. Bars beyond the axis range are cut, and
# their value is printed at the end of the axis.
texts = []
for i_backend, backend in enumerate(backends):
    for i_model in range(n_models):
        value = speedups[backend][i_model]
        if value is None:
            continue
        y = n_models - i_model - 1 + 0.1 + (n_backends - 1 - i_backend + 0.5) * bar_width
        text = ROOT.TLatex(min(value, 0.9 * x_max) + 0.01 * x_max, y, f"{value:.1f}#times")
        text.SetTextAlign(12)
        text.SetTextSize(0.034)
        text.Draw()
        texts.append(text)

# The legend goes into the free space above the model labels, next to the
# run information.
legend = ROOT.TLegend(0.01, 0.78, 0.23, 0.90)
legend.SetBorderSize(0)
legend.SetMargin(0.16)
legend.SetFillStyle(0)
legend.SetTextSize(0.028)
for h, backend in zip(hists, backends):
    label = backend_labels[backend]
    if backend == "CPUMT" and num_threads:
        label = f"CPU, {num_threads} threads"
    legend.AddEntry(h, label, "f")
legend.Draw()

title = ROOT.TLatex(0.5, 0.965, "RooFit evaluation backends in unbinned fits (Migrad, strategy 0)")
title.SetNDC()
title.SetTextAlign(22)
title.SetTextSize(0.036)
title.Draw()

# The two columns of the run information, aligned with the frame.
info_texts = []
row_height = 0.027
for i_row, (key, value) in enumerate(info_rows):
    y = 0.925 - (i_row + 1) * row_height
    for x, text, font in ((left_margin, key, 62), (left_margin + 0.15, value, 42)):
        latex = ROOT.TLatex(x, y, text)
        latex.SetNDC()
        latex.SetTextAlign(12)
        latex.SetTextFont(font)
        latex.SetTextSize(0.025)
        latex.Draw()
        info_texts.append(latex)

canvas.SaveAs(base_name + ".pdf")
canvas.SaveAs(base_name + ".png")
