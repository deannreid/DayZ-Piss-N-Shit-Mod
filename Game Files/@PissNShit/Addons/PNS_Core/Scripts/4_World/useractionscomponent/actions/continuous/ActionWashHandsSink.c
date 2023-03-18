class ActionWashHandsSink_PNSCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.WASH_HANDS);
	}
};

class ActionWashHandsSink_PNS: ActionContinuousBase {
	void ActionWashHandsSink_PNS() {
		m_CallbackClass 	= ActionWashHandsWell_zCB;
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONFB_WASHHANDSPOND; // TODO: Replace with Custom Animation
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_ERECT; // TODO: Replace with Custom Stance
	}

	override string GetText(){
		return "#STR_PNS_ACT_WASHHANDS (PNS)";
	}
	
	override void CreateConditionComponents() {		
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursorParent(UAMaxDistances.DEFAULT);
	}
	
	Object targetobject;
    string targetObjectName;
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) {		
		targetobject = Object.Cast(target.GetObject());
		Static_Base TargetSearched = Static_Base.Cast(targetobject);		
		
		if( !target )
			return false;

		if(GetGame().IsClient()) { //Condition to check if the player is calling as server will crash due to NULL error
			if(!player.HasBloodyHands() || player.GetItemInHands()) // Add || !player.HasPissyHands() || !player.HasShittyHands() when Added
				return false;
			
			targetObjectName = targetobject.GetType();
			targetObjectName.ToLower();
			bool state;
			if (targetObjectName.Contains("basin") || targetObjectName.Contains("basinsink")|| targetObjectName.Contains("bath") ) {
				state = true; //only targets desired objects with lowercase name listed above.. 
			}
			if(targetObjectName=="" || TargetSearched.IsSearched()) { //Only Target objects defined.
				return false;
			} else {
				return state;
			}
		}
		
		if(target.IsProxy()) {
			return true;
		}
        return false;
	}

	override void OnFinishProgressServer( ActionData action_data ) {
		PluginLifespan module_lifespan = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
		module_lifespan.UpdateBloodyHandsVisibility( action_data.m_Player, false );
	}
	override void OnFinishProgressClient( ActionData action_data ) {
		ActionTarget target = ActionTarget.Cast(action_data.m_Target);	
		Object targetobject = Object.Cast(target.GetObject());
		Static_Base TargetSearched = Static_Base.Cast(targetobject);		
		TargetSearched.SetIsSearched(true);	
	}	
};