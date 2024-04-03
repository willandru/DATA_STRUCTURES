//ArbolBinarioOrd.h
#ifndef __ARBOLBINARIOORDENADO_H__
#define __ARBOLBINARIOORDENADO_H__

#include "NodoBinario.h"

template <class T> class ArbolBinarioOrdenado {
protected:
  NodoBinario<T> *raiz;

public:
  ArbolBinarioOrdenado();
  ArbolBinarioOrdenado(T val);
  ~ArbolBinarioOrdenado();
  bool esVacio();
  T datoRaiz();
  NodoBinario<T> *obtenerRaiz();
  void fijarRaiz(NodoBinario<T> *nraiz);
  bool insertarNodo(T n);
  bool insertarNodo(NodoBinario<T> *raiz, T n);
  
  bool eliminarNodo(T n);
  bool eliminarNodo(NodoBinario<T> *padre, NodoBinario<T> *nodo, T n);
  NodoBinario<T> *encontrarMinimo(NodoBinario<T> *nodo);
  bool buscar(T n);
  int altura();
  int altura(NodoBinario<T> *nodo);
  int tamano();
  int tamano(NodoBinario<T> *nodo);
  void preOrden();
  void preOrden(NodoBinario<T> *nodo);
  void inOrden();
  void inOrden(NodoBinario<T> *nodo);
  void posOrden();
  void posOrden(NodoBinario<T> *nodo);
  void nivelOrden();
};

#include "ArbolBinarioOrd.hxx"

#endif
