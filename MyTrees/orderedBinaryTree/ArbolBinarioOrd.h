#ifndef __ARBOLBINARIOORD__H__
#define __ARBOLBINARIOORD__H__

#include "NodoBinarioOrd.h"
template <class T>
class ArbolBinarioOrd{
    protected:
        NodoBinarioOrd<T>* raiz;
    public:
        ArbolBinarioOrd();
        ~ArbolBinarioOrd();
         bool esVacio();
        T datoRaiz();
        bool fijarRaiz(T dato);
        int altura();
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
