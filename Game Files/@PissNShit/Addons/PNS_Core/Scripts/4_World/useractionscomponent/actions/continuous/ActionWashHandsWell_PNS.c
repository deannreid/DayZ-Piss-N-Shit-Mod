class ActionWashHandsWell_PNSCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.WASH_HANDS);
	}
};

class ActionWashHandsWell_PNS: ActionContinuousBase
{
	void ActionWashHandsWell_PNS() {
		m_CallbackClass 	= ActionWashHandsWell_PNSCB;
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONFB_WASHHANDSWELL;
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_CROUCH; // TODO: Replace with Custom Animation
		// m_Text = "#wash_hands";
	}

	override string GetText(){
		return "#STR_PNS_ACT_WASHHANDS (PNS)"; // Change to either STR_PNS_SHIT or STR_PNS_PISS or STR_PNS_VOMIT when implemented
	}
		
	override void CreateConditionComponents() {		
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) {
		return player.HasBloodyHands() && !player.GetItemInHands() && target.GetObject() && target.GetObject().IsWell(); // Add || !player.HasPissyHands() || !player.HasShittyHands() when Added
	}

	override void OnFinishProgressServer( ActionData action_data ) {
		PluginLifespan module_lifespan = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
		module_lifespan.UpdateBloodyHandsVisibility( action_data.m_Player, false );
	}
};