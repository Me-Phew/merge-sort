/**
 * @file merge_sorter.cpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <vector>

#include "merge_sorter.hpp"

std::vector<int> MergeSorter::merge(std::vector<int> arr, int left, int mid, int right) {

  int leftSize = mid - left + 1;
  int rightSize = right - mid;

  std::vector<int> L(leftSize);
  std::vector<int> M(rightSize);

  // Wypełnienie tablicy L danymi z lewej części głównej tablicy
  for (int i = 0; i < leftSize; i++)
    L[i] = arr[left + i];

  // Wypełnienie tablicy M danymi z prawej części głównej tablicy
  for (int j = 0; j < rightSize; j++)
    M[j] = arr[mid + 1 + j];

  // Pozostawienie bieżących indeksów w podtablicach oraz w głównej tablicy
  int i = 0, j = 0, k = left;

  // Dopóki nie osiągniemy końca jednej z podtablic L lub M,
  // wybieramy mniejszy element z L lub M i umieszcamy go we właściwej pozycji w A[left..right]
  while (i < leftSize && j < rightSize) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // Gdy skończą się elementy w jednej z podtablic L lub M,
  // przenosimy pozostałe elementy do A[left..right]
  while (i < leftSize) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < rightSize) {
    arr[k] = M[j];
    j++;
    k++;
  }

  return arr;
}

std::vector<int> MergeSorter::mergeSort(std::vector<int>& arr, int left, int right) {
  if (left < right) {
    // mid jest punktem, w którym tablica jest dzielona na dwie podtablice
    int mid = left + (right - left) / 2;

    // Wywołujemy rekurencyjnie sortowanie dla lewej i prawej części
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Scalamy posortowane podtablice
    arr = merge(arr, left, mid, right);
  }

  return arr;
}

std::vector<int> MergeSorter::sortArray(std::vector<int>& arr) {
  return mergeSort(arr, 0, (int)arr.size() - 1);
}
