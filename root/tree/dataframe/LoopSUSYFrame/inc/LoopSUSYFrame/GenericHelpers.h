#ifndef GENERIC_HELPERS_H
#define GENERIC_HELPERS_H

#include <ROOT/RVec.hxx>
#include <TLorentzVector.h>
#include <TH1D.h>

#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

std::vector<std::string> AddWeightBranches(std::vector<std::string> &inBranches);

int CountObjects(const std::vector<short unsigned int> &idxs);
bool PassTrigger(const ROOT::VecOps::RVec<int> triggerVec);

float DeltaPhi(const float part1phi, const float part2phi);
float GetDeltaPhiMin(const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<float> &phivec, const float METphi);
float GetDeltaPhiMinMin(const std::vector<short unsigned int> &idxs1, const ROOT::VecOps::RVec<float> &phivec1, const std::vector<short unsigned int> &idxs2, const ROOT::VecOps::RVec<float> &phivec2);
float GetDeltaRMin( int id1, const ROOT::VecOps::RVec<float> &pt1, const ROOT::VecOps::RVec<float> &eta1, const ROOT::VecOps::RVec<float> &phi1, const ROOT::VecOps::RVec<float> &mass1, const ROOT::VecOps::RVec<bool>  &passOR1, const std::vector<short unsigned int> &idxs2, const ROOT::VecOps::RVec<float> &pt2, const ROOT::VecOps::RVec<float> &eta2, const ROOT::VecOps::RVec<float> &phi2, const ROOT::VecOps::RVec<float> &mass2, const ROOT::VecOps::RVec<bool>  &passOR2);

inline float Project(const float pT, const float phi) {
	return fabs(pT * cos(phi));
}

float GetHT(const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<float> &ptvec);

