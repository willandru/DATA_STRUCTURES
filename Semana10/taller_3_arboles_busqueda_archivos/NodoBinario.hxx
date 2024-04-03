//NodoBinario.hxx
#include "NodoBinario.h"

template< class T >
NodoBinario<T>::NodoBinario(){
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
}

template< class T >
NodoBinario<T>::NodoBinario(T& val){
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
  this->dato = val;
}

template< class T >
NodoBinario<T>::~NodoBinario(){
  if(this->hijoIzq != NULL){
    delete this->hijoIzq;
    this->hijoIzq = NULL;
  }
  if(this->hijoDer != NULL){
    delete this->hijoDer;
    this->hijoDer = NULL;
  }
}

template< class T >
T& NodoBinario<T>::obtenerDato(){
  return this->dato;
}

template< class T >
void NodoBinario<T>::fijarDato(T& val){
  this->dato = val;
}

template< class T >
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq){
  if(this->hijoIzq != NULL) {
    delete this->hijoIzq;
    this->hijoIzq = izq;
  } else {
    this->hijoIzq = izq;
  }
}

template< class T >
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der){
  if(this->hijoDer != NULL) {
    delete this->hijoDer;
    this->hijoDer = der;
  } else {
    this->hijoDer = der;
  }
}

template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer(){
  if(!(this->hijoDer == NULL)) {
    return this->hijoDer;
  }
  return NULL;
}

template< class T >
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq(){
  if(!(this->hijoIzq == NULL)){
    return this->hijoIzq;
  }
  return NULL;
}

template< class T >
bool NodoBinario<T>::eliminarHijoIzq(){
  if(!this->hijoIzq == NULL){
    delete this->hijoIzq;
    this->hijoIzq = NULL;
    return true;
  }
  return false;
}

template< class T >
bool NodoBinario<T>::eliminarHijoDer(){
  if(! this->hijoDer == NULL){
    delete this->hijoDer;
    this->hijoDer = NULL;
    return true;
  }
  return false;
}

template< class T >
bool NodoBinario<T>::esHoja(){
  return (this->hijoIzq == NULL && this->hijoDer == NULL);
}
