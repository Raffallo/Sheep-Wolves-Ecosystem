#include "TiledMap.h"
#include <numeric>

size_t TiledMap::invalidIdx = std::numeric_limits<size_t>::max();

TiledMap::TiledMap(const size_t mapWidth, const size_t mapHeight)
	: m_mapWidth(mapWidth), m_mapHeight(mapHeight)
	, m_cellsData(mapWidth * mapHeight)
{

}

size_t TiledMap::PosToIdx(const size_t x, const size_t y) const
{
	if (x >= m_mapWidth || y >= m_mapHeight)
		return invalidIdx;

	return x * m_mapWidth + y;
}

size_t TiledMap::IdxMoveBy(const size_t idx, const int dx, const int dy) const
{
    if (idx >= m_cellsData.size())
        return invalidIdx;

    auto [x, y] = IdxToPos(idx);

    if (!(x == 0 && dx < 0) && !(x + 1 >= m_mapWidth && dx > 0))
    {
        x += dx;
    }

    if (!(y == 0 && dy < 0) && !(y + 1 >= m_mapHeight && dy > 0))
    {
        y += dy;
    }

    return PosToIdx(x, y);
}

std::pair<size_t, size_t> TiledMap::IdxToPos(const size_t idx) const
{
    if (idx >= m_cellsData.size())
        return { invalidIdx, invalidIdx };

    return { idx / m_mapWidth, idx % m_mapWidth };
}
