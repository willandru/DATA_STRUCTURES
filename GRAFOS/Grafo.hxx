#include "Grafo.h"

template<class T>
Grafo<T>::Grafo() {
    vertices.clear();
    aristas.clear();
}

template<class T>
Grafo<T>::~Grafo() {
    vertices.clear();
    aristas.clear();
}

template<class T>
std::vector<T> Grafo<T>::obtenerVertices() {
    return vertices;
}

template<class T>
std::vector<std::vector<T>> Grafo<T>::obtenerAristas() {
    return aristas;
}

template<class T>
int Grafo<T>::cantidadVertices() {
    return vertices.size();
}

template<class T>
int Grafo<T>::cantidadAristas() {
    return aristas.size(); 
}

template<class T>
void Grafo<T>::insertarVertice(T vertice) {
    vertices.push_back(vertice);
    int num_ver = cantidadVertices();

    if (num_ver == 1) {
        // Para el primer vertice
        aristas.push_back(std::vector<T>(1, 0));
    } else {
        // Agrega una nueva fila
        aristas.push_back(std::vector<T>(num_ver-1, 0));

        //Agrega una nueva columna
        for(int i = 0; i < num_ver; ++i){
            aristas[i].push_back(0);
        }
    }
}

template<class T>
void Grafo<T>::imprimirMatrizAdyacencia() {
    std::vector<std::vector<T>> aristas = obtenerAristas();
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < aristas.size(); ++i) {
        for (int j = 0; j < aristas[i].size(); ++j) {
            std::cout << aristas[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



/*
template<class T>
void Grafo<T>::insertarArista(int fila, int columna, T costo) {
    // Insert an edge between the vertices at position (fila, columna) with cost 'costo'
}

template<class T>
T Grafo<T>::buscarVertice(T vertice) {
    // Search for the vertex and return it
}

template<class T>
T Grafo<T>::buscarArista(int fila, int columna) {
    // Return the cost of the edge between the vertices at position (fila, columna)
}

template<class T>
bool Grafo<T>::eliminarVertice(T vertice) {
    // Remove the vertex and update the adjacency matrix or list
}

template<class T>
bool Grafo<T>::eliminarArista(int fila, int columna) {
    // Remove the edge between the vertices at position (fila, columna)
}
*/
