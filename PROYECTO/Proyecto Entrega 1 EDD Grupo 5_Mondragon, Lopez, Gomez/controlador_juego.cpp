#include "controlador_juego.h"
#include "puntaje.h"
#include "ayuda.h"
#include <fstream>
#include <iostream>
#include <list>
#include <regex>
#include <string>
#include <vector>


std::list<std::string> controlador_juego::diccionario;
std::list<std::string> controlador_juego::diccionario_inverso;

bool controlador_juego::vLetras(std::string letras_jugador) {
  std::regex letras_regex("^[a-zA-Z]{7}$");
  if (std::regex_match(letras_jugador, letras_regex)) {
    return true;
  }
  return false;
}

bool controlador_juego::vComando(const std::vector<std::string> &strings) {

  ayuda ayudante;
  controlador_juego juegoGlobal;
  std::vector<std::string>::const_iterator it = strings.begin();
  std::string arg1 = *it;
  std::string arg2;

  if (strings.size() >= 2) {
    it++;
    arg2 = *it;
  }
  if (arg1.empty() && arg2.empty()) {
    
      std::cout << "$\n";
    return true;
  }

  else if (arg1 == "iniciar") {
    // COMPONENTE 1.1
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::inicializarDiccionario(arg2);
    } else {
      std::cout << "Modo de uso: inicializar [nombre_del_archivo.txt]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "iniciar_inverso") {
    // COMPONENTE 1.2
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::inicializarDiccionarioInverso(arg2);
    } else {
      std::cout
          << "Modo de uso: iniciar_inverso [nombre_del_archivo.txt]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "puntaje") {
    // COMPONENTE 1.3
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::puntajePalabra(arg2);
    } else {
      std::cout << "Modo de uso: palabra [palabra]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "iniciar_arbol diccionario.txt") {
    // COMPONENTE 2.1
    std::cout << "Comando iniciar arbol no implementado\n";
    return true;
  } else if (arg1 == "iniciar_arbol_inverso diccionario.txt") {
    // COMPONENTE 2.2
    std::cout << "Comando iniciar arbol inverso no implementado\n";
    return true;
  } else if (arg1 == "palabras_por_prefijo prefijo") {
    // COMPONENTE 2.3
    std::cout
        << "Comando palabras por prefijo [prefijo] no implementado\n";
    return true;
  } else if (arg1 == "palabras_por_sufijo sufijo") {
    // COMPONENTE 2.4
    std::cout
        << "Comando palabras por sufijo [sufijo] no implementado\n";
    return true;
  } else if (arg1 == "grafo_de_palabras") {
    // COMPONENTE 3.1
    std::cout << "Comando grafo de palabras no implementado\n";
    return true;
  } else if (arg1 == "posibles_palabras letras") {
    // COMPONENTE 3.2
    std::cout << "Comando posibles palabras [letras] no implementado\n";
    return true;
  } else if (arg1 == "ayuda") {
    if (!arg2.empty()) {
      ayudante.ayuda::printAyudaComando(arg2);
    } else {
      ayudante.ayuda::printAyudaVacio();
    }
    return true;
  } else if (arg1 == "salir") {
    std::cout << "Gracias por usar el sistema de soporte para Scrabble!\n";
    std::cout << "Hasta la proxima!\n";
    return false;
  }

  std::cout << "Comando invalido, intente de nuevo\n";
  return true;
}

