#include "SpectrumGUI.h"

CInif::CInif(){}

void CInif::ParsePath(String FileName){
	//PathIni Pathini_ob;
	
	VectorMap<String, String> cfg = LoadIniFile(FileName);
	/*
	Pathini_ob.ValIp = cfg.Get("IP", Null);
	Pathini_ob.ValPort = ScanInt(cfg.Get("PORT", Null));
	Pathini_ob.ValAve = ScanInt(cfg.Get("VALAVE", Null));
	Pathini_ob.ValHigh = ScanInt(cfg.Get("VALHIGH", Null));
	Pathini_ob.ValPower = ScanInt(cfg.Get("VALPOWER", Null));
	Pathini_ob.ValPass = cfg.Get("PASSWORD", Null);
	Pathini_ob.Version = StrDbl(cfg.Get("VERSION", Null));
	Pathini_ob.PathSound = cfg.Get("PATHSOUND", Null);
	*/
	
	ValIp = cfg.Get("IP", Null);
	ValPort = ScanInt(cfg.Get("PORT", Null));
	ValAve = ScanInt(cfg.Get("VALAVE", Null));
	ValHigh = ScanInt(cfg.Get("VALHIGH", Null));
	ValPower = ScanInt(cfg.Get("VALPOWER", Null));
	ValPowerMin = ScanInt(cfg.Get("VALPOWERMIN", Null));
	ValPass = cfg.Get("PASSWORD", Null);
	PathSound = cfg.Get("PATHSOUND", Null);

	return;
}

uint64_t constexpr mix(char m, uint64_t s){
  return ((s<<7) + ~(s>>3)) + ~m;
}
 
uint64_t constexpr hash(const char * m){
  return (*m) ? mix(*m,hash(m+1)) : 0;
}

void CInif::SaveINIFile(String FileName, String insVal, String Value){
	cfg = LoadIniFile(FileName);
	String ini = "";
	for(int i = 0; i < cfg.GetCount(); i++){
		if (cfg.GetKey(i) == insVal){
			ini << cfg.GetKey(i) <<"=" << Value << "\n";
		}
		else{
			ini << cfg.GetKey(i) <<"=" << cfg[i] << "\n";
		}
	}
	Cerr() << ini <<"=\n";
	
	if( !SaveFile(FileName, ini) ) {
		Cerr() << "Error saving configuration!";
	}
}
