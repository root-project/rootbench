# ATLAS Higgs benchmarks

Benchmarks running RooFit on the ATLAS Higgs combination workspaces published at
https://root.cern/files/rootbench/atlas-higgs-workspaces-2021/.

Two things live here:

- `roofitAtlasHiggsBenchmark.cxx` — a Google Benchmark executable, driven by
  `run_benchmarks.sh`, reporting NLL creation and minimization times.
- `atlasHiggsBackendComparison.C` — a ROOT macro that fits the VHbb workspace
  once per evaluation backend, used for the bar plot below.

## Evaluation backend bar plot

Shows where the wall time of a fit goes for each RooFit evaluation backend, as a
stacked bar per backend: NLL creation, function JIT, gradient generation,
gradient lowering, seeding, minimization, and the unaccounted remainder.

```bash
./download_workspaces.sh                          # once; only WS-VHbb-STXS_mu_toy_new.root is needed
./run_atlasHiggsBackendComparison.sh              # ~1 min per backend, writes atlas/{cpu,codegen}.log
python3 atlasHiggsBackendComparison_make_plot.py  # writes plot_roofit_ad_atlas_root.pdf
```

Both scripts use the working directory, so run them from where the workspace was
downloaded.

Notes:

- The timings are scraped out of ROOT's own log output, so the macro must keep
  printing at `kInfo`. `atlasHiggsBackendComparison.C` lists the exact lines the
  plot script looks for.
- The `time` builtin has to stay wrapped around `root` itself: its `user` line is
  the total bar height, and the measured steps are subtracted from it to get the
  "Other" slice.
- Out of the box this gives two bars, `cpu` and `codegen`. The `legacy` backend
  no longer exists in recent ROOT; on an older ROOT, add it to the loop in
  `run_atlasHiggsBackendComparison.sh` to get a third bar. The plot script drops
  any backend whose log is absent, so no other change is needed.
- The plot script takes the log directory as an argument, so several runs can be
  compared: `python3 atlasHiggsBackendComparison_make_plot.py atlas some-other-run`
  writes one PDF per directory, named after it.

## Machine-readable output

`--json` writes the parsed timings to stdout instead of plotting, as one record
per (run, backend, step):

```bash
python3 atlasHiggsBackendComparison_make_plot.py atlas --json > atlas.json
```

```python
import pandas as pd

df = pd.read_json("atlas.json")                       # columns: run, backend, step, seconds
df.groupby(["run", "backend"]).seconds.sum()          # total per bar
df.pivot_table(index="backend", columns="step", values="seconds")
```

Pass several directories to get them all in one file, already tagged by `run`,
ready to concatenate across runs. Progress messages go to stderr, so stdout stays
valid JSON, and `--json` does not import ROOT at all.
