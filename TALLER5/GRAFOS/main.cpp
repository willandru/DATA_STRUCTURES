#include <iostream>
#include "Grafo.hxx"
#include "Point.hxx"

int main() {
    // Create a new graph
    Grafo<int> grafo;

    Point<double> puntoA;
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

    puntoA.setX(2.1);
    puntoA.setY(2.2);
    puntoA.setZ(3.5);
    puntoA.imprimirPunto(); 
    return 0;
}
