//ArbolGeneral.h
#ifndef __ARBOLGENERAL__H__
#define __ARBOLGENERAL__H__

#include "NodoGeneral.h"


template <class T>
class ArbolGeneral{
    protected:
        NodoGeneral<T>* raiz;
    public:
        ArbolGeneral();
        ~ArbolGeneral();
        NodoGeneral<T>* obtenerRaiz();
        bool fijarRaiz(T ndato);
        bool esVacio();
        int altura();
        int altura(NodoGeneral<T>* nodo);
        bool insertarNodo(T padre, T n);
        bool buscar(T dato);
        bool eliminar(T dato);
        void preOrden();
        void posOrden();
        
        
};


#include "ArbolGeneral.hxx"

#endif