#!/usr/bin/env bash
# Times the RooFit evaluation backends on the ATLAS Higgs VHbb workspace and
# writes one log per backend into atlas/, the input of
# atlasHiggsBackendComparison_make_plot.py.
#
# Run download_workspaces.sh first: the macro opens the workspace from the
# working directory.
#
# The `time` builtin has to wrap root itself, because the plot script reads its
# "user" line as the total bar height.

mkdir -p atlas

for backend in cpu codegen; do
    sh -c "{ time root -q -b 'atlasHiggsBackendComparison.C(\"$backend\")'; }" &> "atlas/$backend.log"
done
