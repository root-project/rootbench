#include <LoopSUSYFrame/LoopSUSYFrame.h>
#include "TROOT.h"

LoopSUSYFrame :: LoopSUSYFrame( TTree *tree )
{
	m_tree.reset( tree );
	m_sumOfWeights = 1.;
	m_outFileName = "ugo.root";
	m_outTreeName = "HistFitterTree";
	m_isData = false;
	m_mcChan = -1;
	m_enableMT = false;

	m_syst = {"NONE"};

}

int LoopSUSYFrame :: Execute()
{

	if(m_enableMT)ROOT::EnableImplicitMT();

	ROOT::RDataFrame dataFrame( *m_tree );

	std::vector<std::pair<CutFlowReport, SnapshotResult>> new_InfoAndTrees;
	size_t systematics_size = m_syst.size();

	new_InfoAndTrees.reserve(systematics_size);
	for (size_t i = 0; i < systematics_size; ++i) {
		new_InfoAndTrees.emplace_back(Process(dataFrame, m_syst[i]));
	}

	auto c = dataFrame.Count();
	c.OnPartialResult(100000, [](ULong64_t c) { std::cerr << "Processed " << c << " events" << std::endl; });

	//Check that at least one event passed the cuts for at least one of the systematic variations
	int ret = 0;
	for (size_t i = 0; i < systematics_size; ++i) {
		ret += (--std::end(new_InfoAndTrees[i].first))->GetPass();
	}

	std::cerr << std::endl;
	std::cerr << "******************************************************************************" << std::endl;
	new_InfoAndTrees[0].first->Print(); // Prints cutflow
	std::cerr << "******************************************************************************" << std::endl;
	std::cerr << std::endl;

	return ret;

}
