#include "ArbolBInarioOrd.h"

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
    this->raiz= NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
    if(this->raiz != NULL){
        delete this->raiz;
        this->raiz=NULL;
    }
}

template <class T>
ArbolBinarioOrd<T>::esVacio(){
    retrun  this->raiz == NULL;
}

template <class T>
ArbolBinarioOrd<T>::datoRaiz(){
   return (this->raiz)->obtenerDato();
}
