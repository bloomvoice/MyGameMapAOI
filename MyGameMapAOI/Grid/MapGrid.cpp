#include "MapGrid.h"



CMapGrid::CMapGrid(const MapCommon::StMap& oMap)
	:m_oMap(oMap)
{
	
}

bool CMapGrid::Init()
{
	if (m_dwLength > MapCommon::HalfMaxIntergral || m_dwWidth > MapCommon::HalfMaxIntergral || m_dwView > MapCommon::HalfMaxIntergral)
	{
		//spdlog
		return false;
	}


	m_dwView = m_oMap.m_dwView;
	{
		m_dwLength = m_oMap.m_dwLength + m_dwView * m_dwView / m_dwView;
		m_dwWidth = m_oMap.m_dwWidth + m_dwView * m_dwView / m_dwView;

		m_dwLengNum = m_dwLength / m_dwView;
		m_dwWidNum = m_dwWidth / m_dwView;
	}

	m_vecArroundCells.clear();
	m_vecCells.clear();
	{
		for (uint32_t dwJ = 0; dwJ < m_dwWidNum; ++dwJ)
		{
			for (uint32_t dwI = 0; dwI < m_dwLengNum; ++dwI)
			{
				uint32_t dwIndex = dwJ * m_dwLengNum + dwI;
				MapCommon::StCell oCell(dwIndex, dwI, dwJ);
				m_vecCells.push_back(oCell);
			}
		}
	}

	return true;
}

MapCommon::StCell CMapGrid::GetStCell(const MapCommon::StPos& oPos)
{
	if (oPos.m_dwX > m_dwLength || oPos.m_dwY > m_dwWidth)
	{
		//spdlog
		//assert
		return MapCommon::StCell(-1, -1, -1);
	}


	uint32_t dwIndexI = oPos.m_dwX / m_dwView;
	uint32_t dwIndexJ = oPos.m_dwY / m_dwView;

	return GetStIndexCell(dwIndexI, dwIndexJ);
}

MapCommon::StCell CMapGrid::GetStIndexCell(const uint32_t dwI, const uint32_t dwJ)
{
	if (dwI > m_dwLengNum || dwJ > m_dwWidNum)
	{
		//spdlog
		//assert
		return MapCommon::StCell(-1, -1, -1);
	}

	uint32_t dwIndex = dwJ * m_dwLength / m_dwView + dwI;

	if (dwIndex >= static_cast<uint32_t>(m_vecCells.size()))
	{
		//spdlog
		//assert
		return MapCommon::StCell(-1, -1, -1);
	}

	return m_vecCells[dwIndex];
}


const std::vector<MapCommon::StCell> & CMapGrid::GetArroundCells(const MapCommon::StPos& oPos)
{
	if (oPos.m_dwX > m_dwLength || oPos.m_dwY > m_dwWidth)
	{
		return m_vecArroundCells;
	}

	m_vecArroundCells.clear();
	uint32_t dwI = GetI(oPos.m_dwX);
	uint32_t dwJ = GetJ(oPos.m_dwY);
	if (dwI > m_dwLengNum || dwJ > m_dwWidNum)
	{
		return m_vecArroundCells;
	}

	uint32_t dwIndex = 0;
	{
		for (uint32_t i = dwI - 1; i <=  dwI + 1; ++i)
		{
			for (uint32_t j = dwJ - 1; j <= dwJ + 1; ++j)
			{
				auto oCell = GetStIndexCell(i, j);
				m_vecArroundCells.push_back(oCell);
			}
		}

	}

	return m_vecArroundCells;
}



