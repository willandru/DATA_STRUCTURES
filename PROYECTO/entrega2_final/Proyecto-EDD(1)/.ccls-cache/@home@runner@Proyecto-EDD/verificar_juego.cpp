#include "verificar_juego.h"
#include <iostream>
#include <regex>

bool verificar_juego::vLetras(std::string letras_jugador) {
  std::regex letras_regex("^[a-zA-Z]{7}$");
  if (std::regex_match(letras_jugador, letras_regex)) {
    return true;
  }
  return false;
}

bool verificar_juego::vComando(std::string comando) {
  if (comando == "inicializar diccionario.txt") {
    std::cout << "Comando inicializar ejecutado correctamente\n";
    return true;
  } else if (comando == "iniciar_inverso diccionario.txt") {
    std::cout << "Comando iniciar_inverso ejecutado correctamente\n";
    return true;
  } else if (comando == "puntaje palabra") {
    std::cout << "Comando puntaje palabra ejecutado correctamente\n";
    return true;
  } else if (comando == "salir") {
    std::cout << "Comando salir ejecutado correctamente\n";
    return true;
  } else if (comando == "iniciar_arbol diccionario.txt") {
    std::cout << "Comando iniciar arbol ejecutado correctamente\n";
    return true;
  } else if (comando == "iniciar_arbol_inverso diccionario.txt") {
    std::cout << "Comando iniciar arbol inverso ejecutado correctamente\n";
    return true;
  } else if (comando == "palabras_por_prefijo prefijo") {
    // Requiere de una segunda capa de verificacion para el prefijo
    std::cout
        << "Comando palabras por prefijo [prefijo] ejecutado correctamente\n";
    return true;
  } else if (comando == "palabras_por_sufijo sufijo") {
    // Requiere de una segunda capa de verificacion para el sufijo
    std::cout
        << "Comando palabras por sufijo [sufijo] ejecutado correctamente\n";
    return true;
  } else if (comando == "grafo_de_palabras") {
    std::cout << "Comando grafo de palabras ejecutado correctamente\n";
    return true;
  } else if (comando == "posibles_palabras letras") {
    // Requiere traer las letras del jugador
    std::cout << "Comando posibles palabras [letras] ejecutado correctamente\n";
    return true;
  }

  return false;
}

