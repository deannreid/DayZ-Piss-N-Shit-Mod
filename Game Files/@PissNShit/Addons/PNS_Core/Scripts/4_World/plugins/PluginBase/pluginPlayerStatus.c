modded class PluginPlayerStatus extends PluginBase {
	void PluginPlayerStatus() {
		Print("[PNS - PluginManager] :: ([PluginPlayerStatus] :: Initializing PlayerStatus Helper.");
		m_NotifiersIcons.Insert( NTFKEY_BLADDER, "iconBladder" );
		m_NotifiersIcons.Insert( NTFKEY_BOWEL, "iconBowel" );
	}		
}