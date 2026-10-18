# Plots the cost of the RooFit evaluation backends for all models of
# benchRooFitBackends: the median wall time of a fit divided by the number of
# likelihood evaluations and the number of events, so that models with very
# different fit times and runs with different numbers of events can be shown
# on one axis. The speedups between the backends are distances on the
# logarithmic axis. A second run can be overlaid with --compare, e.g. to
# compare machines; its markers are hollow.
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
#     python3 benchRooFitBackends_make_plot.py benchRooFitBackends.json \
#         [--compare other_machine.json]
#
# Add for example --events=1000000 to fit 1M events instead of the default
# 100k. The slower fits run for a single iteration, so the repetitions give a
# spread estimate; the plot uses the median over the repetitions when the
# file has one. The plot is written next to the JSON file as PDF and PNG,
# and the timings are printed as a table.

import argparse
import json
import os
import re
import sys

parser = argparse.ArgumentParser(
    description="Plot the cost per likelihood evaluation and event of the RooFit evaluation backends "
    "from benchRooFitBackends."
)
parser.add_argument("json_file", help="JSON output of benchRooFitBackends (filled markers)")
parser.add_argument("--compare", metavar="JSON_FILE", help="second run to overlay (hollow markers)")
parser.add_argument("--output", help="base name of the PDF and PNG files (default: like the JSON file)")
parser.add_argument("--xmin", type=float, default=0.1, help="lower end of the axis in ns (default: 0.1)")
parser.add_argument("--xmax", type=float, default=1000.0, help="upper end of the axis in ns (default: 1000)")
# Parsed before importing ROOT, so that --help stays instant and PyROOT never
# gets a look at sys.argv.
args = parser.parse_args()

import ROOT  # noqa: E402

ROOT.gROOT.SetBatch(True)

base_name = args.output or os.path.splitext(args.json_file)[0]

# Backends in the order of the legend, with marker styles (filled, hollow) and colors.
backend_styles = {
    "CPU": ("CPU, 1 thread", 21, 25, ROOT.kGray + 2),
    "CPUMT": ("CPU, all threads", 22, 26, ROOT.kAzure + 1),
    "CUDA": ("CUDA", 20, 24, ROOT.kGreen + 2),
}


def short_cpu_name(name):
    """E.g. "AMD Ryzen 9 5950X 16-Core Processor" -> "Ryzen 9 5950X"."""
    name = re.sub(r"\((R|TM)\)", "", name)
    name = re.sub(r"\s+\d+-Core Processor|\s+CPU\s+@.*|^(AMD|Intel)\s+", "", name)
    return name.strip()


def load_run(path):
    """Read one JSON file. For every model and backend, the fit time is the
    median over the repetitions if the file has one, otherwise the first
    iteration entry. Returns the context and {model: {backend: entry}}."""
    with open(path) as f:
        results = json.load(f)
    context = results["context"]
    events = int(context["events"]) if context.get("events", "").isdigit() else None
    if events is None:
        sys.exit(f"{path}: the number of events is missing in the benchmark context")
    data = {}
    for bm in results["benchmarks"]:
        is_aggregate = bm.get("run_type", "iteration") == "aggregate"
        if is_aggregate and bm.get("aggregate_name") != "median":
            continue
        model, backend = bm["name"].split("/")[0].split("_Fit")
        if backend not in backend_styles:
            continue
        entry = data.setdefault(model, {})
        if backend in entry and not is_aggregate:
            continue
        evals = bm.get("nll_evals")
        if not evals:
            sys.exit(f"{path}: no nll_evals counter for {bm['name']}; the file is from an older benchmark version")
        entry[backend] = {
            "time_ms": bm["real_time"],
            "evals": evals,
            "converged": bm.get("migrad_status", 0) == 0,
            # Fit time per likelihood evaluation and event in ns.
            "ns": bm["real_time"] * 1e6 / (evals * events),
        }
    return {"context": context, "events": events, "data": data, "path": path}


runs = [load_run(args.json_file)]
if args.compare:
    runs.append(load_run(args.compare))
compare = len(runs) > 1

models = list(runs[0]["data"])
backends = [b for b in backend_styles if any(b in r["data"].get(m, {}) for r in runs for m in models)]
if not models or not backends:
    sys.exit(f"no results in {args.json_file}")

