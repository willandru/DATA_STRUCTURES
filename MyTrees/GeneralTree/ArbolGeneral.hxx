//ArbolGeneral.hxx

#include "ArbolGeneral.h"

template <class T>
ArbolGeneral<T>::ArbolGeneral(){
    this-> raiz= NULL;
}

template <class T>
ArbolGeneral<T>::~ArbolGeneral(){
    delete this-> raiz;
    this-> raiz= NULL;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz(){
    return this->raiz;
}

template <class T>
bool ArbolGeneral<T>::fijarRaiz(T ndato){
    NodoGeneral<T>* nodoRaiz= new NodoGeneral<T>;
    nodoRaiz-> fijarDato(ndato);
    this-> raiz= nodoRaiz;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
    bool added=false;
    if(this->raiz == NULL){
        (this->raiz).fijarDato(padre);
        (this->raiz).adicionarDesc(n);
        added=true;
    }else{
        if((this->raiz).obtenerDato() == padre){
            (this->raiz).adicionarDesc(n);
            added=true;
        }else{
            std::list<NodoGeneral<T> *>::iterator it;
            for(it=this->desc.begin(); )
        }
    }
}


template <class T>

void ArbolGeneral<T>::preOrden();