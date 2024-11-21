/**
 * @file app.cpp
 * @author
 * @brief Implementacja klasy App obsługującej operacje na liście liczb całkowitych poprzez interaktywne menu.
 * @date 2024-11-13
 *
 * @copyright
 */

#ifdef _WIN32
#include <windows.h>
#endif

#include "app.hpp"
#include "../merge_sorter/merge_sorter.hpp"
#include <array_utils/array_utils.hpp>
#include <random_number_generator/random_number_generator.hpp>

std::istream& operator>>(std::istream& iStream, MenuOption& menuOption) {
  int num;
  iStream >> num;
  menuOption = static_cast<MenuOption>(num);

  return iStream;
}

std::vector<int> App::array;

int App::mainMenu() {
  while (true) {
    std::cout << "MENU:\n\n";

    std::cout << "---ZARZĄDZANIE ELEMENTAMI LISTY---\n";
    std::cout << "1. Dodaj element\n\n";

    std::cout << "---ZARZĄDZANIE LISTĄ---\n";
    std::cout << "2. Wyświetl zawrtość\n";
    std::cout << "3. Wypełnij losowymi elementami\n";
    std::cout << "4. Pomieszaj zawartość\n";
    std::cout << "5. Odwróć kolejność elementów\n";
    std::cout << "6. Posortuj\n";
    std::cout << "7. Wyczyść\n\n";

    std::cout << "---OPCJE---\n";
    std::cout << "8. Wyjdź\n\n";

    std::cout << "Wybierz działanie: ";

    MenuOption selectedOption;

    std::cin >> selectedOption;

    if (selectedOption > EXIT) {
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n\n";
      continue;
    }

    std::cout << std::endl;

    switch (selectedOption) {
    case INSERT_ITEM:
      handleInsertItem();
      break;
    case DISPLAY_ARRAY:
      handleDisplayArray();
      break;
    case GENERATE_RANDOM_ARRAY:
      handleGenerateRandomArray();
      break;
    case SHUFFLE_ARRAY:
      handleShuffleArray();
      break;
    case REVERSE_ARRAY:
      handleReverseArray();
      break;
    case SORT_ARRAY:
      handleSortArray();
      break;
    case CLEAR_ARRAY:
      handleClearArray();
      break;
    case EXIT: {
      return handleExit();
    }
    default:
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n";
    }

    std::cout << "\n";
  }
}


int App::run() {
#ifdef _WIN32
  // enable utf-8 printing on windows
  SetConsoleOutputCP(CP_UTF8);
#endif

  int exitCode = mainMenu();
  return exitCode;
}

void App::handleInsertItem() {
  std::cout << "Podaj wartość: ";
  int value;
  std::cin >> value;

  array.push_back(value);
}

void App::handleDisplayArray() {
  displayArray(array);
}

void App::handleGenerateRandomArray() {
  std::cout << "Podaj ilość elementów: ";
  int count;
  std::cin >> count;

  array.clear();

  for (int i = 0; i < count; ++i) {
    array.push_back(RandomNumberGenerator::getRandomNumber(-99, 99));
  }

  std::cout << "Wygenerowano listę\n";
}

void App::handleShuffleArray() {
  randomlyShuffleArray(array);
  std::cout << "Wymieszano listę\n";
}

void App::handleReverseArray() {
  reverseArray(array);
  std::cout << "Odwrócono listę\n";
}

void App::handleClearArray() {
  array.clear();
  std::cout << "Wyczyszczono listę\n";
}

void App::handleSortArray() {
  array = MergeSorter::sortArray(array);
  std::cout << "Posortowano listę\n";
}

int App::handleExit() {
  std::cout << "Dziękujemy za korzystanie z programu\n";
  return 0;
}
