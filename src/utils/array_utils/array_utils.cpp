/**
 * @file array_utils.cpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief Implementacja funkcji pomocniczych do operacji na tablicach liczb całkowitych.
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 */

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

void displayArray(std::vector<int> arr) {
  std::cout << "[";

  for (auto it = arr.begin(); it != arr.end(); ++it) {
    std::cout << *it;

    if (it != arr.end() - 1) {
      std::cout << ", ";
    }
  }

  std::cout << "]\n";
}

void randomlyShuffleArray(std::vector<int>& arr) {
  std::random_device randomDevice;
  std::mt19937 generator(randomDevice());

  std::shuffle(arr.begin(), arr.end(), generator);
}

void reverseArray(std::vector<int>& arr) {
  for (int i = 0; i < arr.size() / 2; i++) {
    //std::swap(arr[i], arr[arrSize - i - 1]);
    int temp = arr[i];

    int swappedElementIndex = arr.size() - i - 1;
    arr[i] = arr[swappedElementIndex];
    arr[swappedElementIndex] = temp;
  }
}
