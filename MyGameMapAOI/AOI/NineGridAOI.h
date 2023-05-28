#ifndef NINE_GRID_AOI_H
#define NINE_GRID_AOI_H
#include "../Common/MapCommon.h"
#include "../Grid/MapGrid.h"


enum class eEventType
{
	 InvalidEvent
	,Disappear
	,Move
	,Appear
	,Max 
};


class Creature
{
public:
	Creature()  = default;
	virtual ~Creature() = default;

	const MapCommon::StPos & GetPos();
private:
	MapCommon::StPos m_oPos;
};



class CNineGridAOI
{
public:
	CNineGridAOI(const MapCommon::StMap& oMap);

	bool Init();

	void EventNotify(const std::vector<Creature>& oCreatures, eEventType eEvent);

	void BroadcastEvent(Creature & oCreature, const std::vector<MapCommon::StCell> & oCells, eEventType eEvent);

private:
	bool _Move(Creature & oCreature, const MapCommon::StPos & oToPos);

	CMapGrid m_oMapGrid;
};

#include "NineGridAOI.inl"

#endif //NINE_GRID_AOI_H

