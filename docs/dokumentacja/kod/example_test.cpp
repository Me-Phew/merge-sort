TEST(TestMergeSorter, KeepsAlreadySortedArrayIntact) {
  std::vector<int> test_array = { 1, 2, 3, 4, 5, 7, 8, 9 };
  MergeSorter::sortArray(test_array);

  ASSERT_THAT(test_array, testing::ElementsAre(1, 2, 3, 4, 5, 7, 8, 9));
}
