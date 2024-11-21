/**
 * @file main.cpp
 * @author Mateusz Basiaga (basmateusz@wp.pl)
 * @brief Punkt wejścia do aplikacji.
 *
 * Funkcja `main` uruchamia główną aplikację, wywołując metodę `run()` klasy `App`,
 * która odpowiedzialna jest za obsługę interaktywnego menu i wykonywanie operacji
 * na liście elementów.
 *
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 */

#include "app/app.hpp"

 /**
  * @brief Funkcja główna programu.
  *
  * Funkcja wywołuje metodę `App::run()`, która uruchamia aplikację i umożliwia użytkownikowi
  * wykonywanie operacji na tablicy liczb całkowitych przez interaktywne menu.
  *
  * @return Kod zakończenia aplikacji (0 - sukces).
  */
int main() {
  return App::run(); ///< Uruchamia aplikację
}
