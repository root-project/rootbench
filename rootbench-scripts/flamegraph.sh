#!/bin/bash

BENCHMARKPATTERN="*benchmark*"
MKDIR=/bin/mkdir
BASENAME=/usr/bin/basename
DIRNAME=/usr/bin/dirname
FIND=/usr/bin/find
SED=/bin/sed
PERF=/usr/bin/perf
STACKCOLLASE=stackcollapse-perf.pl
FLAMEGRAPG=flamegraph.pl

usage()
{
    echo
    echo "--------------------------FlameGraph Generator---------------------------"
    echo
    echo "Usage: $0 [OPTION]..."
    echo "This script generates FlameGraphs for benchmarks !!!"
    echo "OPTIONS"
    echo "   -b, --benchmarkfile path       Location of ROOT benchmark file"
    echo "   -a, --all                      Create all benchmarks."
    echo "   -d, --builddir path            Create all benchmarks."
    echo "   -h, --help                     Display this help and exit"
}

usage_short()
{
#    echo "FlameGraph Generator"
    echo "Usage: $0 -d | --builddir path [-b | --benchmarkfile filepath] [-a | --all] [-h | --help]"
    exit 1
}

get_bm_fn()
{
    if [ ! -f $1 ] ; then
        echo "Can't find the benchmark file"
        exit 1
    else
        bm_fn_full=$1
        bm_fn=`$BASENAME $bm_fn_full`
    fi
}

get_build_dir()
{
    if [ ! -d $1 ] ; then
	echo "Can't find the build directory. Exiting..."
	exit 1
    else
	build_dir=$1
	flamegraph_base_dir=$build_dir/FlameGraph
    fi
}

get_bm_fn_interactive()
{
    read -p "Enter benchmark filename: " bm_fn_full
    if [ -z $bm_fn_full ] ; then
       echo "You did not enter any filename. Exiting..."
       exit 1
    fi
    get_bm_fn $bm_fn_full
}

perf_record()
{
    $PERF record -F 50 --call-graph dwarf $1 --benchmark_filter=${2}$ 
}

perf_script()
{
    $PERF script | stackcollapse-perf.pl | flamegraph.pl --title $1 > $2.svg
}

perf_rec_scr()
{
    perf_record $1 $2
    perf_script $2 $3
    # $PERF record --call-graph dwarf $1 | $PERF script | $STACKCOLLASE | $FLAMEGRAPG > $2
}

get_bm_files()
{
    bm_file_list=`$FIND $build_dir/root -iname "$BENCHMARKPATTERN" |grep -v "CMakeFiles"`
}

run_bm()
{
    for bm_fn_full in $bm_file_list
    do
	bm_fn=`$BASENAME $bm_fn_full`
	bm_dn=`$DIRNAME $bm_fn_full`
	bm_path=`echo "$bm_dn" | $SED -n "s|^$build_dir/||p"`
	bm_sub_list=`$bm_fn_full --benchmark_list_tests`
	outputdir_full=${flamegraph_base_dir}/$bm_path/$bm_fn
	$MKDIR -p $outputdir_full
	if [ $? -ne 0 ]; then
	    echo "Can't create directory $1. Exiting..."
	    exit 1
	fi
	for bm in $bm_sub_list
	do
	    bm_modified_fn=`echo "$bm" | $SED "s|[/:]|-|g"`    #replacing all "/" and ":" with "-"
 	    perf_rec_scr $bm_fn_full $bm ${outputdir_full}/${bm_modified_fn}_FlameGraph
	done
    done
}


#####  Main  #####

[ $# -eq 0 ] && usage_short

while [ $# -gt 0 ]; do
        case "$1" in
        -b | --benchmarkfile )
                              shift
                              get_bm_fn $1
        ;;
        -d | --builddir )
                              shift
                              get_build_dir $1
        ;;

        -a | --all )
                              all=y
        ;;
        -h | --help )
                              usage
                              exit
        ;;
        * )
                              usage
                              exit 1
        ;;
        esac
        shift
done

if [ -z $build_dir ] ; then
    echo "************* Rootbench Build dir is mandatory *****************"
    usage_short
fi

if [ "$all" = "y" ] ; then
    get_bm_files
    run_bm
else
    if [ ! -z $bm_fn_full ] ; then
	bm_file_list=$bm_fn_full
	run_bm
    fi
fi

exit $?
