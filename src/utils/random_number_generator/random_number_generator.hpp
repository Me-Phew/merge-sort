/**
 * @file random_number_generator.hpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef RANDOM_NUMBER_GENERATOR_HPP
#define RANDOM_NUMBER_GENERATOR_HPP

class RandomNumberGenerator {
private:
  static bool isSeeded;

  /// @brief Inicjalizuje generator liczb losowych.
  static void seed();

public:
  static int getRandomNumber(int min, int max);
};

#endif /* RANDOM_NUMBER_GENERATOR_HPP */
