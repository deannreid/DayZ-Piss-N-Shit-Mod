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
		RegisterPCO(new PlayerStatsPCO_v100);
		RegisterPCO(new PlayerStatsPCO_v101);
		RegisterPCO(new PlayerStatsPCO_current);
		RegisterPCO(new PlayerStatsPCO_PNSMod);
		
		//GetPNSLogger().WriteDebug("Registered Player Stats" + PlayerStatsPCO_PNSMOD);
	}
};
	enum EPlayerStats_PNSMod
	{
		BLADDER,
		BOWEL
	}

//class PlayerStatsPCO_PNSMod extends PlayerStatsPCO_Base {
class PlayerStatsPCO_PNSMod extends PlayerStatsPCO_Base
{	
	override void Init()
	{	
		super.Init();
		RegisterStat(	EPlayerStats_PNSMod.BLADDER, 		new PlayerStat<float> 	(0,5000,500,"Bladder", EPSstatsFlags.EMPTY)	);
		Print("[PNS - PlayerStats] :: STAT: Bladder," + EPlayerStats_PNSMod.BLADDER + " Registered");
		RegisterStat(	EPlayerStats_PNSMod.BOWEL, 			new PlayerStat<float>  	(0,20000,600,"Bowel" , EPSstatsFlags.EMPTY)	);
		Print("[PNS - PlayerStats] :: STAT: Bowel," + EPlayerStats_PNSMod.BOWEL   + " Registered");
		
		
		//RegisterStat(EPlayerStats_v100.ENERGY,  			new PlayerStat<float>	(0,20000,600,"Energy",EPSstatsFlags.EMPTY) );
		//RegisterStat(EPlayerStats_v100.WATER,  			    new PlayerStat<float>	(0,5000,500,"Water",EPSstatsFlags.EMPTY) );
	}
}