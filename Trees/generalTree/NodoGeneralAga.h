#ifndef __NODOGENERALAGA_H__
#define __NODOGENERALAGA_H__

#include <list>

template < class T >
class NodoGeneralAga{

protected:
    T dato;
    std::list<NodoGeneralAga<T>* > descendencia;
public:
    NodoGeneralAga();
    ~NodoGeneralAga();

    T& obtenerDato();
    void fijarDato( T& val)T& nval;

    void limpiarLista();
    void adicionarDesc(T& nval);
    void eliminarDesc( T& val)

};