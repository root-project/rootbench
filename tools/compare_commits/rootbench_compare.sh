#!/bin/bash

: '
This is a small script to compare performance between 2 different patches/commits.
The script will take care of building 2 ROOT versions and running the desired benchmarks.
And finally https://github.com/google/benchmark/blob/main/tools/compare.py compares both.
See https://github.com/google/benchmark/blob/main/docs/tools.md.
User needs to specify 2 commits and test regex to run on them:
1. "r" - owner of the baseline (default is `root-project`)
2. "b" - branch name of the baseline (default is `master`)
3. "c" - commit hash of the baseline (if none provided, the latest commit is picked)
4. "R" - owner of the baseline (default is `root-project`)
5. "B" - branch name of the baseline (default is `master`)
6. "C" - commit hash of the baseline (if none provided, the latest commit is picked)
7. "t" - regex to be passed to rootbench ctest (default empty string, hence all tests)
8. "n" - cores to use (default empty string, hence all cores of the machine)

Example usage:
```
sh rootbench_compare.sh -b latest-stable -c 9e7933c9bddba3f6381ba2b8c11539c46e8cc2f4 \
-R eguiraud -B df-bulk -t "(RDF)"
```
```
sh rootbench_compare.sh -B latest-stable -t "(OpenDataBenchmarks|df102_NanoAODDimuonAnalysis)"
```
'

root_owner_baseline="root-project"
branch_baseline="master"
commit_baseline=""

root_owner_compared="root-project"
branch_compared="master"
commit_compared=""

testregex="" # same for both builds

while getopts r:b:c:R:B:C:t:n: flag
do
	case "${flag}" in
		r) root_owner_baseline=${OPTARG};;
		b) branch_baseline=${OPTARG};;
		c) commit_baseline=${OPTARG};;
		R) root_owner_compared=${OPTARG};;
		B) branch_compared=${OPTARG};;
		C) commit_compared=${OPTARG};;
		t) testregex=${OPTARG};;
		n) ncores=${OPTARG};;
	esac
done

git clone https://github.com/${root_owner_baseline}/root --branch ${branch_baseline} baseline_root
cd baseline_root
if [${commit_baseline} != ""]
then
    git reset --hard ${commit_baseline}
fi
mkdir rbuild && cd rbuild
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_FLAGS="-O2 -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer" ..
cmake --build . -- -j${ncores}
cd ../..

git clone https://github.com/${root_owner_compared}/root --branch ${branch_compared} compared_root
cd compared_root
if [${commit_compared} != ""]
then
    git reset --hard ${commit_compared}
fi
mkdir rbuild && cd rbuild
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_FLAGS="-O2 -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer" ..
cmake --build . -- -j${ncores}
cd ../..

source baseline_root/rbuild/bin/thisroot.sh
mkdir baseline_bench && cd baseline_bench
cmake -Drootbench-datafiles=ON -Drootbench-out-format-json=ON ../../..
cmake --build . -- -j${ncores}
RB_TEMP_FS="." ctest -R ${testregex} -j${ncores} --verbose
cd ..

source compared_root/rbuild/bin/thisroot.sh
mkdir compared_bench && cd compared_bench
cmake -Drootbench-datafiles=OFF -Drootbench-out-format-json=ON ../../..
cmake --build . -- -j${ncores}
RB_TEMP_FS="../baseline_bench" ctest -R ${testregex} -j${ncores} --verbose
cd ..

for file in $(find baseline_bench/root -name "*.json")
do
    python3 compare.py benchmarks $file compared_bench/root/${file#baseline_bench/root/} --display_aggregates_only
done
