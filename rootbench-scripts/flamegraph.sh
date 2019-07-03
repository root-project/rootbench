#!/bin/bash


BENCHMARKPATTERN="*benchmark*"
ROOTBENCHBUILDDIR=$1 #/home/lharutyu/ROOT/rootbench-build2   # Enter path to rootbench-build folder
shift                  
FLAMEGRAPHBASEDIR=$ROOTBENCHBUILDDIR/FlameGraph

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
    echo "    Enter path/to/rootbench/build/dir"
    echo "OPTIONS"
    echo "   -b, --benchmarkfile path       Location of ROOT benchmark file"
    echo "   -a, --all                      Create all benchmarks."
    echo "   -h, --help                     Display this help and exit"
}

usage_short()
{
    echo "FlameGraph Generator"
    echo "Usage: $0 [path/to/rootbench/build/dir] [-b |--benchmarkfile filepath] [-a | --all] [-h | --help]"
}

get_bm_fn()
{
    if [ ! -f $1 ] ; then
        echo "Can't find the executable"
        exit 1
    else
        bm_fn_full=$1
        bm_fn=`$BASENAME $bm_fn_full`
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
	$PERF record -F 50 --call-graph dwarf $1 --benchmark_filter=$2 
}

perf_script()
{
	$PERF script | stackcollapse-perf.pl | flamegraph.pl > $1.svg
}

perf_rec_scr()           
{
	perf_record $1 $2
	perf_script $3
	# $PERF record --call-graph dwarf $1 | $PERF script | $STACKCOLLASE | $FLAMEGRAPG > $2
}


get_bm_files()
{
	bm_file_list=`$FIND $ROOTBENCHBUILDDIR/root -iname "$BENCHMARKPATTERN" |grep -v "CMakeFiles"`

}

run_all_bm()
{
	get_bm_files
	for bm_fn_full in $bm_file_list
	do
   	    bm_fn=`$BASENAME $bm_fn_full`
   	    bm_dn=`$DIRNAME $bm_fn_full`
		bm_path=`echo "$bm_dn" | $SED -n "s|^$ROOTBENCHBUILDDIR/||p"`
	    bm_list_exec=`./$bm_path/$bm_fn --benchmark_list_tests`
   		outputdir_full=${FLAMEGRAPHBASEDIR}/$bm_path/$bm_fn
   		$MKDIR -p $outputdir_full
    	if [ $? -ne 0 ]; then
        	echo "Can't create directory $1. Exiting..."
        exit 1
    fi
		for benchmark in $bm_list_exec
		do
    		perf_rec_scr $bm_fn_full $benchmark ${outputdir_full}/${benchmark}_FlameGraph
		done
	done
}


run_spec_bm() 
{
spec_bm_list_exec=`$ROOTBENCHBUILDDIR/$bm_fn_full --benchmark_list_tests`
spec_outputdir_full=$ROOTBENCHBUILDDIR/$bm_fn
$MKDIR $spec_outputdir_full
	if [ $? -ne 0 ]; then
        echo "Can't create directory $1. Exiting..."
        exit 1
    fi
	for benchmark in $spec_bm_list_exec
		do
    		perf_rec_scr $ROOTBENCHBUILDDIR/$bm_fn_full $benchmark ${spec_outputdir_full}/${benchmark}_FlameGraph
		done
}		


#####  Main  #####


if [ \( "$ROOTBENCHBUILDDIR" = "-h" \) -o \( "$ROOTBENCHBUILDDIR" = "--help" \) ] ; then
	usage
	exit 1
fi

if [ ! -d $ROOTBENCHBUILDDIR ] ; then
	echo "Can't find the build directory. Exiting..."
	exit 1
fi

[ $# -eq 0 ] && usage_short

while [ $# -gt 0 ]; do
        case "$1" in
        -b | --benchmarkfile )
                              shift
                              get_bm_fn $1
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

if [ "$all" = "y" ] ; then
   run_all_bm
fi

###    If no "-b" option, we go with interactive mode.   ###
# if [ -z $bm_fn_full  ] ; then
#	get_bm_fn_interactive
# fi
 
if [ ! -z $bm_fn_full ] ; then
	run_spec_bm
fi

exit $?









