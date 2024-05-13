#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <vector>

template <class T>
class Grafo {
protected:
    std::vector<T> vertices;
    std::vector<std::vector<T>> aristas;
public:
    Grafo();
    ~Grafo();
    std::vector<T> obtenerVertices();
    std::vector<std::vector<T>> obtenerAristas();

    int cantidadVertices();
    int cantidadAristas();

    void insertarVertice(T vertice);
    void imprimirMatrizAdyacencia();
    /*
    void insertarArista(int fila, int columna, T& costo);

    T buscarVertice(T& vertice);
    T buscarArista(int fila, int columna);

    bool eliminarVertice(T& vertice);
    bool eliminarArista(int fila, int columna); 
*/
};

#endif
