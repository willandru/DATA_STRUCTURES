//ArbolBinaOrd.h
#ifndef __ARBOLBINARIOORD_H__
#define __ARBOLBINARIOORD_H__

#include "NodoBinario.h"

template <class T>

class ArbolBinaOrd {

    protected:
        NodoBinario<T>* raiz;
    public:
        ArbolBinaOrd();
        ~ArbolBinaOrd();
        bool esVAcio();
        T datoRaiz();
        int altura();
        int tamano();
        bool insertar(T val);
        bool eliminar(T val);
        bool buscar(T val);
        void preOrden();
        void inOrden();
        void posOrden();
        void nivelOrden();
};

#include "ArbolBinarioOrd.hxx"
#endif