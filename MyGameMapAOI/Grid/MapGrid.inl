#ifndef MAP_GRID_INl
#define MAP_GRID_INL

inline uint32_t CMapGrid::GetI(uint32_t dwX)
{
	if (dwX > MapCommon::HalfMaxIntergral)
	{
		//spdlog
		return -1;
	}
	return dwX / m_dwView;
}

inline uint32_t CMapGrid::GetJ(uint32_t dwY)
{
	if (dwY > MapCommon::HalfMaxIntergral)
	{
		//spdlog
		return -1;
	}

	return dwY / m_dwView;
}

#endif //MAP_GRID_INL