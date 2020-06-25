/*
 *   Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
 *   */
#if __has_include("RestFrames/RestFrames.hh")
#include <RootCore/Packages.h>

#ifndef RESTFRAMESHELPER_H
#define RESTFRAMESHELPER_H
#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

enum InvJigsawType { kSetMass, kSetRapidity, kContraBoost };
enum CombJigsawType { kMinMasses };

class RestFramesHelper {
 public:
  RestFramesHelper() {}
  virtual ~RestFramesHelper();
  LabRecoFrame*            addLabFrame(const std::string &name);
  DecayRecoFrame*          addDecayFrame(const std::string &name);
  VisibleRecoFrame*        addVisibleFrame(const std::string &name);
  InvisibleRecoFrame*      addInvisibleFrame(const std::string &name);
  SelfAssemblingRecoFrame* addSAFrame(const std::string &name);
  InvisibleJigsaw*         addInvisibleJigsaw(const std::string &name, InvJigsawType type);
  MinMassesCombJigsaw*     addCombinatoricJigsaw(const std::string &name, CombJigsawType type);
  InvisibleGroup*          addInvisibleGroup(const std::string &name);
  CombinatoricGroup*       addCombinatoricGroup(const std::string &name);

  LabRecoFrame*            getLabFrame(const std::string &name);
  DecayRecoFrame*          getDecayFrame(const std::string &name);
  VisibleRecoFrame*        getVisibleFrame(const std::string &name);
  InvisibleRecoFrame*      getInvisibleFrame(const std::string &name);
  SelfAssemblingRecoFrame* getSAFrame(const std::string &name);
  InvisibleJigsaw*         getInvisibleJigsaw(const std::string &name);
  MinMassesCombJigsaw*     getCombinatoricJigsaw(const std::string &name);
  InvisibleGroup*          getInvisibleGroup(const std::string &name);
  CombinatoricGroup*       getCombinatoricGroup(const std::string &name);

 private:
  std::map<std::string,LabRecoFrame*> m_LabFrames;
  std::map<std::string,DecayRecoFrame*> m_DecayFrames;
  std::map<std::string,SelfAssemblingRecoFrame*> m_SAFrames;
  std::map<std::string,VisibleRecoFrame*> m_VisFrames;
  std::map<std::string,InvisibleRecoFrame*> m_InvFrames;
  std::map<std::string,InvisibleJigsaw*> m_InvJigsaws;
  std::map<std::string,MinMassesCombJigsaw*> m_CombJigsaws;
  std::map<std::string,InvisibleGroup*> m_InvGroups;
  std::map<std::string,CombinatoricGroup*> m_CombGroups;

  std::vector<RFBase*> m_Objects;

};

#endif // restframes helper
#endif 

