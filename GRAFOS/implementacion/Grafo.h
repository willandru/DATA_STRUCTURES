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
    void insertarArista(T ver1, T ver2, T costo);
    
    void imprimirMatrizAdyacencia();
    void imprimirVectorVertices();
   
    

    int buscarVertice(T vertice);
    
    T buscarCostoArista(T ver1, T ver2);

    bool eliminarVertice(T vertice);
   
    bool eliminarArista(T ver1, T ver2); 

};

#endif
