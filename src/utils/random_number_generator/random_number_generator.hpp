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
