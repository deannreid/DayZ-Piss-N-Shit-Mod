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
	
	static const float SL_URINE_CRITICAL = 5000;
	static const float SL_URINE_LOW = 3500;
	static const float SL_URINE_NORMAL = 800;
	static const float SL_URINE_HIGH = 300;
	static const float SL_URINE_MAX = 0;
	
	static const float SL_RECTUM_CRITICAL = 5000;
	static const float SL_RECTUM_LOW = 3500;
	static const float SL_RECTUM_NORMAL = 800;
	static const float SL_RECTUM_HIGH = 300;
	static const float SL_RECTUM_MAX = 0;
	
	//--------------------------------------------------------
	
	static const float URINE_LOSS_HC_PLUS_LOW				= 0;
	static const float URINE_LOSS_HC_PLUS_HIGH				= 0.4;
		
	static const float RECTUM_LOSS_HC_PLUS_LOW				= 0;
	static const float RECTUM_LOSS_HC_PLUS_HIGH				= 0.4;
	
	//--------------------------------------------------------
	static const float METABOLIC_SPEED_URINE_BASAL		= 0.01;		//URINE Increase per second while idle
	
	static const float METABOLIC_SPEED_URINE_WALK		= 0.1;		//URINE Increase per second
	static const float METABOLIC_SPEED_URINE_JOG		= 0.3;		//URINE Increase per second
	static const float METABOLIC_SPEED_URINE_SPRINT		= 0.6;		//URINE Increase per second
	
	static const float METABOLIC_SPEED_RECTUM_BASAL		= 0.01;		//RECTUM Increase per second while idle
	
	static const float METABOLIC_SPEED_RECTUM_WALK		= 0.1;		//RECTUM Increase per second
	static const float METABOLIC_SPEED_RECTUM_JOG		= 0.3;		//RECTUM Increase per second
	static const float METABOLIC_SPEED_RECTUM_SPRINT	= 0.6;		//RECTUM Increase per second
	
	
	static const float HIGH_URINE_THRESHOLD				= SL_URINE_HIGH;    //High Threshold Urine
	static const float HIGH_RECTUM_THRESHOLD			= SL_RECTUM_HIGH;   // High Threshold Rectum
}