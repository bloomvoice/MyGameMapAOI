#include "NineGridAOI.h"
#include <iterator>
#include <chrono>

CNineGridAOI::CNineGridAOI(const MapCommon::StMap& oMap)
	:m_oMapGrid(oMap)
{

}

bool CNineGridAOI::Init()
{
	return true;
}

void CNineGridAOI::EventNotify(const std::vector<Creature>& oCreatures, eEventType eEvent)
{

}

void CNineGridAOI::BroadcastEvent(Creature & oCreature, const std::vector<MapCommon::StCell>& oCells, eEventType eEvent)
{
	switch (eEvent)
	{
	case eEventType::InvalidEvent:

		break;
	case eEventType::Disappear:
		break;
	case eEventType::Move:
		break;
	case eEventType::Appear:
		break;
	case eEventType::Max:
		break;
	default:
		break;
	}
}

bool CNineGridAOI::_Move(Creature& oCreature, const MapCommon::StPos& oToPos)
{
	uint64_t qwStartTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	auto oFromCell = m_oMapGrid.GetStCell(oCreature.GetPos());
	{
		if (!oFromCell.CheckValid())
		{
			return false;
		}
	}

	auto oToCell = m_oMapGrid.GetStCell(oToPos);
	{
		if (!oToCell.CheckValid())
		{
			return false;
		}
	}

	if (MapCommon::IsSameCell(oFromCell , oToCell))
	{
		const auto& oCells = m_oMapGrid.GetArroundCells(oCreature.GetPos());
		BroadcastEvent(oCreature, oCells, eEventType::Move);
		return true;
	}

	const auto & oFromCells = m_oMapGrid.GetArroundCells(oCreature.GetPos());
	const auto& oToCells = m_oMapGrid.GetArroundCells(oToPos);
	{
		if (oFromCells.empty() || oToCells.empty())
		{
			return false;
		}
	}

	const auto funCmp = [](const MapCommon::StCell& left, const MapCommon::StCell& right)
	{
		return left.GetIndex() > right.GetIndex();
	};

	std::vector<MapCommon::StCell> oDiffCells;
	{
		std::set_difference(oFromCells.begin(), oFromCells.end(), oToCells.begin(), oToCells.end(), std::back_inserter(oDiffCells), funCmp);
		BroadcastEvent(oCreature, oDiffCells, eEventType::Disappear);
	}


	std::vector<MapCommon::StCell> oSameCells;
	{
		std::set_intersection(oFromCells.begin(), oFromCells.end(), oToCells.begin(), oToCells.end(), std::back_inserter(oSameCells), funCmp);
		BroadcastEvent(oCreature, oSameCells, eEventType::Move);
	}


	oDiffCells.clear();
	{
		std::set_difference(oToCells.begin(), oToCells.end(), oFromCells.begin(), oFromCells.end(), std::back_inserter(oDiffCells), funCmp);
		BroadcastEvent(oCreature, oSameCells, eEventType::Appear);

	}

	uint64_t qwEndTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	auto qwMoveTime = qwEndTime - qwStartTime;
	//spdlog

	return true;
}