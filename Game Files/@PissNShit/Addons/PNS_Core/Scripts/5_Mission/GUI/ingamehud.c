modded class IngameHud extends Hud
{
	override void InitBadgesAndNotifiers()
	{
		super.InitBadgesAndNotifiers();
		
		m_StatesWidgetNames.Set( NTFKEY_BLADDER, "Bladder" );	
		m_StatesWidgetNames.Set( NTFKEY_BOWEL, "Bowel" );
		int key = 0;
		for ( int k = 0; k < m_StatesWidgetNames.Count(); k++ )
		{
			string widget_name = m_StatesWidgetNames.GetElement(k);
				key = m_StatesWidgetNames.GetKey(k);
				ImageWidget wgt;
				Class.CastTo(wgt,  m_Notifiers.FindAnyWidget( String( "Icon" + widget_name ) ) );
				m_StatesWidgets.Set( key, wgt );
				wgt.Show( true );			
			if (widget_name == "Bladder" || widget_name == "Bowel")
			{
				for ( int z = 0; z < 5; z++ ) {
					wgt.LoadImageFile( z, "set:PNS_UI image:icon" + widget_name + z );
				}
			}		
			wgt.SetImage( 0 );
			float alpha = wgt.GetAlpha();
			wgt.SetColor( ARGB( alpha * 255, 220, 220, 220 ) );	//white
			m_TendencyStatusCritical.Remove( wgt );
			// clear all arrows
			for ( int x = 1; x < 4; x++ )
			{
				Class.CastTo(wgt,  m_Notifiers.FindAnyWidget( String( widget_name + "ArrowUp" + x.ToString() ) ) );
				wgt.Show( false );
				Class.CastTo(wgt,  m_Notifiers.FindAnyWidget( String( widget_name + "ArrowDown" + x.ToString() ) ) );
				wgt.Show( false );
			}
		}	
	}
}