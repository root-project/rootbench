#!/bin/bash

BENCHMARKPATTERN="*benchmark*"
MKDIR=$(which mkdir)
BASENAME=$(which basename)
DIRNAME=$(which dirname)
FIND=$(which find)
SED=$(which sed)
PERF=$(which perf)
STACKCOLLAPSE=stackcollapse-perf.pl
FLAMEGRAPH=flamegraph.pl

usage() {
	echo
	echo "--------------------------FlameGraph Generator---------------------------"
	echo
	echo "Usage: $0 [OPTION]..."
	echo "This script generates FlameGraphs for benchmarks !!!"
	echo "OPTIONS"
	echo "   -d, --builddir path            Create all benchmarks."
	echo "   -b, --benchmarkfile path       Location of ROOT benchmark file"
	echo "   -a, --all                      Create all benchmarks."
	echo "   -c, --cpu                      Generate CPU FlameGraphs"
	echo "   -m, --memory                   Generate Memory FlameGraphs"
	echo "   -h, --help                     Display this help and exit"
}

usage_short() {
	echo "Usage: $0 -d | --builddir path [-b | --benchmarkfile filepath] [-a | --all] [-c | --cpu] [-m | --memory] [-h | --help]"
	exit 1
}

get_bm_fn() {
	if [ ! -f $1 ]; then
		echo "Can't find the benchmark file"
		exit 1
	else
		bm_fn_full=$1
		bm_fn=$($BASENAME $bm_fn_full)
	fi
}

get_build_dir() {
	if [ ! -d $1 ]; then
		echo "Can't find the build directory. Exiting..."
		exit 1
	else
		build_dir=$1
		flamegraph_base_dir=$build_dir/FlameGraph
	fi
}

get_bm_fn_interactive() {
	read -p "Enter benchmark filename: " bm_fn_full
	if [ -z $bm_fn_full ]; then
		echo "You did not enter any filename. Exiting..."
		exit 1
	fi
	get_bm_fn $bm_fn_full
}

perf_record_cpu() {
	$PERF record -F 50 --call-graph dwarf $1 --benchmark_filter=${2}$
}

perf_script_cpu() {
	$PERF script | stackcollapse-perf.pl | flamegraph.pl --title $1 >$2.svg
}

perf_record_mem() {
	$PERF record -F 50 -e page-faults --call-graph dwarf $1 --benchmark_filter=${2}$
}

perf_script_mem() {
	$PERF script | stackcollapse-perf.pl | flamegraph.pl --color=mem --title=$1 --countname="pages" >$2.svg
}

perf_rec_scr_cpu() {
	perf_record_cpu $1 $2
	perf_script_cpu $2 $3
}

perf_rec_scr_mem() {
	perf_record_mem $1 $2
	perf_script_mem $2 $3
}

get_bm_files() {
	bm_file_list=$($FIND $build_dir/root -iname "$BENCHMARKPATTERN" | grep -v "CMakeFiles\|pyroot\|interpreter\|.csv")
}

run_bm() {
	for bm_fn_full in $bm_file_list; do
		bm_fn=$($BASENAME $bm_fn_full)
		bm_dn=$($DIRNAME $bm_fn_full)
		bm_path=$(echo "$bm_dn" | $SED -n "s|^$build_dir/||p")
		bm_sub_list=$($bm_fn_full --benchmark_list_tests)
		flamegraph_base_dir_mem=${flamegraph_base_dir}/FlameGraph_Memory
		flamegraph_base_dir_cpu=${flamegraph_base_dir}/FlameGraph_CPU
		outputdir_full_mem=${flamegraph_base_dir_mem}/$bm_path/$bm_fn
		outputdir_full_cpu=${flamegraph_base_dir_cpu}/$bm_path/$bm_fn
		if [ "$memory" = "y" ]; then
			$MKDIR -p $outputdir_full_mem
			if [ $? -ne 0 ]; then
				echo "Can't create directory $1. Exiting..."
				exit 1
			fi
		fi
		if [ "$cpu" = "y" ]; then
			$MKDIR -p $outputdir_full_cpu
			if [ $? -ne 0 ]; then
				echo "Can't create directory $1. Exiting..."
				exit 1
			fi
		fi
		for bm in $bm_sub_list; do
			bm_modified_fn=$(echo "$bm" | $SED "s|[/:]|-|g") #replacing all "/" and ":" with "-"
			if [ "$cpu"="y" ]; then
				perf_rec_scr_cpu $bm_fn_full $bm ${outputdir_full_cpu}/${bm_modified_fn}_FlameGraph
			fi
			if [ "$memory"="y" ]; then
				perf_rec_scr_mem $bm_fn_full $bm ${outputdir_full_mem}/${bm_modified_fn}_FlameGraph
			fi
		done
	done
}

#####  Main  #####

[ $# -eq 0 ] && usage_short

while [ $# -gt 0 ]; do
	case "$1" in
	-b | --benchmarkfile)
		shift
		get_bm_fn $1
		;;
	-d | --builddir)
		shift
		get_build_dir $1
		;;

	-a | --all)
		all=y
		;;
	-c | --cpu)
		cpu=y
		;;
	-m | --memory)
		memory=y
		;;
	-h | --help)
		usage
		exit
		;;
	*)
		usage
		exit 1
		;;
	esac
	shift
done

if [ -z $build_dir ]; then
	echo "************* Rootbench Build dir is mandatory *****************"
	usage_short
fi

if [ -z $cpu -a -z $memory ]; then
	echo "************* Please specify the type of the FlameGraphs *****************"
	usage_short
fi

if [ "$all" = "y" ]; then
	get_bm_files
	run_bm
else
	if [ ! -z $bm_fn_full ]; then
		bm_file_list=$bm_fn_full
		run_bm
	fi
fi

exit $?
