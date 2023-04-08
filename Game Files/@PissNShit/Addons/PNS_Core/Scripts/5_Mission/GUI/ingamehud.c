modded class IngameHud extends Hud
{
	protected const float						FADE_IN_TIME = 0.3;
	protected const float						FADE_OUT_TIME = 0.3;
	protected const float						HIDE_MENU_TIME = 5;

	protected ref map<int,string>				m_StatesWidgetNames;
	protected ref map<int,ImageWidget>			m_StatesWidgets;  // [key] ImageWidget

	protected ref map<ImageWidget, int>			m_TendencyStatusCritical;	//array of icons that are blinking due to critical tendency status
	protected const float						TENDENCY_BLINK_TIME = 0.25;
	protected float								m_BlinkTime;
	
	protected ref map<int,string>				m_BadgesWidgetNames;
	protected ref map<int,int>					m_BadgesWidgetDisplay;
	protected ref map<int,ImageWidget>			m_BadgesWidgets;  // [key] ImageWidget
	protected bool								m_AnyBadgeVisible;
	protected bool								m_IsTemperatureVisible;
	protected float								m_TemperatureTimer;
	protected float								m_TemperatureShowTime = 30;
	protected ImageWidget						m_HeatBufferPlus;

	protected bool								m_IsStaminaVisible;
	protected float								m_StaminaTimer;
	protected float								m_StaminaShowTime = 0.15;
	
	protected ref map<int,string>				m_VehicleGearTable;
	protected ref map<int,string>				m_VehicleGearTableAuto;

	protected Widget							m_HudPanelWidget;
	protected Widget							m_LeftHudPanelWidget;
	protected Widget							m_QuickbarWidget;
	protected ref InventoryQuickbar				m_Quickbar;
	
	protected Widget							m_VehiclePanel;
	
	protected ImageWidget						m_VehicleRPMPointer;
	protected ImageWidget						m_VehicleRPMDial;
	protected ImageWidget						m_VehicleRPMRedline;
	protected ImageWidget						m_VehicleSpeedPointer;
	protected Widget							m_VehicleTemperatureIndicator;
	protected ImageWidget						m_VehicleTemperaturePointer;
	protected ImageWidget						m_VehicleTemperatureLight;
	protected ImageWidget						m_VehicleFuelPointer;
	protected ImageWidget						m_VehicleFuelLight;
	
	protected TextWidget						m_VehicleSpeedValue;
	
	protected TextWidget						m_VehicleCurrentGearValue;
	protected TextWidget						m_VehicleNextGearValue;
	protected TextWidget						m_VehiclePrevGearValue;
	
	protected ImageWidget						m_VehicleBatteryLight;
	protected ImageWidget						m_VehicleEngineLight;
	protected ImageWidget						m_VehicleOilLight;
	protected ImageWidget						m_VehicleHandBrakeLight;
	protected ImageWidget						m_VehicleWheelLight;
	
	protected bool 								m_VehicleDamageZoneHitEngineState;
	protected float								m_VehicleDamageZonesHitTimer;
	
	protected bool								m_InVehicleAsDriver;
	protected CarScript							m_CurrentVehicle;
	
	
	protected Widget 							m_GameStatusIconsPanel;					
	protected ImageWidget 						m_HighPingA;					
	protected ImageWidget 						m_HighPingB;					
	protected ImageWidget 						m_LowServerPerfA;			
	protected ImageWidget 						m_LowServerPerfB;			
	protected ImageWidget 						m_ConnectionLost;			
	
	protected Widget							m_Notifiers;
	protected TextWidget						m_BloodType;
	protected TextWidget						m_BloodPosType;
	protected Widget							m_BadgeNotifierDivider;
	protected Widget							m_Badges;
	protected ref Timer							m_HideTimer;
	protected ref WidgetFadeTimer				m_FadeTimerCrosshair;
	protected ref WidgetFadeTimer				m_FadeTimerActionCursor;
//	protected ref WidgetFadeTimer				m_FadeTimerWeaponMode;
//	protected ref WidgetFadeTimer				m_FadeTimerZeroing;
	protected ref WidgetFadeTimer				m_FadeTimerZeroingOld;
	protected ref WidgetFadeTimer				m_FadeTimerMagazineName;
	protected ref WidgetFadeTimer				m_FadeTimerWeaponName;
	protected ref WidgetFadeTimer				m_FadeTimerWeaponStats;
	protected ref WidgetFadeTimer				m_FadeTimerQuickbar;
	protected ref WidgetFadeTimer				m_FadeTimerWalkieTalkie;
	protected ref WidgetFadeTimer				m_FadeTimerWalkieTalkieText;
	
	protected ProgressBarWidget					m_Stamina;
	protected Widget							m_StaminaBackground;
	protected Widget							m_Presence;
	protected Widget							m_StanceProne;
	protected Widget							m_StanceStand;
	protected Widget							m_StanceStandWalk;
	protected Widget							m_StanceCrouch;
	protected Widget							m_StanceCar;
	protected Widget							m_StancePanel;
	protected Widget							m_PresenceLevel0;
	protected Widget							m_PresenceLevel1;
	protected Widget							m_PresenceLevel2;
	protected Widget							m_PresenceLevel3;
	protected Widget							m_PresenceLevel4;
	protected ref Timer							myTimer; //TEMP
	protected ref array<ref WidgetFadeTimer>	m_FadeTimers = new array<ref WidgetFadeTimer>;
	protected Widget							m_MouseSingleAction;
	protected Widget							m_MouseContinuousAction;
	protected Widget							m_RadialProgressBar1;
	protected Widget							m_RadialProgressBarCrossHair;
	protected Widget							m_RadialProgressBar;
	protected Widget							m_CursorWidget;
	protected ImageWidget						m_CursorIcon;
	protected Widget							m_WalkieTalkie;
	
	protected Widget							m_ActionWidget;
	protected TextWidget						m_ActionDesc;
	protected TextWidget						m_ActionItemDesc;
	protected Widget							m_ActionItemQuantityWrapper
	protected ImageWidget						m_ActionHealthMark;
	protected ProgressBarWidget					m_ActionQuantityBar;
	protected Widget							m_ActionQuantityBox;
	protected TextWidget						m_ActionQuantityBoxText;
	protected ImageWidget						m_ActionIcon;
	protected TextWidget						m_ActionButtonText;

	protected Widget							m_ActionIconFrame;
	protected Widget							m_ActionMultipleItemsFrame;
	
	protected Widget							m_ActionTarget;
	protected ActionTargetsCursor				m_ActionTargetsCursor;
	
	// CrossHairs
	protected ImageWidget						m_PermanentCrossHair;
	
	protected bool								m_HudHideUI;
	protected bool								m_HudHidePlayer;
	protected bool								m_HudInventory;
	protected bool								m_HudState; //options-driven global setting
	protected bool								m_QuickbarHideUI;
	protected bool								m_QuickbarHidePlayer;
	protected bool								m_QuickbarState; //options-driven global setting
	protected bool								m_IsQuickbarVisible;
	protected bool								m_IsHudVisible;
	protected bool								m_Faded;
	protected bool								m_ZeroingKeyPressed;
	
	protected Widget 							m_HitIndicatorUp;
	protected Widget 							m_HitIndicatorDown;
	protected Widget 							m_HitIndicatorLeft;
	protected Widget 							m_HitIndicatorRight;
	protected Widget 							m_HitIndicatorSingle;
	protected Widget							m_SpecializatonPanel;
	protected Widget							m_SpecializationIcon;
	
	ref array<ref HitDirectionEffectBase> 		m_HitDirEffectArray;
		
	void IngameHud()
	{
		m_FadeTimerCrosshair			= new WidgetFadeTimer;
		m_FadeTimerActionCursor			= new WidgetFadeTimer;
	 	m_FadeTimerQuickbar			= new WidgetFadeTimer;
	 	m_FadeTimerWalkieTalkie		= new WidgetFadeTimer;
		m_FadeTimerWalkieTalkieText	= new WidgetFadeTimer;
		
		m_StatesWidgets					= new map<int, ImageWidget>; // [key] widgetName
		m_StatesWidgetNames				= new map<int, string>;
		
		m_TendencyStatusCritical		= new map<ImageWidget, int>;
		
		m_BadgesWidgets					= new map<int, ImageWidget>; // [key] widgetName
		m_BadgesWidgetNames				= new map<int, string>;
		m_BadgesWidgetDisplay			= new map<int, int>;
		
		m_VehicleDamageZonesHitTimer	= 0;

		m_VehicleGearTable				= new map<int, string>;
		m_VehicleGearTable.Set(-1, "");
		m_VehicleGearTable.Set(CarGear.REVERSE, "R");
		m_VehicleGearTable.Set(CarGear.NEUTRAL, "N");
		m_VehicleGearTable.Set(CarGear.FIRST, "1");
		m_VehicleGearTable.Set(CarGear.SECOND, "2");
		m_VehicleGearTable.Set(CarGear.THIRD, "3");
		m_VehicleGearTable.Set(CarGear.FOURTH, "4");
		m_VehicleGearTable.Set(CarGear.FIFTH, "5");
		m_VehicleGearTable.Set(CarGear.SIXTH, "6");
		m_VehicleGearTable.Set(CarGear.SEVENTH, "7");
		m_VehicleGearTable.Set(CarGear.EIGTH, "8");
		
		m_VehicleGearTableAuto			= new map<int, string>;
		m_VehicleGearTableAuto.Set(-1, "");
		m_VehicleGearTableAuto.Set(CarAutomaticGearboxMode.R, "R");
		m_VehicleGearTableAuto.Set(CarAutomaticGearboxMode.N, "N");
		m_VehicleGearTableAuto.Set(CarAutomaticGearboxMode.D, "D");

	}

	override void Init( Widget hud_panel_widget )
	{
		m_HudPanelWidget = hud_panel_widget;
		m_HudPanelWidget.Show( true );

		//Quickbar
		m_QuickbarWidget		= m_HudPanelWidget.FindAnyWidget("QuickbarGrid");
		m_QuickbarWidget.Show( false );
		
		//Left HUD Panel
		m_LeftHudPanelWidget	= m_HudPanelWidget.FindAnyWidget("LeftHUDPanel");
		
		//TEMPORARY HACK!!! player is not present when Hud is being initialized 
		myTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		myTimer.Run( 1, this, "InitQuickbar" );
		
		m_CursorWidget = m_HudPanelWidget.FindAnyWidget("CursorIcons");
		m_CursorWidget.Show(true);
		Class.CastTo(m_CursorIcon, m_HudPanelWidget.FindAnyWidget("Cursor"));

		//Permanent Crosshair
		Class.CastTo(m_PermanentCrossHair, m_HudPanelWidget.FindAnyWidget("PermanentCrossHair"));
		
		m_WalkieTalkie = m_HudPanelWidget.FindAnyWidget("WalkieTalkie");
		
		//Panels
		Class.CastTo(m_Stamina, m_HudPanelWidget.FindAnyWidget("StaminaBar"));
		m_Presence						= m_HudPanelWidget.FindAnyWidget("PresencePanel");
		m_Badges						= hud_panel_widget.FindAnyWidget("BadgesPanel");
		m_Notifiers						= m_HudPanelWidget.FindAnyWidget("NotifiersPanel");
		m_SpecializatonPanel			= m_HudPanelWidget.FindAnyWidget("SpecializationPanel");
		m_SpecializationIcon 			= m_HudPanelWidget.FindAnyWidget("SpecializationIcon");
		m_BadgeNotifierDivider			= m_HudPanelWidget.FindAnyWidget("BadgeNotifierDivider");
		m_BloodType						= TextWidget.Cast( m_HudPanelWidget.FindAnyWidget("BloodType") );
		m_BloodPosType					= TextWidget.Cast( m_HudPanelWidget.FindAnyWidget("BloodPosType") );
		
		m_VehiclePanel					= m_HudPanelWidget.FindAnyWidget("VehiclePanel");
		m_VehiclePanel.Show(false);
		
		m_VehicleRPMPointer				= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("RPMPointer") );
		m_VehicleRPMDial				= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("RPMDial") );
		m_VehicleRPMRedline				= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("RPMDialRedline") );
		m_VehicleSpeedPointer			= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("SpeedPointer") );
		m_VehicleSpeedValue				= TextWidget.Cast( m_VehiclePanel.FindAnyWidget("SpeedValue") );
		
		m_VehicleCurrentGearValue		= TextWidget.Cast( m_VehiclePanel.FindAnyWidget("Current") );
		m_VehicleNextGearValue			= TextWidget.Cast( m_VehiclePanel.FindAnyWidget("Next") );
		m_VehiclePrevGearValue			= TextWidget.Cast( m_VehiclePanel.FindAnyWidget("Prev") );
		
		m_VehicleBatteryLight			= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("BatteryLight"));
		m_VehicleEngineLight			= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("EngineLight"));
		m_VehicleOilLight				= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("OilLight"));
		m_VehicleHandBrakeLight			= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("HandBrakeLight"));
		m_VehicleWheelLight				= ImageWidget.Cast( m_VehiclePanel.FindAnyWidget("WheelLight"));
		
		m_VehicleTemperatureIndicator	= m_VehiclePanel.FindAnyWidget("TemperatureIndicator");
		m_VehicleTemperaturePointer		= ImageWidget.Cast(m_VehiclePanel.FindAnyWidget("TemperaturePointer"));
		m_VehicleTemperatureLight		= ImageWidget.Cast(m_VehiclePanel.FindAnyWidget("TemperatureLight"));
		m_VehicleFuelPointer			= ImageWidget.Cast(m_VehiclePanel.FindAnyWidget("FuelPointer"));
		m_VehicleFuelLight				= ImageWidget.Cast(m_VehiclePanel.FindAnyWidget("FuelLight"));
		
		m_StaminaBackground				= m_HudPanelWidget.FindAnyWidget("StaminaBackground");
		m_StaminaBackground.Show(true);
		m_StanceProne					= m_HudPanelWidget.FindAnyWidget("StanceProne");
		m_StanceCrouch					= m_HudPanelWidget.FindAnyWidget("StanceCrouch");
		m_StanceStand					= m_HudPanelWidget.FindAnyWidget("StanceStand");
		m_StanceStandWalk				= m_HudPanelWidget.FindAnyWidget("StanceStandWalk");
		m_StanceCar						= m_HudPanelWidget.FindAnyWidget("StanceCar");
		m_StancePanel					= m_HudPanelWidget.FindAnyWidget("StancePanel");

		m_ActionTarget					= m_HudPanelWidget.FindAnyWidget("ActionTargetsCursorWidget");
		//! gets scripted handler from widget
		m_ActionTarget.GetScript(m_ActionTargetsCursor);

		// heat buffer plus sign
		m_HeatBufferPlus = ImageWidget.Cast( m_HudPanelWidget.FindAnyWidget( "HeatBuffer" ) );
		
		//Game State Icons
		m_GameStatusIconsPanel			= m_HudPanelWidget.FindAnyWidget("GameStatusIcons");
		m_HighPingA						= ImageWidget.Cast(m_HudPanelWidget.FindAnyWidget("HighPingA"));
		m_HighPingB						= ImageWidget.Cast(m_HudPanelWidget.FindAnyWidget("HighPingB"));
		m_LowServerPerfA				= ImageWidget.Cast(m_HudPanelWidget.FindAnyWidget("LowServerPerfA"));
		m_LowServerPerfB				= ImageWidget.Cast(m_HudPanelWidget.FindAnyWidget("LowServerPerfB"));
		m_ConnectionLost				= ImageWidget.Cast(m_HudPanelWidget.FindAnyWidget("ConnectionLost"));
		
		if ( m_HeatBufferPlus )
			m_HeatBufferPlus.Show( false );

		#ifndef NO_GUI
		m_Timer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_Timer.Run(0.333, this, "RefreshQuickbar", NULL, true );
		#endif
		InitBadgesAndNotifiers();
		
		m_PresenceLevel0 = hud_panel_widget.FindAnyWidget("Presence0");
		m_PresenceLevel1 = hud_panel_widget.FindAnyWidget("Presence1");
		m_PresenceLevel2 = hud_panel_widget.FindAnyWidget("Presence2");
		m_PresenceLevel3 = hud_panel_widget.FindAnyWidget("Presence3");
		m_PresenceLevel4 = hud_panel_widget.FindAnyWidget("Presence4");
		m_PresenceLevel0.Show( false );
		m_PresenceLevel1.Show( false );
		m_PresenceLevel2.Show( false );
		m_PresenceLevel3.Show( false );
		m_PresenceLevel4.Show( false );
		
		SetLeftStatsVisibility( true );
		m_HudState = g_Game.GetProfileOption( EDayZProfilesOptions.HUD );
		MissionGameplay.Cast(GetGame().GetMission()).GetConnectivityInvoker().Insert(OnConnectionIconsSettingsChanged);
		m_GameStatusIconsPanel.Show(g_Game.GetProfileOption(EDayZProfilesOptions.CONNECTIVITY_INFO));
		//ShowQuickBar(GetGame().GetInput().IsEnabledMouseAndKeyboardEvenOnServer() && g_Game.GetProfileOption(EDayZProfilesOptions.QUICKBAR)); //unreliable
	}
	
	override void InitBadgesAndNotifiers()
	{
		// state notifiers
		m_StatesWidgetNames.Clear();
		m_StatesWidgets.Clear();
		
		
		m_StatesWidgetNames.Set( NTFKEY_BLADDER, "Bladder" );	
		m_StatesWidgetNames.Set( NTFKEY_BOWEL, "Bowel" );
		
		
		m_StatesWidgetNames.Set( NTFKEY_THIRSTY, "Thirsty" );
		m_StatesWidgetNames.Set( NTFKEY_HUNGRY, "Hungry" );
		m_StatesWidgetNames.Set( NTFKEY_SICK, "Health" );
		m_StatesWidgetNames.Set( NTFKEY_BLEEDISH, "Blood" );
		m_StatesWidgetNames.Set( NTFKEY_FEVERISH, "Temperature" );
	
		m_Notifiers.Show( true );
		m_Badges.Show( true );

		int i = 0;
		int key = 0;
		
		for ( i = 0; i < m_StatesWidgetNames.Count(); i++ )
		{
			string widget_name = m_StatesWidgetNames.GetElement(i);
				key = m_StatesWidgetNames.GetKey(i);
				ImageWidget w;
				Class.CastTo(w,  m_Notifiers.FindAnyWidget( String( "Icon" + widget_name ) ) );
				m_StatesWidgets.Set( key, w );
				w.Show( true );			
			if (widget_name == "Thirsty" || widget_name == "Hungry" || widget_name == "Health" || widget_name == "Blood" || widget_name == "Temperature")
			{
				for ( int y = 0; y < 5; y++ ) {
					w.LoadImageFile( y, "set:dayz_gui image:icon" + widget_name + y );
				}
			}
			if (widget_name == "Bladder" || widget_name == "Bowel")
			{
				for ( int z = 0; z < 5; z++ ) {
					w.LoadImageFile( z, "set:PNS_UI image:icon" + widget_name + z );
				}
			}		
			w.SetImage( 0 );
			float alpha = w.GetAlpha();
			w.SetColor( ARGB( alpha * 255, 220, 220, 220 ) );	//white
			m_TendencyStatusCritical.Remove( w );
			// clear all arrows
			for ( int x = 1; x < 4; x++ )
			{
				Class.CastTo(w,  m_Notifiers.FindAnyWidget( String( widget_name + "ArrowUp" + x.ToString() ) ) );
				w.Show( false );
				Class.CastTo(w,  m_Notifiers.FindAnyWidget( String( widget_name + "ArrowDown" + x.ToString() ) ) );
				w.Show( false );
			}
		
			
		}

		// badges
		m_BadgesWidgetNames.Clear();
		m_BadgesWidgets.Clear();
		m_BadgesWidgetDisplay.Clear();
		m_BadgesWidgetNames.Set( NTFKEY_FRACTURE, "Fracture" );
		m_BadgesWidgetNames.Set( NTFKEY_STUFFED, "Stomach" );
		m_BadgesWidgetNames.Set( NTFKEY_SICK, "Sick" );
		m_BadgesWidgetNames.Set( NTFKEY_WETNESS, "Wetness" );
		m_BadgesWidgetNames.Set( NTFKEY_POISONED, "Poisoned" );
		m_BadgesWidgetNames.Set( NTFKEY_BLEEDISH, "Bleeding" );
		m_BadgesWidgetNames.Set( NTFKEY_LIVES, "Shock" );
		m_BadgesWidgetNames.Set( NTFKEY_PILLS, "Pills" );
	
		for ( i = 0; i < m_BadgesWidgetNames.Count(); i++ )
		{
			string badge_name = m_BadgesWidgetNames.GetElement(  i);
			key = m_BadgesWidgetNames.GetKey( i );
			ImageWidget badge_widget;
			Class.CastTo(badge_widget,  m_Badges.FindAnyWidget( badge_name ) );
			m_BadgesWidgets.Set( key, badge_widget );
			badge_widget.Show( false );
			m_BadgesWidgetDisplay.Set( key, false );
		}
		m_AnyBadgeVisible = false;
		m_BadgeNotifierDivider.Show(false);
	
	}
	
	override void Show( bool show )
	{
		m_HudPanelWidget.Show( show );
	}
	
	override void DisplayNotifier( int key, int tendency, int status )
	{
		ImageWidget w;
		if ( key == NTFKEY_FEVERISH )
		{
			DisplayTendencyTemp( key, tendency, status );
		}
		else
		{
			DisplayTendencyNormal( key, tendency, status );
		}
		
		// tendency arrows
		string arrow_name = "ArrowUp";
		if ( tendency < 0 )
		{
			arrow_name = "ArrowDown";
		}
		tendency = Math.AbsInt( tendency );

		for ( int x = 1; x < 4; x++ )
		{ 
			Class.CastTo(w,  m_Notifiers.FindAnyWidget( String(  m_StatesWidgetNames.Get( key ) + "ArrowUp" + x.ToString() ) ) );
			if( w )
				w.Show( false );
			Class.CastTo(w,  m_Notifiers.FindAnyWidget( String(  m_StatesWidgetNames.Get( key ) + "ArrowDown" + x.ToString() ) ) );
			if( w )
				w.Show( false );
		}
		
		if( tendency > 0 )
		{
			string widget_name = m_StatesWidgetNames.Get( key ) + arrow_name + Math.Clamp( tendency, 1, 3 );
			Class.CastTo(w, m_Notifiers.FindAnyWidget( widget_name ) );
			if( w )
				w.Show( true );
		}
	}
	
	override void Update( float timeslice )
	{
		super.Update( timeslice );

		m_ActionTargetsCursor.Update();
		DisplayPresence();
		//
		//modifiers - tendency status (critical)
		if ( m_BlinkTime > TENDENCY_BLINK_TIME )
		{
			//get color & alpha
			if ( m_TendencyStatusCritical.Count() > 0 )
			{
				for ( int i = 0; i < m_TendencyStatusCritical.Count(); ++i )
				{
					
					ImageWidget widget = m_TendencyStatusCritical.GetKey( i );
					int alpha = widget.GetAlpha() * 255;
					int color;
					int colorA = ARGB( alpha, 255, 255, 255 );
					int colorB = m_TendencyStatusCritical.Get( widget );
					
					//set new color to different color
					if ( widget.GetColor() == colorA )
					{
						color = colorB;
					}
					else
					{
						color = colorA;
					}

					widget.SetColor( color );
				}
			}
			
			m_BlinkTime = 0;	//reset
		}
		else
		{
			m_BlinkTime += timeslice;
		}
		
		if( m_IsTemperatureVisible )
		{
			m_TemperatureTimer += timeslice;
			if( m_TemperatureTimer > m_TemperatureShowTime )
			{
				HideTemperature();
			}
		}
		
		if ( !m_IsStaminaVisible )
		{
			m_StaminaTimer += timeslice;
			if ( m_StaminaTimer > m_StaminaShowTime )
			{
				SetStaminaBarVisibility( true );
			}
			
		}
		
		if ( m_HitDirEffectArray && m_HitDirEffectArray.Count() > 0 )
		{
			UpdateHitDirEffects(timeslice);
			CleanupHitDirEffects();
		}
		
		RefreshVehicleHud(timeslice);
		
		#ifdef PLATFORM_PS4
		RefreshPlayerTags();
		ShowPlayerTag(timeslice);
		#endif
	}
}