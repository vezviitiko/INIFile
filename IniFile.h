#ifndef _SpectrumGUI_IniFile_h_
#define _SpectrumGUI_IniFile_h_

using namespace Upp;

class CInif {
	public:
		CInif();
		//void LoadConfig();
		//void StoreConfig();
		
		void ParsePath(String FileName);
		String ValIp;
		int ValPort;
		int ValAve;
		int ValHigh;
		int ValPower;
		int ValPowerMin;
		String ValPass;
		String PathSound;
		
		void SaveINIFile(String FileName, String insVal, String Value);
		VectorMap<String, String> cfg;
};

#endif
