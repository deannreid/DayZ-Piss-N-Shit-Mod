/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: PluginManager.c
 *  
 * Class Information:
 *
 * Class helps with keybinds
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 16/10/2022 - Initial Code Development
 */

modded class PluginManager {
	override void Init() {
	 super.Init();
		Print("[PNS - PluginManager] :: [DEBUG] :: Loading Plugin Classes");
		//Register Modules
		//              Module Class :           Client  |  Server
		RegisterPlugin("PNSLogHelper",			 false, 	true);
		RegisterPlugin("PNSClientRPC", 			 true, 		false);
		RegisterPlugin("PNSServerRPC", 			 false, 	true);
		RegisterPlugin("PNSKeybindHelper", 		 true, 		false);		
	}
}