/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: DayZGame.c
 *  
 * Class Information:
 *
 * Class handles Config stuff
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 15/03/2023 - Initial Code Development
 */

modded class DayZGame {
	
	protected ref PNSConfig pnsConfig;
	
    void SetPNSConfig(PNSConfig config) {
        pnsConfig = config;
		Print("SetPNSConfig: " + config );
    }
	
	ref PNSConfig GetPNSConfig() {
        return pnsConfig;
		Print("GetPNSConfig: " + pnsConfig );
    }	
}