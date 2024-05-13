#include "ArbolGeneral.h"
#include <iostream>
#include <list>
#include <queue>

template< class T >
ArbolGeneral<T>::ArbolGeneral(){
  this->raiz = NULL;
}

template< class T >
ArbolGeneral<T>::ArbolGeneral(T val){
  NodoGeneral<T> *nodo = new NodoGeneral<T>;
  nodo->fijarDato(val);
  this->raiz = nodo;
}

template< class T >
ArbolGeneral<T>::~ArbolGeneral(){
  delete this->raiz;
  this->raiz = NULL;
}

template< class T >
bool ArbolGeneral<T>::esVacio(){
  return this->raiz == NULL;
}

template< class T >
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz(){
  return this->raiz;
}

template< class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz){
  this->raiz = nraiz;
}

template< class T >
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
  if (this->esVacio()) {
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->fijarDato(n);
    this->raiz = nodo;
  } else {
    //READY
    /*si hay al menos un nodo en el arbol:
      - revisar el nodo done estoy para ver si coincide con padre
      - si es padre, insertar ahi el nuevo hijo
      - si no es el padre, revisar cada hijo y llamar a insertar alli*/
    return this->insertarNodo(this->raiz, padre, n);
  }
}

template< class T >
bool ArbolGeneral<T>::insertarNodo(NodoGeneral<T>* nodo, T padre, T n){
  if (nodo->obtenerDato() == NULL) return false;
  if (nodo->obtenerDato() == padre) {
      nodo->adicionarDesc(n);
    return true;
  } else {
      typename std::list< NodoGeneral<T>* >::iterator it;
    for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
      if (this->insertarNodo(*it, padre, n)) return true;
    }
  }
    return false;
}

template< class T >
bool ArbolGeneral<T>::eliminarNodo(T n){
  //READY
  /*
    si el arbol es vacio:
      - retornar

    si es la raiz la que quiero eliminar:
      - hacer delete a raiz

    si hay al menos un nodo en el arbol:
      - si alguno de los hjos es el que quiero eliminar, moverme dentro de los hijos, verificar su dato, si coincide eliminar
      - si ninguno de los hijos es el que quiero eliminar, revisar cada hijo y llamar a eliminar alli
  */
  if (this->esVacio()) {
    return false;
  }
  if (raiz->obtenerDato() == n){
    delete raiz;
    raiz = nullptr;
    return true;
  }
  return eliminarNodo(raiz, n);
}

template< class T >
bool ArbolGeneral<T>::eliminarNodo(NodoGeneral<T>* raiz, T n){
    typename std::list< NodoGeneral<T>* >::iterator it;
  for (it = raiz->desc.begin(); it != raiz->desc.end(); it++){
    if ((*it)->obtenerDato() == n){
      delete *it;
      raiz->desc.eliminarDesc(it);
      return true;
    } else {
      if (eliminarNodo(*it, n)) return true;
    }
  }
  return false;
}

template< class T >
bool ArbolGeneral<T>::buscar(T n){
  //READY
  /*
    si el arbol no esta vacio:
      - comparar en el nodo actual con dato parametro
      - si es ese, retorno que lo encontre
      - si no, revisar cada hijo y buscar en ellos  
  */
  if (this->esVacio()) return false;
  else return buscar(raiz, n);
}

template< class T >
bool ArbolGeneral<T>::buscar(NodoGeneral<T> *nodo, T n){
  if (nodo->obtenerDato() == n) return true;
  std::list< NodoGeneral<T>* > hijos = nodo->obtenerDesc();
    typename std::list< NodoGeneral<T>* >::iterator it;
  for (it = hijos.begin(); it != hijos.end(); it++){
    if (bucar(*it, n)) return true;
  }
  return false;
}

template< class T >
int ArbolGeneral<T>::altura(){
  if (this->esVacio()){
    return -1;
  } else {
    return this->altura(this->raiz);
  }

}

template< class T >
int ArbolGeneral<T>::altura(NodoGeneral<T> *nodo){
  int alt = -1;
  if (nodo->esHoja()) {
    alt = 0;
  } else {
    int alth;
      typename std::list< NodoGeneral<T>* >::iterator it;
    for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
      alth = this->altura(*it);
      if (alt < alth + 1)
        alt = alth + 1;
    }
  }
  return alt;
}

template< class T >
int ArbolGeneral<T>::tamano(){
  //READY
  /*
    si el arbol esta vacio:
    - retornar 0
    si hay al menos un nodo:
    - para cada uno de los hijos, llamo a tamano
    - acumulo esos tamanos en una variable
    - retorno esa variable mas 1 (el propio nodo)
  */
  if (this->esVacio()) return 0;
  else return tamano(this->raiz);
}

template<class T>
int ArbolGeneral<T>::tamano(NodoGeneral<T> *nodo) {
  int tamano = 1;
  std::list< NodoGeneral<T>* > hijos = nodo->obtenerDesc();
    typename std::list< NodoGeneral<T>* >::iterator it;
  for (it = hijos.begin(); it != hijos.end(); it++){
    tamano += this->tamano(*it);
  }
  return tamano;
}

template< class T >
void ArbolGeneral<T>::preOrden(){
  if (!this->esVacio())
    this->preOrden(this->raiz);
}

template< class T >
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo){
  if (nodo == nullptr) return;
  std::cout << nodo->obtenerDato() << " ";

    typename std::list< NodoGeneral<T>* >::iterator it;
  for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
    this->preOrden(*it);
  }
}

template< class T >
void ArbolGeneral<T>::posOrden(){
  //READY
  //llamo a posorden sobre los hijos
  //imprimo el dato del nodo actual
  if (!this->esVacio())
    this->posOrden(this->raiz);
}
template< class T >
void ArbolGeneral<T>::posOrden(NodoGeneral<T>* nodo){
  if (nodo == nullptr) return;
  std::list< NodoGeneral<T>* > hijos = nodo->obtenerDesc();
    typename std::list< NodoGeneral<T>* >::iterator it;

  for (it = hijos.begin(); it != hijos.end(); it++) {
    posOrden(*it);
  }
  std::cout << nodo->obtenerDato() << " ";
}

template< class T >
void ArbolGeneral<T>::nivelOrden(){
  //READY
  // NO ES RECURRENTE
  // ubicarme en la raiz
  // poiner la raiz en una cola
  // hacer un ciclo mientras haya algo en la cola
  // - saco el primero disponible en la cola
  // - imprimo su dato
  // - inserto en la cola todos sus hijos (recorrido sobre cada uno de ellos)
  if (!this->esVacio()) {
    std::queue< NodoGeneral<T>* > cola;
    cola.push(raiz);
    while (!cola.empty()) {
      NodoGeneral<T> *nodo = cola.front();
      cola.pop();
      std::cout << nodo->obtenerDato() << " ";
      std::list< NodoGeneral<T>* > hijos = nodo->obtenerDesc();
        typename std::list< NodoGeneral<T>* >::iterator it;
      for (it = hijos.begin(); it != hijos.end(); it++){
        cola.push(*it);
      }
    }
  }
  return;
}

template< class T >
void ArbolGeneral<T>::limpiar(){
  if (!this->esVacio()){
    this->limpiar(this->raiz);
  }
}

template< class T >
void ArbolGeneral<T>::limpiar(NodoGeneral<T>* nodo){
  if (nodo == nullptr) return;
  if (nodo->esHoja()) {
    delete nodo;
    nodo = nullptr;
  } else {
    typename std::list< NodoGeneral<T>* >::iterator it;
    for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
      this->limpiar(*it);
    }
  }
}
