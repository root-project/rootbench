## About

flamegraph.sh is a script that generates Flame Graphs for each benchmark in `rootbench.git`. More information on Flame Graphs can be found [here](http://www.brendangregg.com/flamegraphs.html).

## Options

See the USAGE message (--help) for options. 

To generate only CPU or only memory Flame Graphs, use `-c` or `-m` respectively. To generate both CPU and memory Flame Graphs for all benchmarks at once run the following command:
```bash
flamegraph.sh -d path/to/rootbench/build/dir -a -c -m 
```

To generate Flame Graphs for specific benchmark just run the following command with `-c` or `-m` options or both:
 ```bash
flamegraph.sh -d path/to/rootbench/build/dir -b path/to/benchmark 
``` 

## Configuration

If `perf` cannot find symbols in the program try to execute the following commands
```bash
echo 0 > /proc/sys/kernel/kptr_restrict
echo 1 > /proc/sys/kernel/sched_schedstats
```

To generate Flame Graphs for each benchmark add `-Dflamegraph=ON` option to your cmake configuration.

```bash
cmake ../rootbench -Dflamegraph=ON
make -j4
ctest -V -R rootbench-CLASSNAMEBenchmarks
```
You can also run the script for Flame Graph generation from your rootbench directory. 
The Flame Graphs will be stored in the local rootbench build directory under FlameGraph folder.
