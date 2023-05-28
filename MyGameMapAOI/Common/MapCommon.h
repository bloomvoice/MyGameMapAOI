#ifndef MAP_COMMON_H
#define MAP_COMMON_H
#include <cstdint>
#include <algorithm>

namespace MapCommon
{
	static constexpr uint32_t HalfMaxIntergral = static_cast<uint32_t>(static_cast<uint32_t>(~0) >> 1);

	struct StMap
	{
		uint32_t m_dwMapId = 0;
		uint32_t m_dwLength = 0;
		uint32_t m_dwWidth = 0;
		uint32_t m_dwView = 0;
	};

	struct StCell
	{
		StCell(uint32_t dwIndex, uint32_t dwI, uint32_t dwJ);
		bool CheckValid();

		uint32_t GetIndex() const;
		uint32_t GetI() const;
		uint32_t GetJ() const;

		uint32_t m_dwIndex = 0;
		uint32_t m_dwI = 0;
		uint32_t m_dwJ = 0;
	};

	enum class eCreatureType
	{
		  Player
		, Monster
		, NPC
		, Max
	};

	struct StPos
	{
		uint32_t m_dwX = 0;
		uint32_t m_dwY = 0;
	};

	bool IsSameCell(const StCell & left, const StCell& right);

}

#include "MapCommon.inl"

#endif // !MAP_COMMON_H