// Some free functions returning Lambdas O.o
namespace LambdaMaker
{

inline auto NoFilt(const bool isdata)
{
	return [isdata](const int ChannelNumber)
	{
		if (isdata) return true;
		else{
			if (ChannelNumber == 407345) return false;
			if (ChannelNumber == 407346) return false;
			if (ChannelNumber == 407347) return false;
			if (ChannelNumber == 407344) return false;
			if (ChannelNumber == 407343) return false;
			if (ChannelNumber == 407342) return false;
		}
		return true;
	};
}


inline auto MCFiltMET(const bool isdata)
{
	return [isdata](const int ChannelNumber, const float GenFiltMET)
	{
		if (isdata) return true;
		else {
/*			if ((ChannelNumber == 410000 || ChannelNumber == 410009 || ChannelNumber == 410065 || ChannelNumber == 410064 || ChannelNumber == 410015 || ChannelNumber == 410016) && GenFiltMET > 200000) {
				return false;
			}
			if ((ChannelNumber == 407012 || ChannelNumber == 407021 || ChannelNumber == 407019 ) && GenFiltMET < 200000) {
				return false;
			}*/
			if ( (ChannelNumber == 410470 || ChannelNumber == 410472) && GenFiltMET > 200000.){
				return false;
			}
			if (ChannelNumber == 407345 && ( GenFiltMET <= 200000. || GenFiltMET > 300000.)){
				return false;
			}
			if (ChannelNumber == 407346 && ( GenFiltMET <= 300000. || GenFiltMET > 400000.)){
				return false;
			}
			if (ChannelNumber == 407347 && GenFiltMET <= 400000. ){
				return false;
			}
			if ( (ChannelNumber == 407344) || (ChannelNumber == 407343) || (ChannelNumber == 407342)){
				return false;
			}
		return true;
		}
	};
}

inline auto MCFiltMETWt(const bool isdata)
{
	return [isdata](const int ChannelNumber, const float GenFiltMET)
	{
		if (isdata) return true;
		else {
			if ( (ChannelNumber == 410646 || ChannelNumber == 410647 || ChannelNumber == 410648 || ChannelNumber == 410649 || ChannelNumber == 410655 || ChannelNumber == 410654 || ChannelNumber == 410656 || ChannelNumber == 410657) && GenFiltMET > 200000.){
				return false;
			}
			if ((ChannelNumber == 411196 || ChannelNumber == 411202 || ChannelNumber == 411193 || ChannelNumber == 411199 ) && ( GenFiltMET <= 200000. || GenFiltMET > 300000.)){
				return false;
			}
			if ((ChannelNumber == 411197 || ChannelNumber == 411203 || ChannelNumber == 411194 || ChannelNumber == 411200 ) && ( GenFiltMET <= 300000. || GenFiltMET > 400000.)){
				return false;
			}
			if ((ChannelNumber == 411198 || ChannelNumber == 411204 || ChannelNumber == 411195 || ChannelNumber == 411201 ) && GenFiltMET <= 400000. ){
				return false;
			}
		return true;
		}
	};
}

inline auto MCFiltHT(const bool isdata)
{
	return [isdata](const int ChannelNumber, const float GenFiltHT)
	{
		if (isdata) return true;
		else {
/*			if ( (ChannelNumber == 410000 || ChannelNumber == 407012 || ChannelNumber == 410001 || ChannelNumber == 410002 || ChannelNumber == 410004) && GenFiltHT > 600000) {
				return false;
			}
			if ( (ChannelNumber == 410013 || ChannelNumber == 410014 || ChannelNumber == 410019 || ChannelNumber == 410021) && GenFiltHT > 500000 ) {
				return false;
			}*/
			if ( ChannelNumber == 410470 && GenFiltHT > 600000.){
				return false;
			}
			if ( ChannelNumber == 407344 && ( GenFiltHT <= 600000. && GenFiltHT > 1000000.)){
				return false;
			}
			if ( ChannelNumber == 407343 && ( GenFiltHT <= 1000000. && GenFiltHT > 1500000.)){
				return false;
			}
			if ( ChannelNumber == 407342 &&  GenFiltHT <= 1500000. ){
				return false;
			}
			if (ChannelNumber == 407345 || ChannelNumber == 407346 || ChannelNumber == 407347){
				return false;
			}
			return true;
		}
	};
}

inline auto MCFiltMETHT(const bool isdata)
{
	return [isdata](const int ChannelNumber, const float GenFiltMET, const float GenFiltHT)
	{
		if (isdata) return true;
		else {
/*			if ( (ChannelNumber == 410000 ) && (GenFiltMET > 200000 || GenFiltHT > 600000) ) {
				return false;
			}
			if ( (ChannelNumber == 407012 || ChannelNumber == 410001 || ChannelNumber == 410002 || ChannelNumber == 410004) && GenFiltHT > 600000) {
				return false;
			}
			if ( (ChannelNumber == 410013 || ChannelNumber == 410014) && (GenFiltMET > 200000 || GenFiltHT > 500000) ) {
				return false;
			}
			if ( (ChannelNumber == 410019 || ChannelNumber == 410021) && GenFiltHT > 500000) {
				return false;
			}
*/			
			if ( (ChannelNumber == 410470) && ( (GenFiltMET > 200000.) || (GenFiltHT > 600000.)) ){
				return false;
			}
			if ( (ChannelNumber == 407344) && ( (GenFiltMET > 200000.) || (GenFiltHT < 600000.) || (GenFiltHT > 1000000.))){
				return false;
			}
			if ( (ChannelNumber == 407343) && ( (GenFiltMET > 200000.) || (GenFiltHT < 1000000.) || (GenFiltHT > 1500000.))){
				return false;
			}
			if ( (ChannelNumber == 407342) && ( (GenFiltMET > 200000.) || (GenFiltHT < 1500000.) )){
				return false;
			}
			if ( (ChannelNumber == 407345) && ( (GenFiltMET <= 200000.) || (GenFiltMET > 300000.))){
				return false;
			}
			if ( (ChannelNumber == 407346) && ( (GenFiltMET <= 300000.) || (GenFiltMET > 400000.))){
				return false;
			}
			if ( (ChannelNumber == 407347) && (GenFiltMET <= 400000.) ){
				return false;
			}

			return true;
		}
	};
}

inline auto MCFiltMETHTWt(const bool isdata)
{
	return [isdata](const int ChannelNumber, const float GenFiltMET, const float GenFiltHT)
	{
		if (isdata) return true;
		else {		
			if ( (ChannelNumber == 410646 || ChannelNumber == 410647 || ChannelNumber == 410648 || ChannelNumber == 410649 || ChannelNumber == 410655 || ChannelNumber == 410654 || ChannelNumber == 410656 || ChannelNumber == 410657) && ( (GenFiltMET > 200000.) || (GenFiltHT > 600000.)) ){
				return false;
			}

			if ( (ChannelNumber == 411181 || ChannelNumber == 411184 ) && ( GenFiltMET > 200000. && ( GenFiltHT > 600000. || GenFiltHT < 1000000.)) ){
				return false;
			}
			if ( (ChannelNumber == 411182 || ChannelNumber == 411185 ) && ( GenFiltMET > 200000. && ( GenFiltHT > 1000000. || GenFiltHT < 1500000.)) ){
				return false;
			}
			if ( (ChannelNumber == 411183 || ChannelNumber == 411186 ) && ( GenFiltMET > 200000. && GenFiltHT < 1500000.) ){
				return false;
			}

			if ((ChannelNumber == 411196 || ChannelNumber == 411202 || ChannelNumber == 411193 || ChannelNumber == 411199 ) && ( GenFiltMET <= 200000. || GenFiltMET > 300000.)){
				return false;
			}
			if ((ChannelNumber == 411197 || ChannelNumber == 411203 || ChannelNumber == 411194 || ChannelNumber == 411200 ) && ( GenFiltMET <= 300000. || GenFiltMET > 400000.)){
				return false;
			}
			if ((ChannelNumber == 411198 || ChannelNumber == 411204 || ChannelNumber == 411195 || ChannelNumber == 411201 ) && GenFiltMET <= 400000. ){
				return false;
			}

			return true;
		}
	};
}

inline auto LumiWeightCalc(const double sumOfWeights, const bool isMCa, const bool isMCd, const bool isMCe)
{
	return [sumOfWeights,isMCa,isMCd,isMCe]() {
		double weight = 1. / sumOfWeights;
		double lumi15 = 3.2;
		double lumi16 = 33.0;
		double lumi17 = 44.3;
		double lumi18 = 58.45;
		double lumi_total = lumi15 + lumi16 + lumi17 + lumi18;
//		double lumi_total = lumi17;
		if(isMCa) weight = weight * (lumi15+lumi16)/lumi_total;
		else if(isMCd) weight = weight * lumi17/lumi_total;
		else if(isMCe) weight = weight * lumi18/lumi_total;
		else weight = weight*-1;
//
//		TEMPORARY FIX
//		if(isMCa) weight = weight * 36.2/(79.8+59.937);
//		else weight = weight * (43.6+59.937)/(79.8+59.937);

		return weight;
	};
}

inline auto GetWeights(const bool isdata, const bool isSignal, const float xsecFromfile, const float kFact, const float filtEff)
{
    return [isdata,isSignal,xsecFromfile,kFact,filtEff](const float Wevents, const float WselSF, const float WsmuSF, const float WJVT, const double xsec, const int dsid, const double lumiW) {
        float weight = 1.;
        if(!isdata && !isSignal) {
            if(dsid == 344235) weight=Wevents*WselSF*WsmuSF*WJVT*float(5.13e-04*1000.)*float(lumiW);
            else if(dsid == 345055) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0521*1000.)*float(lumiW);
            else if(dsid == 345061) weight=Wevents*WselSF*WsmuSF*WJVT*float(2.79e-04*1000.)*float(lumiW);
            else if(dsid == 345073) weight=Wevents*WselSF*WsmuSF*WJVT*float(1.37e-02*1000.)*float(lumiW);
            else if(dsid == 345074 || dsid == 345075) weight=Wevents*WselSF*WsmuSF*WJVT*float(9.57e-03*1000.)*float(lumiW);
            else if(dsid == 345076) weight=Wevents*WselSF*WsmuSF*WJVT*float(4.71e-02*1000.)*float(lumiW);
            else if(dsid == 345120) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.149*1000.)*float(lumiW);
            else if(dsid == 345121 || dsid == 345122) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.105*1000.)*float(lumiW);
            else if(dsid == 345123) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.523*1000.)*float(lumiW);
            else if(dsid == 345211) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0334*1000.)*float(lumiW);
            else if(dsid == 345212) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0527*1000.)*float(lumiW);
            else if(dsid == 345217) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0554*1000.)*float(lumiW);
            else if(dsid == 345319) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.002*1000.)*float(lumiW);
            else if(dsid == 345323) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0858*1000.)*float(lumiW);
            else if(dsid == 345324) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.494*1000.)*float(lumiW);
            else if(dsid == 345325) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0128*1000.)*float(lumiW);
            else if(dsid == 345326) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0041*1000.)*float(lumiW);
            else if(dsid == 345327) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0064*1000.)*float(lumiW);
            else if(dsid == 345336) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.0140*1000.)*float(lumiW);
            else if(dsid == 345337) weight=Wevents*WselSF*WsmuSF*WJVT*float(0.002*1000.)*float(lumiW);
            else if(dsid == 345446) weight=Wevents*WselSF*WsmuSF*WJVT*float(2.82e-04*1000.)*float(lumiW);
            else weight = Wevents*WselSF*WsmuSF*WJVT*float(xsec*1000.)*float(lumiW);
        }
        else if(!isdata && isSignal) weight = Wevents*WselSF*WsmuSF*WJVT*xsecFromfile*float(1000.)*kFact*filtEff*float(lumiW);
        return weight;
    };
}

