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
			"DZ_Scripts"
		};
	};
};

class CfgMods {
	class PissNShit {
		dir="PNS_Core";
		type="mod";
		picture="PNS_Core\Assets\Images\logo\logoOpaque.edds";
		logoSmall="PNS_Core\Assets\Images\logo\logoOpaque.edds";
		logo="PNS_Core\Assets\Images\logo\logoOpaque.edds";
		logoOver="PNS_Core\Assets\Images\logo\logoOpaque.edds";
		tooltip="Piss N' Shit Mod";
		overview="A mod to add the ability to fart uncontrolably, think of it like a human POX Vial.";
		action="https://steamcommunity.com/sharedfiles/filedetails/?id=2946290672";
		author="BigDeano";
		inputs="PNS_Core/Scripts/Data/PNSKeybinds.xml";
		dependencies[]= {
			"World", "Mission"
		};
		class defs {
			class imageSets {
				files[]= {
					"PNS_Core\Assets\Imagesets\PNS_UI.imageset"
				};
			}
			class coreScriptModule {
                value = "";
                files[] = {
					"PNS_Core/Scripts/1_Core"
				};
            };
			class gameScriptModule {
				value="";
				files[]= {
					"PNS_Core/Scripts/3_Game"};
			};
			class worldScriptModule {
				value="";
				files[]= {
					"PNS_Core/Scripts/4_World"};
			};
			class missionScriptModule {
				value="";
				files[]= {
					"PNS_Core/Scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles {
	class StaticObject;
	class House;
	class Inventory_Base;
};
class CfgNonAIVehicles {
	class StaticObject;
};
