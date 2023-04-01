/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: missionGameplay.c
 *  
 * Class Information:
 *
 * Class handles Userside Mission.
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

modded class MissionGameplay {

	// UI reference
	PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
	
	void MissionGameplay() {
		
	}
	
	void ~MissionGameplay() {

	}
	
	override void OnInit() {
        super.OnInit();

		Print("[PNS - LogHandler] :: [DEBUG] :: ([missionGameplay] :: OnInit - Client"); 
		//PNSKeybindHelper.RegisterBind("OBJECT TO BIND", PNSBinds.Press, "TITLE OF OBJECT", this);
		PNSKeybindHelper.RegisterBind("PNSSettings", PNSBinds.Press, "STR_PNS_SETTINGS", this);
		PNSKeybindHelper.RegisterBind("PNSPiss", PNSBinds.Press,  "STR_PNS_PISS", this);
		PNSKeybindHelper.RegisterBind("PNSShit", PNSBinds.Press,  "STR_PNS_SHIT", this);
		PNSKeybindHelper.RegisterBind("PNSVomit", PNSBinds.Press,  "STR_PNS_VOMIT", this);
	}
	
	override void OnMissionStart() {
        super.OnMissionStart();
        Print("[PNS - missionGameplay] :: OnMissionStart - Client");
		//GetPNSLogger().WriteDebug("- [missionGameplay] :: OnMissionStart - Client"); 
		
    }

    override void OnMissionFinish() {
        super.OnMissionFinish();
        Print("[PNS - missionGameplay] :: OnMissionFinish - Client");
		//GetPNSLogger().WriteDebug("- [missionGameplay] :: OnMissionStart - Client"); 
    }
	/*
	 * Not Yet Required
	 *
	override void OnUpdate(float timeslice) {
		super.OnUpdate(timeslice);
	}
			
	override void Pause() {
        super.Pause();
	}
	
	override void Continue() {
        super.Continue();
	}

	override void OnKeyPress(int key) {
		super.OnKeyPress(key);
	}	
	*/
}