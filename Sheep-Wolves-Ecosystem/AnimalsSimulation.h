#pragma once
#include "TiledMap.h"

class AnimalsSimulation
{
public:
    AnimalsSimulation(const size_t mapWidth, const size_t mapHeight);
    ~AnimalsSimulation() = default;

    bool Run(const size_t sheepCount, const size_t wolvesCount, const size_t iterations);

private:
    bool ValidateInput(const size_t sheepCount, const size_t wolvesCount, const size_t iterations) const;

    const size_t m_mapWidth;
    const size_t m_mapHeight;

    void PopulateAnimals(TiledMap& map, const size_t sheepCount, const size_t wolvesCount) const;
    void MoveAnimals(const TiledMap& from, TiledMap& to) const;
    void ResolveIteration(TiledMap& map) const;

    std::vector<TiledMap> m_iterationHistory;// 0 = before iterations
};
