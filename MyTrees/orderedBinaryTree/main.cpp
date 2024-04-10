//main.cpp
#include <iostream>
#include "ArbolBinarioOrd.h"

int main() {
    // Crear el árbol general
    ArbolBinarioOrd<int> arbol;
    arbol.fijarRaiz(25);
    arbol.insertar(20);
    arbol.insertar(36);
    arbol.insertar(10);
    arbol.insertar(22);
    arbol.insertar(30);
    arbol.insertar(40);
    arbol.insertar(5);
    arbol.insertar(12);
    arbol.insertar(1);
    arbol.insertar(8);
    arbol.insertar(15);
    arbol.insertar(28);
    arbol.insertar(38);
    arbol.insertar(48);
    arbol.insertar(45);
    arbol.insertar(50);
 
    arbol.preOrden();
    std::cout << arbol.buscar(10)<<std::endl;
    arbol.eliminar(10);
    std::cout << arbol.buscar(10)<<std::endl;
    

    // Imprimir el árbol en preorden
    std::cout << "Preorden del árbol general: ";
    arbol.preOrden();
    

    return 0;
}
