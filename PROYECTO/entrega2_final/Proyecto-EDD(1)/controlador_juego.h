#include "ArbolGeneral.h"
#include "NodoGeneral.h"
#include "puntaje.h"
#include <iostream>
#include <list>
#include <vector>

class controlador_juego {
private:
  static std::list<std::string> diccionario;
  static std::list<std::string> diccionario_inverso;
  static ArbolGeneral<char> arbol;
  static ArbolGeneral<char> arbol_inverso;
  static std::list<std::string> palabras_prefijo;
  static std::list<std::string> palabras_sufijo;
  static puntaje puntajeObject;

public:
  static bool vLetras(std::string letras_jugador);
  static bool vComando(const std::vector<std::string> &strings);
  void inicializarDiccionario(std::string fileName);
  void inicializarDiccionarioInverso(std::string fileName);
  void puntajePalabra(std::string palabra);
  void inicializarArbol(std::string fileName);
  void inicializarArbol(std::string &line, NodoGeneral<char> *nodo);
  void inicializarArbolInverso(std::string fileName);
  void inicializarArbolInverso(std::string &line, NodoGeneral<char> *nodo);
  void palabrasPorPrefijo(std::string prefijo);
  void palabrasPorSufijo(std::string sufijo);
  // ADICIONALES
  std::string invertString(const std::string &str);
  void encontrarPalabras(NodoGeneral<char> *nodo, std::string &palabra,
                         std::vector<std::string> &palabrasEncontradas);
};