#!/usr/bin/env python
# coding: utf-8


# Run on the output of benchCodeSquashAD piped into a file:
# $ ./benchCodeSquashAD &> benchCodeSquashAD.out
filename = "benchCodeSquashAD.out"


import numpy as np
import matplotlib.pyplot as plt
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


t = np.arange(0.01, 5.0, 0.01)
s1 = np.sin(2 * np.pi * t)
s2 = np.exp(-t)
s3 = np.sin(4 * np.pi * t)

f, (a0, a1) = plt.subplots(2, 1, gridspec_kw={"height_ratios": [2, 1]})

dfs = dict()


for backend, df_g in df.groupby("backend"):
    dfs[backend] = df_g
    nparams = df_g["nparams"]
    vals = df_g.eval("migrad + seeding")
    # vals = df_g.eval("fval")
    if backend == "codegen_no_grad":
        continue
    if backend == "RooFit AD":
        a0.plot(nparams, vals + 0 * df_g["jitting"], label=backend)
        a0.plot(nparams, df_g["jitting"], label="JIT time", color="k", linewidth=1, linestyle="--")
    else:
        a0.plot(nparams, vals, label=backend)
        # plt.plot(nparams, df_g["jitting"], label=backend + "_jit")

nparams = dfs["RooFit"]["nparams"]

a0.legend(loc="upper left")

plt.tick_params("x", labelsize=6)

# make these tick labels invisible
# plt.tick_params('x', labelbottom=False)
vals = dfs["RooFit"]["migrad"].values / dfs["RooFit AD"]["migrad"].values

a1.plot(nparams, vals, color="k")

a1.set_xlabel("Number of parameters")
a0.set_ylabel("Minimization time [s]")
a0.set_ylim(0, 30)
a0.set_xlim(0, nparams.to_numpy()[-1])

a1.set_ylabel("AD speedup")
a1.set_ylim(1, 4.2)
a1.set_xlim(0, nparams.to_numpy()[-1])

plt.savefig("scaling_study.png")
