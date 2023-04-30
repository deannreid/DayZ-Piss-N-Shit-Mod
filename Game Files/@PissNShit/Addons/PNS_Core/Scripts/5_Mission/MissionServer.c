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
	
	void MissionServer() {
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
		
		if (GetGame().IsServer()) {
			GetRPCManager().AddRPC( "RPCPlayerSats", "SyncPlayersRequest", this, SingeplayerExecutionType.Server );		
		}			
    }
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		Print("[PNS - missionServer] :: Plugin InvokeOnConnect!");
        super.InvokeOnConnect(player, identity);
		if (!player) { return; }
		
        auto configParams = new Param1<PNSConfig>(GetDayZGame().GetPNSConfig());
		GetGame().RPCSingleParam(player, PNSRPC.RPC_CLIENT_SETCONFIG, configParams, true, identity);
		Print("[PNS - ConfigManager] :: Parameter: " + configParams + " Found");
    }
	
	void SyncPlayersRequest( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		ref TFloatArray PlayerValues		= new TFloatArray;
		array<Man> players 				= new array<Man>;
		PlayerBase player;
		PlayerIdentity PlayerIdentity_;
       
		if ( type == CallType.Server && GetGame().IsServer() ) {
			GetGame().GetPlayers(players);
			for (int i = 0; i < players.Count(); ++i) {
				player = PlayerBase.Cast(players.Get(i));
				PlayerIdentity_ = player.GetIdentity();
				
				if (PlayerIdentity_.GetPlayerId() == sender.GetPlayerId())
				{
					PlayerValues.Insert(player.GetStatBowel().Get());
					PlayerValues.Insert(player.GetStatBladder().Get());
					PlayerValues.Insert(player.GetStatWater().Get());
					PlayerValues.Insert(player.GetStatEnergy().Get());
					PlayerValues.Insert(player.IsAlive());
					PlayerValues.Insert(player.m_DiseaseCount);
					PlayerValues.Insert(player.m_Environment.GetTemperature());	
					PlayerValues.Insert(player.GetHealth("","Health"));
					PlayerValues.Insert(player.GetHealth("","Blood"));
				}
			}
			GetRPCManager().SendRPC( "RPCPlayerSats", "SyncPlayers", new Param1<ref TFloatArray> (PlayerValues), true, sender );
			Print("[PNS - PlayerValue DEBUG] :: Player: " + player + " Stats: " + "Bowel, Bladder, WaterLevel, EnergyLevel, IsAlive, DiseaseCount, EnvironmentTemp, Health");			
			Print("[PNS - PlayerValue DEBUG] :: Player: " + player + " Stats: " + PlayerValues);
		}
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
}