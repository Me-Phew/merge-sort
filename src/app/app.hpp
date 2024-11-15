/**
 * @file app.hpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <vector>

 /// @brief Wyliczenie opcji dostępnych w menu.
 /// Definiuje różne operacje, które użytkownik może wybrać w aplikacji.
enum MenuOption {
  INSERT_ITEM = 1,

  DISPLAY_ARRAY,
  GENERATE_RANDOM_ARRAY,
  SHUFFLE_ARRAY,
  REVERSE_ARRAY,
  SORT_ARRAY,
  CLEAR_ARRAY,

  EXIT                        ///< Zakończenie działania aplikacji.
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
  static std::vector<int> array;

  App() = delete;
  App(const App&) = delete;
  App& operator=(const App&) = delete;

  /// @brief Wyświetla główne menu aplikacji i zwraca wybraną opcję.
  /// @return Wybrana opcja menu.
  static int mainMenu();

  static void handleInsertItem();

  static void handleDisplayArray();

  static void handleGenerateRandomArray();

  static void handleShuffleArray();

  static void handleReverseArray();

  static void handleClearArray();

  static void handleSortArray();

  /// @brief Obsługuje zakończenie działania aplikacji.
  /// @return Kod wyjścia z aplikacji.
  static int handleExit();

public:
  /// @brief Uruchamia aplikację.
  /// Wyświetla menu i pozwala użytkownikowi wykonywać operacje na liście.
  /// @return Kod zakończenia aplikacji.
  static int run();
};

#endif /* APP_HPP */
