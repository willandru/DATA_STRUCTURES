#include <iostream>
#include <vector>

class puntaje {
  private: 
    static std::vector<std::vector <char> > puntajesPorletra;
  public:
  puntaje ();
  static int calcularPuntaje(std::string palabra);
};


//eof  puntaje.h