#pragma once
#include <random>

class RandomGenerator {
  public:
    static std::mt19937& get();
    static float randomFloat(float min, float max);
    static int randomInt(int min, int max);
};

