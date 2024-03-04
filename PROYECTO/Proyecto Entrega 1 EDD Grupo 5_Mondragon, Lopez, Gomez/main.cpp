#include "controlador_juego.h"
#include "menu.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <sstream>

int main() {

  std::string letras_jugador;
  std::string comando;
  std::vector<std::string> comandoArray;
  bool string_valido = false;
  bool continueProgram = true;

  menu::printWelcome();
  
  menu::printMenu();
  
while (continueProgram){
  std::cout << "$ ";
  std::getline(std::cin, comando);

   if (comando.empty()) {
      continue; 
    }

  
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
