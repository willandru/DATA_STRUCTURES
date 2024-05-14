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

    grafo.insertarArista(1,2,1);
    grafo.insertarArista(1,1,3);

    grafo.imprimirMatrizAdyacencia();

    std::cout<< grafo.buscarVertice(2) << std::endl;

    std::cout<< grafo.buscarArista(2,1) << std::endl;

    grafo.eliminarVertice(2);
    grafo.imprimirMatrizAdyacencia();
    grafo.eliminarArista(1,1);
    grafo.imprimirMatrizAdyacencia();

    return 0;
}
