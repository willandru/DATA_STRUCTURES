#include "ayuda.h"
#include <iostream>

void ayuda::printAyudaVacio(){
  std::cout << "Para usar ayuda de un comando especifico, escribir el siguiente comando: " << std::endl;
  std::cout << "ayuda [comando]" << std::endl;
}
void ayuda::printAyudaComando(std::string comando){
  if (comando == "inicializar") {
    std::cout << "Descripcion: carga el diccionario de palabras en el programa" << std::endl;
    std::cout << "Uso: inicializar [nombre_archivo]" << std::endl;
  } else if (comando == "iniciar_inverso") {
    std::cout << "Descripcion: carga el diccionario de palabras en el programa en orden reverso" << std::endl;
    std::cout << "Uso: iniciar_inverso [nombre_archivo]" << std::endl;
  } else if (comando == "puntaje") {
    std::cout << "Descripcion: determina el puntaje de una palabra, esta palabra tiene que existir en el diccionario, que debe de estar previamente inicializado" << std::endl;
    std::cout << "Uso: puntaje [palabra]" << std::endl;
  } else if (comando == "iniciar_arbol diccionario.txt") {
    // COMPONENTE 2.1
    std::cout << "Comando iniciar arbol no implementado\n";

  } else if (comando == "iniciar_arbol_inverso diccionario.txt") {
    // COMPONENTE 2.2
    std::cout << "Comando iniciar arbol inverso no implementado\n";

  } else if (comando == "palabras_por_prefijo prefijo") {
    // COMPONENTE 2.3
    std::cout
        << "Comando palabras por prefijo [prefijo] no implementado\n";

  } else if (comando == "palabras_por_sufijo sufijo") {
    // COMPONENTE 2.4
    std::cout
        << "Comando palabras por sufijo [sufijo] no implementado\n";

  } else if (comando == "grafo_de_palabras") {
    // COMPONENTE 3.1
    std::cout << "Comando grafo de palabras no implementado\n";

  } else if (comando == "posibles_palabras letras") {
    // COMPONENTE 3.2
    std::cout << "Comando posibles palabras [letras] no implementado\n";

  }
}