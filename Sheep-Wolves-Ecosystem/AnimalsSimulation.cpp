#include "AnimalsSimulation.h"
#include <exception>
#include <iostream>
#include <string>
#include "Common/RandomGenerator.h"

AnimalsSimulation::AnimalsSimulation(const size_t mapWidth, const size_t mapHeight)
	: m_mapWidth(mapWidth), m_mapHeight(mapHeight)
{
	
}

bool AnimalsSimulation::Run(const size_t sheepCount, const size_t wolvesCount, const size_t iterations) try
{
	m_iterationHistory.clear();

	if (!ValidateInput(sheepCount, wolvesCount, iterations))
		return false;

	m_iterationHistory.resize(iterations + 1, TiledMap(m_mapWidth, m_mapHeight));

	PopulateAnimals(m_iterationHistory[0], sheepCount, wolvesCount);
	//In the start round, animals remain idle—no eating or reproduction occurs.

	for (size_t i = 1; i <= iterations; i++)//0 = starting
	{
		MoveAnimals(m_iterationHistory[i - 1], m_iterationHistory[i]);
	}

	return true;
}
catch (const std::exception& e)
{
	std::cerr << "Cannot do simulation: " << e.what() << std::endl;
	return false;
}

bool AnimalsSimulation::ValidateInput(const size_t sheepCount, const size_t wolvesCount, const size_t iterations) const
{
	if (m_mapWidth < 10 || m_mapHeight < 10)
	{
		std::cerr << "Map size should be at least 10x10 tiles" << std::endl;
		return false;
	}

	if (sheepCount < 2)
	{
		std::cerr << "Sheep count shouldn't be smaller than 2" << std::endl;
		return false;
	}

	if (wolvesCount < 2)
	{
		std::cerr << "Wolves count shouldn't be smaller than 2" << std::endl;
		return false;
	}

	if (iterations < 2)
	{
		std::cerr << "Iterations count shouldn't be smaller than 2" << std::endl;
		return false;
	}

	return true;
}

void AnimalsSimulation::PopulateAnimals(TiledMap& map, const size_t sheepCount, const size_t wolvesCount) const
{
	if (map.m_cellsData.empty())
		return;

	auto& randomGenerator = RandomGenerator::GetInstance();
	for (size_t i = 0; i < sheepCount; i++)
	{
		const size_t currentIdx = randomGenerator.GetRandomSizeT(0, map.m_cellsData.size() - 1);
		const size_t isCurrentMan = randomGenerator.GetRandomBool();
		map.m_cellsData[currentIdx].sheepVect.emplace_back(isCurrentMan);
	}

	for (size_t i = 0; i < wolvesCount; i++)
	{
		const size_t currentIdx = randomGenerator.GetRandomSizeT(0, map.m_cellsData.size() - 1);
		const size_t isCurrentMan = randomGenerator.GetRandomBool();
		map.m_cellsData[currentIdx].wolvesVect.emplace_back(isCurrentMan);
	}
}

void AnimalsSimulation::MoveAnimals(const TiledMap& from, TiledMap& to) const
{
	if (from.m_cellsData.size() != to.m_cellsData.size())
		return;

	auto& randomGenerator = RandomGenerator::GetInstance();
	const auto GetNewIdx = [&](const size_t cellIdx) -> size_t
		{
			const int dx = randomGenerator.GetRandomInt(-1, 1);
			const int dy = randomGenerator.GetRandomInt(-1, 1);

			const size_t newCellIdx = from.IdxMoveBy(cellIdx, dx, dy);
			if (newCellIdx == TiledMap::invalidIdx)
				throw std::exception("Internal error");//shouldn't happen

			return newCellIdx;
		};

	for (size_t cellIdx = 0; cellIdx < from.m_cellsData.size(); cellIdx++)
	{
		const auto& cellData = from.m_cellsData[cellIdx];

		for (const auto& animal : cellData.sheepVect)
		{
			to.m_cellsData[GetNewIdx(cellIdx)].sheepVect.emplace_back(animal);
		}
		for (const auto& animal : cellData.wolvesVect)
		{
			to.m_cellsData[GetNewIdx(cellIdx)].wolvesVect.emplace_back(animal);
		}
	}
}

void AnimalsSimulation::ResolveIteration(TiledMap& map) const
{
	if (map.m_cellsData.empty())
		return;

}
