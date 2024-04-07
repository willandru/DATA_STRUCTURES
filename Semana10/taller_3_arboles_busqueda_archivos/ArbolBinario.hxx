//ArbolBinario.hxx
#include "ArbolBinario.h"

template< class T >
ArbolBinario<T>::ArbolBinario(){
  this->raiz = NULL;
  nodo->obtenerHijoIzq() == NULL
}

template< class T >
ArbolBinario<T>::ArbolBinario(T val){
    NodoBinario<T> *nodo = new NodoBinario<T>;
    nodo->fijarDato(val);
    this->fijarRaiz(nodo);
    //this->raiz = nodo;
}

template< class T >
ArbolBinario<T>::~ArbolBinario(){
  if(this->raiz != NULL) {
  delete this->raiz;
  this->raiz = NULL;
  }
}

template< class T >
bool ArbolBinario<T>::esVacio(){
  return this->raiz == NULL;
}

template< class T>
T ArbolBinario<T>::datoRaiz(){
  return (this->raiz)->obtenerDato();
}

template< class T >
NodoBinario<T>* ArbolBinario<T>::obtenerRaiz(){
  return this->raiz;
}

template< class T >
void ArbolBinarioOrdenado<T>::fijarRaiz(NodoBinario<T>* nraiz){
  this->raiz = nraiz;
}

template< class T >
bool ArbolBinarioOrdenado<T>::insertarNodo(T n){
    if (this->raiz == nullptr){
        this->raiz = new NodoBinario<T>(n);
        std::cout << "Se inserto la raiz";
    } 
    