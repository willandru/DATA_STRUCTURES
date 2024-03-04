#include "menu.h"
#include <iostream>

void menu::printWelcome(){
  std::cout << "Bienvenid@ al sistema de apoyo para el juego Scrabble!\n\n";
}
void menu::printMenu(){
  std::cout << "Estos son los comandos disponibles: \n";
  std::cout << "1. iniciar\n";
  std::cout << "2. iniciar_inverso\n";
  std::cout << "3. puntaje\n";
  std::cout << "4. iniciar_arbol\n";
  std::cout << "5. iniciar_arbol_inverso\n";
  std::cout << "6. palabras_por_prefijo\n";
  std::cout << "7. palabras_por_sufijo\n";
  std::cout << "8. grafo de_palabras\n";
  std::cout << "9. posibles_palabras\n";
  std::cout << "10. Ayuda\n";
  std::cout << "11. Salir\n";
}
