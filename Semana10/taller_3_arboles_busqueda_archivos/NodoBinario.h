//Nodo Binario
#ifndef __NODOBINARIO_H__
#define __NODOBINARIO_H__
#include <list>
template< class T > 
class NodoBinario {
  protected:
    T dato;
    NodoBinario<T>* hijoIzq;
    NodoBinario<T>* hijoDer;
  public:
    NodoBinario();
    NodoBinario(T& val);
    ~NodoBinario();
    T& obtenerDato();
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarDato(T& val);
    void fijarHijoIzq(NodoBinario<T>* izq);
    void fijarHijoDer(NodoBinario<T>* der);
    bool eliminarHijoIzq();
    bool eliminarHijoDer();
    bool esHoja();
};
#include "NodoBinario.hxx"
#endif
