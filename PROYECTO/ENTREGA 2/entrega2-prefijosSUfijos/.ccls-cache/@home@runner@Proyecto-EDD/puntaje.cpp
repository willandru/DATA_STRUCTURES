#include "puntaje.h"
#include <iostream>

std::vector<std::vector<char>> puntaje::puntajesPorletra;

puntaje::puntaje() {
  if (puntajesPorletra.empty()) {
    puntajesPorletra.push_back({'1', 'E', 'A', 'I', 'O', 'N', 'R',
                                'T', 'L', 'S', 'U', 'e', 'a', 'i',
                                'o', 'n', 'r', 't', 'l', 's', 'u'}); // 1 punto
    puntajesPorletra.push_back({'2', 'D', 'G', 'd', 'g'});           // 2 puntos
    puntajesPorletra.push_back(
        {'3', 'B', 'C', 'M', 'P', 'b', 'c', 'm', 'p'}); // 3 puntos
    puntajesPorletra.push_back(
        {'4', 'F', 'H', 'V', 'W', 'Y', 'f', 'h', 'v', 'w', 'y'}); // 4 puntos
    puntajesPorletra.push_back({'5', 'K', 'k'});                  // 5 puntos
    puntajesPorletra.push_back({'8', 'J', 'X', 'j', 'x'});        // 8 puntos
    puntajesPorletra.push_back({'9', 'Q', 'Z', 'q', 'z'});        // 10 puntos
  }
}

int puntaje::calcularPuntaje(std::string palabra) {

  puntaje puntajeObject = puntaje();
  int puntajeRetorno = 0;
  int puntajeTemporal = 0;
  for (char letra : palabra) {
    for (size_t i = 0; i < puntajesPorletra.size(); i++) {
      for (size_t j = 0; j < puntajesPorletra[i].size(); j++) {
        if (j == 0) {
          puntajeTemporal = puntajesPorletra[i][j] - '0';
          //std::cout << puntajeTemporal << std::endl;
        }
        if (letra == puntajesPorletra[i][j]) {
          puntajeRetorno = puntajeRetorno + puntajeTemporal;
          //std::cout << puntajeRetorno << std::endl;
          //std::cout << letra << " " << puntajesPorletra[i][j] << std::endl;
        }
      }
    }
  }

  return puntajeRetorno;
}