inline auto GetLumiWeight(const bool isdata, const bool isSignal, const float xsecFromfile, const float kFact, const float filtEff)
{
    return [isdata,isSignal,xsecFromfile,kFact,filtEff](const double xsec, const int dsid, const double lumiW) {
        float weight = 1.;
        if(!isdata && !isSignal) {
            if(dsid == 344235) weight=float(5.13e-04*1000.)*float(lumiW);
            else if(dsid == 345055) weight=float(0.0521*1000.)*float(lumiW);
            else if(dsid == 345061) weight=float(2.79e-04*1000.)*float(lumiW);
            else if(dsid == 345073) weight=float(1.37e-02*1000.)*float(lumiW);
            else if(dsid == 345074 || dsid == 345075) weight=float(9.57e-03*1000.)*float(lumiW);
            else if(dsid == 345076) weight=float(4.71e-02*1000.)*float(lumiW);
            else if(dsid == 345120) weight=float(0.149*1000.)*float(lumiW);
            else if(dsid == 345121 || dsid == 345122) weight=float(0.105*1000.)*float(lumiW);
            else if(dsid == 345123) weight=float(0.523*1000.)*float(lumiW);
            else if(dsid == 345211) weight=float(0.0334*1000.)*float(lumiW);
            else if(dsid == 345212) weight=float(0.0527*1000.)*float(lumiW);
            else if(dsid == 345217) weight=float(0.0554*1000.)*float(lumiW);
            else if(dsid == 345319) weight=float(0.002*1000.)*float(lumiW);
            else if(dsid == 345323) weight=float(0.0858*1000.)*float(lumiW);
            else if(dsid == 345324) weight=float(0.494*1000.)*float(lumiW);
            else if(dsid == 345325) weight=float(0.0128*1000.)*float(lumiW);
            else if(dsid == 345326) weight=float(0.0041*1000.)*float(lumiW);
            else if(dsid == 345327) weight=float(0.0064*1000.)*float(lumiW);
            else if(dsid == 345336) weight=float(0.0140*1000.)*float(lumiW);
            else if(dsid == 345337) weight=float(0.002*1000.)*float(lumiW);
            else if(dsid == 345446) weight=float(2.82e-04*1000.)*float(lumiW);
            else weight = float(xsec*1000.)*float(lumiW);
        }
        else if(!isdata && isSignal) weight = float(1000.)*xsecFromfile*kFact*filtEff*float(lumiW);
        return weight;
    };
}
 inline auto GetLRHxsec(const bool isdata, const bool isSignal)
 {
   return [isdata,isSignal](const int dsid, const bool isLH) {
     float LRHxsec = 1.;
     std::pair <float,float> the_LRHxsec;
     //     if(isSignal) {
     if(dsid == 395897) the_LRHxsec = std::make_pair (0.470691,0.165388);
     else if(dsid == 395898) the_LRHxsec = std::make_pair (0.470691,0.165388);
     else if(dsid == 395908) the_LRHxsec = std::make_pair (0.27079,0.09651);
     else if(dsid == 395909) the_LRHxsec = std::make_pair (0.27079,0.09651);
     else if(dsid == 395910) the_LRHxsec = std::make_pair (0.27079,0.09651);
     else if(dsid == 395920) the_LRHxsec = std::make_pair (0.131639,0.047683);
     else if(dsid == 395930) the_LRHxsec = std::make_pair (0.06334,0.02332);
     else if(dsid == 395931) the_LRHxsec = std::make_pair (0.06334,0.02332);
     else if(dsid == 395946) the_LRHxsec = std::make_pair (0.02181,0.00815);
     else if(dsid == 395947) the_LRHxsec = std::make_pair (0.02181,0.00815);
     else if(dsid == 395948) the_LRHxsec = std::make_pair (0.02181,0.00815);
     else if(dsid == 395949) the_LRHxsec = std::make_pair (0.02181,0.00815);
     else if(dsid == 395962) the_LRHxsec = std::make_pair (0.00921,0.00347);
     else if(dsid == 395963) the_LRHxsec = std::make_pair (0.00921,0.00347);
     else if(dsid == 395964) the_LRHxsec = std::make_pair (0.00921,0.00347);
     else if(dsid == 395965) the_LRHxsec = std::make_pair (0.00921,0.00347);
     else if(dsid == 395969) the_LRHxsec = std::make_pair (0.00443,0.00168);
     else if(dsid == 395970) the_LRHxsec = std::make_pair (0.00443,0.00168);
     else if(dsid == 395971) the_LRHxsec = std::make_pair (0.00443,0.00168);
     else if(dsid == 395972) the_LRHxsec = std::make_pair (0.00443,0.00168);
     else if(dsid == 395973) the_LRHxsec = std::make_pair (0.00443,0.00168);
     else if(dsid == 395974) the_LRHxsec = std::make_pair (0.00443,0.00168);
     else if(dsid == 395975) the_LRHxsec = std::make_pair (0.00233,0.00089);
     else if(dsid == 395976) the_LRHxsec = std::make_pair (0.00233,0.00089);
     else if(dsid == 395977) the_LRHxsec = std::make_pair (0.00233,0.00089);
     else if(dsid == 395978) the_LRHxsec = std::make_pair (0.00233,0.00089);
     else if(dsid == 395979) the_LRHxsec = std::make_pair (0.00233,0.00089);
     else if(dsid == 395980) the_LRHxsec = std::make_pair (0.00233,0.00089);
     else if(dsid == 395981) the_LRHxsec = std::make_pair (0.00233,0.00089);
     else if(dsid == 395982) the_LRHxsec = std::make_pair (0.00131,0.0005);
     else if(dsid == 395983) the_LRHxsec = std::make_pair (0.00131,0.0005);
     else if(dsid == 395984) the_LRHxsec = std::make_pair (0.00131,0.0005);
     else if(dsid == 395985) the_LRHxsec = std::make_pair (0.00131,0.0005);
     else if(dsid == 395986) the_LRHxsec = std::make_pair (0.00131,0.0005);
     else if(dsid == 395987) the_LRHxsec = std::make_pair (0.00131,0.0005);
     else if(dsid == 395988) the_LRHxsec = std::make_pair (0.00131,0.0005);
     else if(dsid == 395989) the_LRHxsec = std::make_pair (0.00077,0.0003);
     else if(dsid == 395990) the_LRHxsec = std::make_pair (0.00077,0.0003);
     else if(dsid == 395991) the_LRHxsec = std::make_pair (0.00077,0.0003);
     else if(dsid == 395992) the_LRHxsec = std::make_pair (0.00077,0.0003);
     else if(dsid == 395993) the_LRHxsec = std::make_pair (0.00077,0.0003);
     else if(dsid == 395994) the_LRHxsec = std::make_pair (0.00077,0.0003);
     else if(dsid == 395995) the_LRHxsec = std::make_pair (0.00077,0.0003);
     else if(dsid == 395996) the_LRHxsec = std::make_pair (0.00047,0.00018);
     else if(dsid == 395997) the_LRHxsec = std::make_pair (0.00047,0.00018);
     else if(dsid == 395998) the_LRHxsec = std::make_pair (0.00047,0.00018);
     else if(dsid == 395999) the_LRHxsec = std::make_pair (0.00047,0.00018);
     else if(dsid == 396000) the_LRHxsec = std::make_pair (0.00047,0.00018);
     else if(dsid == 396001) the_LRHxsec = std::make_pair (0.00047,0.00018);
     else if(dsid == 396002) the_LRHxsec = std::make_pair (0.00047,0.00018);
     else if(dsid == 396003) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396004) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396005) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396006) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396007) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396008) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396009) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396010) the_LRHxsec = std::make_pair (0.000293,0.000116);
     else if(dsid == 396011) the_LRHxsec = std::make_pair (0.000190,0.0000751);
     else if(dsid == 396012) the_LRHxsec = std::make_pair (0.000190,0.0000751);
     else if(dsid == 396013) the_LRHxsec = std::make_pair (0.000190,0.0000751);
     else if(dsid == 396014) the_LRHxsec = std::make_pair (0.000190,0.0000751);
     else if(dsid == 396015) the_LRHxsec = std::make_pair (0.000190,0.0000751);
     else if(dsid == 396016) the_LRHxsec = std::make_pair (0.000190,0.0000751);
     else if(dsid == 396017) the_LRHxsec = std::make_pair (0.000190,0.0000751);
     else if(dsid == 396018) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396019) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396020) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396021) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396022) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396023) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396024) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396025) the_LRHxsec = std::make_pair (0.000126,0.0000499);
     else if(dsid == 396026) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396027) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396028) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396029) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396030) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396031) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396032) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396033) the_LRHxsec = std::make_pair (0.0000850,0.0000338);
     else if(dsid == 396034) the_LRHxsec = std::make_pair (0.0000405,0.0000162);
     else if(dsid == 396035) the_LRHxsec = std::make_pair (0.0000405,0.0000162);
     else if(dsid == 396036) the_LRHxsec = std::make_pair (0.0000405,0.0000162);
     else if(dsid == 396037) the_LRHxsec = std::make_pair (0.0000405,0.0000162);
     else if(dsid == 396038) the_LRHxsec = std::make_pair (0.0000405,0.0000162);
     else if(dsid == 396039) the_LRHxsec = std::make_pair (0.0000405,0.0000162);
     else if(dsid == 396040) the_LRHxsec = std::make_pair (0.0000405,0.0000162);
     else if(dsid == 396041) the_LRHxsec = std::make_pair (0.0000405,0.0000162); // this the the last 2L8 filtered sample
     else if(dsid == 398178) the_LRHxsec = std::make_pair (0.26793,0.09779);
     else if(dsid == 398179) the_LRHxsec = std::make_pair (0.26793,0.09779);
     else if(dsid == 398180) the_LRHxsec = std::make_pair (0.26793,0.09779);
     else if(dsid == 398181) the_LRHxsec = std::make_pair (0.12167,0.045239);
     else if(dsid == 398182) the_LRHxsec = std::make_pair (0.12167,0.045239);
     else if(dsid == 398183) the_LRHxsec = std::make_pair (0.12167,0.045239);
     else if(dsid == 398184) the_LRHxsec = std::make_pair (0.063306,0.023811);
     else if(dsid == 398185) the_LRHxsec = std::make_pair (0.063306,0.023811);
     else if(dsid == 398186) the_LRHxsec = std::make_pair (0.063306,0.023811);
     else if(dsid == 398187) the_LRHxsec = std::make_pair (0.036071,0.01368);
     else if(dsid == 398188) the_LRHxsec = std::make_pair (0.036071,0.01368);
     else if(dsid == 398189) the_LRHxsec = std::make_pair (0.036071,0.01368);
     else if(dsid == 398190) the_LRHxsec = std::make_pair (0.021942,0.008372);
     else if(dsid == 398191) the_LRHxsec = std::make_pair (0.021942,0.008372);
     else if(dsid == 398192) the_LRHxsec = std::make_pair (0.021942,0.008372);
     else if(dsid == 398193) the_LRHxsec = std::make_pair (0.014031,0.0053796);
     else if(dsid == 398194) the_LRHxsec = std::make_pair (0.014031,0.0053796);
     else if(dsid == 398195) the_LRHxsec = std::make_pair (0.014031,0.0053796);
     else if(dsid == 398196) the_LRHxsec = std::make_pair (0.0093297,0.0035906);
     else if(dsid == 398197) the_LRHxsec = std::make_pair (0.0093297,0.0035906);
     else if(dsid == 398198) the_LRHxsec = std::make_pair (0.0093297,0.0035906);
     else if(dsid == 398199) the_LRHxsec = std::make_pair (0.0064025,0.0024724);
     else if(dsid == 398200) the_LRHxsec = std::make_pair (0.0064025,0.0024724);
     else if(dsid == 398201) the_LRHxsec = std::make_pair (0.0064025,0.0024724);
     else if(dsid == 398202) the_LRHxsec = std::make_pair (0.0045083,0.0017459);
     else if(dsid == 398203) the_LRHxsec = std::make_pair (0.0045083,0.0017459);
     else if(dsid == 398204) the_LRHxsec = std::make_pair (0.0045083,0.0017459);
     else std::cout << "ERROR: no xsec found for dsid = " << dsid << std::endl;

     if (isLH)
       LRHxsec = the_LRHxsec.first;
     else
       LRHxsec = the_LRHxsec.second;
     //     }
     return LRHxsec;
   };
 }

