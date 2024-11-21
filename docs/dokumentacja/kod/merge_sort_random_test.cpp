TEST(TestMergeSorter, SortsLargeArrayWithNegativeAndPositiveDuplicates) {
  std::vector<int> test_array;

  for (int i = 0; i < 500; ++i) {
    test_array.push_back(RandomNumberGenerator::getRandomNumber(-99, 99));
  }

  MergeSorter::sortArray(test_array);

  for (std::vector<int>::size_type i = 0; i < test_array.size() - 1; ++i) {
    ASSERT_LE(test_array[i], test_array[i + 1]);
  }
}
