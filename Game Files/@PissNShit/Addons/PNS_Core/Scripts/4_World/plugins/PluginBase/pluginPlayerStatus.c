modded class PluginPlayerStatus extends PluginBase {

	void PluginPlayerStatus() {
		Print("[PNS - PluginManager] :: ([PluginPlayerStatus] :: Initializing PlayerStatus Helper.");
		//m_NotifiersLabel = new multiMap<int, string>; // [key] label
		//m_NotifiersIndexColor = new multiMap<int, int>; // [key] index, color

		//m_NotifiersIcons = new multiMap<int, string>; // [key] iconName
		m_NotifiersIcons.Insert( NTFKEY_BLADDER, "iconBladder" );
		m_NotifiersIcons.Insert( NTFKEY_BOWEL, "iconBowel" );
	}		
}