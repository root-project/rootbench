#ifndef READFFXML_H
#define READFFXML_H

#include "TXMLEngine.h"
#include "TString.h"
#include <exception>
#include <regex>
#include <vector>
#include <string>
#include <map>


class readFFXML {

public:

    readFFXML( const char* filename );
    ~readFFXML(){
       ele_systList.clear();
       muon_systList.clear();
       eleMap.clear();
       muonMap.clear();
    };
   
    std::vector<TString> getEleSystList(){return ele_systList; };
    std::vector<TString> getMuonSystList(){return muon_systList; };
    std::map<TString,std::vector<TString>> getEleMap(){return eleMap; };
    std::map<TString,std::vector<TString>> getMuonMap(){return muonMap; };
   
private:
    
    std::vector<TString> ele_systList;
    std::vector<TString> muon_systList;
    std::map<TString,std::vector<TString>> eleMap;
    std::map<TString,std::vector<TString>> muonMap; 

    void GetNode(TXMLEngine* xml, XMLNodePointer_t node, Int_t level, std::vector<TString> &ele_systList, std::vector<TString> &muon_systList, std::map<TString,std::vector<TString>> &eleMap,  std::map<TString,std::vector<TString>> &muonMap);
};

#endif
