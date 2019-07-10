///\file Memory measurement.

#include <string>

//running usr/bin/time to collect measurements in perffile
std::string getMemoryStats(const std::string& dir, const std::string& filename, std::string& rootInvocation, const std::string& rootexe, const std::string& endInvoc);

//getting Maximum resident set size form perffile and storing in peakSize
int getMemoryMeasurement(std::string& perftutorial);

//extracting filename from given path
std::string getFileName(std::string& path);

