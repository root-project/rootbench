#!/bin/bash

# Function to run a benchmark script and wait until the CSV file is generated
# to make it executable chmod +x run_benchmarks.sh
#then run it using ./run_benchmarks.sh
#!/bin/bash

# Function to run the benchmark command and wait for CSV file to be generated
run_benchmark() {
    echo "Running benchmark: $1"
    $1 &
    local pid=$!
    while [ ! -f $2 ]; do
        sleep 1
    done
    wait $pid
    echo "CSV file generated: $2"
}

# Run benchmarks
run_benchmark "./benchRooFitBinned -b codegen --benchmark_out_format=csv --benchmark_out=out_codegen.csv" "out_codegen.csv"
run_benchmark "./benchRooFitBinned -b codegen_no_grad --benchmark_out_format=csv --benchmark_out=out_codegen_ngrad.csv" "out_codegen_ngrad.csv"
run_benchmark "./benchRooFitBinned -b legacy --benchmark_out_format=csv --benchmark_out=out_legacy.csv" "out_legacy.csv"
run_benchmark "./benchRooFitBinned -b cpu --benchmark_out_format=csv --benchmark_out=out_cpu.csv" "out_cpu.csv"

# Run Python script
python3 compare_benchmarks.py