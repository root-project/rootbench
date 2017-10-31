# ROOT Benchmarks

This repository contains a set of relatively small programs (usually based on [gbenchmark](https://github.com/google/benchmark) micro benchmarking infrastructure) built on top of [ROOT](https://github.com/root-project/root). Their primary goal is to provide stable performance metrics which can be monitored over time.

# Project Health
|       |     |
| :---: |:---:|
| Linux/OSX [![Build Status](https://travis-ci.org/root-project/rootbench.svg?branch=master)](https://travis-ci.org/root-project/rootbench) | Experimental Benchmark Coverage: [![Coverage Status](https://coveralls.io/repos/github/root-project/rootbench/badge.svg?branch=master)](https://coveralls.io/github/root-project/rootbench?branch=master)  |  


## About
Collection of benchmarks and performance monitoring applications

## Building
Clone the repo

    $ git clone https://github.com/root-project/rootbench.git
    
Make a directory for building

    $ mkdir build
    $ cd build
    
Run cmake and make

    $ cmake ../rootbench
    $ make

