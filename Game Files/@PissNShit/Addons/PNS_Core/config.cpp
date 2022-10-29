/*
 * DayZ - Piss N' Shit Mod mod.
 * Developed by @Dean Reid
 *
 * Class: config.cpp
 *  
 * Class Information:
 *
 * Class handels configuration for mod.
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 29/10/2022 - Initial Code Development
 */
class CfgPatches {
	class PNS_Core {
		requiredVersion=0.1;
		requiredAddons[]= {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Characters_Headgear"
		};
	};
};

class CfgMods
{
	class AutoSorting
	{
		dir="PissNShit/PNS_Core";
		type="mod";
		picture="PissNShit/PNS_Core/Assets/Images/logoOpaque.edds";
		inputs="PissNShit/PNS_Core/Scripts/Data/ACSKeybinds.xml";
		dependencies[]=
		{
			"World", "Mission"
		};
		class defs
		{
			class coreScriptModule
            {
                value = "";
                files[] = {
					"PissNShit/PNS_Core/Scripts/1_Core"
				};
            };
			class gameScriptModule
			{
				value="";
				files[]={
					"PissNShit/PNS_Core/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={
					"PissNShit/PNS_Core/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={
					"PissNShit/PNS_Core/Scripts/5_Mission"};
			};
		};
	};
};

/*class CfgSlots
{
	class Slot_SortingHat
	{
		name="Sorting Hat";
		displayName="Sorting Hat";
		ghostIcon="missing";
	};
};*/