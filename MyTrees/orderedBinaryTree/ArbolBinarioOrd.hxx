#include "ArbolBinarioOrd.h"
#include <queue>

template< class T >
ArbolBinarioOrd<T>::ArbolBinarioOrd() {
  this->raiz = NULL;
}

template< class T >
ArbolBinarioOrd<T>::~ArbolBinarioOrd() {
  if (this->raiz != NULL) {
    delete this->raiz;
    this->raiz = NULL;
  }
}

template <class T>
bool ArbolBinarioOrd<T>::fijarRaiz(T ndato){
    if (raiz != nullptr) {  
        delete raiz; 
    }
    NodoBinarioOrd<T>* nodoRaiz= new NodoBinarioOrd<T>;
    nodoRaiz-> fijarDato(ndato);
    this-> raiz= nodoRaiz;
    return true;
}

template< class T >
bool ArbolBinarioOrd<T>::esVacio() {
  return this->raiz == NULL;
}

template< class T >
T ArbolBinarioOrd<T>::datoRaiz() {
  return (this->raiz)->obtenerDato();
}

// recurrente
template< class T >
int ArbolBinarioOrd<T>::altura() {
  if (this->esVacio())
    return -1;
  else
    return (this->raiz)->altura();
}



// iterativa
template< class T >
bool ArbolBinarioOrd<T>::insertar(T val) {
  NodoBinarioOrd<T>* nodo = this->raiz;
  NodoBinarioOrd<T>* padre = this->raiz;
  bool insertado = false;
  bool duplicado = false;
  
  while (nodo != NULL) {
    padre = nodo;
    if (val < nodo->obtenerDato()) {
      nodo = nodo->obtenerHijoIzq();
    } else if (val > nodo->obtenerDato()) {
      nodo = nodo->obtenerHijoDer();
    } else {
      duplicado = true;
      break;
    }
  }

  if (!duplicado) {
    NodoBinarioOrd<T>* nuevo = new NodoBinarioOrd<T>();
    nuevo->fijarDato(val);
    if (nuevo != NULL) {
      if (val < padre->obtenerDato())
        padre->fijarHijoIzq(nuevo);
      else
        padre->fijarHijoDer(nuevo);
    }
    insertado = true;
  }

  return insertado;
}

// iterativa
template< class T >
bool ArbolBinarioOrd<T>::eliminar(T val) {
  
// comparar con dato en nodo para bajar por izquierda o derecha
// y para saber si val esta en el arbol
  NodoBinarioOrd<T>* nodo = this->raiz;
  NodoBinarioOrd<T>* padre = this->raiz;
  bool encontrado = false;

  while (nodo != NULL && !encontrado) {
    if (val < nodo->obtenerDato()) {
      padre=nodo;
      nodo = nodo->obtenerHijoIzq();
    } else if (val > nodo->obtenerDato()) {
      padre =nodo;
      nodo = nodo->obtenerHijoDer();
    } else {
      encontrado = true;
      std::cout << " El nodo es hoja";
    }
  } 
  

  if(encontrado){
    
    std::cout << "LA HOJA " << nodo->obtenerDato()<<std::endl ;
    std::cout << "EL PADRE "<< padre->obtenerDato()<<std::endl ;
    if(nodo->esHoja()){
      if (padre->obtenerHijoIzq()->obtenerDato() == nodo->obtenerDato()) {
        padre->fijarHijoIzq(NULL);
        return true;
      }
      else{
        padre->fijarHijoDer(NULL);
        return true;
      }
    }else{
      if(nodo->obtenerHijoDer() == NULL){
        //el  nodo solo tiene hijo izq
        padre->fijarHijoIzq(nodo->obtenerHijoIzq());
      }else if(nodo->obtenerHijoIzq() == NULL){
        padre->fijarHijoDer(nodo->obtenerHijoDer());
      }else{
        //el nodo tiene 2 hijos
        NodoBinarioOrd<T> *mayor= nodo;
        bool mayorEncontrado=false;
        while(!mayorEncontrado){
          
          if( mayor->obtenerHijoDer() !=NULL ){
            padre=mayor;
            mayor= mayor->obtenerHijoDer();
          }else{
            mayorEncontrado=true;
          }
        }

        nodo->fijarDato(mayor->obtenerDato());
        padre->fijarHijoDer(NULL);
      }
    }
     
    
  }

  return false;
// si val esta en el arbol
// verificar situacion de eliminacion:
// 1. nodo hoja, borrarlo
// 2. nodo con un solo hijo, usar hijo para reemplazar nodo
// 3. nodo con dos hijos, usar el valor mayor del subarbol izquierdo
//    para reemplazar nodo, es decir el utlmido hijo derecho

}

// iterativa
template< class T >
bool ArbolBinarioOrd<T>::buscar(T val) {
  NodoBinarioOrd<T>* nodo = this->raiz;
  bool encontrado = false;

  while (nodo != NULL && !encontrado) {
    if (val < nodo->obtenerDato()) {
      nodo = nodo->obtenerHijoIzq();
    } else if (val > nodo->obtenerDato()) {
      nodo = nodo->obtenerHijoDer();
    } else {
      encontrado = true;
    }
  }

  return encontrado;
}

// recurrente
template< class T >
void ArbolBinarioOrd<T>::preOrden() {
  if (!this->esVacio())
    (this->raiz)->preOrden();
}

// recurrente
template< class T >
void ArbolBinarioOrd<T>::inOrden() {
  if (!this->esVacio())
    (this->raiz)->inOrden();
}

// recurrente
template< class T >
void ArbolBinarioOrd<T>::posOrden() {
  if (!this->esVacio())
    (this->raiz)->posOrden();
}

// iterativa
template< class T >
void ArbolBinarioOrd<T>::nivelOrden() {
	if (!this->esVacio()) {
    std::queue< NodoBinarioOrd<T>* > cola;
    cola.push(this->raiz);
    NodoBinarioOrd<T>* nodo;
    while (!cola.empty()) {
      nodo = cola.front();
      cola.pop();
      std::cout << nodo->obtenerDato() << " ";
      if (nodo->obtenerHijoIzq() != NULL)
        cola.push(nodo->obtenerHijoIzq());
      if (nodo->obtenerHijoDer() != NULL)
        cola.push(nodo->obtenerHijoDer());
    }
  }
}