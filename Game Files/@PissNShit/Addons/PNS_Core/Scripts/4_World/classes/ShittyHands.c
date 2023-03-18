class ShittyHands
{
	string m_Materials[2];
	
	const int MATERIAL_TYPE_NORMAL = 0;
	const int MATERIAL_TYPE_SHITTY = 1;

	void ShittyHands( string normal_material, string shitty_material )
	{
		m_Materials[MATERIAL_TYPE_NORMAL] = normal_material;
		m_Materials[MATERIAL_TYPE_SHITTY] = shitty_material;
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