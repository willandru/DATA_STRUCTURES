//ArbolGeneral.h
#ifndef __ARBOLGENERAL__H__
#define __ARBOLGENERAL__H__

#include "NodoGeneral.h"


template <class T>
class ArbolGeneral{
    protected:
        NodoGeneral<T>* raiz;
    public:
        ArbolGeneral(T n);
        ~ArbolGeneral();
        NodoGeneral<T>* obtenerRaiz();
        bool fijarRaiz(T ndato);
        bool insertarNodo(T padre, T n);
        void preOrden();
}


#include "ArbolGeneral.hxx"

#endif