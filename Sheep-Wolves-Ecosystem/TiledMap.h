#pragma once
#include "CellData.h"

class TiledMap
{
public:
    TiledMap(const size_t mapWidth, const size_t mapHeight);
    ~TiledMap() = default;
    
    size_t PosToIdx(const size_t x, const size_t y) const;
    size_t IdxMoveBy(const size_t idx, const int dx, const int dy) const;
    std::pair<size_t, size_t> IdxToPos(const size_t idx) const;

    static size_t invalidIdx;

    const size_t m_mapWidth;
    const size_t m_mapHeight;

    std::vector<CellData> m_cellsData;
};
