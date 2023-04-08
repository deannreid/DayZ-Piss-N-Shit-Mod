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
class BladderMdfr: ModifierBase {
	
	//protected float	m_EnergyDelta;
	protected float				m_LastBladderLevel;
	ref HumanMovementState		m_MovementState	= new HumanMovementState();
		
	override void Init() {
		Print("[PNS - LogHandler] :: [DEBUG] :: (Init Bladder Modifier)");
		
		m_TrackActivatedTime 	= false;
		m_ID 					= eModifiersPNS.MDF_BLADDER;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
		DisableDeactivateCheck();
	}
	
	override bool ActivateCondition(PlayerBase player){return true;}
	override void OnReconnect(PlayerBase player){}
	override bool DeactivateCondition(PlayerBase player){return false;}

	override void OnTick(PlayerBase player, float deltaT) {
		player.GetMovementState(m_MovementState);
		
		float bladder 			= player.GetStatBladder().Get();
			Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : Bladder Current State:" + bladder);
		
		float metabolic_speed 	= MiscGameplayFunctions.GetBladderMetabolicSpeed(m_MovementState.m_iMovement);
			Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : metabolic_speed Current State:" + metabolic_speed);
		
		float modifier 			= bladder/PlayerConstants.SL_BLADDER_MAX + PlayerConstants.CONSUMPTION_MULTIPLIER_BASE; 
		metabolic_speed 	   *= modifier; //non linear shaping for consumption curve (comment out to have it linear)
			Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : GetStatBladder() Current State:" + -metabolic_speed * deltaT);
			Print("==============================");
		
		player.GetStatEnergy().Add( -metabolic_speed * deltaT );
		
		if ( bladder >= PlayerConstants.HIGH_BLADDER_THRESHOLD )
		{
			//player.SetMixedSoundState( eMixedSoundStates.HUNGRY );
			if( !player.GetStomach().IsDigesting() )	
				player.AddHealth("GlobalHealth", "Health", -PlayerConstants.HIGH_BLADDER_DAMAGE_PER_SEC * deltaT );
					Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : player.AddHealth() Current State:" + -PlayerConstants.HIGH_BLADDER_DAMAGE_PER_SEC * deltaT);
		}
				Print("==============================");
	}
};
/*
	override void OnTick(PlayerBase player, float deltaT)
	{
		//super.OnTick(player, deltaT);
		player.GetMovementState(m_MovementState);
		float bladder = player.GetStatBladder().Get();
		Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : Bladder Current State:" + bladder);
		float metabolic_speed = MiscGameplayFunctions.GetBladderMetabolicSpeed(m_MovementState.m_iMovement);
		float modifier = bladder*PlayerConstants.SL_BLADDER_MAX + PlayerConstants.CONSUMPTION_MULTIPLIER_BASE;
		metabolic_speed *= modifier; //non linear shaping for consumption curve (comment out to have it linear)
		Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : metabolic_speed Current State:" + metabolic_speed);
		player.GetStatBladder().Add( (-metabolic_speed * deltaT) );
		Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : GetStatBladder() Current State:" + -metabolic_speed * deltaT);
		
		if ( bladder >= PlayerConstants.HIGH_BLADDER_THRESHOLD )
		{	
			if( !player.GetStomach().IsDigesting() )	
				player.AddHealth("GlobalHealth", "Health", -PlayerConstants.HIGH_BLADDER_DAMAGE_PER_SEC * deltaT );
			Print("[PNS :: DEBUG] -- PlayerModifier [BLADDER] : player.AddHealth() Current State:" + -PlayerConstants.HIGH_BLADDER_DAMAGE_PER_SEC * deltaT);
		}	
		Print("==============================");
	}	
}*/