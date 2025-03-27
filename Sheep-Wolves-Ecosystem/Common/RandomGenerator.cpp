#include "RandomGenerator.h"
#include <mutex>

RandomGenerator* RandomGenerator::m_pInstance = nullptr;

RandomGenerator::RandomGenerator()
{
    rng.seed(std::random_device{}());
}

RandomGenerator& RandomGenerator::GetInstance()
{
    if (!m_pInstance)
    {
        static std::mutex creationMutex;
        std::lock_guard<std::mutex> lock(creationMutex);
        if (!m_pInstance)
        {
            m_pInstance = new RandomGenerator();
        }
    }
    return *m_pInstance;
}

bool RandomGenerator::GetRandomBool()
{
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(rng);
}

size_t RandomGenerator::GetRandomSizeT(const size_t min, const size_t max)
{
    std::uniform_int_distribution<size_t> distribution(min, max);
    return distribution(rng);
}

int RandomGenerator::GetRandomInt(const int min, const int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}
