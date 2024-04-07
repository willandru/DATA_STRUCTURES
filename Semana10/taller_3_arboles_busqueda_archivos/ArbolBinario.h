//ArbolBinario.h
#ifndef __ARBOLBINARIO_H__
#define __ARBOLBINARIO_H__

#include "NodoBinario.h"

template <class T> class ArbolBinario{
    protected:
        NodoBinario<T> *raiz;
    private:
        ArbolBinario();
        ArbolBinario(T val);
        ~ArbolBinario();
        bool esVacio();
        T datoRaiz();
        NodoBinario<T> *obtenerRaiz();
        void fijarRaiz(NodoBinario<T> *nraiz);
        bool insertarNodo(T p, T n);
        void preOrden();
}