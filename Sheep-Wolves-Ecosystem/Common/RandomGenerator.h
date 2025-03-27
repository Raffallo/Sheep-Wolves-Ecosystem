#pragma once
#include <random>

class RandomGenerator
{
public:
    static RandomGenerator& GetInstance();

    bool GetRandomBool();
    size_t GetRandomSizeT(const size_t min, const size_t max);
    int GetRandomInt(const int min, const int max);

    RandomGenerator(const RandomGenerator&) = delete;
    RandomGenerator& operator=(const RandomGenerator&) = delete;

private:
    RandomGenerator();

    static RandomGenerator* m_pInstance;
    std::mt19937 rng;
};

