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

modded class PlayerBase extends ManBase
{
    private float m_BladderLevel;  // Urination level is between 0 and 10, where 0 means the player doesn't need to urinate and 1 means they urgently need to urinate
    private float m_BowelLevel;  // Poop level is between 0 and 10, where 0 means the player doesn't need to urinate and 1 means they urgently need to urinate
	protected PlayerStat<float> m_StatBladder;
	protected PlayerStat<float> m_StatBowel;
	

	EStatLevels GetStatLevelBladder() {
		float bladder = GetStatBladder().Get();
		return GetStatLevel(bladder, PlayerConstants.SL_BLADDER_CRITICAL, PlayerConstants.SL_BLADDER_LOW, PlayerConstants.SL_BLADDER_NORMAL, PlayerConstants.SL_BLADDER_HIGH);
		Print("[PNS :: DEBUG] -- PlayerBase [BLADDER] : GetStatLevelBladder Current State:" +bladder);
	}

	EStatLevels GetStatLevelBowel() {
		float bowel = GetStatBowel().Get();
		return GetStatLevel(bowel, PlayerConstants.SL_BOWEL_CRITICAL, PlayerConstants.SL_BOWEL_LOW, PlayerConstants.SL_BOWEL_NORMAL, PlayerConstants.SL_BOWEL_HIGH);
		Print("[PNS :: DEBUG] -- PlayerBase [BLADDER] : GetStatLevelBowel Current State:" +bowel);
	}

	float GetStatBordersBladder()
	{
		float bladder 		= GetStatBladder().Get();
		float bladder_max 	= GetStatBladder().GetMax();
		return GetStatLevelBorders(bladder, PlayerConstants.SL_BLADDER_CRITICAL, PlayerConstants.SL_BLADDER_LOW, PlayerConstants.SL_BLADDER_NORMAL, PlayerConstants.SL_BLADDER_HIGH, bladder_max);
	}	

	float GetStatBordersBowel()
	{
		float bowel 	= GetStatBowel().Get();
		float bowel_max = GetStatBowel().GetMax();
		return GetStatLevelBorders(bowel, PlayerConstants.SL_BOWEL_CRITICAL, PlayerConstants.SL_BOWEL_LOW, PlayerConstants.SL_BOWEL_NORMAL, PlayerConstants.SL_BOWEL_HIGH, bowel_max);
	}	
	
	PlayerStat<float> GetStatBladder() {
		if( !m_StatBladder && GetPlayerStats()) {
			m_StatBladder = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_PNSMod.BLADDER));
			//m_StatBladder = "2500";
		}
		return m_StatBladder;
		Print("[PNS :: DEBUG] -- PlayerBase [BLADDER] : GetStatBladder Current State:" + m_StatBladder);
	}
	
	PlayerStat<float> GetStatBowel() {
		if( !m_StatBowel && GetPlayerStats()) {
			m_StatBowel = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_PNSMod.BOWEL));
			//m_StatBowel = "2500";
		}
		return m_StatBowel;
		Print("[PNS :: DEBUG] -- PlayerBase [BLADDER] : GetStatBowel Current State:" + m_StatBowel);
	}		
}