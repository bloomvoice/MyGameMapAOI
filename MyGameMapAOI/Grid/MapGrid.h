#ifndef MAP_GRID_H
#define MAP_GRID_H
#include "../Common/MapCommon.h"
#include <vector>

class CMapGrid
{

public:
	CMapGrid(const MapCommon::StMap & oMap);
	~CMapGrid() = default;

	bool Init();

	uint32_t GetI(uint32_t dwX);
	uint32_t GetJ(uint32_t dwY);

	const std::vector<MapCommon::StCell> & GetArroundCells(const MapCommon::StPos& oPos);
	MapCommon::StCell GetStCell(const MapCommon::StPos & oPos);
	MapCommon::StCell GetStIndexCell(const uint32_t dwI, const uint32_t dwJ);

private:

	uint32_t m_dwWidth = 0;
	uint32_t m_dwLength = 0;
	uint32_t m_dwView = 0;
	uint32_t m_dwLengNum = 0;
	uint32_t m_dwWidNum = 0;


	MapCommon::StMap m_oMap;
	std::vector<MapCommon::StCell> m_vecCells;
	std::vector<MapCommon::StCell> m_vecArroundCells;
};


#include "MapGrid.inl"
#endif //MAP_GRID_H