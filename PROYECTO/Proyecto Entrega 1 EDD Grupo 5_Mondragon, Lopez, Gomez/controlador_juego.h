#include <iostream>
#include <list>
#include <vector>

class controlador_juego {
  private:
    static std::list<std::string> diccionario;
    static std::list<std::string> diccionario_inverso;
    
  public:
    static bool vLetras (std::string letras_jugador);
    static bool vComando(const std::vector<std::string>& strings);
    void inicializarDiccionario(std::string fileName);
    void inicializarDiccionarioInverso(std::string fileName);
    void puntajePalabra(std::string palabra);

};

// eof controlador_juego.h