//ArbolGeneral.hxx

#include "ArbolGeneral.h"
#include <iostream>
#include <list>

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
    if (raiz != nullptr) {  
        delete raiz; 
    }
    NodoGeneral<T>* nodoRaiz= new NodoGeneral<T>;
    nodoRaiz-> fijarDato(ndato);
    this-> raiz= nodoRaiz;
    return true;
}

template <class T>
int ArbolGeneral<T>::altura(){
    if(this->raiz ==NULL){
        return -1;
    }else{
        return this->altura(this->raiz);
    }
}

template <class T>
int ArbolGeneral<T>::altura(NodoGeneral<T> * nodo){
    int alt = -1;
    if(nodo->esHoja()){
        alt=0;
    }else{
        typename std::list<NodoGeneral<T>* >::iterator it;
        int alth;
        for(it=nodo->desc.begin(); it !=nodo->desc.end(); it++){
            alth= this->altura(*it);
            if(alt < alth+1){
                alt=alth+1;
            }
        }
    }
    return alt;
}


template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
    if(this->raiz == NULL){
        this->raiz = new NodoGeneral<T>;
        (this->raiz)->fijarDato(padre);
        (this->raiz)->adicionarDesc(n);
        return true;
    }else{
        return (this->raiz)->insertarNodo(padre, n);
    }
}


template <class T>
void ArbolGeneral<T>::preOrden(){
    if(this->raiz==NULL){
        std::cout << "El arbol esta vacio" << std::endl;
    }else{
        (this->raiz)->preOrden();
        }
 }


template <class T>
void ArbolGeneral<T>::posOrden(){
    if(this->raiz==NULL){
        std::cout << "El arbol esta vacio" << std::endl;
    }else{
        (this->raiz)->posOrden();
        }
}
 

template <class T>
bool ArbolGeneral<T>::buscar( T dato){
    if(this->raiz==NULL){
        std::cout << "El arbol esta vacio" << std::endl;
        return false;
    }else{
        return (this-raiz)->buscar( dato);
    }
}

template <class T>
bool ArbolGeneral<T>::eliminar( T dato){
    if(this->raiz==NULL){
        std::cout << "El arbol esta vacio" << std::endl;
    }else if(this->raiz == dato){
        delete this-> raiz;
        this->raiz = NULL;
    }else{
        (this-raiz)->eliminar( dato);
    }
}
