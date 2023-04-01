/*
 * DayZ - Piss N' Shit Mod
 * Developed by @Dean Reid
 *
 * Class: modifiermanager.c
 *  
 * Class Information:
 *
 * Class handles modifier enums
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 05/12/2022 - Initial Code Development
 */

modded class ModifiersManager {

	override void Init () {
	
		AddModifier (new BladderMdfr);
		AddModifier  (new BowelMdfr);
	
	}

}