# Print the numbers as a table, one block per run.
for run in runs:
    print(f"{run['path']}: {run['context'].get('cpu', 'unknown')}, {run['events']:,} events")
    print(f"{'model':24s}" + "".join(f"{b + ' [ms]':>14s}{'evals':>7s}{'ns':>9s}" for b in backends))
    for model in models:
        line = f"{model:24s}"
        for b in backends:
            e = run["data"].get(model, {}).get(b)
            if e is None:
                line += f"{'-':>14s}{'-':>7s}{'-':>9s}"
            else:
                flag = "" if e["converged"] else "*"
                line += f"{e['time_ms']:14.1f}{int(e['evals']):7d}{e['ns']:8.3g}{flag:1s}"
        print(line)
    print()
if any(not e["converged"] for r in runs for d in r["data"].values() for e in d.values()):
    print("* Migrad did not converge (status != 0), so the backends may have done different work.")

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


def info_values(run):
    """Values of the run information table for one run. The values are
    shortened when two runs are shown next to each other."""
    c = run["context"]
    cpu = c.get("cpu", "unknown")
    gpu = c.get("gpu", "none")
    software = f"{c.get('root_version', '?')}, {c.get('batchcompute_library', '?')}, VDT: {c.get('vdt', '?')}"
    run_info = c.get("date", "")[:10] + (", " if compare else " on ") + c.get("host_name", "unknown")
    if compare:
        cpu = short_cpu_name(cpu)
        gpu = re.sub(r"^NVIDIA\s+", "", gpu)
    else:
        software = "ROOT " + software.replace(", ", ", RooBatchCompute ", 1)
    threads = c.get("threads", "unknown")
    return [cpu, gpu, f"{run['events']:,}", threads if compare else f"{threads} (multi-threaded CPU backend)",
            software, run_info]


info_labels = ["CPU", "GPU", "Events per fit", "CPU threads", "ROOT" if compare else "Software", "Run"]

n_models = len(models)
x_min, x_max = args.xmin, args.xmax

# The layout is defined in pixels and converted to the fractions of the canvas
# height that ROOT uses, such that the text has the same size no matter how
# many rows there are. With two runs, the rows are higher to make room for two
# rows of markers.
top_px = 386 if compare else 359
bottom_px = 138
row_px = 180 if compare else 120
height = top_px + bottom_px + row_px * n_models


def size(px):
    """Text size in pixels as a fraction of the canvas height."""
    return px / height


def y_ndc(px_from_top):
    return 1.0 - px_from_top / height


canvas = ROOT.TCanvas("canvas", "canvas", 1400, height)
left_margin = 0.25
canvas.SetLeftMargin(left_margin)
canvas.SetRightMargin(0.045)
canvas.SetTopMargin(top_px / height)
canvas.SetBottomMargin(bottom_px / height)
canvas.SetLogx()
canvas.SetGridx()

# Empty frame with one row per model, the first model at the top. The axis
# range is fixed, such that plots from different runs can be compared visually.
frame = ROOT.TH2F("frame", "", 1, x_min, x_max, n_models, 0, n_models)
frame.SetStats(False)
for i_model, model in enumerate(models):
    frame.GetYaxis().SetBinLabel(n_models - i_model, labels_dict.get(model, model))
frame.GetYaxis().SetLabelSize(size(52))
frame.GetYaxis().SetTickLength(0)
frame.GetXaxis().SetTitle("Fit time / (likelihood evaluations #times events)  [ns]")
frame.GetXaxis().SetLabelSize(size(52))
frame.GetXaxis().SetTitleSize(size(52))
frame.GetXaxis().SetTitleOffset(1.1)
frame.GetXaxis().SetNoExponent(True)
frame.Draw("AXIS")

# Thin separators between the models.
keep = []
for i in range(1, n_models):
    line = ROOT.TLine()
    line.SetLineColor(ROOT.kGray)
    line.SetLineStyle(3)
    line.DrawLine(x_min, i, x_max, i)
    keep.append(line)


def value_text(value):
    return f"{value:.2g}" if value < 100 else f"{value:.0f}"


