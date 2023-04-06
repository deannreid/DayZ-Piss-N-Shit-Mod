/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: Bowel.c
 *  
 * Class Information:
 *
 * Class handles Bowel stuff
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 05/12/2022 - Initial Code Development
 */

class BowelMdfr: ModifierBase
{
	float m_LastBowelLevel;
	ref HumanMovementState m_MovementState = new HumanMovementState();
	
	override void Init()
	{
		//GetPNSLogger().WriteDebug("Init Bowel Modifier");
		Print("[PNS - LogHandler] :: [DEBUG] :: (Init Bowel Modifier");
		m_TrackActivatedTime = false;
		m_ID = eModifiersPNS.MDF_BOWEL;
		m_TickIntervalActive = 1;
		DisableDeactivateCheck();	
	}

	override bool ActivateCondition(PlayerBase player){
		return true;
	}
	
	override void OnReconnect(PlayerBase player){
	}
	
	override bool DeactivateCondition(PlayerBase player){
		return false;
	}
		
	override void OnTick(PlayerBase player, float deltaT)
	{
		//super.OnTick(player, deltaT);
		player.GetMovementState(m_MovementState);
		float bowel = player.GetStatBowel().Get();
		Print("[PNS :: DEBUG] -- PlayerModifier [BOWEL] : Bowel Current State:" + bowel);
		float metabolic_speed = MiscGameplayFunctions.GetBowelMetabolicSpeed(m_MovementState.m_iMovement);
		
		float modifier = bowel*PlayerConstants.SL_BOWEL_MAX + PlayerConstants.CONSUMPTION_MULTIPLIER_BASE;
		metabolic_speed *= modifier; //non linear shaping for consumption curve (comment out to have it linear)
		Print("[PNS :: DEBUG] -- PlayerModifier [BOWEL] : metabolic_speed Current State:" + metabolic_speed);
		
		player.GetStatBowel().Add( (-metabolic_speed * deltaT) );
		Print("[PNS :: DEBUG] -- PlayerModifier [BOWEL] : GetStatBowel() Current State:" + -metabolic_speed * deltaT);
		
		if ( bowel >= PlayerConstants.HIGH_BOWEL_THRESHOLD )
		{	
			if( !player.GetStomach().IsDigesting() )	
				player.AddHealth("GlobalHealth", "Health", -PlayerConstants.HIGH_BOWEL_DAMAGE_PER_SEC * deltaT );
			Print("[PNS :: DEBUG] -- PlayerModifier [BOWEL] : player.AddHealth() Current State:" + -PlayerConstants.HIGH_BOWEL_DAMAGE_PER_SEC * deltaT);
		}	
	}
}