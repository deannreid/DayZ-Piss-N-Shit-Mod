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

modded class PlayerConstants {
	//----------------------------------------------------------
	//					STAT LEVELS START
	//----------------------------------------------------------
	
	static const float SL_BLADDER_CRITICAL 					= 0;
	static const float SL_BLADDER_LOW 						= 300;
	static const float SL_BLADDER_NORMAL 					= 800;
	static const float SL_BLADDER_HIGH 						= 3500;
	static const float SL_BLADDER_MAX 						= 5000;
	
	static const float SL_BOWEL_CRITICAL 					= 0;
	static const float SL_BOWEL_LOW 						= 300;
	static const float SL_BOWEL_NORMAL 						= 800;
	static const float SL_BOWEL_HIGH 						= 3500;
	static const float SL_BOWEL_MAX 						= 5000;

	//----------------------------------------------------------
	//						STAT LEVELS END
	//----------------------------------------------------------			

	static const float METABOLIC_SPEED_BLADDER_BASAL		= 0.01;		//BLADDER loss per second while idle	
	static const float METABOLIC_SPEED_BLADDER_WALK			= 0.1;		//BLADDER loss per second
	static const float METABOLIC_SPEED_BLADDER_JOG			= 0.3;		//BLADDER loss per second
	static const float METABOLIC_SPEED_BLADDER_SPRINT		= 0.6;		//BLADDER loss per second
	
	//----------------------------------------------------------	
		
	static const float METABOLIC_SPEED_BOWEL_BASAL			= 0.01;		//water loss per second while idle	
	static const float METABOLIC_SPEED_BOWEL_WALK			= 0.1;		//water loss per second
	static const float METABOLIC_SPEED_BOWEL_JOG			= 0.3;		//water loss per second
	static const float METABOLIC_SPEED_BOWEL_SPRINT			= 0.6;		//water loss per second	
	
	//--------------------------------------------------------	
	
	static const float BLOOD_REGEN_MODIFIER_BLADDER_LOW		= 0; 	//multiplier for blood regen rate 
	static const float BLOOD_REGEN_MODIFIER_BLADDER_MID		= 0.5;
	static const float BLOOD_REGEN_MODIFIER_BLADDER_HIGH	= 1;
	
	static const float BLOOD_REGEN_MODIFIER_BOWEL_LOW		= 0; 	//multiplier for blood regen rate (BLOOD_REGEN_MULTIPLIER_BOWEL_LOW ?)
	static const float BLOOD_REGEN_MODIFIER_BOWEL_MID		= 0.5;
	static const float BLOOD_REGEN_MODIFIER_BOWEL_HIGH		= 1;	
	
	//--------------------------------------------------------		
	
	static const float BLADDER_GAIN_THRESHOLD_HC_PLUS_LOW	= THRESHOLD_HEAT_COMFORT_PLUS_WARNING;
	static const float BLADDER_GAIN_THRESHOLD_HC_PLUS_HIGH	= THRESHOLD_HEAT_COMFORT_PLUS_CRITICAL;
	
	static const float BOWEL_GAIN_THRESHOLD_HC_MINUS_LOW	= THRESHOLD_HEAT_COMFORT_MINUS_WARNING;
	static const float BOWEL_GAIN_THRESHOLD_HC_MINUS_HIGH	= THRESHOLD_HEAT_COMFORT_MINUS_CRITICAL;	
	
	static const float HIGH_BLADDER_THRESHOLD				= SL_BLADDER_HIGH;    //High Threshold BLADDER threshold from which BLADDER affects health
	static const float HIGH_BOWEL_THRESHOLD			 		= SL_BOWEL_HIGH;   // High Threshold BOWEL threshold from which BOWEL affects health	
	
	
	static const float BLADDER_GAIN_HC_PLUS_LOW				= 0;
	static const float BLADDER_GAIN_HC_PLUS_HIGH			= 0.4;

	static const float BOWEL_GAIN_HC_MINUS_LOW				= 0.2;
	static const float BOWEL_GAIN_HC_MINUS_HIGH				= 0.45;	
	
	//--------------------------------------------------------
	static const float HIGH_BLADDER_DAMAGE_PER_SEC			= 0.05;	//health loss per second while high bladder
	static const float HIGH_BOWEL_DAMAGE_PER_SEC			= 0.05;	//health loss per second while high bowel	
	
	//--------------------------------------------------------	
}