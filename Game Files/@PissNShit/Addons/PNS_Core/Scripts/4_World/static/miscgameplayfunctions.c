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

/* Add Bladder effects when player is Walking, Running or Jogging */
modded class MiscGameplayFunctions {
	static float GetBladderMetabolicSpeed(int movement_speed) {
		float speed;
		switch (movement_speed) {
			case DayZPlayerConstants.MOVEMENTIDX_WALK:
				speed = PlayerConstants.METABOLIC_SPEED_BLADDER_WALK;
			break;
			case DayZPlayerConstants.MOVEMENTIDX_RUN:
				speed = PlayerConstants.METABOLIC_SPEED_BLADDER_JOG;
			break;
			case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
				speed = PlayerConstants.METABOLIC_SPEED_BLADDER_SPRINT;
			break;
			default:
				speed = 0;
			break;
		}

		speed += PlayerConstants.METABOLIC_SPEED_BLADDER_BASAL;
		return speed;
	}

/* Add Poop effects when player is Walking, Running or Jogging */
	static float GetBowelMetabolicSpeed(int movement_speed) {
		float speed;
		switch (movement_speed)
		{
			case DayZPlayerConstants.MOVEMENTIDX_WALK:
				speed = PlayerConstants.METABOLIC_SPEED_BOWEL_WALK;
			break;
			case DayZPlayerConstants.MOVEMENTIDX_RUN:
				speed = PlayerConstants.METABOLIC_SPEED_BOWEL_JOG;
			break;
			case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
				speed = PlayerConstants.METABOLIC_SPEED_BOWEL_SPRINT;
			break;
			default:
				speed = 0;
			break;
		}

		speed += PlayerConstants.METABOLIC_SPEED_BOWEL_BASAL;
		return speed;
	}
}