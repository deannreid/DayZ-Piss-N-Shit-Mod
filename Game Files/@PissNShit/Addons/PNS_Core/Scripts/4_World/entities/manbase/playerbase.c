/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: playerbase.c
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

modded class PlayerBase {

	protected PlayerStat<float> m_StatUrine;
	protected PlayerStat<float> m_StatRectum;
	

	
	PlayerStat<float> GetStatUrine()
	{
		if( !m_StatUrine && GetPlayerStats())
		{
			m_StatUrine = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_PNSMod.URINE));
		}
		return m_StatUrine;
	}
	
	PlayerStat<float> GetStatRectum()
	{
		if( !m_StatRectum && GetPlayerStats())
		{
			m_StatRectum = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_PNSMod.RECTUM));
		}
		return m_StatRectum;
	}
}