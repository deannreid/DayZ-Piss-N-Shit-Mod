modded class IngameHud extends Hud
{
	override void InitBadgesAndNotifiers()
	{
		super.InitBadgesAndNotifiers();
		
		m_StatesWidgetNames.Set( NTFKEY_BLADDER, "Bladder" );	
		m_StatesWidgetNames.Set( NTFKEY_BOWEL, "Bowel" );

		int i = 0;
		int key = 0;
		for ( i = 0; i < m_StatesWidgetNames.Count(); i++ ) {
			string widget_name = m_StatesWidgetNames.GetElement(i);
			key = m_StatesWidgetNames.GetKey(i);
			ImageWidget w;
			Class.CastTo(w,  m_Notifiers.FindAnyWidget( String( "Icon" + widget_name ) ) );
			m_StatesWidgets.Set( key, w );
			w.Show( true );
			for ( int y = 0; y < 5; y++ )
			{
				w.LoadImageFile( y, "set:dayz_gui image:icon" + widget_name + y );
			}
			if (widget_name == "Bladder" || widget_name == "Bowel")
			{
				for ( int z = 0; z < 2; z++ ) {
					w.LoadImageFile( y, "set:PNS_UI image:icon" + widget_name + y );
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
	}
}