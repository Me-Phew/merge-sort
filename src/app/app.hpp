/**
 * @file app.hpp
 * @author Mateusz Basiaga
 * @brief Plik nagłówkowy aplikacji obsługującej listę elementów z różnymi operacjami na tablicy.
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 */

#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <vector>

 /// @brief Wyliczenie opcji dostępnych w menu.
 /// Definiuje różne operacje, które użytkownik może wybrać w aplikacji.
enum MenuOption {
  INSERT_ITEM = 1,             ///< Dodawanie elementu do tablicy.
  DISPLAY_ARRAY,               ///< Wyświetlanie zawartości tablicy.
  GENERATE_RANDOM_ARRAY,       ///< Generowanie losowej tablicy liczb.
  SHUFFLE_ARRAY,               ///< Tasowanie elementów tablicy.
  REVERSE_ARRAY,               ///< Odwracanie kolejności elementów w tablicy.
  SORT_ARRAY,                  ///< Sortowanie tablicy.
  CLEAR_ARRAY,                 ///< Czyszczenie zawartości tablicy.
  EXIT                         ///< Zakończenie działania aplikacji.
};

/// @brief Przeciążenie operatora >> do wyboru opcji menu.
/// @param iStream Strumień wejściowy.
/// @param menuOption Opcja menu, którą należy ustawić.
/// @return Referencja do strumienia wejściowego.
std::istream& operator>>(std::istream& iStream, MenuOption& menuOption);

/// @brief Klasa reprezentująca aplikację obsługującą listę.
/// Umożliwia operacje takie jak dodawanie, usuwanie i wyświetlanie elementów oraz sortowanie listy poprzez menu.
class App {
private:
  static std::vector<int> array; ///< Tablica przechowująca liczby całkowite.

  /// @brief Konstruktor usunięty, ponieważ klasa zawiera wyłącznie statyczne metody.
  App() = delete;

  /// @brief Usunięty konstruktor kopiujący.
  App(const App&) = delete;

  /// @brief Usunięty operator przypisania.
  App& operator=(const App&) = delete;

  /// @brief Wyświetla główne menu aplikacji i zwraca wybraną opcję.
  /// @return Wybrana opcja menu jako liczba całkowita.
  static int mainMenu();

  /// @brief Obsługuje dodawanie nowego elementu do tablicy.
  /// Użytkownik wprowadza wartość, która zostanie dodana na końcu tablicy.
  static void handleInsertItem();

  /// @brief Wyświetla zawartość tablicy na standardowym wyjściu.
  static void handleDisplayArray();

  /// @brief Generuje losową tablicę liczb całkowitych.
  /// Wartości są losowane w ustalonym zakresie, a istniejąca zawartość tablicy jest nadpisywana.
  static void handleGenerateRandomArray();

  /// @brief Tasuje elementy tablicy w losowej kolejności.
  static void handleShuffleArray();

  /// @brief Odwraca kolejność elementów w tablicy.
  /// Funkcja zmienia miejsca elementów tablicy, aby były w odwrotnej kolejności.
  static void handleReverseArray();

  /// @brief Usuwa wszystkie elementy z tablicy.
  /// Po wykonaniu tej operacji tablica będzie pusta.
  static void handleClearArray();

  /// @brief Sortuje elementy tablicy w porządku rosnącym.
  /// Funkcja wykorzystuje algorytm sortowania przez scalanie (merge sort).
  static void handleSortArray();

  /// @brief Obsługuje zakończenie działania aplikacji.
  /// Wyświetla komunikat końcowy przed wyjściem.
  /// @return Kod wyjścia aplikacji (domyślnie 0).
  static int handleExit();

public:
  /// @brief Uruchamia aplikację.
  /// Wyświetla menu i pozwala użytkownikowi wykonywać operacje na liście.
  /// Kontroluje główną pętlę programu, w której użytkownik wybiera opcje z menu.
  /// @return Kod zakończenia aplikacji.
  static int run();
};

#endif /* APP_HPP */
