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
	float ticktime = 0;
	float UpdateInterval_ = 4.0;
	int playerIsAlive = 0;
	
	protected ProgressBarWidget						h_HealthBar;
	protected ProgressBarWidget						h_BloodBar;
	protected float									h_b1Max;	// Max Blood
	protected float									b1;			// Current Blood
	protected float									h_blood_normalized;
	protected float 								h_BloodFinal;
	
	protected ImageWidget							h_HealthImage;
	protected ImageWidget							h_BloodImage;
	protected ImageWidget							h_WaterImage;
	protected ImageWidget							h_FoodImage;
	protected ImageWidget							h_BladderImage;
	protected ImageWidget							h_BowelImage;
	protected ImageWidget							h_TempImage;
	PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());	
	
	override void OnInit() {
		
		Print("[PNS - LogHandler] :: [DEBUG] :: ([missionGameplay] :: OnInit - Client"); 
		//PNSKeybindHelper.RegisterBind("OBJECT TO BIND", PNSBinds.Press, "TITLE OF OBJECT", this);
		PNSKeybindHelper.RegisterBind("PNSSettings", PNSBinds.Press, "STR_PNS_SETTINGS", this);
		PNSKeybindHelper.RegisterBind("PNSPiss", PNSBinds.Press,  "STR_PNS_PISS", this);
		PNSKeybindHelper.RegisterBind("PNSShit", PNSBinds.Press,  "STR_PNS_SHIT", this);
		PNSKeybindHelper.RegisterBind("PNSVomit", PNSBinds.Press,  "STR_PNS_VOMIT", this);
		
        if ( !m_HudRootWidget ) {
			Print ( "Loading PNS UI Element" );
			//g_Game.GetUIManager().LoadImageSet("PNS_UI");
			
            m_HudRootWidget            = GetGame().GetWorkspace().CreateWidgets("PNS_Core/Assets/Layouts/UIV2/day_z_hud.layout");
			m_HudRootWidget.Show(false);
			
			m_Chat.Init(m_HudRootWidget.FindAnyWidget("ChatFrameWidget"));
			
			m_ActionMenu.Init( m_HudRootWidget.FindAnyWidget("ActionsPanel"), TextWidget.Cast( m_HudRootWidget.FindAnyWidget("DefaultActionWidget") ) );
			
			m_Hud.Init( m_HudRootWidget.FindAnyWidget("HudPanel") );
			
			// von enabled icon
			m_MicrophoneIcon = ImageWidget.Cast( m_HudRootWidget.FindAnyWidget("mic") );
			m_MicrophoneIcon.Show(false);
			
			// von voice level
			m_VoiceLevels = m_HudRootWidget.FindAnyWidget("VoiceLevelsPanel");
			m_VoiceLevelsWidgets = new map<int, ImageWidget>; // [key] voice level
			m_VoiceLevelTimers = new map<int,ref WidgetFadeTimer>; // [key] voice level
		
			if( m_VoiceLevels )
			{
				m_VoiceLevelsWidgets.Set(VoiceLevelWhisper, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Whisper") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelTalk, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Talk") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelShout, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Shout") ));
				
				m_VoiceLevelTimers.Set(VoiceLevelWhisper, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelTalk, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelShout, new WidgetFadeTimer);
			}
			
			HideVoiceLevelWidgets();
			
			// chat channel
			m_ChatChannelArea		= m_HudRootWidget.FindAnyWidget("ChatChannelPanel");
			m_ChatChannelText		= TextWidget.Cast( m_HudRootWidget.FindAnyWidget("ChatChannelText") ); 

			//PNS
			Class.CastTo(h_BladderImage, m_HudRootWidget.FindAnyWidget("ImageBladder"));
			Class.CastTo(h_BowelImage, m_HudRootWidget.FindAnyWidget("ImageBowel"));				
								
			//Class.CastTo(h_HealthImage, m_HudRootWidget.FindAnyWidget("ImageHealth"));
			//Class.CastTo(h_BloodImage, m_HudRootWidget.FindAnyWidget("ImageBlood"));
			//Class.CastTo(h_WaterImage, m_HudRootWidget.FindAnyWidget("ImageThirsty"));
			//Class.CastTo(h_FoodImage, m_HudRootWidget.FindAnyWidget("ImageHungry"));
			//Class.CastTo(h_TempImage, m_HudRootWidget.FindAnyWidget("ImageTemperature"));
	   }		
        super.OnInit();
	}
	
	void MissionGameplay() {
		if (GetGame().IsClient()) {
			GetRPCManager().AddRPC( "RPCPlayerSats", "SyncPlayers", this, SingeplayerExecutionType.Client );
		}		
	}
	
	void ~MissionGameplay() {

	}	
	
void SyncPlayers( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1<ref TFloatArray> PlayerServerData;
        ref TFloatArray ClientPlayerData = new TFloatArray;
        
		if ( type == CallType.Client && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			if ( !ctx.Read( PlayerServerData ) ) 
			{
			
				return;
			}

		    ClientPlayerData = PlayerServerData.param1;
			
			int PSD_Health =  ClientPlayerData[0];
			int PSD_Blood = ClientPlayerData[1];
			int PSD_Water = ClientPlayerData[2];
			int PSD_Energy = ClientPlayerData[3];
			playerIsAlive = ClientPlayerData[4];
			int PSD_Disease = ClientPlayerData[5];
			int PSD_Temp = ClientPlayerData[6];
			int PST_Bladder = ClientPlayerData[7];
			int PST_Bowel   = ClientPlayerData[8];
			string Disease_Message;
			if(PSD_Disease <= 0) 
			{
				Disease_Message = " Diseases: None";
			} else 
			{
				Disease_Message = " Diseases: " + PSD_Disease.ToString();
			}
		}
	}

	override void TickScheduler(float timeslice) {
		super.TickScheduler( timeslice);
		ticktime += timeslice;
		if(ticktime > UpdateInterval_) {
		    ticktime = 0;
			if(playerIsAlive == 1) {
				m_HudRootWidget.Show(true);
			} else  {
				m_HudRootWidget.Show(false);
			}
			GetRPCManager().SendRPC( "RPCPlayerSats", "SyncPlayersRequest", new Param1< int >(0),true,NULL  );
	    }	
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