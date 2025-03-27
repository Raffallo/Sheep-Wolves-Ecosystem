#include "AnimalsSimulation.h"

int main()
{
    const size_t mapWidth{ 10 };
    const size_t mapHeight{ 10 };

    const size_t sheepCount{ 150 };
    const size_t wolvesCount{ 20 };

    const size_t iterations{ 10 };

    AnimalsSimulation simulation(mapWidth, mapHeight);
    simulation.Run(sheepCount, wolvesCount, iterations);
}
