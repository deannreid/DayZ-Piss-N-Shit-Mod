/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: playerstatspco.c
 *  
 * Class Information:
 *
 * Class handles Player Stats for Urine and Poo
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 05/12/2022 - Initial Code Development
 */

modded class PCOHandlerStats {

	ref map<int, ref PlayerStatsPCO_Base> m_PCOs = new map<int, ref PlayerStatsPCO_Base>;
	
	void PCOHandlerStats()
	{
		RegisterPCO(new PlayerStatsPCO_PNSMod);
		//GetPNSLogger().WriteDebug("Registered Player Stats" + PlayerStatsPCO_PNSMOD);
		
	}
};
	enum EPlayerStats_PNSMod
	{
		BLADDER,
		BOWEL
	}

class PlayerStatsPCO_PNSMod extends PlayerStatsPCO_Base {

	override void Init()
	{	
		RegisterStat(	EPlayerStats_PNSMod.BLADDER, 		new PlayerStat<float> 	(0,5000,500,"Urine", EPSstatsFlags.EMPTY)	);
		Print("[PNS - PlayerStats] :: STAT: " + EPlayerStats_PNSMod.BLADDER + " Registered");
		RegisterStat(	EPlayerStats_PNSMod.BOWEL, 			new PlayerStat<float>  	(0,5000,500,"Poop" , EPSstatsFlags.EMPTY)	);
		Print("[PNS - PlayerStats] :: STAT: " + EPlayerStats_PNSMod.BOWEL   + " Registered");
	}
}