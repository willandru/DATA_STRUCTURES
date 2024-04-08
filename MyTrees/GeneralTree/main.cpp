#include <iostream>
#include "ArbolGeneral.h"

int main() {
    // Crear el árbol general
    ArbolGeneral<int> arbol(3);
    arbol.insertarNodo(3, 1);
    arbol.insertarNodo(3, 2);
    arbol.insertarNodo(3, 4);
    arbol.insertarNodo(3, 5);
    arbol.insertarNodo(1, 5);
    arbol.insertarNodo(2, 6);
    arbol.insertarNodo(4, 7);

    // Imprimir el árbol en preorden
    std::cout << "Preorden del árbol general: ";
    arbol.preOrden();
    std::cout << std::endl;

    return 0;
}