// COMPONENTE 1.1
void controlador_juego::inicializarDiccionario(std::string fileName) {
  if (!this->diccionario.empty()) {
    std::cout << "El diccionario ya se encuentra inicializado." << std::endl;
    return;
  }

  //std::cout << "FILENAME: " << fileName << std::endl;
  
  std::regex inValido("[A-Za-z]+");

  std::ifstream inFile(fileName);
  std::list<std::string> lines;

  if (!inFile.is_open()) {
    std::cerr << "Error: El archivo " << fileName
              << " no existe o no puede ser leído." << std::endl;
    return;
  }

  std::string line;
  while (std::getline(inFile, line)) {
    if (std::regex_match(line, inValido)){
      this->diccionario.push_back(line);
      }
  }

  inFile.close();

  if (!this->diccionario.empty()) {
    std::cout << "El diccionario " << fileName
              << " ha sido inicializado correctamente." << std::endl;
  } else {
    std::cerr << "El diccionario " << fileName
              << " no se pudo inicializar correctamente." << std::endl;
    return;
  }

  //for (std::list<std::string>::const_iterator tIt = this->diccionario.begin(); tIt != this->diccionario.end(); tIt++)
  //  {
  //    std::cout << *tIt << std::endl;
  //  }
}

// COMPONENTE 1.2
void controlador_juego::inicializarDiccionarioInverso(std::string fileName) {

  if (!this->diccionario_inverso.empty()) {
    std::cout << "El diccionario inverso " << fileName
              << " ya se encuentra inicializado." << std::endl;
    return;
  }

  std::regex inValido("[A-Za-z]+");

  std::ifstream inFile(fileName);
  std::list<std::string> lines;

  if (!inFile.is_open()) {
    std::cerr << "Error: El archivo " << fileName
              << " no existe o no puede ser leído." << std::endl;
    return;
  }

  std::string line;
  while (std::getline(inFile, line)) {
    lines.push_back(line);
  }

  inFile.close(); // Don't forget to close the file after reading

  for (const std::string& line : lines) {
    std::stack<char> reverseString;
    std::string newLine = "";

    for (size_t i = 0; i < line.length(); i++) {
      reverseString.push(line[i]);
    }

    while (!reverseString.empty()) {
      newLine += reverseString.top();
      reverseString.pop();
    }

    if (std::regex_match(newLine, inValido)) {
      this->diccionario_inverso.push_back(newLine);
    }
  }

  if (!this->diccionario_inverso.empty()) {
    std::cout << "El diccionario inverso " << fileName
              << " ha sido inicializado correctamente." << std::endl;
  } else {
    std::cerr << "El diccionario inverso " << fileName
              << " no se puede inicializar." << std::endl;
    return;
  }

}

void controlador_juego::puntajePalabra(std::string palabra) {

  std::regex inValido("[A-Za-z]+");
  int puntajeRetorno = 0;
  puntaje puntajeObject;
  
  if (!std::regex_match(palabra, inValido)){
    std::cout << "La palabra ingresada contiene simbolos invalidos." << std::endl;
    std::cout << "Por favor intente de nuevo." << std::endl;
    return;
  }
  
  if (this->diccionario_inverso.empty() && this->diccionario.empty()){
    std::cout << "No hay ningun diccionario inicializado en este momento." << std::endl;
    std::cout << "Por favor inicializar algun diccionario antes de continuar." << std::endl;
    return;
  }
  
  if(!this->diccionario_inverso.empty()){
    std::list<std::string>::const_iterator it;
    for (it = diccionario_inverso.begin(); it != diccionario_inverso.end(); it++){
      if (*it == palabra){
        puntajeRetorno = puntajeObject.calcularPuntaje(palabra);
        std::cout << "El puntaje de la palabra " << palabra << " es: " << puntajeRetorno << std::endl;
        return;
      }
    }
  }
  if (!this->diccionario.empty()){
    std::list<std::string>::const_iterator it;
    for (it = diccionario.begin(); it != diccionario.end(); it++){
      if (*it == palabra){
        puntajeRetorno = puntajeObject.calcularPuntaje(palabra);
        std::cout << "El puntaje de la palabra " << palabra << " es: " << puntajeRetorno << std::endl;
        return;
      }
    }
  }

  if (puntajeRetorno == 0){
    std::cout << "La palabra no se encuentra en el diccionario." << std::endl;
    return;
  }

}
