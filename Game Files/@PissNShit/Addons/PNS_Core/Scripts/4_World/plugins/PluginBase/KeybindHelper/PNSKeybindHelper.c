/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: PNSKeybindHelper.c
 *  
 * Class Information:
 *
 * Class helps with keybinds
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 16/10/2022 - Initial Code Development
 */
typedef Param4<int, UAIDWrapper, Class, string > PNSKeybindParam; // Mode, Wrapper, Class > Method

enum PNSBinds
{
	Press = 2,
	Release = 4, 
	Hold = 8,
	HoldBegin = 16,
	DoubleClick = 32,
	Click = 64,
};

class PNSKeybindHelper: PluginBase
{
	protected static ref PNSKeybindHelper instance;
	protected ref map < int, ref PNSKeybindParam> m_KeyWrappers;
	protected ref ScriptInvoker m_KeyInvokers;
	
	void PNSKeybindHelper()
	{
		instance = this;
		m_KeyWrappers = new map < int, ref PNSKeybindParam>;
		m_KeyInvokers = new ScriptInvoker();
	}
	
	override void OnInit(){
		//GetPNSLogger().WriteDebug("[PNSKeybindHelper] :: Initializing Keybind Helper.");
		Print("[PNS - LogHandler] :: [DEBUG] :: ([PNSKeybindHelper] :: Initializing Keybind Helper.");
	}
	
	override void OnUpdate(float time)
	{
		if (m_KeyWrappers.Count() <= 0){
			return;
		}
	
		foreach(int id, PNSKeybindParam params: m_KeyWrappers)
		{
			if (!params) 
				continue;
			
			typename e = PNSBinds;
			
			for (int bit = 1, i = 0; i < e.GetVariableCount(); i++)
			{
			 bit <<= 1; 
				if (params.param1 & bit)
				{
					bool paramBuild;
					g_Script.CallFunction(params.param2.InputP(), string.Format("Local%1", typename.EnumToString(PNSBinds, bit)), paramBuild, NULL);
					
					if (paramBuild) 
					{
						g_Script.CallFunction(params.param3, params.param4, NULL, NULL,);
					}
				}
			}
		}
	}
	
	map <int, ref PNSKeybindParam> Binds()
	{
		return m_KeyWrappers;
	}
	
	/*
		Register Bind to call function.
		=======
		@Param0: inputName - Name of the UA input defined in inputsSortingHatmaster
		@Param1: mode - Bind Behavior - see enum
		@Param2: callBackFunction - Method to be called on event
		@Param3: endPoint - Instance of callback, Null = Global Call
	*/
	static void RegisterBind(string inputName, PNSBinds mode, string callBackFunc, Class endPoint = NULL)
	{
		UAInput input = GetUApi().GetInputByName(inputName);
		if (input == NULL)
		{
			Print(string.Format("[PNSKeybindHelper] RegisterBind() :: Failed to bind ["+ inputName +"] is an invalid input! check spelling on input name."));
			//GetPNSLogger().WriteDebug("[PNSKeybindHelper] RegisterBind() :: Failed to bind ["+ inputName +"] is an invalid input! check spelling on input name.");
			//Print("[PNSKeybindHelper] RegisterBind() :: Failed to bind ["+ inputName +"] is an invalid input! check spelling on input name.");
			return;
		}
	
		PNSKeybindParam params = new PNSKeybindParam(mode, input.GetPersistentWrapper(), endPoint, callBackFunc);
		PNSKeybindHelper.GetInstance().Binds().Insert(input.ID(), params);
		Print(string.Format("[PNSKeybindHelper] RegisterBind() :: Registered bind: [%1] mode: [%2] callback function: [%3]", inputName, typename.EnumToString(PNSBinds, mode), callBackFunc));
	}
	
	static PNSKeybindHelper GetInstance()
	{
		return instance;
	}
}