inline auto GetMCchan(const int mcChan)
{
	return [mcChan]() {
		return mcChan;
	};
}

inline auto CountObjectsAbovePt(const float &threshold)
{
	return [threshold] (const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<float> &ptvec)
	{
		int counter = 0;
		for (short unsigned int iobj = 0; iobj < idxs.size(); iobj++) {
			int index = idxs[iobj];
			if (ptvec[index] > threshold) counter++;
		}
		return counter;
	};
}

inline auto CountObjectsEqualTo(const int &ID)
{
	return [ID] (const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &pdgIDvec)
	{
		int counter = 0;
		for (short unsigned int iobj = 0; iobj < idxs.size(); iobj++) {
			int index = idxs[iobj];
			if (pdgIDvec[index] == ID) counter++;
		}
		return counter;
	};
}

inline auto FindNLeading(const short unsigned int position, const bool divideByAThousand = false)
{
	return [position, divideByAThousand](const ROOT::VecOps::RVec<float> &vec, const std::vector<short unsigned int> &idxs)
	{
		if (idxs.size() > position) {
			if (divideByAThousand) return float(vec[idxs[position]] / 1000.);
			else return float(vec[idxs[position]]);
		}
		else return float(-10.);
	};
}

inline auto FindNLeading_Int(const short unsigned int position, const bool divideByAThousand = false)
{
	return [position, divideByAThousand](const ROOT::VecOps::RVec<int> &vec, const std::vector<short unsigned int> &idxs)
	{
		if (idxs.size() > position) {
			if (divideByAThousand) return int(vec[idxs[position]] / 1000.);
			else return int(vec[idxs[position]]);
		}
		else return int(-10);
	};
}

