#include "random_generator.h"

std::mt19937& RandomGenerator::get() {
  static std::mt19937 gen(std::random_device{}());
  return gen;
}

float RandomGenerator::randomFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(get());
}

int RandomGenerator::randomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(get());
}
