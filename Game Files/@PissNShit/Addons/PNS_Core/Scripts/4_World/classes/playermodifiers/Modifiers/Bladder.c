/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: Bladder.c
 *  
 * Class Information:
 *
 * Class handles bladder modifiers
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 05/12/2022 - Initial Code Development
 */

class BladderMdfr: ModifierBase
{

	float m_LastBladderLevel;
	
	ref HumanMovementState m_MovementState = new HumanMovementState();
	
	override void Init()
	{
		//GetPNSLogger().WriteDebug("Init Bladder Modifier");
		Print("[PNS - LogHandler] :: [DEBUG] :: (Init Bladder Modifier");
		m_TrackActivatedTime = false;
		m_ID = eModifiersPNS.MDF_BLADDER;
		m_TickIntervalActive = 1;
		DisableDeactivateCheck();
	}
	
	override bool ActivateCondition(PlayerBase player){return true;}
	override void OnReconnect(PlayerBase player){}
	override bool DeactivateCondition(PlayerBase player){return false;}
	
	
	override void OnTick(PlayerBase player, float deltaT)
	{
		player.GetMovementState(m_MovementState);
		float urine = player.GetStatBladder().Get();
		float metabolic_speed = MiscGameplayFunctions.GetBladderMetabolicSpeed(m_MovementState.m_iMovement);	
		
		float modifier = urine/PlayerConstants.SL_BLADDER_MAX + PlayerConstants.CONSUMPTION_MULTIPLIER_BASE;
		metabolic_speed *= modifier; //non linear shaping for consumption curve (comment out to have it linear)
		
		player.GetStatBladder().Add( (-metabolic_speed * deltaT) );
		
		if ( urine >= PlayerConstants.HIGH_BLADDER_THRESHOLD )
		{	
			if( !player.GetStomach().IsDigesting() )	
				// Will Lower health by set amount if the player doesn't pee 
				player.AddHealth("GlobalHealth", "Health", -PlayerConstants.HIGH_BLADDER_DAMAGE_PER_SEC * deltaT );
		}
	}
}