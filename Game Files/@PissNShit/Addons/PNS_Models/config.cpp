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
	class PNS_Models{
		units[]= {
			"PNS_Bottle_Urine"
		};
		requiredVersion=0.1;
		requiredAddons[]= {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Drinks"
		};
	};
};
class cfgVehicles {
	class Inventory_Base;
	class Edible_Base;
	class PNS_BigTurd: Edible_Base {
		scope=2;
		displayName="$STR_PNS_MDL_POOP";
		descriptionShort="$STR_PNS_MDL_POOP_DESC";
		model="PNS_Models\data\Models\PileOPoo\Poop.p3d";
		weight=350;
		absorbency=1;
		itemSize[]={2,2};
		//isMeleeWeapon=1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=100;
					healthLevels[]= {
						{ 1, {	"DZ\gear\food\data\carp_fillet_raw.rvmat"	} },
						{ 0.69999999, { "DZ\gear\food\data\carp_fillet_dried.rvmat" } },
						{ 0.5, { "DZ\gear\food\data\carp_fillet_burnt.rvmat" } },
						{ 0.30000001, { "DZ\gear\food\data\carp_fillet_burnt.rvmat" } },
						{ 0, { "DZ\gear\food\data\food_can_destruct.rvmat" } }
					};
				};
			};
		};
		class Nutrition {
			fullnessIndex=1;
			energy=200;
			water=20.23918;
			nutritionalIndex=1;
			toxicity=500;
		};		
	};	
	class BandageDressing;
	class PNS_ToiletRoll_Base: BandageDressing {
		scope=2;
		displayName="$STR_PNS_MDL_TOILETROLL";
		descriptionShort="$STR_PNS_MDL_TOILETROLL_DESC";
		model="PNS_Models\data\Models\ToiletRoll\toilet_roll.p3d";
		weight=5;
		absorbency=1;
		itemSize[]={1,2};
		inventorySlot[]= {
			"Rags"
		};
		canBeSplit=0;
		quantityBar=1;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		rotationFlags=17;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=50;
					/*healthLevels[]= {
						{ 1, {	"PNS_Models\data\Models\ToiletRoll\toilet_roll.rvmat"	} },
						{ 0.69999999, { "PNS_Models\data\Models\ToiletRoll\toilet_roll.rvmat" } },
						{ 0.5, { "PNS_Models\data\Models\ToiletRoll\toilet_roll.rvmat" } },
						{ 0.30000001, { "PNS_Models\data\Models\ToiletRoll\toilet_roll.rvmat" } },
						{ 0, { "PNS_Models\data\Models\ToiletRoll\toilet_roll_ruined.rvmat" } }
					};*/
				};
			};
		};		
		class AnimEvents {
			class SoundWeapon {
				class Bandage_loop1 {
					soundSet="Bandage_loop_SoundSet";
					id=201;
				};
				class Bandage_loop2 {
					soundSet="Bandage_loop_SoundSet";
					id=202;
				};
				class Bandage_loop3 {
					soundSet="Bandage_loop_SoundSet";
					id=203;
				};
				class Bandage_start {
					soundSet="Bandage_start_SoundSet";
					id=204;
				};
				class Bandage_end {
					soundSet="Bandage_end_SoundSet";
					id=205;
				};
				class pickUpItem_Light {
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem {
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};	
	class PNS_ToiletRoll_Clean: PNS_ToiletRoll_Base
	{
		scope=2;
		displayName="$STR_PNS_MDL_TOILETROLL";
		descriptionShort="$STR_PNS_MDL_TOILETROLL_CLEAN_DESC";
		hiddenSelectionsTextures[]=
		{
			"PNS_Models\data\Models\ToiletRoll\CleanToiletRoll.paa"
		};
		varQuantityInit=10;
		varQuantityMin=10;
	};
	class PNS_ToiletRoll_Dirty: PNS_ToiletRoll_Base
	{
		scope=2;
		displayName="$STR_PNS_MDL_TOILETROLL (Used)";
		descriptionShort="$STR_PNS_MDL_TOILETROLL_DIRTY_DESC";
		hiddenSelectionsTextures[]=
		{
			"PNS_Models\data\Models\ToiletRoll\DirtyToiletRoll.paa"
		};
		varQuantityInit=5;
		varQuantityMin=1;
	};
	class Bottle_Base;
	class PNS_GamerBottle_Base: Bottle_Base
	{
		scope=2;
		displayName="$STR_PNS_MDL_GAMERBOTTLE";
		descriptionShort="$STR_PNS_MDL_GAMERBOTTLE_DESC";
		model="PNS_Models\data\Models\GamerBottle\GamerBottle.p3d";
		hiddenSelectionsTextures[]=
		{
			"PNS_Models\data\Models\GamerBottle\GamerBottle.paa"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		weight=80;
		itemSize[]={1,3};
		SingleUseActions[]=
		{
			507,
			"AT_WASH_HANDS",
			505,
			544
		};
		ContinuousActions[]={222,221,182,176,169,189,160,108,225,226,234,106};
		varLiquidTypeInit=512;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=500;
		isMeleeWeapon=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]= {
						{ 1, {	"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"	} },
						{ 0.69999999, { "DZ\gear\drinks\data\Loot_WaterBottle.rvmat" } },
						{ 0.5, { "DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat" } },
						{ 0.30000001, { "DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat" } },
						{ 0, { "DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat" } }
					};
				};
			};
		};
		class Nutrition {
			fullnessIndex=1;
			energy=150;
			water=350;
			nutritionalIndex=1;
			toxicity=200;
		};
		class AnimEvents {
			class SoundWeapon {
				class WaterBottle_in_B {
					soundSet="WaterBottle_in_B_SoundSet";
					id=202;
				};
				class WaterBottle_in_C {
					soundSet="WaterBottle_in_C_SoundSet";
					id=203;
				};
				class WaterBottle_in_C1 {
					soundSet="WaterBottle_in_C1_SoundSet";
					id=204;
				};
				class WaterBottle_out_A {
					soundSet="WaterBottle_out_A_SoundSet";
					id=205;
				};
				class WaterBottle_out_B {
					soundSet="WaterBottle_out_B_SoundSet";
					id=206;
				};
				class WellPond_loop {
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop {
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
				class pickup {
					soundSet="WaterBottle_pickup_SoundSet";
					id=797;
				};
			};
		};
	};	
	class PNS_GamerBottle_Urine: PNS_GamerBottle_Base
	{
		scope=2;
		displayName="$STR_PNS_MDL_GAMERBOTTLE";
		descriptionShort="$STR_PNS_MDL_GAMERBOTTLE_URINE_DESC";
		hiddenSelectionsTextures[]=
		{
			"PNS_Models\data\Models\GamerBottle\GamerBottle.paa"
		};
		varQuantityInit=500;
		varQuantityMin=0;
	};
};
