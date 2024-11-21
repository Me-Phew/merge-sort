/**
 * @file array_utils.hpp
 * @author
 * @brief Deklaracja funkcji narzędziowych do operacji na tablicach liczb całkowitych.
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 */

#ifndef ARRAY_UTILS_HPP
#define ARRAY_UTILS_HPP

#include <vector>

 /// @brief Wyświetla zawartość tablicy na standardowym wyjściu.
 /// 
 /// Funkcja wypisuje każdy element tablicy oddzielony spacją. Jeśli tablica jest pusta,
 /// zostanie wyświetlona odpowiednia informacja.
 /// 
 /// @param array Tablica liczb całkowitych do wyświetlenia.
void displayArray(std::vector<int> array);

/// @brief Tasuje losowo elementy w tablicy.
/// 
/// Funkcja zmienia kolejność elementów w podanej tablicy na losową.
/// Wykorzystuje algorytm tasowania Fishera-Yatesa.
/// 
/// @param array Tablica liczb całkowitych, której elementy mają zostać przetasowane.
void randomlyShuffleArray(std::vector<int>& array);

/// @brief Odwraca kolejność elementów w tablicy.
/// 
/// Funkcja modyfikuje podaną tablicę, zmieniając kolejność jej elementów na odwrotną.
/// 
/// @param array Tablica liczb całkowitych, której elementy mają zostać odwrócone.
void reverseArray(std::vector<int>& array);

#endif /* ARRAY_UTILS_HPP */
