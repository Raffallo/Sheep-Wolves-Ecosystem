#include <iostream>

#include "AnimalsSimulation.h"

int main()
{
    const size_t mapWidth{ 10 };
    const size_t mapHeight{ 10 };
    const size_t sheepCount{ 200 };
    const size_t wolvesCount{ 200 };
    const size_t iterations{ 2 };

    AnimalsSimulation simulation(mapWidth, mapHeight);
    simulation.Run(sheepCount, wolvesCount, iterations);


    std::cout << "Hello World!\n";
}
