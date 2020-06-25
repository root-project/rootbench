#ifndef LoopSUSYTZTZ_H
#define LoopSUSYTZTZ_H

#include <LoopSUSYFrame/LoopSUSYFrame.h>

#include <utility>
#include <array>
#include <string>
#include <memory>
#include <vector>
#include <TTree.h>

using CutFlowReport = ROOT::RDF::RResultPtr<ROOT::RDF::RCutFlowReport>;
using SnapshotResult = ROOT::RDF::RResultPtr<ROOT::RDF::RInterface<ROOT::Detail::RDF::RLoopManager>>;

class LoopSUSYTZTZ : public LoopSUSYFrame
{

public:

	// this is a standard constructor
	LoopSUSYTZTZ (TTree *tree) : LoopSUSYFrame(tree){};
	~LoopSUSYTZTZ(){};
	virtual std::vector<std::string> DefineBranches(const std::string &syst);
	virtual std::pair<CutFlowReport,SnapshotResult> Process(ROOT::RDataFrame &dataFrame, const std::string &syst);

private:


};

#endif

