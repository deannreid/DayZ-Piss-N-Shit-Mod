class ActionUseToiletContinuousCB : ActionContinuousBaseCB {

	override void CreateActionComponent() { 
	
		float time = SetAnimDuration(m_ActionData.m_Target);
		m_ActionData.m_ActionComponent = new CAContinuousTime ( time );	
	}

	float SetAnimDuration( ActionTarget target ) {
		return 2500;
	}
	
};

class ActionUseToiletContinuous: ActionContinuousBase {

	void ActionUseToiletContinuous() {
		m_CallbackClass = ActionUseToiletContinuousCB;
		m_CommandUID = DayZPlayerConstants.CMD_GESTUREFB_SHRUG;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}	
	
	override string GetText() {
	
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if ( player ) { 
		
			ActionManagerBase actmgr = player.GetActionManager();
			Object targetObject = actmgr.FindActionTarget().GetObject();
			
			//Using BBP Toilet as Placeholder*
			Land_Misc_Toilet_Dry objectToilet = Land_Misc_Toilet_Dry.Cast( targetObject );
			
			if( objectToilet ) {
				return "STR_PNS_PISS";	
			}
			return "Use Continuous";
		}
	}
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) {	
		Object targetObject = target.GetObject();
		Land_Misc_Toilet_Dry objectToilet = Land_Misc_Toilet_Dry.Cast( targetObject );
			
		if ( targetObject ) {
			if ( objectToilet ) {
				return true;
			}
		}
		return false;
	}
	
	override bool HasProgress() {
		return false;
	}
	
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL ) {	
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			SetAnimation( target );
			return true;
		}
		
		return false;
	}
	
	protected void SetAnimation( ActionTarget target ) {
		Object targetObject = target.GetObject();
		Land_Misc_Toilet_Dry objectToilet = Land_Misc_Toilet_Dry.Cast( targetObject );
		
		switch( targetObject ) {
			case objectToilet:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VOMIT;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_GESTUREFB_SHRUG;
				break;
		}
	}		
}