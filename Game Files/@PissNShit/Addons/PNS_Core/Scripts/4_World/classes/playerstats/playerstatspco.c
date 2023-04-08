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

	void PCOHandlerStats() {
		RegisterPCO(new PlayerStatsPCO_PNSMod);	
		//RegisterPCO(new PlayerStatsPCO_current);
		//GetPNSLogger().WriteDebug("Registered Player Stats" + PlayerStatsPCO_PNSMOD);
	}
};

enum EPlayerStats_PNSMod {
	BLADDER,
	BOWEL
}

//modded class PlayerStatsPCO_current extends PlayerStatsPCO_v115 { 
class PlayerStatsPCO_PNSMod extends PlayerStatsPCO_Base {

	override void Init() {	
		super.Init();
		// ==                                                                        Min, Max, Value,   Label,              Flag
		RegisterStat(	EPlayerStats_PNSMod.BLADDER, 		new PlayerStat<float> 	( 0,  5000,   700,    "Bladder"   , EPSstatsFlags.EMPTY)	);
		Print("[PNS - PlayerStats] :: STAT: Bladder," + EPlayerStats_PNSMod.BLADDER + " Registered");
		RegisterStat(	EPlayerStats_PNSMod.BOWEL, 			new PlayerStat<float>  	( 0,  5000,   700,    "Bowel"     , EPSstatsFlags.EMPTY)	);
		Print("[PNS - PlayerStats] :: STAT: Bowel," + EPlayerStats_PNSMod.BOWEL   + " Registered");
		
		
		//RegisterStat(EPlayerStats_v100.ENERGY,  			new PlayerStat<float>	(0,20000,600,"Energy",EPSstatsFlags.EMPTY) );
		//RegisterStat(EPlayerStats_v100.WATER,  			    new PlayerStat<float>	(0,5000,500,"Water",EPSstatsFlags.EMPTY) );
	}
}