//NodoGeneral.h
#ifndef __NODOGENERAL__H__
#define __NODOGENERAL__H__

#include <list>

template <class T>
class NodoGeneral{
    protected:
        T dato;
        std::list<NodoGeneral<T> *> desc;
    public:
        NodoGeneral();
        ~NodoGeneral();
        T& obtenerDato();
        bool fijarDato(T ndato);
        std::list<NodoGeneral<T> *> obtenerDesc();
        bool adicionarDesc(T nHijo);
        
}


#include "NodoGeneral.hxx"

#endif