///\file Contains utilities to measure memory usage.
#include "rootbench/MemoryMeasurement.h"
#include "rootbench/RBConfig.h"
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

// runs the given command and returns the output
std::string GetStdoutFromCommand(std::string cmd)
{
   std::string data;
   FILE *stream;
   const int max_buffer = 256;
   char buffer[max_buffer];
   cmd.append(" 2>&1");
   stream = popen(cmd.c_str(), "r");
   if (stream) {
      while (!feof(stream))
         if (fgets(buffer, max_buffer, stream) != NULL)
            data.append(buffer);
      pclose(stream);
   }
   return data;
}

// gets file name from path
std::string getFileName(std::string path)
{
   std::string base_fn = path.substr(path.find_last_of("/\\") + 1);
   return base_fn.substr(0, base_fn.find_last_of('.'));
}

std::string getMemoryStats(const std::string &dir, const std::string &filename, std::string &rootInvocation,
                           const std::string &rootexe, const std::string &endInvoc)
{
   std::string perffile = "";
   std::string timePathLong = GetStdoutFromCommand("which time");
   std::string timePath = timePathLong.substr(0, timePathLong.size() - 1);
   if (access(timePath.c_str(), X_OK) == 0) {
      std::string rootsys = RB::GetRootSys();
      std::string thisroot = rootsys + "/bin/thisroot.sh";
      perffile = getFileName(filename) + "_perfile.txt";
      if (!filename.empty()) {
         std::string fullpath = rootsys + "/" + dir + filename;
         // FIXME: no source in /usr/dash
         // We are writing /usr/bin/time -v output in file to get maximum resident memory for the benchmark
         rootInvocation =
            "source \"" + thisroot + "\" && " + timePath + " -v -o \"" + perffile + rootexe + fullpath + endInvoc;
      } else {
         rootInvocation = "source \"" + thisroot + "\" && " + timePath + " -v -o \"" + perffile +
                          "\" root.exe -l -q -b "; // starter for ROOT
      }
   } else {
      std::cout << "Cannot find usr/bin/time" << std::endl;
   }
   return perffile;
}

int getMemoryMeasurement(std::string &perftutorial)
{
   int peakSize = 0;
   std::string memorytutorial =
      "cat \"" + perftutorial + "\"| grep 'Maximum resident set size' | awk '{print $6}' > tmp_mem_file";
   int res = std::system(memorytutorial.c_str());
   (void)res;
   std::ifstream("tmp_mem_file") >> peakSize;
   return peakSize;
}