# Vertical offsets of the marker rows and of the value labels within a model
# row, in units of rows.
marker_offsets = [26 / row_px, -26 / row_px] if compare else [0.0]
text_offset = 14 / row_px
value_size = size(28 if compare else 33)
for i_run, run in enumerate(runs):
    for i_model, model in enumerate(models):
        entries = run["data"].get(model, {})
        y = n_models - i_model - 0.5 + marker_offsets[i_run]
        values = [entries[b]["ns"] for b in backends if b in entries]
        if not values:
            continue
        # A line spanning the backends of this model, so the gaps between them
        # (the speedups) are visible as lengths.
        span = ROOT.TGraph(2)
        span.SetPoint(0, min(values), y)
        span.SetPoint(1, max(values), y)
        span.SetLineColor(ROOT.kGray + 1)
        span.SetLineWidth(2)
        span.Draw("L")
        keep.append(span)
        for b in backends:
            e = entries.get(b)
            if e is None:
                continue
            _, filled, hollow, color = backend_styles[b]
            marker = ROOT.TGraph(1)
            marker.SetPoint(0, e["ns"], y)
            marker.SetMarkerStyle(filled if i_run == 0 else hollow)
            marker.SetMarkerColor(color)
            marker.SetMarkerSize(2.6)
            marker.Draw("P")
            keep.append(marker)
            # The value above the markers of the first run and below the
            # markers of the second one.
            above = i_run == 0
            text = ROOT.TLatex(e["ns"], y + (text_offset if above else -text_offset),
                               value_text(e["ns"]) + ("" if e["converged"] else "*"))
            text.SetTextAlign(21 if above else 23)
            text.SetTextSize(value_size)
            text.SetTextColor(color if b != "CPU" else ROOT.kBlack)
            text.Draw()
            keep.append(text)

# The legend for the backends goes into the free space above the model labels.
legend_top = y_ndc(110)
legend = ROOT.TLegend(0.01, legend_top - size(55) * len(backends), 0.23, legend_top)
legend.SetBorderSize(0)
legend.SetFillStyle(0)
legend.SetTextSize(size(36))
legend_markers = []
for b in backends:
    label, filled, _, color = backend_styles[b]
    sample = ROOT.TGraph(1)
    sample.SetMarkerStyle(filled)
    sample.SetMarkerColor(color)
    sample.SetMarkerSize(2.2)
    legend.AddEntry(sample, label, "p")
    legend_markers.append(sample)
legend.Draw()

if any(not e["converged"] for r in runs for d in r["data"].values() for e in d.values()):
    note = ROOT.TLatex(0.02, legend_top - size(55) * len(backends) - size(25), "* Migrad did not converge")
    note.SetNDC()
    note.SetTextAlign(12)
    note.SetTextSize(size(26))
    note.Draw()
    keep.append(note)

title = ROOT.TLatex(0.5, y_ndc(48), "RooFit evaluation backends in unbinned fits (Migrad, strategy 0)")
title.SetNDC()
title.SetTextAlign(22)
title.SetTextSize(size(50))
title.Draw()

# The run information as a table above the frame: one column of labels and
# one column of values per run. With two runs, the column headers show the
# marker style of each run.
info_size = size(30 if compare else 34.5)
row_height = size(34.5 if compare else 39)
label_width = 0.13 if compare else 0.15
column_width = 0.29
y_top = y_ndc(103)
first_row = 0
if compare:
    first_row = 1
    for i_run, run in enumerate(runs):
        x = left_margin + label_width + i_run * column_width
        sample = ROOT.TMarker(x + 0.008, y_top - row_height, 20 if i_run == 0 else 24)
        sample.SetNDC()
        sample.SetMarkerSize(1.8)
        sample.Draw()
        keep.append(sample)
        header = ROOT.TLatex(x + 0.022, y_top - row_height, "filled markers" if i_run == 0 else "hollow markers")
        header.SetNDC()
        header.SetTextAlign(12)
        header.SetTextFont(62)
        header.SetTextSize(info_size)
        header.Draw()
        keep.append(header)
columns = [info_values(run) for run in runs]
for i_row, label in enumerate(info_labels):
    y = y_top - (first_row + i_row + 1) * row_height
    cells = [(left_margin, label, 62)]
    cells += [(left_margin + label_width + i_run * column_width, columns[i_run][i_row], 42) for i_run in range(len(runs))]
    for x, text, font in cells:
        latex = ROOT.TLatex(x, y, text)
        latex.SetNDC()
        latex.SetTextAlign(12)
        latex.SetTextFont(font)
        latex.SetTextSize(info_size)
        latex.Draw()
        keep.append(latex)

canvas.SaveAs(base_name + ".pdf")
canvas.SaveAs(base_name + ".png")
