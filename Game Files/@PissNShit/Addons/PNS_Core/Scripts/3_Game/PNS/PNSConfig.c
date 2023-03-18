/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: playerconstants.c
 *  
 * Class Information:
 *
 * Class handles Player Constants
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 15/03/2023 - Initial Code Development
 */

class PNSConfig {
/*
 * Game Booleans
 */
	
	private string PNS_RequireToiletRoll;
	private string PNS_AttractZombies;
/*
 * Game Integers
 */	
	private int PNS_SicknessChance; //In Percentage
	private int PNS_AttractWolvesChance; // If 0 then No wolves will come. 
	private int PNS_PoopDropChance; // if 0 then no shit will drop.
	private int PNS_FartIllnessChange; // If 0 then you won't get ill from farting. 
	private int PermissionReloadTime;
	
/*
 * Server Booleans
 */	
	private string PNS_EnableLogging; // Enable Server Logging
	
	void PNSConfig() {
	
		private static ref PNSConfig pnsConfig = NULL;
		
		PNS_RequireToiletRoll = "true";
		PNS_AttractZombies = "true";
		
		PNS_SicknessChance = 20;
		PNS_AttractWolvesChance = 20;
		PNS_PoopDropChance = 40;
		PNS_FartIllnessChange = 50;
		
		PNS_EnableLogging = "true";
	}
	
	float GetConfigReloadTime() {
        return PermissionReloadTime;
    }

	bool PNS_RequireToiletRoll() {
	    string pnsString = PNS_RequireToiletRoll;
        pnsString.ToLower();

        return pnsString == "true";
	}	
	bool PNS_AttractZombies() {
	    string pnsString = PNS_AttractZombies;
        pnsString.ToLower();

        return pnsString == "true";
	}	
	bool PNS_EnableLogging() {
	    string pnsString = PNS_EnableLogging;
        pnsString.ToLower();

        return pnsString == "true";
	}	
	int PNS_SicknessChance() {
        return PNS_SicknessChance;
    }
	int PNS_AttractWolvesChance() {
        return PNS_AttractWolvesChance;
    }
	int PNS_PoopDropChance() {
        return PNS_PoopDropChance;
    }
	int PNS_FartIllnessChange() {
        return PNS_FartIllnessChange;
    }
	
	void ValidateOptions() {
		Print("[PNS - ConfigManager] :: Validating Configuration Entries");
		if (PNS_RequireToiletRoll == string.Empty){
	            PNS_RequireToiletRoll = "true";
				Print("[PNSConfig] :: String {{PNS_RequireToiletRoll}} is empty!!! | Setting it to Default " + PNS_RequireToiletRoll);
	    }
		if (PNS_AttractZombies == string.Empty) {
	            PNS_AttractZombies = "true";
				Print("[PNSConfig] :: String {{PNS_AttractZombies}} is empty!!! | Setting it to Default " + PNS_AttractZombies);
	    }
		if (PNS_EnableLogging == string.Empty) {
	            PNS_EnableLogging = "true";
				Print("[PNSConfig] :: String {{PNS_EnableLogging}} is empty!!! | Setting it to Default " + PNS_EnableLogging);
	    }				
		if (PNS_SicknessChance < 0) {
			PNS_SicknessChance = 20;
			Print("[PNSConfig] :: The entry {{PNS_SicknessChance}} is not configured correctly!!! | Setting it to Default:" + PNS_SicknessChance);

        }		
		if (PNS_AttractWolvesChance < 0) {
			PNS_AttractWolvesChance = 20;
			Print("[PNSConfig] :: The entry {{PNS_AttractWolvesChance}} is not configured correctly!!! | Setting it to Default:" + PNS_AttractWolvesChance);

        }
		if (PNS_PoopDropChance < 0) {
			PNS_PoopDropChance = 40;
			Print("[PNSConfig] :: The entry {{PNS_PoopDropChance}} is not configured correctly!!! | Setting it to Default:" + PNS_PoopDropChance);

        }	
		if (PNS_FartIllnessChange < 0) {
			PNS_FartIllnessChange = 50;
			Print("[PNSConfig] :: The entry {{PNS_FartIllnessChange}} is not configured correctly!!! | Setting it to Default:" + PNS_FartIllnessChange);
        }		
		Print("[PNS - ConfigManager] :: Validated Configuration Entries");	
	}	
}