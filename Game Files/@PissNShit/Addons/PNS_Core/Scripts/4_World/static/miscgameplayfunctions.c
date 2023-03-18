/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: miscgameplayfunctions.c
 *  
 * Class Information:
 *
 * Class handles Player metabolism
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 05/12/2022 - Initial Code Development
 */

static float GetUrineMetabolicSpeed(int movement_speed)
{
	float speed;
	switch (movement_speed)
	{
		case DayZPlayerConstants.MOVEMENTIDX_WALK:
			speed = PlayerConstants.METABOLIC_SPEED_URINE_WALK;
		break;
		case DayZPlayerConstants.MOVEMENTIDX_RUN:
			speed = PlayerConstants.METABOLIC_SPEED_URINE_JOG;
		break;
		case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
			speed = PlayerConstants.METABOLIC_SPEED_URINE_SPRINT;
		break;
		default:
			speed = 0;
		break;
	}

	speed += PlayerConstants.METABOLIC_SPEED_URINE_BASAL;
	return speed;
}

static float GetRectumMetabolicSpeed(int movement_speed)
{
	float speed;
	switch (movement_speed)
	{
		case DayZPlayerConstants.MOVEMENTIDX_WALK:
			speed = PlayerConstants.METABOLIC_SPEED_RECTUM_WALK;
		break;
		case DayZPlayerConstants.MOVEMENTIDX_RUN:
			speed = PlayerConstants.METABOLIC_SPEED_RECTUM_JOG;
		break;
		case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
			speed = PlayerConstants.METABOLIC_SPEED_RECTUM_SPRINT;
		break;
		default:
			speed = 0;
		break;
	}

	speed += PlayerConstants.METABOLIC_SPEED_RECTUM_BASAL;
	return speed;
}