inline auto FindNLeading_Bool(const short unsigned int position)
{
	return [position](const ROOT::VecOps::RVec<bool> &vec, const std::vector<short unsigned int> &idxs)
	{
		if(idxs.size() > position) return bool(vec[idxs[position]]);
		else return false;
	};
}

inline auto GetMlll(const bool divideByAThousand = false)
{
	return [divideByAThousand](const short unsigned int idx1, const short unsigned int idx2, const short unsigned int idx3, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec)
	{
		TLorentzVector lep1, lep2, lep3;
		lep1.SetPtEtaPhiM(ptvec[idx1], etavec[idx1], phivec[idx1], massvec[idx1]);
		lep2.SetPtEtaPhiM(ptvec[idx2], etavec[idx2], phivec[idx2], massvec[idx2]);
		lep3.SetPtEtaPhiM(ptvec[idx3], etavec[idx3], phivec[idx3], massvec[idx3]);
		float mlll = (lep1 + lep2 + lep3).M();
		if (divideByAThousand) mlll /= 1000.;
		return mlll;
	};
}
 
 
inline auto GetMll(const bool divideByAThousand = false)
{
	return [divideByAThousand](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec)
	{
		TLorentzVector lep1, lep2;
		if (idx1==65535||idx2==65535) {float mll = -1.;return mll;}
		lep1.SetPtEtaPhiM(ptvec[idx1], etavec[idx1], phivec[idx1], massvec[idx1]);
		lep2.SetPtEtaPhiM(ptvec[idx2], etavec[idx2], phivec[idx2], massvec[idx2]);
		float mll = (lep1 + lep2).M();
		if (divideByAThousand) mll /= 1000.;
		
		return mll;
	};
}
 inline auto GetMllMET(const bool divideByAThousand = false) 
 {
   return [divideByAThousand](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec, float MET, float MET_phi)
     {
       TLorentzVector lep1, lep2;
       if (idx1==65535||idx2==65535) {float mllMET = -1.;return mllMET;}
       lep1.SetPtEtaPhiM(ptvec[idx1], etavec[idx1], phivec[idx1], massvec[idx1]);
       lep2.SetPtEtaPhiM(ptvec[idx2], etavec[idx2], phivec[idx2], massvec[idx2]);

       TLorentzVector Etmiss;
       Etmiss.SetPtEtaPhiM(MET, 0., MET_phi, 0.);
       
       float mllMET = (lep1 + lep2 + Etmiss).M();
       if (divideByAThousand) mllMET /= 1000.;

       return mllMET;
     };
 }

 inline auto calcMTauTau(const bool divideByAThousand = false) // approximate invariant mass of the two taus (e.g. arXiv:1501.02511)
 {
   return [divideByAThousand](const short unsigned int &lep1_idx, const short unsigned int &lep2_idx, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec, const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec, float MET, float MET_phi)
     {
       TLorentzVector lep1, lep2;
       lep1.SetPtEtaPhiM(ptvec[lep1_idx] / 1000., etavec[lep1_idx], phivec[lep1_idx], massvec[lep1_idx] / 1000.);
       lep2.SetPtEtaPhiM(ptvec[lep2_idx] / 1000., etavec[lep2_idx], phivec[lep2_idx], massvec[lep2_idx] / 1000.);
       TLorentzVector Etmiss;
       Etmiss.SetPtEtaPhiM(MET, 0., MET_phi, 0.);
       float determinant = lep1.Px() * lep2.Py() - lep1.Py() * lep2.Px();
       float xi_1 = (Etmiss.Px() * lep2.Py() - lep2.Px() * Etmiss.Py())/determinant;
       float xi_2 = (Etmiss.Py() * lep1.Px() - lep1.Py() * Etmiss.Px())/determinant;

       float MSqTauTau = (1. + xi_1) * (1. + xi_2) * 2 * lep1.Dot(lep2);

       float MTauTau = 0.;
       if (MSqTauTau >= 0) MTauTau =   sqrt( MSqTauTau );
       if (MSqTauTau < 0)  MTauTau = - sqrt( fabs( MSqTauTau ) );

       if (divideByAThousand) MTauTau /= 1000.;

       return MTauTau;
     };
 }

 inline auto GetcosTstar() //cos theta star from arXiv:0511115
 {
   return [](const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec)
     {
       TLorentzVector lep1, lep2;
       lep1.SetPtEtaPhiM(ptvec[lep1_idx] / 1000., etavec[lep1_idx], phivec[lep1_idx], massvec[lep1_idx] / 1000.);
       lep2.SetPtEtaPhiM(ptvec[lep2_idx] / 1000., etavec[lep2_idx], phivec[lep2_idx], massvec[lep2_idx] / 1000.);

       float detall = lep1.Eta() - lep2.Eta();
       float cosTstar = abs(tanh(0.5*detall));
       return cosTstar;

     };
 }

 

inline auto GetPt_ll(const bool divideByAThousand = false)
{
	return [divideByAThousand](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec)
	{
		TLorentzVector lep1, lep2;
		if (idx1==65535||idx2==65535) {float pTll = -1.;return pTll;}
		lep1.SetPtEtaPhiM(ptvec[idx1], etavec[idx1], phivec[idx1], massvec[idx1]);
		lep2.SetPtEtaPhiM(ptvec[idx2], etavec[idx2], phivec[idx2], massvec[idx2]);
		float pTll = (lep1 + lep2).Pt();
		if (divideByAThousand) pTll /= 1000.;

		return pTll;

	};
}

