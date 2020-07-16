#!/bin/bash
# Download data from https://root.cern.ch/files/rootbench
# Usage: download_files.sh <output_dir> <fname> [fname]...
# where `fname` is assumed to be available as https://root.cern.ch/files/rootbench/<fname>.

# set bash unofficial strict mode
# (http://redsymbol.net/articles/unofficial-bash-strict-mode)
set -euo pipefail
IFS=$'\n\t'

if [[ $# -lt 2 ]]; then
   echo "Usage: $0 <output_dir> <file_url> [file_url]..." 1>&2
   exit 1
fi

OUT_DIR="$1"
shift

# Check output directory exists, create it if needed
if [[ -e "$OUT_DIR" && ! -d "$OUT_DIR" ]]; then
   echo "Path \"$OUT_DIR\" already exists and it is not a directory, aborting" 1>&2
   exit 2
elif [[ ! -e "$OUT_DIR" ]]; then
   mkdir -p "$OUT_DIR"
fi
echo "Output directory: \"${OUT_DIR}\""

# Download files that are not already in $OUT_DIR
BASEURL="https://root.cern.ch/files/rootbench"
pushd $OUT_DIR
for FNAME in "$@"; do
   echo -n "Downloading ${FNAME}..."
   if [[ ! -e "${FNAME}" ]]; then
      HTTP_CODE=$(curl --silent --show-error -w '%{http_code}' --remote-name "${BASEURL}/${FNAME}")
      if [[ "${HTTP_CODE}" != "200" ]]; then
         echo "There was an error retrieving file '${FNAME}'. HTTP response was ${HTTP_CODE}" 1>&2
         rm -f ${FNAME}
         exit 3
      fi
      echo "done"
   else
      echo "file already present"
   fi
done
popd
