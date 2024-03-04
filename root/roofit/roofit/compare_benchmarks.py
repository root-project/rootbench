import pandas as pd
import csv
import matplotlib.pyplot as plt
import numpy as np
from io import StringIO


def read_csv(csv_file_path):
    with open(csv_file_path, "r") as csvfile:
        lines = [line for line in csvfile if ("BM_RooFit" in line or "name," in line)]
    print("\n".join(lines))
    return pd.read_csv(StringIO("\n".join(lines)))


codegen_df = read_csv("out_codegen.csv")
codegen_nograd_df = read_csv("out_codegen_ngrad.csv")
legacy_df = read_csv("out_legacy.csv")
cpu_df = read_csv("out_cpu.csv")

# Plotting
plt.figure(figsize=(10, 6))

x = np.arange(len(codegen_df["name"].unique()))


for i, benchmark in enumerate(codegen_df["name"].unique()):

    codegen_time = codegen_df.loc[codegen_df["name"] == benchmark, "real_time"]
    codegen_nograd_time = codegen_nograd_df.loc[codegen_nograd_df["name"] == benchmark, "real_time"]
    cpu_time = cpu_df.loc[cpu_df["name"] == benchmark, "real_time"]
    legacy_time = legacy_df.loc[legacy_df["name"] == benchmark, "real_time"]

    plt.bar(x[i] - 0.10, codegen_time, width=0.15, align="center", label="codegen", color="lightblue")
    plt.bar(x[i], codegen_nograd_time, width=0.15, align="edge", label="codegen_nograd", color="navy")
    plt.bar(x[i] + 0.15, cpu_time, width=0.15, align="edge", label="cpu", color="cyan")
    plt.bar(x[i] + 0.30, legacy_time, width=0.15, align="edge", label="legacy", color="gray")


# Customize legend
legend_labels = ["codegen", "codegen_nograd", "cpu", "legacy"]
legend_colors = ["lightblue", "navy", "cyan", "gray"]
legend_handles = [plt.Rectangle((0, 0), 1, 1, color=color) for color in legend_colors]
plt.legend(legend_handles, legend_labels)

plt.yscale("log")

plt.xlabel("Benchmark")
plt.ylabel("Time (milliseconds)")
plt.title("Comparison of Benchmarks for Different Evaluation Backends")
plt.xticks(x, rotation=90)
plt.tight_layout()
plt.savefig("comparision_plot.png")
