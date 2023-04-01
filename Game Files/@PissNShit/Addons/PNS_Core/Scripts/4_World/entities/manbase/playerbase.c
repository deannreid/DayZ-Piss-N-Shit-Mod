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
		
    void PlayerBase() {
        /* 
		 * Level to Increase by 1 every 10 Minutes
		 * or increase by 1 when player drinks a full container of liquid
		 */
    }

	PlayerStat<float> GetStatBladder() {
		if( !m_StatBladder && GetPlayerStats())
		{
			m_StatBladder = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_PNSMod.BLADDER));
		}
		return m_StatBladder;
	}
	
	PlayerStat<float> GetStatBowel() {
		if( !m_StatBowel && GetPlayerStats())
		{
			m_StatBowel = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_PNSMod.BOWEL));
		}
		return m_StatBowel;
	}	

	EStatLevels GetStatLevelBladder()
	{
		float bladder = GetStatBladder().Get();
		return GetStatLevel(bladder, PlayerConstants.SL_BLADDER_CRITICAL, PlayerConstants.SL_BLADDER_LOW, PlayerConstants.SL_BLADDER_NORMAL, PlayerConstants.SL_BLADDER_HIGH);
	}

	EStatLevels GetStatLevelBowel()
	{
		float bowel = GetStatBowel().Get();
		return GetStatLevel(bowel, PlayerConstants.SL_BOWEL_CRITICAL, PlayerConstants.SL_BOWEL_LOW, PlayerConstants.SL_BOWEL_NORMAL, PlayerConstants.SL_BOWEL_HIGH);
	}
}