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




template<class T>
void Grafo<T>::insertarArista(T vertice1, T vertice2, T costo) {
    // Find the indices of the vertices in the vertices vector
    int index1 = buscarVertice(vertice1);
    int index2 = buscarVertice(vertice2);
    
    // Ensure that both vertices are found
    if (index1 != -1 && index2 != -1) {
        // Update the value in the adjacency matrix at the specified position
        aristas[index1][index2] = costo;
        // Since this is an undirected graph, update the value at the symmetric position as well
        //aristas[index2][index1] = costo;
    } else {
        // Print an error message if any vertex is not found
        std::cerr << "Error: One or both vertices not found." << std::endl;
    }
}



template<class T>
int Grafo<T>::buscarVertice(T vertice) {
    // Iterate through the vertices vector to find the vertex
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i] == vertice) {
            // Return the vertex if found
            return i;
        }   
    }
    // If the vertex is not found, return a default value (0 for int, nullptr for pointers, etc.)
    return -1; // This returns a default-constructed object of type T
}


template<class T>
T Grafo<T>::buscarArista(T vertice1, T vertice2) {
    // Find the indices of the vertices in the vertices vector
    int index1 = buscarVertice(vertice1);
    int index2 = buscarVertice(vertice2);
    
    // Ensure that both vertices are found
    if (index1 != -1 && index2 != -1) {
        // Return the cost of the edge between the vertices from the adjacency matrix
        return aristas[index1][index2];
    } else {
        // Print an error message if any vertex is not found
        std::cerr << "Error: One or both vertices not found." << std::endl;
        // Return a default value (you may choose to handle this differently)
        return T(); // This returns a default-constructed object of type T
    }
}


template<class T>
bool Grafo<T>::eliminarVertice(T vertice) {
    // Find the index of the vertex in the vertices vector
    int index = buscarVertice(vertice);

    // Check if the vertex was found
    if (index != -1) {
        // Remove the vertex from the vertices vector
        vertices.erase(vertices.begin() + index);

        // Remove the corresponding row and column from the adjacency matrix
        aristas.erase(aristas.begin() + index);
        for (int i = 0; i < aristas.size(); ++i) {
            aristas[i].erase(aristas[i].begin() + index);
        }

        // Return true indicating successful removal
        return true;
    } else {
        // Print an error message if the vertex is not found
        std::cerr << "Error: Vertex not found." << std::endl;
        // Return false indicating failure to remove
        return false;
    }
}

template<class T>
bool Grafo<T>::eliminarArista(T vertice1, T vertice2) {
    // Find the indices of the vertices in the vertices vector
    int index1 = buscarVertice(vertice1);
    int index2 = buscarVertice(vertice2);
    
    // Ensure that both vertices are found
    if (index1 != -1 && index2 != -1) {
        // Remove the edge between the vertices by setting the corresponding entry in the adjacency matrix to 0
        aristas[index1][index2] = 0;
        //aristas[index2][index1] = 0; // Since this is an undirected graph, remove the edge in both directions
        
        // Return true indicating successful removal
        return true;
    } else {
        // Print an error message if any vertex is not found
        std::cerr << "Error: One or both vertices not found." << std::endl;
        // Return false indicating failure to remove
        return false;
    }
}


