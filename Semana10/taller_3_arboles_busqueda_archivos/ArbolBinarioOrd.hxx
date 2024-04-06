//ArbolBinarioOrd.hxx
#include "ArbolBinarioOrd.h"

template< class T >
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado(){
  this->raiz = NULL;
}

template< class T >
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado(T val){
    NodoBinario<T> *nodo = new NodoBinario<T>;
    nodo->fijarDato(val);
    this->fijarRaiz(nodo);
    //this->raiz = nodo;
}

template< class T >
ArbolBinarioOrdenado<T>::~ArbolBinarioOrdenado(){
  if(this->raiz != NULL) {
  delete this->raiz;
  this->raiz = NULL;
  }
}

template< class T >
bool ArbolBinarioOrdenado<T>::esVacio(){
  return this->raiz == NULL;
}

template< class T>
T ArbolBinarioOrdenado<T>::datoRaiz(){
  return (this->raiz)->obtenerDato();
}

template< class T >
NodoBinario<T>* ArbolBinarioOrdenado<T>::obtenerRaiz(){
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
    
    
    //reordenarArbol(raiz);
    return insertarNodo(this->raiz, n);  
  
}
  
template< class T >
bool ArbolBinarioOrdenado<T>::insertarNodo(NodoBinario<T>* nodo, T n) {
    if (nodo == nullptr) {
        return false;
    }
    if (nodo->obtenerDato() == n) return false;
  
    if (n > nodo->obtenerDato()) {
        if (nodo->obtenerHijoDer() == nullptr) {
            NodoBinario<T>* nuevoNodo = new NodoBinario<T>(n);
            nodo->fijarHijoDer(nuevoNodo);
            return true;
        } else {
            return insertarNodo(nodo->obtenerHijoDer(), n);
        }
    }
    if (n < nodo->obtenerDato()) {
        if (nodo->obtenerHijoIzq() == nullptr) {
            NodoBinario<T>* nuevoNodo = new NodoBinario<T>(n);
            nodo->fijarHijoIzq(nuevoNodo);
            return true;
        } else {
            return insertarNodo(nodo->obtenerHijoIzq(), n);
        }
    }
  
    return false;
}


//--------------------------//



template< class T >
bool ArbolBinarioOrdenado<T>::eliminarNodo(T n) {
    if (this->esVacio()) {
        return false;
    }
    return eliminarNodo(NULL, raiz, n);
}

template< class T>
bool ArbolBinarioOrdenado<T>::eliminarNodo(NodoBinario<T>* padre, NodoBinario<T>* nodo, T n) {
    if (nodo == NULL) {
        return false;
    }

    if (n == nodo->obtenerDato()) {
        // Caso 1: Nodo sin hijos
        if (nodo->obtenerHijoIzq() == NULL && nodo->obtenerHijoDer() == nullptr) {
            if (padre == nullptr) {
                delete nodo;
                raiz = nullptr;
                return true;
            } else if (padre->obtenerHijoIzq() == nodo) {
                delete nodo;
                padre->fijarHijoIzq(NULL);
                return true;
            } else {
                delete nodo;
                padre->fijarHijoDer(NULL);
                return true;
            }
        }
        // Caso 2: Nodo con un solo hijo
        else if (nodo->obtenerHijoIzq() == NULL) {
            NodoBinario<T>* temp = nodo;
            nodo = nodo->obtenerHijoDer();
            delete temp;
            if (padre == nullptr) {
                raiz = nodo;
                return true;
            } else if (padre->obtenerHijoIzq() == temp) {
                padre->fijarHijoIzq(nodo);
                return true;
            } else {
                padre->fijarHijoDer(nodo);
                return true;
            }
        } else if (nodo->obtenerHijoDer() == NULL) {
            NodoBinario<T>* temp = nodo;
            nodo = nodo->obtenerHijoIzq();
            delete temp;
            if (padre == nullptr) {
                raiz = nodo;
                return true;
            } else if (padre->obtenerHijoIzq() == temp) {
                padre->fijarHijoIzq(nodo);
            } else {
                padre->fijarHijoDer(nodo);
            }
        }
        // Caso 3: Nodo con dos hijos
        else {
            NodoBinario<T>* temp = encontrarMinimo(nodo->obtenerHijoDer());
            nodo->fijarDato(temp->obtenerDato());
            eliminarNodo(nodo, nodo->obtenerHijoDer(), temp->obtenerDato());
        }
        return true;
    } else if (n < nodo->obtenerDato()) {
        return eliminarNodo(nodo, nodo->obtenerHijoIzq(), n);
    } else {
        return eliminarNodo(nodo, nodo->obtenerHijoDer(), n);
    }
}




template<class T>
NodoBinario<T>* ArbolBinarioOrdenado<T>::encontrarMinimo(NodoBinario<T>* nodo) {
    while (nodo->obtenerHijoIzq() != nullptr) {
        nodo = nodo->obtenerHijoIzq();
    }
    return nodo;
}



template< class T >
int ArbolBinarioOrdenado<T>::altura(){
  if(this->esVacio()) return -1;
  else return this->altura(this->raiz);
}

template< class T >
int ArbolBinarioOrdenado<T>::altura(NodoBinario<T>* nodo){
  if (nodo == NULL) {
    return -1; 
  } else {
    int alt_izq = altura(nodo->obtenerHijoIzq());
    int alt_der = altura(nodo->obtenerHijoDer());
    return std::max(alt_izq, alt_der) + 1;
  }
}


template< class T >
void ArbolBinarioOrdenado<T>::preOrden(){
  if (!this->esVacio())
    this->preOrden(this->obtenerRaiz());
}

template< class T >
void ArbolBinarioOrdenado<T>::preOrden(NodoBinario<T>* nodo){
  if (nodo == NULL) return;
  std::cout << nodo->obtenerDato() << " ";
    
    
  this->preOrden(nodo->obtenerHijoIzq());
  this->preOrden(nodo->obtenerHijoDer());
}

template< class T >
void ArbolBinarioOrdenado<T>::inOrden() {
  if (!this->esVacio())
    this->inOrden(this->obtenerRaiz());
}

template< class T >
void ArbolBinarioOrdenado<T>::inOrden(NodoBinario<T>* nodo) {
  if (nodo == NULL) return;
      
    this->inOrden(nodo->obtenerHijoIzq());
      std::cout << nodo->obtenerDato() << " ";
    this->inOrden(nodo->obtenerHijoDer());
  
}

template< class T >
void ArbolBinarioOrdenado<T>::posOrden(){
  if (!this->esVacio())
    this->posOrden(this->obtenerRaiz());
}

template< class T >
void ArbolBinarioOrdenado<T>::posOrden(NodoBinario<T>* nodo){
  if (nodo == NULL) return;

    
  this->posOrden(nodo->obtenerHijoIzq());
  this->posOrden(nodo->obtenerHijoDer());
  std::cout << nodo->obtenerDato() << " ";
  
}
