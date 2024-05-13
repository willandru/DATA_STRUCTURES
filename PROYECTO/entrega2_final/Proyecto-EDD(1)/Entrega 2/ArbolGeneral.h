#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__

#include "NodoGeneral.h"

template < class T >
class ArbolGeneral {
  protected:
    NodoGeneral<T>* raiz;
  public:
    ArbolGeneral();
    ArbolGeneral(T val);
    ~ArbolGeneral();
    bool esVacio();
    NodoGeneral<T>* obtenerRaiz();
    void fijarRaiz(NodoGeneral<T>* nraiz);
    bool insertarNodo(T padre, T n);
    bool insertarNodo(NodoGeneral<T>* raiz, T padre, T n);
    bool eliminarNodo(T n);
    bool eliminarNodo(NodoGeneral<T>* raiz, T n);
    bool buscar(T n);
    bool buscar(NodoGeneral<T> *nodo, T n);
    int altura();
    int altura(NodoGeneral<T>* nodo);
    int tamano();
    int tamano(NodoGeneral<T>* nodo);
    void preOrden();
    void preOrden(NodoGeneral<T>* nodo);
    void posOrden();
    void posOrden(NodoGeneral<T>* nodo);
    void nivelOrden();
    void limpiar();
    void limpiar(NodoGeneral<T>* nodo);
};

#include "ArbolGeneral.hxx"

#endif
