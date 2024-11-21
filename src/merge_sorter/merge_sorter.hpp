/**
 * @file merge_sorter.hpp
 * @author
 * @brief Deklaracja klasy MergeSorter do sortowania tablicy za pomocą algorytmu merge sort.
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 */

#ifndef MERGE_SORTER_HPP
#define MERGE_SORTER_HPP

#include <vector>

 /// @brief Klasa MergeSorter implementująca algorytm merge sort.
 /// Klasa umożliwia sortowanie tablic liczb całkowitych w porządku rosnącym.
class MergeSorter {
private:
  /// @brief Prywatny konstruktor klasy, aby zapobiec tworzeniu obiektów.
  MergeSorter() = delete;

  /// @brief Usunięty konstruktor kopiujący.
  MergeSorter(const MergeSorter&) = delete;

  /// @brief Usunięty operator przypisania.
  MergeSorter& operator=(const MergeSorter&) = delete;

  /// @brief Łączy dwie części tablicy w jedną posortowaną część.
  /// 
  /// Funkcja odpowiedzialna za scalanie dwóch podtablic w jedną posortowaną część.
  /// Operacja jest wykonywana jako część algorytmu merge sort.
  /// 
  /// @param arr Tablica liczb całkowitych do scalenia.
  /// @param left Lewy indeks podtablicy.
  /// @param mid Środkowy indeks podziału podtablicy.
  /// @param right Prawy indeks podtablicy.
  /// @return Nowa tablica zawierająca scalone i posortowane elementy.
  static std::vector<int> merge(std::vector<int> arr, int left, int mid, int right);

  /// @brief Sortuje podtablicę za pomocą algorytmu merge sort.
  /// 
  /// Funkcja rekursywnie dzieli tablicę na mniejsze części i sortuje je,
  /// wykorzystując funkcję `merge` do scalania.
  /// 
  /// @param arr Tablica liczb całkowitych do posortowania.
  /// @param left Lewy indeks zakresu tablicy do posortowania.
  /// @param right Prawy indeks zakresu tablicy do posortowania.
  /// @return Nowa tablica zawierająca posortowane elementy w zadanym zakresie.
  static std::vector<int> mergeSort(std::vector<int>& arr, int left, int right);

public:
  /// @brief Sortuje całą tablicę liczb całkowitych w porządku rosnącym.
  /// 
  /// Funkcja ta jest głównym punktem wejścia dla użytkownika, który chce posortować tablicę
  /// za pomocą algorytmu merge sort.
  /// 
  /// @param arr Tablica liczb całkowitych do posortowania.
  /// @return Nowa tablica zawierająca posortowane elementy.
  static std::vector<int> sortArray(std::vector<int>& arr);
};

#endif /* MERGE_SORTER_HPP */
