#ifndef MERGE_SORTER_HPP
#define MERGE_SORTER_HPP

#include <vector>

class MergeSorter {
private:
  MergeSorter() = delete;
  MergeSorter(const MergeSorter&) = delete;
  MergeSorter& operator=(const MergeSorter&) = delete;

  static std::vector<int> merge(std::vector<int> arr, int left, int mid, int right);
  static std::vector<int> mergeSort(std::vector<int>& arr, int left, int right);

public:
  static std::vector<int> sortArray(std::vector<int>& arr);
};

#endif /* MERGE_SORTER_HPP */
