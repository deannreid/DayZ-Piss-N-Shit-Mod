/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: missionServer.c
 *  
 * Class Information:
 *
 * Class handles serverside bits
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

modded class MissionServer {
	
	ref PNSConfig pnsConfig;
	string configDir;
	string permissionDir;
	
	void MissionServer()
    {
		configDir = PNSConstants.configRoot + PNSConstants.configFileName;
		if (!FileExist(configDir)) {
			Print("[PNS - ConfigManager] :: Folder " + configDir + " Not Found");
            if (!pnsConfig) {
                pnsConfig = new PNSConfig();
				Print("[PNS - ConfigManager] :: File " + pnsConfig + " Not Found");	
            }
			MakeDirectory(PNSConstants.configRoot);
			Print("[PNS - ConfigManager] :: Folder " + PNSConstants.configRoot + " Created! (Finally), Generating Configs");
            GetDayZGame().SetPNSConfig(pnsConfig);
            SavePNSConfig();
			
        } else {
            LoadPNSConfig();
            GetDayZGame().SetPNSConfig(pnsConfig);
			Print("[PNS - ConfigManager] :: File " + pnsConfig + " Found!, Loading Configs");
            SavePNSConfig();
        }
		//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetDayZGame().GetCodeLockConfig().GetConfigReloadTime() * 1000, true);
    }
	
	override void OnMissionStart(){
		super.OnMissionStart();
        Print("[PNS - missionServer] OnMissionStart - Server");
	}
	
	override void OnMissionFinish()
    {
        super.OnMissionFinish();
        Print("[PNS - missionServer] OnMissionFinish - Server");
    }
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
		Print("[PNS - missionServer] :: Plugin InvokeOnConnect!");
        super.InvokeOnConnect(player, identity);
		if (!player) { return; }
		
		//Allow Admin Access
		//if (GetCLPermissionManager().UserIsAdmin(identity.GetPlainId())) {
        //    auto params = new Param2<ref array<ref PNSAdmin>, string>(GetCLPermissionManager().GetAdmins(), identity.GetPlainId());
        //    GetGame().RPCSingleParam(player, CLRPC.RPC_CLIENT_SYNCHADMINS, params, true, identity);
        //}
		
        auto configParams = new Param1<PNSConfig>(GetDayZGame().GetPNSConfig());
		GetGame().RPCSingleParam(player, PNSRPC.RPC_CLIENT_SETCONFIG, configParams, true, identity);
		Print("[PNS - ConfigManager] :: Parameter: " + configParams + " Found");
       // GetGame().RPCSingleParam(player, PNSRPC.CHECKPNSCONFIG, configParams, true, identity); Not Implemented Yet
    }
	
	private void SavePNSConfig() {
        JsonFileLoader<PNSConfig>.JsonSaveFile(configDir, pnsConfig);
		Print("[PNS - ConfigManager] :: File " + configDir+pnsConfig + " Created");
    }

    private void LoadPNSConfig() {
        JsonFileLoader<PNSConfig>.JsonLoadFile(configDir, pnsConfig);
		Print("[PNS - ConfigManager] :: File " + configDir+pnsConfig + " Loaded");
        pnsConfig.ValidateOptions();
    }
	
	override void OnInit() {
		super.OnInit();	
		Print("[PNS - missionServer] :: Init - Server!");
	}
}