inline auto GetDphi()
{
	return [](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec)
	{
		TLorentzVector lep1, lep2;
		if (idx1==65535||idx2==65535) {float GetDphi = -1.;return GetDphi;}
		lep1.SetPtEtaPhiM(ptvec[idx1], etavec[idx1], phivec[idx1], massvec[idx1]);
		lep2.SetPtEtaPhiM(ptvec[idx2], etavec[idx2], phivec[idx2], massvec[idx2]);
		float GetDphi = fabs(lep1.DeltaPhi(lep2));
		return GetDphi;

	};
}
inline auto GetDphiMETll()
{
  return [](const short unsigned int lep1_idx, const short unsigned int lep2_idx, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec, float MET, float MET_phi)
    {
      TLorentzVector lep1, lep2;
      lep1.SetPtEtaPhiM(ptvec[lep1_idx] / 1000., etavec[lep1_idx], phivec[lep1_idx], massvec[lep1_idx] / 1000.);
      lep2.SetPtEtaPhiM(ptvec[lep2_idx] / 1000., etavec[lep2_idx], phivec[lep2_idx], massvec[lep2_idx] / 1000.);

      TLorentzVector Etmiss;
      Etmiss.SetPtEtaPhiM(MET, 0., MET_phi, 0.);

      float dphiMETll = fabs(Etmiss.DeltaPhi(lep1 + lep2));

      return dphiMETll;
    };
}
 inline auto GetDphiMETl()
 {
   return [](const short unsigned int lep1_idx, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec, float MET, float MET_phi)
     {
       TLorentzVector lep1;
       lep1.SetPtEtaPhiM(ptvec[lep1_idx] / 1000., etavec[lep1_idx], phivec[lep1_idx], massvec[lep1_idx] / 1000.);

       TLorentzVector Etmiss;
       Etmiss.SetPtEtaPhiM(MET, 0., MET_phi, 0.);
       
       float dphiMETl = fabs(Etmiss.DeltaPhi(lep1));

       return dphiMETl;
     };
 }
 inline auto GetdR()
 {
  return [](const short unsigned int idx1, const short unsigned int idx2, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec)
    {
      TLorentzVector lep1, lep2;
      if (idx1==65535||idx2==65535) {float dR = -1.;return dR;}
      lep1.SetPtEtaPhiM(ptvec[idx1] / 1000., etavec[idx1], phivec[idx1], massvec[idx1] / 1000.);
      lep2.SetPtEtaPhiM(ptvec[idx2] / 1000., etavec[idx2], phivec[idx2], massvec[idx2] / 1000.);
      float dRll = lep1.DeltaR(lep2);
      return dRll;

    };
}

inline auto GetdRMETl()
{
  return [](const short unsigned int idx1, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec, float MET, float MET_phi)
    {
      TLorentzVector lep;
      lep.SetPtEtaPhiM(ptvec[idx1] / 1000., etavec[idx1], phivec[idx1], massvec[idx1] / 1000.);
      TLorentzVector Etmiss;
      Etmiss.SetPtEtaPhiM(MET, 0., MET_phi, 0.);

      float dRMETl = Etmiss.DeltaR(lep);
      return dRMETl;


    };
}


inline auto minDPhiDRLepJet(const bool showDR=false)
{   return[showDR](const short unsigned int lepidx, const ROOT::VecOps::RVec<float> &ptlep, const ROOT::VecOps::RVec<float> &etalep,  const ROOT::VecOps::RVec<float> &philep,  const ROOT::VecOps::RVec<float> &mlep, const std::vector<short unsigned int> &jetidxs, const ROOT::VecOps::RVec<float> &ptjet, const ROOT::VecOps::RVec<float> &etajet,  const ROOT::VecOps::RVec<float> &phijet,  const ROOT::VecOps::RVec<float> &mjet)
    {
       float minVal = -10.;
       TLorentzVector lep;
       lep.SetPtEtaPhiM(ptlep[lepidx], etalep[lepidx], philep[lepidx], mlep[lepidx]);
       std::vector<float> vDiff;
       for (unsigned int iJet=0; iJet<jetidxs.size();iJet++){
           TLorentzVector jet;
           jet.SetPtEtaPhiM(ptjet[jetidxs[iJet]],etajet[jetidxs[iJet]],phijet[jetidxs[iJet]],mjet[jetidxs[iJet]]);
           if (showDR) vDiff.push_back(lep.DeltaR(jet));
           else vDiff.push_back(std::abs(lep.DeltaPhi(jet)));
       }
       if(vDiff.size()>0) minVal = *std::min_element(vDiff.begin(),vDiff.end());
       return minVal;
    };
}


 inline auto GetMEToverHT()
 {
   return [](const short unsigned int &lep1_idx, const short unsigned int &lep2_idx, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec,  const ROOT::VecOps::RVec<float> &massvec, float MET)
     {
       TLorentzVector lep1, lep2;
       
       lep1.SetPtEtaPhiM(ptvec[lep1_idx] / 1000., etavec[lep1_idx], phivec[lep1_idx], massvec[lep1_idx] / 1000.);
       lep2.SetPtEtaPhiM(ptvec[lep2_idx] / 1000., etavec[lep2_idx], phivec[lep2_idx], massvec[lep2_idx] / 1000.);
       
       float HTlep  = fabs(lep1.Pt() + lep2.Pt());
       
       float METoverHT = MET/HTlep;
       return METoverHT;
     };
 }
 
 
 inline auto GetHTlep(const bool divideByAThousand = false)
 {
   return [divideByAThousand](const short unsigned int &lep1_idx, const short unsigned int &lep2_idx, const ROOT::VecOps::RVec<float> &ptvec,  const ROOT::VecOps::RVec<float> &etavec,  const ROOT::VecOps::RVec<float> &phivec, const ROOT::VecOps::RVec<float> &massvec)
     {
       TLorentzVector lep1, lep2;

       lep1.SetPtEtaPhiM(ptvec[lep1_idx] / 1000., etavec[lep1_idx], phivec[lep1_idx], massvec[lep1_idx] / 1000.);
       lep2.SetPtEtaPhiM(ptvec[lep2_idx] / 1000., etavec[lep2_idx], phivec[lep2_idx], massvec[lep2_idx] / 1000.);

       float HTlep  = fabs(lep1.Pt() + lep2.Pt());
       if (divideByAThousand) HTlep /= 1000.;

       return HTlep;
     };
 }



inline auto SingleLepTrigMatch() 
{   return[](const bool isEle, const short unsigned int idx,  const unsigned int RunNumber,  const ROOT::VecOps::RVec<int> &HLT_mu20_iloose_L1MU15_match, const ROOT::VecOps::RVec<int> &HLT_mu26_ivarmedium_match, const ROOT::VecOps::RVec<int> &HLT_mu50_match, const ROOT::VecOps::RVec<int> &HLT_e24_lhmedium_L1EM20VH_match, const ROOT::VecOps::RVec<int> &HLT_e26_lhtight_nod0_ivarloose_match, const ROOT::VecOps::RVec<int> &HLT_e60_lhmedium_match, const ROOT::VecOps::RVec<int> &HLT_e60_lhmedium_nod0_match, const ROOT::VecOps::RVec<int> &HLT_e120_lhloose_match, const ROOT::VecOps::RVec<int> &HLT_e140_lhloose_nod0_match) 
    {
     bool trigMatch = false;
     if(isEle){
       if(RunNumber<296939){
         if (HLT_e24_lhmedium_L1EM20VH_match[idx] || HLT_e60_lhmedium_match[idx] || HLT_e120_lhloose_match[idx]) trigMatch = true; 
       }else{
         if (HLT_e26_lhtight_nod0_ivarloose_match[idx] || HLT_e60_lhmedium_nod0_match[idx] || HLT_e140_lhloose_nod0_match[idx]) trigMatch = true;
       }
     }else{
       if(RunNumber<296939){
         if (HLT_mu20_iloose_L1MU15_match[idx] || HLT_mu50_match[idx]) trigMatch = true;
       }else{
         if (HLT_mu26_ivarmedium_match[idx] || HLT_mu50_match[idx]) trigMatch = true;
       }
     }
     return trigMatch;
    };  
}

