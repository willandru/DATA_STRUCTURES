//NodoGeneral.hxx
#include "NodoGeneral.h"

template <class T>
NodoGeneral<T>::NodoGeneral(){
    this->desc.clear();
}
        
template <class T>
NodoGeneral<T>::~NodoGeneral(){
    std::list<NodoGeneral<T> *>::iterator it;
    for(it=this->desc.begin(); it!=this->desc.end(); it++){
        delete *it;
    }
    this->desc.clear();
}

template <class T>
T& NodoGeneral<T>::obtenerDato(){
    return this->dato;
}

template <class T>
bool NodoGeneral<T>::fijarDato(T& ndato){
    this->dato= ndato;
    return true;
}

template <class T>
std::list<NodoGeneral<T> *> NodoGeneral<T>::obtenerDesc(){
    return this->desc;
}

template <class T>
bool NodoGeneral<T>::adicionarDesc(T nHijo){
    NodoGeneral<T>* nodoHijo= new NodoGeneral<T>;
    nodoHijo->fijarDato(nHijo);
    this->desc.push_back(nodoHijo);
}
