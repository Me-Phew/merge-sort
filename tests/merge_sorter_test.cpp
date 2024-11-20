/**
 * @file merge_sorter_test.cpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief Zbiór testów jednostkowych dla klasy MergeSorter.
 *
 * Testy jednostkowe obejmują różne scenariusze sortowania tablic za pomocą algorytmu
 * Merge Sort, w tym przypadki z tablicami już posortowanymi, w odwrotnej kolejności,
 * tablicami losowymi, z powtórzeniami i liczbami ujemnymi.
 *
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 */

#include "gtest/gtest.h"
#include <gmock/gmock-matchers.h>
#include <vector>

#include "merge_sorter.hpp"
#include "random_number_generator.hpp"

 /**
  * @brief Testuje, czy już posortowana tablica pozostaje niezmieniona po sortowaniu.
  */
TEST(TestMergeSorter, KeepsAlreadySortedArrayIntact) {
  std::vector<int> test_array = { 1, 2, 3, 4, 5, 7, 8, 9 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1, 2, 3, 4, 5, 7, 8, 9));
}

/**
 * @brief Testuje, czy tablica posortowana w odwrotnej kolejności zostaje poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsArrayAlreadySortedInReverseOrder) {
  std::vector<int> test_array = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1, 2, 3, 4, 5, 6, 7, 8, 9));
}

/**
 * @brief Testuje, czy losowa tablica jest poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsRandomArray) {
  std::vector<int> test_array;

  for (int i = 0; i < 25; ++i) {
    test_array.push_back(RandomNumberGenerator::getRandomNumber(-99, 99));
  }

  MergeSorter::sortArray(test_array);

  for (int i = 0; i < test_array.size() - 1; ++i) {
    ASSERT_LE(test_array[i], test_array[i + 1]);
  }
}

/**
 * @brief Testuje, czy tablica z liczbami ujemnymi zostaje poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsArrayWithNegativeNumbers) {
  std::vector<int> test_array = { -1, -2, -6, -4, -5, -2, -8, -9 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(-9, -8, -6, -5, -4, -2, -2, -1));
}

/**
 * @brief Testuje, czy tablica z liczbami dodatnimi i ujemnymi zostaje poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsArrayWithNegativeAndPositiveNumbers) {
  std::vector<int> test_array = { -1, -2, 6, 4, 5, 2, -8, -9 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(-9, -8, -2, -1, 2, 4, 5, 6));
}

/**
 * @brief Testuje, czy pustą tablicę można posortować bez rzucania wyjątku.
 */
TEST(TestMergeSorter, HandlesEmptyArrayWithoutThrowingAnException) {
  std::vector<int> test_array = { };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre());
}

/**
 * @brief Testuje, czy tablica z jednym elementem pozostaje niezmieniona po sortowaniu.
 */
TEST(TestMergeSorter, KeeepArrayWithOneElementIntact) {
  std::vector<int> test_array = { 1 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1));
}

/**
 * @brief Testuje, czy tablica z duplikatami zostaje poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsArrayWithDuplicates) {
  std::vector<int> test_array = { 1, 2, 3, 4, 5, 7, 8, 9, 1, 2, 3, 4, 5, 7, 8, 9 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 7, 7, 8, 8, 9, 9));
}

/**
 * @brief Testuje, czy tablica z duplikatami liczb ujemnych zostaje poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsArrayWithNegativeDuplicates) {
  std::vector<int> test_array = { -1, -2, -6, -4, -5, -2, -8, -9, -1, -2, -6, -4, -5, -2, -8, -9 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(-9, -9, -8, -8, -6, -6, -5, -5, -4, -4, -2, -2, -2, -2, -1, -1));
}

/**
 * @brief Testuje, czy tablica z duplikatami liczb dodatnich i ujemnych zostaje poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsArrayWithPositiveAndNegativeDuplicates) {
  std::vector<int> test_array = { -1, -2, 6, 4, 5, 2, -8, -9, -1, -2, 6, 4, 5, 2, -8, -9 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(-9, -9, -8, -8, -2, -2, -1, -1, 2, 2, 4, 4, 5, 5, 6, 6));
}

/**
 * @brief Testuje, czy tablica z dwoma elementami jest poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsArrayWithTwoElements) {
  std::vector<int> test_array = { 2, 1 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1, 2));
}

/**
 * @brief Testuje, czy bardzo duża tablica jest poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsLargeArray) {
  std::vector<int> test_array;

  for (int i = 200; i > 0; --i) {
    test_array.push_back(i);
  }

  MergeSorter::sortArray(test_array);

  for (int i = 0; i < test_array.size() - 1; ++i) {
    ASSERT_LE(test_array[i], test_array[i + 1]);
  }
}

/**
 * @brief Testuje, czy duża tablica z liczbami dodatnimi i ujemnymi z duplikatami jest poprawnie posortowana.
 */
TEST(TestMergeSorter, SortsLargeArrayWithNegativeAndPositiveDuplicates) {
  std::vector<int> test_array;

  for (int i = 0; i < 500; ++i) {
    test_array.push_back(RandomNumberGenerator::getRandomNumber(-99, 99));
  }

  MergeSorter::sortArray(test_array);

  for (int i = 0; i < test_array.size() - 1; ++i) {
    ASSERT_LE(test_array[i], test_array[i + 1]);
  }
}

/**
 * @brief Testuje, czy tablica z jednym powtarzającym się elementem pozostaje niezmieniona po sortowaniu.
 */
TEST(TestMergeSorter, KeepsArrayWithSingleRepeatingElementIntact) {
  std::vector<int> test_array = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1, 1, 1, 1, 1, 1, 1, 1, 1, 1));
}

/**
 * @brief Testuje, czy tablica z jednym powtarzającym się elementem ujemnym pozostaje niezmieniona po sortowaniu.
 */
TEST(TestMergeSorter, KeepsArrayWithSingleNegativeRepeatingElementIntact) {
  std::vector<int> test_array = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1));
}