inline auto IFFNFakeLep()
{   return[](const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<int> &IFFTypelep)
    /*namespace IFF {
     enum class Type {
      0 -Unknown,
      1 -KnownUnknown,
      2 -IsoElectron,
      3 -ChargeFlipIsoElectron,
      4 -PromptMuon,
      5 -PromptPhotonConversion,
      6 -ElectronFromMuon,
      7 -TauDecay,
      8 -BHadronDecay,
      9 -CHadronDecay,
      10 -LightFlavorDecay,
     };
    }*/
    { int IFFNFakeLep = 0;
      for(unsigned int i=0;i<idxs.size();i++){
         if(IFFTypelep[idxs[i]] != 2 && IFFTypelep[idxs[i]] != 4) IFFNFakeLep+=1;
      }
      return IFFNFakeLep;
    };
}
inline auto GetMbl(const bool divideByAThousand = false)
{
    return [divideByAThousand](const short unsigned int lepid1, const short unsigned int lepid2, const ROOT::VecOps::RVec<float> &ptlep, const ROOT::VecOps::RVec<float> &etalep, const ROOT::VecOps::RVec<float> &philep, const ROOT::VecOps::RVec<float> &masslep, const short unsigned int jetid1, const short unsigned int jetid2, const ROOT::VecOps::RVec<float> &ptjet, const ROOT::VecOps::RVec<float> &etajet, const ROOT::VecOps::RVec<float> &phijet, const ROOT::VecOps::RVec<float> &massjet)
    {
        float mbl=-1;
        if(jetid1 != 100 && jetid2 != 100) {
            TLorentzVector lep1, lep2, jet1, jet2;
            lep1.SetPtEtaPhiM(ptlep[lepid1], etalep[lepid1], philep[lepid1], masslep[lepid1]);
            lep2.SetPtEtaPhiM(ptlep[lepid2], etalep[lepid2], philep[lepid2], masslep[lepid2]);
            jet1.SetPtEtaPhiM(ptjet[jetid1], etajet[jetid1], phijet[jetid1], massjet[jetid1]);
            jet2.SetPtEtaPhiM(ptjet[jetid2], etajet[jetid2], phijet[jetid2], massjet[jetid2]);
            float ml1j1 = (lep1 + jet1).M();
            float ml2j1 = (lep2 + jet1).M();
            float ml1j2 = (lep1 + jet2).M();
            float ml2j2 = (lep2 + jet2).M();
            mbl = std::min( std::max(ml1j1,ml2j2), std::max(ml1j2,ml2j1) );
	    if(divideByAThousand) mbl /= 1000.;
        }
        return mbl;
    };
}

inline auto FindNLeadingJets(const short unsigned int position, const bool divideByAThousand = false)
{
	return [position, divideByAThousand](const ROOT::VecOps::RVec<float> &vec, const std::vector<short unsigned int> &idxs)
	{
		if (idxs.size() > position) {
			if (divideByAThousand) return float(vec[idxs[position]] / 1000.);
			else return float(vec[idxs[position]]);
		}
		else return float(0.0);
	};
}

inline auto Get2lNj(const bool divideByAThousand = false, int njets = 0)
{
	// "lep1idx", "lep2idx", "jetIdxs", "ptleptons","ptjets", "EtMiss_tst"
	return [divideByAThousand,njets](const short unsigned int idx1, const short unsigned int idx2, const std::vector<short unsigned int> &idxs_jet , const ROOT::VecOps::RVec<float> &ptvec, const ROOT::VecOps::RVec<float> &ptvec_jet, const float MET_MEV)
	{
		float sumptjet4=0.;
		for (short unsigned int ijet = 0; ijet < idxs_jet.size(); ijet++) {
			short unsigned int id_jet = idxs_jet[ijet];
			sumptjet4 += ptvec_jet[id_jet];
			if (ijet == njets-1) break;
		}
		float twolfourj = ptvec[idx1] + ptvec[idx2] + sumptjet4 + MET_MEV;
		if(divideByAThousand) twolfourj /= 1000.;
		return twolfourj;
	};
}

inline auto GetMT(const bool divideByAThousand = false)
{
	return [divideByAThousand](const float part1pT, const float part2pT, const float dphi)
	{
		float mT = sqrt(2.*part1pT * part2pT * (1. - cos(dphi)));
		if (divideByAThousand) mT /= 1000.;
		return mT;
	};
}


inline auto GetHT(const bool divideByAThousand = false)
{
	return [divideByAThousand](const std::vector<short unsigned int> &idxs, const ROOT::VecOps::RVec<float> &ptvec)
	{

		float HT = 0.;
		for (short unsigned int ijet = 0; ijet < idxs.size(); ijet++) {
			int id_jet = idxs[ijet];
			HT += ptvec[id_jet];
		}
		if (divideByAThousand) HT /= 1000.;
		return HT;
	};
}

inline auto FindJets(const float &ptcut)
{
	return [ptcut](const ROOT::VecOps::RVec<float> &ptjets, const ROOT::VecOps::RVec<float> &etajets, const ROOT::VecOps::RVec<bool> &passORjet )
	{

		std::vector<std::pair<float, short unsigned int>> the_jets;

		for (short unsigned int ijet = 0; ijet < ptjets.size(); ijet++) {

			double ptjet   = ptjets[ijet];
			double etajet  = std::fabs(etajets[ijet]);

			if ( ptjet < ptcut ) continue;
			if ( etajet > 2.5 ) continue;
			if ( passORjet[ijet] == false ) continue;
			//std::cout << "passOR after check " << passORjet[ijet] << std::endl;

			std::pair<float, short unsigned int> new_jet = std::make_pair(ptjet, ijet);
			the_jets.push_back(new_jet);

		}

		sort(the_jets.rbegin(), the_jets.rend());

		std::vector<short unsigned int> the_sorted_jets;
		for (short unsigned int ijet = 0; ijet < the_jets.size(); ijet++) {
			//std::cout << "passOR in sort jets " << passORjet[the_jets[ijet].second] << std::endl;

			the_sorted_jets.push_back(the_jets[ijet].second);

		}

		return the_sorted_jets;
	};
}

