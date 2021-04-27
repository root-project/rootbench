/* 
 *Class to read FF xml  
 *All FF info are stored in una map<TString,vector<TString>>
 *Name of the syst are stored in vector<TString> 
*/

#include <LoopSUSYFrame/readFFXML.h>
#include <iostream>

readFFXML::readFFXML(const char* filename)
{

   std::cout<<">>>>>>>>>> Reading FF from "<<filename<<" <<<<<<<<<<"<<std::endl;

   ele_systList.clear();
   muon_systList.clear();
   eleMap.clear();
   muonMap.clear();

   // First create engine
   TXMLEngine* xml = new TXMLEngine;
   // Now try to parse xml file
   // Only file with restricted xml syntax are supported
   XMLDocPointer_t xmldoc = xml->ParseFile(filename);
   if (xmldoc==0) {
      delete xml;
      return;
   }
   // take access to main node
   XMLNodePointer_t mainnode = xml->DocGetRootElement(xmldoc);
   // display recursively all nodes and subnodes
   GetNode(xml, mainnode, 1, ele_systList, muon_systList, eleMap, muonMap);

   // Release memory before exit
   xml->FreeDoc(xmldoc);
   delete xml;
}

void readFFXML::GetNode(TXMLEngine* xml, XMLNodePointer_t node, Int_t level, std::vector<TString> &ele_systList, std::vector<TString> &muon_systList, std::map<TString,std::vector<TString>> &eleMap,  std::map<TString,std::vector<TString>> &_muonMap)

{
   // this function display all accessible information about xml node and its children
   TString ndName = xml->GetNodeName(node);
   
   printf("%*c node: %s\n",level,' ', ndName.Data());
   // display namespace
   /*XMLNsPointer_t ns = xml->GetNS(node); 
   if (ns!=0)
      printf("%*c namespace: %s refer: %s\n",level+2,' ', xml->GetNSName(ns), xml->GetNSReference(ns));*/
   // display attributes
   XMLAttrPointer_t attr = xml->GetFirstAttr(node);
   std::vector<TString> vAttrName; 
   std::vector<TString> vAttrVal;
   while (attr!=0) {
       TString attrName = TString(xml->GetAttrName(attr));
       TString attrVal = TString(xml->GetAttrValue(attr));
       printf("%*c attr: %s value: %s\n",level+2,' ', attrName.Data(), attrVal.Data());
       vAttrName.push_back(attrName);
       vAttrVal.push_back(attrVal);
       attr = xml->GetNextAttr(attr);
   }

  
   // display content (if exists)
   TString content = TString(xml->GetNodeContent(node));
   if (content!=0)
      printf("%*c cont: %s\n",level+2,' ', content.Data());
   

   //Store informaiton
   if (ndName.Contains("syst")){
      try{
        TString systs = content.ReplaceAll(" ","");         
        if (vAttrName[0].Contains("affects") ){
           if ( vAttrVal[0].Contains("electron") ) ele_systList.push_back(systs); 
           if ( vAttrVal[0].Contains("muon") ) muon_systList.push_back(systs); 
        }

      } catch(const std::exception& e) { // caught by reference to base
        std::cout << " a standard exception was caught, with message '"<< e.what() <<std::endl;
      }     
   }

   if (ndName.Contains("bin")){
      try{
        XMLAttrPointer_t parent = xml->GetParent(node);
        TString parentName = xml->GetNodeName(parent);

        if (parentName.Contains("electron")){
           for(unsigned int i=0; i<vAttrName.size();i++) eleMap[vAttrName[i]].push_back(vAttrVal[i]);          
           eleMap["FFval"].push_back(content);
        } 
        if (parentName.Contains("muon")){
           for(unsigned int i=0; i<vAttrName.size();i++) _muonMap[vAttrName[i]].push_back(vAttrVal[i]);          
           _muonMap["FFval"].push_back(content);
        } 
               

      } catch(const std::exception& e) { // caught by reference to base
          std::cout << " a standard exception was caught, with message '"<< e.what() <<std::endl;
      }     
   }


   // display all child nodes
   XMLNodePointer_t child = xml->GetChild(node);
   while (child!=0) {
      GetNode(xml, child, level+2, ele_systList, muon_systList, eleMap, _muonMap);
      child = xml->GetNext(child);
   }
}




