#ifndef __NODOBINARIOORD__H__
#define __NODOBINARIOORD__H__



template <class T>
class NodoBinarioOrd{
    protected:
        T dato;
        NodoBinarioOrd<T>* hijoIzq;
        NodoBinarioOrd<T>* hijoDer;
    public:
        NodoBinarioOrd();
        ~NodoBinarioOrd();
        bool esVacio();
        void fijarDato(T val );
        T obtenerDato();
        NodoBinarioOrd<T>* obtenerHijoIzq();
        NodoBinarioOrd<T>* obtenerHijoDer();
        void fijarHijoIzq(NodoBinarioOrd<T> *nHijoIzq);
        void fijarHijoDer(NodoBinarioOrd<T> *nHijoDer);
        bool esHoja();
        int altura();

        void inOrden();
        void preOrden();
        void posOrden();
    
};


#include "NodoBinarioOrd.hxx"

#endif