inline auto FindBJets(const float &ptcut) //USE ONLY IF YOU USE PseudoContinuos Btagging
{
	return [ptcut](const ROOT::VecOps::RVec<float> &ptjets, const ROOT::VecOps::RVec<float> &etajets, const ROOT::VecOps::RVec<bool> &passORjet, const ROOT::VecOps::RVec<int> &isBjet )
	{

		std::vector<std::pair<float, short unsigned int>> the_jets;

		for (short unsigned int ijet = 0; ijet < ptjets.size(); ijet++) {

			double ptjet   = ptjets[ijet];
			double etajet  = std::fabs(etajets[ijet]);

			if ( ptjet > ptcut && etajet < 2.5 ) {

				if (passORjet[ijet] == false) continue;
				if (isBjet[ijet] <= 2) continue;

				std::pair<float, short unsigned int> new_jet = std::make_pair(ptjet, ijet);
				the_jets.push_back(new_jet);

			}

		}

		sort(the_jets.rbegin(), the_jets.rend());

		std::vector<short unsigned int> the_sorted_jets;
		for (short unsigned int ijet = 0; ijet < the_jets.size(); ijet++) {

			the_sorted_jets.push_back(the_jets[ijet].second);

		}

		return the_sorted_jets;
	};
}

inline auto FindTrueBJets(const float &ptcut) //USE ONLY IF YOU USE PseudoContinuos Btagging
{
	return [ptcut](const ROOT::VecOps::RVec<float> &ptjets, const ROOT::VecOps::RVec<float> &etajets, const ROOT::VecOps::RVec<bool> &passORjet, const ROOT::VecOps::RVec<int> &labeljets_reco )
	{

		std::vector<std::pair<float, short unsigned int>> the_jets;

		for (short unsigned int ijet = 0; ijet < ptjets.size(); ijet++) {

			double ptjet   = ptjets[ijet];
			double etajet  = std::fabs(etajets[ijet]);

			if ( ptjet > ptcut && etajet < 2.5 ) {

				if (passORjet[ijet] == false) continue;
				if (labeljets_reco[ijet] != 5) continue;

				std::pair<float, short unsigned int> new_jet = std::make_pair(ptjet, ijet);
				the_jets.push_back(new_jet);

			}

		}

		sort(the_jets.rbegin(), the_jets.rend());

		std::vector<short unsigned int> the_sorted_jets;
		for (short unsigned int ijet = 0; ijet < the_jets.size(); ijet++) {

			the_sorted_jets.push_back(the_jets[ijet].second);

		}

		return the_sorted_jets;
	};
}

inline auto FindBJetsFixedEff(const float &ptcut) //USE ONLY IF YOU ARE NOT USING PseudoContinuos Btagging
{
	return [ptcut](const ROOT::VecOps::RVec<float> &ptjets, const ROOT::VecOps::RVec<float> &etajets, const ROOT::VecOps::RVec<bool> &passORjet, const ROOT::VecOps::RVec<int> &isBjet )
	{

		std::vector<std::pair<float, short unsigned int>> the_jets;

		for (short unsigned int ijet = 0; ijet < ptjets.size(); ijet++) {

			double ptjet   = ptjets[ijet];
			double etajet  = std::fabs(etajets[ijet]);

			if ( ptjet > ptcut && etajet < 2.5 ) {

				if (passORjet[ijet] == false) continue;
				if (isBjet[ijet] == 0) continue;

				std::pair<float, short unsigned int> new_jet = std::make_pair(ptjet, ijet);
				the_jets.push_back(new_jet);

			}

		}

		sort(the_jets.rbegin(), the_jets.rend());

		std::vector<short unsigned int> the_sorted_jets;
		for (short unsigned int ijet = 0; ijet < the_jets.size(); ijet++) {

			the_sorted_jets.push_back(the_jets[ijet].second);

		}

		return the_sorted_jets;
	};
}

inline auto DefineSignal0()
{
	return [](const ROOT::VecOps::RVec<bool> &isMediumlep )
	{

		std::vector<bool> isSignal;

		for (short unsigned int ilep = 0; ilep < isMediumlep.size(); ilep++) {
			if(isMediumlep[ilep]) isSignal.push_back(true);
			else isSignal.push_back(false);
		}

		return isSignal;
	};
}

inline auto DefineSignal1()
{
	return [](const ROOT::VecOps::RVec<bool> &isMediumlep, const ROOT::VecOps::RVec<float> &ptvarcone30_tightTTVAleptons, const ROOT::VecOps::RVec<float> &ptleptons )
	{

		std::vector<bool> isSignal;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++) {
			if(isMediumlep[ilep] && (ptvarcone30_tightTTVAleptons[ilep]/ptleptons[ilep]<0.06)) isSignal.push_back(true);
			else isSignal.push_back(false);
		}

		return isSignal;
	};
}

inline auto DefineSignal2()
{
	return [](const ROOT::VecOps::RVec<bool> &isMediumlep, std::vector<int> &flavleptons, std::vector<float> &ptvarcone30_tightTTVAleptons, const ROOT::VecOps::RVec<float> &topoetcone20leptons, const ROOT::VecOps::RVec<float> &ptleptons )
	{

		std::vector<bool> isSignal;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++) {
			if(fabs(flavleptons[ilep]) == 11) {
				if(isMediumlep[ilep] && (topoetcone20leptons[ilep] < ptleptons[ilep] * 0.015 || topoetcone20leptons[ilep] < 3500)) isSignal.push_back(true);
				else isSignal.push_back(false);
			}
			else {
				if(ptvarcone30_tightTTVAleptons[ilep]/ptleptons[ilep]<0.06) isSignal.push_back(true);
				else isSignal.push_back(false);
			}
		}

		return isSignal;
	};
}

inline auto DefineSignal3()
{
	return [](const ROOT::VecOps::RVec<bool> &isMediumlep, std::vector<int> &flavleptons, const ROOT::VecOps::RVec<bool> &LepIsoFixedCutTight, const ROOT::VecOps::RVec<bool> &LepIsoFixedCutTightTrackOnly, const ROOT::VecOps::RVec<float> &ptleptons, const ROOT::VecOps::RVec<float> &d0sig, const ROOT::VecOps::RVec<float> &z0sinTheta )
	{

		std::vector<bool> isSignal;

		for (short unsigned int ilep = 0; ilep < ptleptons.size(); ilep++) {
			if(fabs(flavleptons[ilep]) == 11) {
				if(isMediumlep[ilep] && LepIsoFixedCutTight[ilep] && fabs(d0sig[ilep]) < 5 && fabs(z0sinTheta[ilep]) < 0.5) isSignal.push_back(true);
				else isSignal.push_back(false);
			}
			else {
				if(LepIsoFixedCutTightTrackOnly[ilep] && fabs(d0sig[ilep]) < 3 && fabs(z0sinTheta[ilep]) < 0.5) isSignal.push_back(true);
				else isSignal.push_back(false);
			}
		}

		return isSignal;
	};
}

}

#endif
