#include "controlador_juego.h"
#include "menu.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <sstream>

int main() {

  menu::printMenu();
  std::string letras_jugador;
  std::string comando;
  std::vector<std::string> comandoArray;
  //bool string_valido = false;
  bool continueProgram = true;

  menu::printWelcome();
  
/*while(!string_valido){
  std::cout << "Por favor ingrese su tablero: ";
  std::getline(std::cin, letras_jugador);

  string_valido = controlador_juego::vLetras(letras_jugador);

  if (!string_valido) {
    std::cout << "Tablero invalido, intente de nuevo\n";
  }
}*/

  //menu::printMenu();
  
while (continueProgram){
  std::cout << "$ ";
  std::getline(std::cin, comando);
  std::stringstream ss(comando);
  std::string token;

  while(std::getline(ss, token, ' ')){
    comandoArray.push_back(token);
  }

    continueProgram = controlador_juego::vComando(comandoArray);
    comandoArray.clear();
}
  return 0;
}
