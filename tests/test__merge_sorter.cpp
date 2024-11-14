/**
 * @file test_defaults.cpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include <vector>

#include "merge_sorter.hpp"

TEST(TestMergeSorter, SortsBasicArray) {
  std::vector<int> test_array = { 3, 2, 1 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1, 2, 3));
}
