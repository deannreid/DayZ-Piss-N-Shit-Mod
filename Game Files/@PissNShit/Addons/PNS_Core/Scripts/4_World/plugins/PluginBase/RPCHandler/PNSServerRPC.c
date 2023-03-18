/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: PNSServerRPC.c
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

class PNSServerRPC : PluginBase {

	PlayerBase player;
	
	void PNSServerRPC() {
		Print("[PNS - RPCHandler] :: ([PNSServerRPC] :: Initializing Server RPC Handler");

        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { 
			Print("[PNS - RPCHandler] :: ([PNSServerRPC] :: Not Loaded - Running on Client.");
			return; 
		}
        GetDayZGame().Event_OnRPC.Insert(ServerRPCHandler);
	}

    void ~PNSServerRPC() {
        GetDayZGame().Event_OnRPC.Remove(ServerRPCHandler);
    }	

	void ServerRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {		
	Print("[PNS - RPCHandler] :: ([PNSServerRPC] :: ServerRPCs Loaded");
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            delete this;
            return;
        }
        if (!sender) { return; }		
	}
	
	PNSServerRPC GetPNSServerRPCHandler() {
    	if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }
    	return PNSServerRPC.Cast(GetPlugin(PNSServerRPC));
	}
}