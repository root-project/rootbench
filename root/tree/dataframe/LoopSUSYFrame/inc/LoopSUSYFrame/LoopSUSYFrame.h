#ifndef LoopSUSYFrame_H
#define LoopSUSYFrame_H

#include <ROOT/RDataFrame.hxx>
#include <TTree.h>

#include <string>
#include <memory>

using CutFlowReport = ROOT::RDF::RResultPtr<ROOT::RDF::RCutFlowReport>;
using SnapshotResult = ROOT::RDF::RResultPtr<ROOT::RDF::RInterface<ROOT::Detail::RDF::RLoopManager>>;

class LoopSUSYFrame
{

public:

	// this is a standard constructor
	LoopSUSYFrame( TTree * tree );

	virtual ~LoopSUSYFrame() {};
	virtual int Execute();
	virtual std::pair<CutFlowReport,SnapshotResult> Process(ROOT::RDataFrame &dataFrame, const std::string &syst) = 0;

	inline void setSumOfWeights(const double sumOfWeights) { m_sumOfWeights = sumOfWeights; };
	inline void setSyst(const std::vector<std::string> &syst) { m_syst = syst; };
	inline void setOutFileName(const std::string &fileName) { m_outFileName = fileName; };
	inline void setOutTreeName(const std::string &treeName) { m_outTreeName = treeName; };
	inline void setIsData(const bool isdata) { m_isData = isdata; };
	inline void setIsSignal(const bool isSignal) { m_isSignal = isSignal; };
        inline void setXsect(const float Xsect) { m_Xsect = Xsect;};
        inline void setKfactor(const float kFact) { m_kFact = kFact;};
        inline void setFilterEff(const float filtEff) { m_filtEff = filtEff;};
	inline void setMultiThread(const bool enable_MT) { m_enableMT = enable_MT; };
	inline void setIsolationVarSave(const bool storeISOvars) { m_storeISOvars = storeISOvars; };
	inline void setMcChan(const int mcChan) { m_mcChan = mcChan; };
	inline void setMcProd(const bool isMCa, const bool isMCd, const bool isMCe) { m_isMCa = isMCa; m_isMCd =isMCd; m_isMCe = isMCe; };
	inline void setDataYear(const bool isData15, const bool isData16, const bool isData17, const bool isData18) { m_isData15 = isData15; m_isData16 =isData16; m_isData17 = isData17; m_isData18 = isData18 ; };

	std::unique_ptr<TTree> m_tree;
	double m_sumOfWeights;
	bool m_isData, m_isSignal;
        float m_Xsect, m_kFact, m_filtEff;
	bool m_enableMT, m_storeISOvars;
	int m_mcChan;
	bool m_isMCa;
	bool m_isMCd;
	bool m_isMCe;
	bool m_isData15;
	bool m_isData16;
	bool m_isData17;
	bool m_isData18;
	std::vector<std::string> m_syst;
	std::string m_outFileName;
	std::string m_outTreeName;

};

#endif
