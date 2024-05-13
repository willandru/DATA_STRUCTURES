#include <iostream>
#include "Grafo.hxx"

int main() {
    // Create a new graph
    Grafo<int> grafo;

    // Add vertices 1, 2, 3, and 4
    grafo.insertarVertice(1);
    grafo.insertarVertice(2);
    grafo.insertarVertice(3);
    grafo.insertarVertice(4);

    grafo.imprimirMatrizAdyacencia();

    return 0;
}
