#include <iostream>
#include "Grafo.hxx"

int main() {
    // Create a new graph
    Grafo<int> grafo;
    grafo.imprimirVectorVertices();
    // Add vertices 1, 2, 3, and 4
    grafo.insertarVertice('A');
    grafo.insertarVertice('B');
    grafo.insertarVertice('C');
    grafo.insertarVertice('D');

    grafo.insertarArista('A','B',1);
    grafo.insertarArista('A','A',3);

    std::cout << " AOLAS " << (grafo.obtenerVertices()).size() ;

    grafo.imprimirMatrizAdyacencia();
    grafo.imprimirVectorVertices();

    std::cout<< grafo.buscarVertice('C') << std::endl;

    std::cout<< grafo.buscarArista('A','A') << std::endl;

    grafo.eliminarVertice('B');
    grafo.imprimirMatrizAdyacencia();
    grafo.eliminarArista('A','A');
    grafo.imprimirMatrizAdyacencia();

    grafo.imprimirVectorVertices();

    return 0;
}
