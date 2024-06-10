#!/bin/bash


set -e
CHECK_ABI=abi-compliance-checker


LAST_ABI_XML_FILE=/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/dist/abi/abi_checker_last.xml
LAST_ABI_DUMP=/Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX-build/abi_dump_last.abi.tar.gz

echo "Generate  new ABI dump...."
$CHECK_ABI -l davix -dump $LAST_ABI_XML_FILE -dump-path $LAST_ABI_DUMP

echo "Looking for abi dumps in /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX/dist/abi/abi_dumps/"
ls /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX/dist/abi/abi_dumps/
shopt -s nullglob
for i in /Users/abhiacherjee/Documents/rootbench/root/builtins/davix/DAVIX-prefix/src/DAVIX/dist/abi/abi_dumps/*$(gcc -dumpversion | sed 's/^\([0-9]*\)\.\([0-9]*\)\.*.*/\1\2/g')*$(gcc -dumpmachine)*.abi.tar.gz
do
echo "Scan for $i with $LAST_ABI_DUMP"
$CHECK_ABI -l davix -old $i -new $LAST_ABI_DUMP
echo "Scan with success"

done

echo "Finish !"
