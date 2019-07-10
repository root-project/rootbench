///\file Contains utilities to measure memory usage.
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <stdlib.h>
#include "rootbench/RBConfig.h"
#include "rootbench/MemoryMeasurement.h"

std::string getFileName(std::string path) {
	std::string base_fn = path.substr(path.find_last_of("/\\") + 1);
	return base_fn.substr(0, base_fn.find_last_of('.'));
}

std::string getMemoryStats(const std::string& dir, const std::string& filename, std::string& rootInvocation, const std::string& rootexe, const std::string& endInvoc) {
		std::string perffile="";
		if (access("/usr/bin/time", X_OK) == 0) {
			std::string rootsys = RB::GetRootSys();
			std::string thisroot = rootsys + "/bin/thisroot.sh";
			perffile = getFileName(filename) + "_perfile.txt";
			if (!filename.empty()) {
				std::string fullpath = rootsys + "/" + dir + filename;
				// FIXME: no source in /usr/dash
		    // We are writing /usr/bin/time -v output in file to get maximum resident memory for the benchmark
				rootInvocation = "/usr/bin/time -v -o \"" + perffile + rootexe + fullpath + endInvoc;
				std::cout<<"helllloooooooooooooooooooo     "<< rootInvocation <<"      hellllllloooooooooooooo"<<std::endl;
			}
			else {
				rootInvocation = "/usr/bin/time -v -o \"" + perffile + "\" root.exe -l -q -b "; // for pyroot?
			}
		}
		else {
			std::cout << "Cannot find usr/bin/time" << std::endl;
	}
	return perffile;
}
//  rootInvocation = "source \"" + thisroot + "\" && /usr/bin/time -v -o \"" + perffile + "\" root.exe -l -q -b -n -x \"" + fullpath + "\" -e return ";
//  rootInvocation = "source \"" + thisroot + "\" && /usr/bin/time -v -o \"" + perffile + "\" root.exe -l -q -b ";

int getMemoryMeasurement(std::string& perftutorial) {
		int peakSize=0;
	  std::string memorytutorial = "cat \"" + perftutorial + "\"| grep 'Maximum resident set size' | awk '{print $6}' > tmp_mem_file";
    int res = std::system(memorytutorial.c_str());
    (void) res;
    std::ifstream("tmp_mem_file") >> peakSize;
		return peakSize;
}
