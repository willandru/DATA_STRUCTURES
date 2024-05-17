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
    void imprimirVectorVertices();
   
    void insertarArista(T ver1, T ver2, T costo);

    int buscarVertice(T vertice);
    
    T buscarArista(T ver1, T ver2);

    bool eliminarVertice(T vertice);
   
    bool eliminarArista(T ver1, T ver2); 

};

#endif
