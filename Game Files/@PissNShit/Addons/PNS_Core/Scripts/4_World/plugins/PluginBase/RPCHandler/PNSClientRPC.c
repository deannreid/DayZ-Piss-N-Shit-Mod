/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: PNSClientRPC.c
 *  
 * Class Information:
 *
 * Class handles RPC for Server
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */
class PNSClientRPC : PluginBase {
	void PNSClientRPC() {
		Print("[PNS - RPCHandler] :: ([PNSClientRPC] :: Initializing Client RPC Handler");
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) { 
			Print("[PNS - RPCHandler] :: ([PNSClientRPC] :: Not Loaded - Running on Server.");
			return; 
		}

        GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);
    }
	
    void ~PNSClientRPC() {
        GetDayZGame().Event_OnRPC.Remove(ClientRPCHandler);
    }	
	
	void ClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		Print("[PNS - RPCHandler] :: ([PNSClientRPC] :: ClientRPCs Loaded");
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            delete this;
            return;
        }
		
	switch (rpc_type) {
		case PNSRPC.RPC_CLIENT_SETCONFIG:
	        {
				Print("[PNS - RPCHandler] :: RPC Loading");
	            Param1<PNSConfig> dataConfig;
	            ctx.Read(dataConfig);
				Print("[PNS - RPCHandler] :: RPC: " + dataConfig + " Found");
				
	            PNSConfig config = dataConfig.param1;
	
	            if (!config) {
	                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().DisconnectSessionForce, 100, false);
                    return;
	            }
	
	            GetDayZGame().SetPNSConfig(config);
				Print("[PNS - RPCHandler] :: RPC: " + config + " Set");
	            break;
	        }
		}
	}	
}