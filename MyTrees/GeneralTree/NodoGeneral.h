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
        bool fijarDato(T& ndato);
        std::list<NodoGeneral<T> *> obtenerDesc();
        bool adicionarDesc(T& nHijo);
        bool esHoja();
        bool insertarNodo(T padre, T n);
        void preOrden();
        void posOrden();
        bool buscar(T dato);
        bool eliminar(T dato);
        
};


#include "NodoGeneral.hxx"

#endif