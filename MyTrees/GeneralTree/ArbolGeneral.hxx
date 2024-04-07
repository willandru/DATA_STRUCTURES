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
            NodoGeneral<T>* aux= new NodoGeneral<T>;
            for(it=this->desc.begin(); it !=this->desc.end(); it++){
                aux= *it;
                if(aux->obtenerDato()== padre){
                    aux->adicionarDesc(n)
                    added=true;
                }
            }
        }
    }
    return added;
}


template <class T>
void ArbolGeneral<T>::preOrden(){
    if(this->raiz==NULL){
        std::cout << "El arbol esta vacio" << std::endl;
    }else{
        std::cout << this->raiz->obtenerDato() << std::endl;
        std::list<NodoGeneral<T> *>::iterator it;
        NodoGeneral<T>* aux= new NodoGeneral<T>;
        for(it=this->desc.begin(); it !=this->desc.end(); it++){
            aux= *it;
            std::cout << aux->raiz->obtenerDato() << std::endl;
        }
    }

}