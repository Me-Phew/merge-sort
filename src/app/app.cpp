/**
 * @file app.cpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifdef _WIN32
#include <windows.h>
#endif

#include "app.hpp"
#include "../merge_sorter/merge_sorter.hpp"

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
    std::cout << "3. Posortuj\n";
    std::cout << "4. Wyczyść\n\n";

    std::cout << "---OPCJE---\n";
    std::cout << "5. Wyjdź\n\n";

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
  std::cout << "[";

  for (auto it = array.begin(); it != array.end(); ++it) {
    std::cout << *it;

    if (it != array.end() - 1) {
      std::cout << ", ";
    }
  }

  std::cout << "]\n";
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
