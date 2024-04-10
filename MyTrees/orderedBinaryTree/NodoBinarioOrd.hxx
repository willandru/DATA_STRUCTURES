#include "NodoBinarioOrd.h"

template< class T >
NodoBinarioOrd<T>::NodoBinarioOrd() {
	this->hijoIzq = NULL;
  this->hijoDer = NULL;
}


template< class T >
NodoBinarioOrd<T>::~NodoBinarioOrd() {
	if (this->hijoIzq != NULL) {
    delete this->hijoIzq;
    this->hijoIzq = NULL;
  }
  if (this->hijoDer != NULL) {
    delete this->hijoDer;
    this->hijoDer = NULL;
  }
}

template< class T >
T NodoBinarioOrd<T>::obtenerDato() {
	return this->dato;
}

template< class T >
void NodoBinarioOrd<T>::fijarDato(T val) {
	this->dato = val;
}

template< class T >
NodoBinarioOrd<T>* NodoBinarioOrd<T>::obtenerHijoIzq() {
	return this->hijoIzq;
}

template< class T >
NodoBinarioOrd<T>* NodoBinarioOrd<T>::obtenerHijoDer() {
	return this->hijoDer;
}

template< class T >
void NodoBinarioOrd<T>::fijarHijoIzq(NodoBinarioOrd<T>* izq) {
	this->hijoIzq = izq;
}

template< class T >
void NodoBinarioOrd<T>::fijarHijoDer(NodoBinarioOrd<T>* der) {
	this->hijoDer = der;
}

template< class T >
bool NodoBinarioOrd<T>::esHoja() {
  return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

template< class T >
int NodoBinarioOrd<T>::altura() {
  int valt;

  if (this->esHoja()) {
    valt = 0;
  } else {
    int valt_izq = -1;
    int valt_der = -1;
    if (this->hijoIzq != NULL)
      valt_izq = (this->hijoIzq)->altura();
    if (this->hijoDer != NULL)
      valt_der = (this->hijoDer)->altura();
    if (valt_izq > valt_der)
      valt = valt_izq + 1;
    else
      valt = valt_der + 1;
  }

  return valt;
}

template< class T >
void NodoBinarioOrd<T>::preOrden() {
  std::cout << this->dato << " ";

  if (this->hijoIzq != NULL)
    (this->hijoIzq)->preOrden();
  
  if (this->hijoDer != NULL)
    (this->hijoDer)->preOrden();
}

template< class T >
void NodoBinarioOrd<T>::posOrden() {
  if (this->hijoIzq != NULL)
    (this->hijoIzq)->posOrden();
  
  if (this->hijoDer != NULL)
    (this->hijoDer)->posOrden();

  std::cout << this->dato << " ";
}

template< class T >
void NodoBinarioOrd<T>::inOrden() {
  if (this->hijoIzq != NULL)
    (this->hijoIzq)->inOrden();
  std::cout << this->dato << " ";
  if (this->hijoDer != NULL)
    (this->hijoDer)->inOrden();
}