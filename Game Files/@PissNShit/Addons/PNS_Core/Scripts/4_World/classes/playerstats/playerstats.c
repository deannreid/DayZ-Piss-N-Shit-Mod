modded class PlayerStats
{

	override void GetDebugInfo( array<ref StatDebugObject> objects, int flags )
	{
		
		for(int i = 0; i < m_PlayerStats.Count(); i++)
		{
			m_PlayerStats.Get(i).SerializeValue(objects, flags);
		}
		
	}

	override void GatherAllRecords()
	{
		
		FileHandle file = OpenFile("$profile:StatRecords.log", FileMode.WRITE);
		
		FPrintln(file, "================================================================");
		FPrintln(file," ================== " + m_Player.ToString() +" ================== ");
		FPrintln(file, "================================================================");
		
		for(int i = 0; i < m_PlayerStats.Count(); i++)
		{
			array<PlayerStatRecord> records =  m_PlayerStats.Get(i).GetRecords();
			
			FPrintln(file, m_PlayerStats.Get(i).GetLabel() );
			
			for(int z = 0; z < records.Count(); z++)
			{
				PlayerStatRecord record = records.Get(z);
				string output = record.GetStringOutput();
				FPrintln(file, output);
			}
		}
	}
}