/**
 * @file random_number_generator.cpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include<cstdlib>
#include<ctime>

#include <random_number_generator/random_number_generator.hpp>

bool RandomNumberGenerator::isSeeded = false;

void RandomNumberGenerator::seed() {
  if (!isSeeded) {
    std::srand(std::time(NULL));
    isSeeded = true;
  }
}

int RandomNumberGenerator::getRandomNumber(int min, int max) {
  RandomNumberGenerator::seed();

  int range = max - min;
  return std::rand() % range;
}
