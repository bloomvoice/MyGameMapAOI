#ifndef MAP_COMMON_INL
#define MAP_COMMON_INL

namespace MapCommon
{
	inline StCell::StCell(uint32_t dwIndex, uint32_t dwI, uint32_t dwJ)
		: m_dwIndex(dwIndex)
		, m_dwI(dwI)
		, m_dwJ(dwJ)
	{

	}

	inline uint32_t StCell::GetIndex() const
	{
		return m_dwIndex;
	}

	inline uint32_t StCell::GetI() const
	{
		return m_dwI;
	}

	inline uint32_t StCell::GetJ() const
	{
		return m_dwJ;
	}

	inline bool StCell::CheckValid()
	{
		return (m_dwIndex < HalfMaxIntergral && m_dwI < HalfMaxIntergral && m_dwJ < HalfMaxIntergral);
	}

	inline bool IsSameCell(const StCell& left, const StCell& right)
	{
		return (left.GetIndex() == right.GetI());
	}

}


#endif //MAP_COMMON_INL
