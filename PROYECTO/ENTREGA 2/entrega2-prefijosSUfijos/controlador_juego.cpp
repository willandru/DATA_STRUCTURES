#include "controlador_juego.h"
#include "ArbolGeneral.h"
#include "ayuda.h"
#include "puntaje.h"
#include <fstream>
#include <iostream>
#include <list>
#include <regex>
#include <string>
#include <vector>

std::list<std::string> controlador_juego::diccionario;
std::list<std::string> controlador_juego::diccionario_inverso;
ArbolGeneral<char> controlador_juego::arbol;
ArbolGeneral<char> controlador_juego::arbol_inverso;

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

  if (arg1 == "inicializar") {
    // COMPONENTE 1.1 - R
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::inicializarDiccionario(arg2);
    } else {
      std::cout << "Modo de uso: inicializar [nombre_del_archivo.txt]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "iniciar_inverso") {
    // COMPONENTE 1.2 - R
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::inicializarDiccionarioInverso(arg2);
    } else {
      std::cout << "Modo de uso: iniciar_inverso [nombre_del_archivo.txt]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "puntaje") {
    // COMPONENTE 1.3 - R
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::puntajePalabra(arg2);
    } else {
      std::cout << "Modo de uso: palabra [palabra]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "iniciar_arbol") {
    // COMPONENTE 2.1 - R
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::inicializarArbol(arg2);
      // juegoGlobal.arbol.preOrden();
    } else {
      std::cout << "Modo de uso: iniciar_arbol [nombre_del_archivo.txt]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "iniciar_arbol_inverso") {
    // COMPONENTE 2.2 - R
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::inicializarArbolInverso(arg2);
      // juegoGlobal.arbol_inverso.preOrden();
    } else {
      std::cout
          << "Modo de uso: iniciar_arbol_inverso [nombre_del_archivo.txt]\n";
      std::cout << "Por favor intente de nuevo\n";
    }
    return true;
  } else if (arg1 == "palabras_prefijo") {
    
    // COMPONENTE 2.3
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::palabrasPorPrefijo(arg2);
    } else {
      std::cout << "Comando palabras por prefijo [prefijo] \n";
      std::cout << "Por favor intente de nuevo\n";
    } return true;
    
  } else if (arg1 == "palabras_sufijo") {
    
    // COMPONENTE 2.4
    if (!arg2.empty()) {
      juegoGlobal.controlador_juego::palabrasPorSufijo(arg2);
    } else {
      std::cout << "Comando palabras por sufijo [sufijo] \n";
      std::cout << "Por favor intente de nuevo\n";
    } return true;
    
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
  } else if (arg1 == "reset") {   
    if (!diccionario.empty()) diccionario.clear();
    if (!diccionario_inverso.empty()) diccionario_inverso.clear();
    if (!arbol.esVacio()) arbol.limpiar();
    if (!arbol_inverso.esVacio()) arbol_inverso.limpiar();
    std::cout << "Diccionarios reiniciados\n";
    return true;
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

  // std::cout << "FILENAME: " << fileName << std::endl;

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
    if (std::regex_match(line, inValido)) {
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

  // for (std::list<std::string>::const_iterator tIt =
  // this->diccionario.begin(); tIt != this->diccionario.end(); tIt++)
  //   {
  //     std::cout << *tIt << std::endl;
  //   }
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
  std::string lineInverso;

  while (std::getline(inFile, line)) {
    lineInverso = invertString(line);
    lines.push_back(lineInverso);
  }

  inFile.close();

  std::list<std::string>::iterator it;
  for (it = lines.begin(); it != lines.end(); it++) {
    if (std::regex_match(*it, inValido)) {
      this->diccionario_inverso.push_back(*it);
    }
  }

  if (!this->diccionario_inverso.empty()) {
    std::cout << "El diccionario inverso " << fileName
              << " ha sido inicializado correctamente." << std::endl;
  } else if (this->diccionario_inverso.empty()) {
    std::cerr << "El diccionario inverso " << fileName
              << " no se puedon inicializar." << std::endl;
    return;
  }

  // for (std::list<std::string>::const_iterator tIt =
  // this->diccionario_inverso.begin(); tIt != this->diccionario_inverso.end();
  // tIt++)
  //   {
  //     std::cout << *tIt << std::endl;
  //   }
}

// COMPONENTE 1.3
void controlador_juego::puntajePalabra(std::string palabra) {

  std::regex inValido("[A-Za-z]+");
  int puntajeRetorno = 0;
  puntaje puntajeObject;

  if (!std::regex_match(palabra, inValido)) {
    std::cout << "La palabra ingresada contiene simbolos invalidos."
              << std::endl;
    std::cout << "Por favor intente de nuevo." << std::endl;
    return;
  }

  if (this->diccionario_inverso.empty() && this->diccionario.empty()) {
    std::cout << "No hay ningun diccionario inicializado en este momento."
              << std::endl;
    std::cout << "Por favor inicializar algun diccionario antes de continuar."
              << std::endl;
    return;
  }

  if (!this->diccionario_inverso.empty()) {
    std::list<std::string>::const_iterator it;
    for (it = diccionario_inverso.begin(); it != diccionario_inverso.end();
         it++) {
      if (*it == palabra) {
        puntajeRetorno = puntajeObject.calcularPuntaje(palabra);
        std::cout << "El puntaje de la palabra " << palabra
                  << " es: " << puntajeRetorno << std::endl;
        return;
      }
    }
  } else if (!this->diccionario.empty()) {
    std::list<std::string>::const_iterator it;
    for (it = diccionario.begin(); it != diccionario.end(); it++) {
      if (*it == palabra) {
        puntajeRetorno = puntajeObject.calcularPuntaje(palabra);
        std::cout << "El puntaje de la palabra " << palabra
                  << " es: " << puntajeRetorno << std::endl;
        return;
      }
    }
  }

  if (puntajeRetorno == 0) {
    std::cout << "La palabra no se encuentra en el diccionario." << std::endl;
    return;
  }
}

// COMPONENTE 2.1
void controlador_juego::inicializarArbol(std::string fileName) {

  NodoGeneral<char> *nodoRaiz = new NodoGeneral<char>('+');
  arbol.fijarRaiz(nodoRaiz);

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

  typename std::list<std::string>::iterator it;
  for (it = lines.begin(); it != lines.end(); it++) {
    if (std::regex_match(*it, inValido)) {
      inicializarArbol(*it, arbol.obtenerRaiz());
    }
  }
  if (arbol.esVacio()){
    std::cout << "El arbol no se pudo inicializar correctamente." << std::endl;
  } else {
    std::cout << "El arbol ha sido inicializado correctamente." << std::endl;
  }
  inFile.close();
}

// Mirar palabra por palabra todos sus caracteres uno a uno
// Si caracter i se encuentra en los descendientes del nodo actual, se pasa al
// nodo del caracter i y se repite el paso ahora con el caracter i + 1

void controlador_juego::inicializarArbol(std::string &line,
                                         NodoGeneral<char> *nodo) {

  typename std::list<NodoGeneral<char> *>::iterator it;
  char inChar = line[0];

  for (it = nodo->desc.begin(); it != nodo->desc.end(); it++) {
    if ((*it)->obtenerDato() == inChar) {
      line.erase(0, 1);
      inicializarArbol(line, *it);
      return;
    }
  }

  if (inChar != '\0') {
    nodo->adicionarDesc(inChar);
    line.erase(0, 1);
    inicializarArbol(line, nodo->obtenerDesc().back());
  }
  return;
}

// COMPONENTE 2.2
void controlador_juego::inicializarArbolInverso(std::string fileName) {
  NodoGeneral<char> *nodoRaiz = new NodoGeneral<char>('+');
  arbol_inverso.fijarRaiz(nodoRaiz);

  std::regex inValido("[A-Za-z]+");

  std::ifstream inFile(fileName);
  std::list<std::string> lines;

  if (!inFile.is_open()) {
    std::cerr << "Error: El archivo " << fileName
              << " no existe o no puede ser leído." << std::endl;
    return;
  }

  std::string line;
  std::string inverseLine;
  while (std::getline(inFile, line)) {
    inverseLine = invertString(line);
    lines.push_back(inverseLine);
  }

  //Dejamos la lista inversa en orden alfabetico para poder reducir el tamano del arbol
  lines.sort();
  
  typename std::list<std::string>::iterator it;
  for (it = lines.begin(); it != lines.end(); it++) {
    if (std::regex_match(*it, inValido)) {
      inicializarArbolInverso(*it, arbol_inverso.obtenerRaiz());
    }
  }

  if (arbol_inverso.esVacio()){
    std::cout << "El arbol no se pudo inicializar correctamente." << std::endl;
  } else {
    std::cout << "El arbol ha sido inicializado correctamente." << std::endl;
  }
  
  inFile.close();
}

void controlador_juego::inicializarArbolInverso(std::string &line,
                                                NodoGeneral<char> *nodo) {
  typename std::list<NodoGeneral<char> *>::iterator it;
  char inChar = line[0];

  for (it = nodo->desc.begin(); it != nodo->desc.end(); it++) {
    if ((*it)->obtenerDato() == inChar) {
      line.erase(0, 1);
      inicializarArbol(line, *it);
      return;
    }
  }

  if (inChar != '\0') {
    nodo->adicionarDesc(inChar);
    line.erase(0, 1);
    inicializarArbol(line, nodo->obtenerDesc().back());
  }
  return;
}

//COMPONENTE 2.3
// $ palabrasPorPrefijo prefijo

void controlador_juego::palabrasPorPrefijo(std::string prefijo) {
   
    puntaje puntajeObject;

    if (prefijo.size() < 2) {
        std::cout << "(Prefijo inválido) El prefijo debe tener al menos dos letras." << std::endl;
        return;
    }

    NodoGeneral<char> *nodoPrefijo = arbol.obtenerRaiz();
    for (size_t i = 0; i < prefijo.size(); ++i) {
        char c = prefijo[i];
        bool encontrado = false;
        for (std::list<NodoGeneral<char> *>::iterator it = nodoPrefijo->desc.begin(); it != nodoPrefijo->desc.end(); ++it) {
            if ((*it)->obtenerDato() == c) {
                nodoPrefijo = *it;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "(Prefijo inválido) El prefijo '" << prefijo << "' no pudo encontrarse en el diccionario." << std::endl;
            return;
        }
    }

    std::cout << "(Resultado exitoso) Las palabras que inician con el prefijo '" << prefijo << "' son:" << std::endl;
    std::vector<std::string> palabras;
    encontrarPalabras(nodoPrefijo, prefijo, palabras);
    for (std::vector<std::string>::iterator it = palabras.begin(); it != palabras.end(); ++it) {
        std::cout << *it << " (Longitud: " << it->size() << ", El puntaje es:"<< puntajeObject.calcularPuntaje(*it) << ")" << std::endl;
    }
}


//COMPONENTE 2.4
// $ palabrasPorSufijo sufijo


void controlador_juego::palabrasPorSufijo(std::string sufijo) {

  puntaje puntajeObject;

    if (sufijo.size() < 2) {
        std::cout << "(Sufijo inválido) El sufijo debe tener al menos dos letras." << std::endl;
        return;
    }

    NodoGeneral<char> *nodoSufijo = arbol_inverso.obtenerRaiz();
    for (size_t i = 0; i < sufijo.size(); ++i) {
        char c = sufijo[i];
        bool encontrado = false;
        for (std::list<NodoGeneral<char> *>::iterator it = nodoSufijo->desc.begin(); it != nodoSufijo->desc.end(); ++it) {
            if ((*it)->obtenerDato() == c) {
                nodoSufijo = *it;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "(Sufijo inválido) El sufijo '" << sufijo << "' no pudo encontrarse en el diccionario." << std::endl;
            return;
        }
    }

    std::cout << "(Resultado exitoso) Las palabras que terminan con el sufijo '" << sufijo << "' son:" << std::endl;
    std::vector<std::string> palabras;
    encontrarPalabras(nodoSufijo, sufijo, palabras);
    if (palabras.empty()) {
        std::cout << "No hay palabras que terminen con este sufijo en el diccionario." << std::endl;
    } else {
        for (std::vector<std::string>::iterator it = palabras.begin(); it != palabras.end(); ++it) {
            std::cout << *it << " (Longitud: " << it->size() << ", El puntaje es:"<<  ")" << std::endl;
        }
    }
}


// FUNCIONES DE SOPORTE ADICIONALES
std::string controlador_juego::invertString(const std::string &str) {
  std::string invertedStr = str;
  int length = str.length();
  for (int i = 0; i < length / 2; ++i) {
    char temp = invertedStr[i];
    invertedStr[i] = invertedStr[length - i - 1];
    invertedStr[length - i - 1] = temp;
  }
  return invertedStr;
}

void controlador_juego::encontrarPalabras(NodoGeneral<char> *nodo, std::string &palabra, std::vector<std::string> &palabrasEncontradas) {
    // Si el nodo actual es una hoja, agregamos la palabra completa encontrada a la lista de palabras.
    if (nodo->esHoja()) {
        palabrasEncontradas.push_back(palabra);
        return;
    }

    // Exploramos recursivamente todos los descendientes del nodo actual.
    for (std::list<NodoGeneral<char> *>::iterator it = nodo->desc.begin(); it != nodo->desc.end(); ++it) {
        char c = (*it)->obtenerDato();
        palabra.push_back(c); // Añadimos el carácter del nodo actual a la palabra.
        encontrarPalabras(*it, palabra, palabrasEncontradas);
        palabra.pop_back(); // Deshacemos la adición del carácter para explorar otras ramas.
    }
}
