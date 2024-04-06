//ArbolGeneral.h
#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__

#include "NodoGeneral.h"

template <class T>

class ArbolGeneral {
<<<<<<< HEAD
protected:
    NodoGeneral<T>* raiz;
public:
    ArbolGeneral();
    ArbolGeneral(T val);
    ~ArbolGeneral();
    
    bool esVacio();
    NodoGeneral<T>* obtenerRaiz();
    void fijarRaiz(NodoGeneral<T>* nraiz);
    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    bool buscar(T n);
    unsigned int altura();
    unsigned int tamano();
    void preOrden();
    void posOrden();
    void nivelOrden();

=======
    protected:
        NodoGeneral<T>* raiz;
    public:
        ArbolGeneral();
        ArbolGeneral(T val);
        ~ArbolGeneral();
        bool esVacio();
        NodoGeneral<T>* obtenerRaiz();
        void fijarRaiz(NodoGeneral<T>* nraiz);
        bool insertarNodo(T padre, T n);
        bool eliminarNodo(T n);
        bool buscar(T n);
        unsigned int altura();
        unsigned int tamano();
        void preOrden();
        void posOrden();
        void nivelOrden();
>>>>>>> 605ab8f0e8b0dd8f8a9e420f7530ef90a600479e
};

#include "ArbolGeneral.hxx"

#endif