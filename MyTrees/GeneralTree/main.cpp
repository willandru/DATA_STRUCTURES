//main.cpp
#include <iostream>
#include "ArbolGeneral.h"

int main() {
    // Crear el árbol general
    ArbolGeneral<int> arbol;
    arbol.fijarRaiz(1);
    arbol.insertarNodo(1, 14);
    arbol.insertarNodo(1, 16);
    arbol.insertarNodo(1, 18);
    arbol.insertarNodo(14, 5);
    arbol.insertarNodo(14, 13);
    arbol.insertarNodo(16, 17);
    arbol.insertarNodo(16, 8);
    arbol.insertarNodo(18, 9);
    arbol.insertarNodo(18, 4);
    arbol.insertarNodo(18, 11);
    arbol.insertarNodo(18, 12);
    arbol.insertarNodo(5, 6);
    arbol.insertarNodo(5, 2);
    arbol.insertarNodo(17, 15);
    arbol.insertarNodo(8, 3);
    arbol.insertarNodo(8, 7);
    arbol.insertarNodo(4, 10);
    std::cout << arbol.buscar(6)<<std::endl;
    arbol.eliminar(14);
    std::cout << arbol.buscar(6)<<std::endl;
    

    // Imprimir el árbol en preorden
    std::cout << "Preorden del árbol general: ";
    arbol.preOrden();
    

    return 0;
}
