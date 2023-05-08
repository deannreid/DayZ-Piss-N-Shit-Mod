class ActionUseToiletContinuousCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.SHAVE);
	}
};

class ActionUseToiletContinuous: ActionContinuousBase
{	
	void ActionUseToiletContinuous()
	{
		m_CallbackClass = ActionUseToiletContinuousCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DRINKWELL;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Take a Shit in the Well";
	}
		
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{		
		return target.GetObject() && target.GetObject().IsWell();
	}

	override void OnStart(ActionData action_data)
	{
		super.OnStart(action_data);
		
		action_data.m_Player.TryHideItemInHands(true);
	}

	override void OnEnd(ActionData action_data)
	{
		action_data.m_Player.TryHideItemInHands(false);
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		//Print("OnFinishProgressServer");
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
		if(nacdata)
		{
			float amount = UAQuantityConsumed.DRINK;
			action_data.m_Player.Consume(NULL,amount, EConsumeType.ENVIRO_WELL);
		}
		
		if ( action_data.m_Player.HasBloodyHands() && !action_data.m_Player.GetInventory().FindAttachment( InventorySlots.GLOVES ) )
		{
			action_data.m_Player.SetBloodyHandsPenalty();
		}
	}
	
	override void OnEndAnimationLoopServer( ActionData action_data )
	{
		//Print("OnEndAnimationLoopServer");
		if(action_data.m_Player.HasBloodyHands())
		{
			action_data.m_Player.InsertAgent(eAgents.CHOLERA, 1);
		}
	}
};