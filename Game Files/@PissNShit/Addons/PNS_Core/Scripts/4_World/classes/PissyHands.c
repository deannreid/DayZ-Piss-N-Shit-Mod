class PissyHands
{
	string m_Materials[2];
	
	const int MATERIAL_TYPE_NORMAL = 0;
	const int MATERIAL_TYPE_PISSY = 1;

	void PissyHands( string normal_material, string pissy_material )
	{
		m_Materials[MATERIAL_TYPE_NORMAL] = normal_material;
		m_Materials[MATERIAL_TYPE_PISSY] = pissy_material;
	}

	string GetMaterial( int material_type )
	{
		return m_Materials[material_type];
	}

	void SetMaterial( int material_type, string material )
	{
		m_Materials[material_type] = material;
	}
	
}