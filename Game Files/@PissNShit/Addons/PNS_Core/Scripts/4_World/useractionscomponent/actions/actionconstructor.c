// Script File
modded class ActionTargets {
	private const float c_MaxActionDistance = 5;
};

modded class ActionConstructor {
	override void RegisterActions(TTypenameArray actions) {	
		super.RegisterActions(actions);
		
		action.Insert(ActionWipeBottom); //Action to Wipe Bottom
		action.Insert(ActionWipeBottomNoTP); //Action to Wipe Bottom without Toilet Paper.
	
		action.Insert(ActionFillBottle_PNS); //Action to Fill PNS Gamer Bottle with Pee
		action.Insert(ActionWashHandsWell_PNS); // Action to Wash Pee and Poo off hands at Well
		action.Insert(ActionWashHandsSink_PNS); // Action to Wash Pee and Poo off hands at Sinks
	}
}