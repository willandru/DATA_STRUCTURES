//Version 2 del main
/*
#include "verificar_juego.h"
#include <iostream>

int main() {

  std::string letras_jugador;
  std::string comando;
  bool string_valido = false;
  int id_menu = 0;

  std::cout << "Bienvenid@ al sistema de apoyo para el juego Scrabble!\n";
input_restart:
  std::cout
      << "Por favor ingrese las letras en su soporte, sin espacios ni comas: ";
  std::getline(std::cin, letras_jugador);

  string_valido = verificar_juego::vLetras(letras_jugador);

  if (!string_valido) {
    std::cout << "Tablero invalido\n";
    goto input_restart;
  }

  verificar_juego::menuPantalla();
  std::cout << "Por favor ingrese una opcion: ";
  std::cin >> id_menu;
  verificar_juego::menuSelect(id_menu);

  return 0;
}*/