/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: playerconstants.c
 *  
 * Class Information:
 *
 * Class handles Player Constants
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 05/12/2022 - Initial Code Development
 */

modded class PlayerConstants 
{
	//----------------------------------------------------------
	//					STAT LEVELS START
	//----------------------------------------------------------
	
	static const float SL_BLADDER_CRITICAL = 0;
	static const float SL_BLADDER_LOW = 300;
	static const float SL_BLADDER_NORMAL = 800;
	static const float SL_BLADDER_HIGH = 3500;
	static const float SL_BLADDER_MAX = 5000;
	
	static const float SL_BOWEL_CRITICAL = 0;
	static const float SL_BOWEL_LOW = 300;
	static const float SL_BOWEL_NORMAL = 800;
	static const float SL_BOWEL_HIGH = 3500;
	static const float SL_BOWEL_MAX = 5000;
	
	//--------------------------------------------------------
	
	static const float BLADDER_LOSS_HC_PLUS_LOW			= 0;
	static const float BLADDER_LOSS_HC_PLUS_HIGH		= 0.4;
		
	static const float BOWEL_LOSS_HC_PLUS_LOW			= 0;
	static const float BOWEL_LOSS_HC_PLUS_HIGH			= 0.4;
	
	//--------------------------------------------------------
	static const float METABOLIC_SPEED_BLADDER_BASAL	= 0.01;		//BLADDER Increase per second while idle
	
	static const float METABOLIC_SPEED_BLADDER_WALK		= 0.1;		//BLADDER Increase per second
	static const float METABOLIC_SPEED_BLADDER_JOG		= 0.3;		//BLADDER Increase per second
	static const float METABOLIC_SPEED_BLADDER_SPRINT	= 0.6;		//BLADDER Increase per second
	//########################################################################################################\\
	static const float METABOLIC_SPEED_BOWEL_BASAL		= 0.01;		//BOWEL Increase per second while idle
	
	static const float METABOLIC_SPEED_BOWEL_WALK		= 0.1;		//BOWEL Increase per second
	static const float METABOLIC_SPEED_BOWEL_JOG		= 0.3;		//BOWEL Increase per second
	static const float METABOLIC_SPEED_BOWEL_SPRINT		= 0.6;		//BOWEL Increase per second
	
	
	static const float HIGH_BLADDER_THRESHOLD			= SL_BLADDER_HIGH;    //High Threshold BLADDER threshold from which BLADDER affects health
	static const float HIGH_BOWEL_THRESHOLD			 		= SL_BOWEL_HIGH;   // High Threshold BOWEL threshold from which BOWEL affects health	

	static const float HIGH_BLADDER_DAMAGE_PER_SEC			= 5; // Damage per second to player when they don't urinate
	static const float HIGH_BOWEL_DAMAGE_PER_SEC			= 5; // Damage per second to player when they don't poop
}