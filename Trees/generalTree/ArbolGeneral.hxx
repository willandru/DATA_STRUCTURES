#include "ArbolGeneral.h"

template <class T>
ArbolGeneral<T>::ArbolGeneral(){
    this->raiz= NULL;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T val){
    NodoGeneral<T>* nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);
    this->raiz=nodo;
}

template <class T>
ArbolGeneral<T>::~ArbolGeneral(){
    delete this->raiz;
    this->raiz=NULL;
}

template <class T>
bool ArbolGeneral<T>::esVacio(){
    return this->raiz== NULL;
}


template<class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz(){
    return this->raiz;
}

template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz){
    this-> raiz= nraiz;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
    bool added = false;
    if (this->esVacio()){
        NodoGeneral<T>* nuevoNodo = new NodoGeneral<T>();
        nuevoNodo->fijarDato(padre);
        nuevoNodo->adicionarDesc(n);
        this->fijarRaiz(nuevoNodo);
        added = true;
    } else{
       if( (this->raiz).obtenerDato == padre ){
        (this->raiz).adicionarDesc(n);
        added =true;
       }
       else{
        std::list<NodoGeneral<T>* >::iterator it;
        NodoGeneral<T>* aux;
        for(it=desc.begin(); it!=desc.end(); it++){
            aux= *it;
            if(!added && aux.obtenerDato== padre){
                aux.insertarNodo(T padre, T n);
            }
        }
       }
    }
    // si el arbol es vacio:
        //crear nuevo nodo, asignar dato, poner ese nodo como raiz

    // si hay almenos un nodo en el arbol
        // - revisar el nodo donde estoy para ver si es el padre
        //- ahí puedo insertar el nuevo hijo
        //si no es el padre, revisar cada nodo hijo y llamar a insertar all
}

template <class T>
bool ArbolGeneral<T>::eliminarNodo( T n){
    bool eliminado= false;
    if(this->esVacio()){
        return eliminado;
    }
    else if((this->raiz).obtenerDato == n){
        delete this->raiz;
        this->raiz=NULL;
        eliminado = true;
        return eliminado;
    }else{
        std::list<NodoGeneral<T>* >::iterator it;
        NodoGeneral<T>* aux;
        for(it=desc.begin(); it!=desc.end(); it++){
            aux= *it;
            if(!eliminado && aux.obtenerDato()== n ){
                aux.eliminarNodo(T n);
            }
        }
    }
    // si el arbol es vacio:
        //retornar

    //si es la raiz la que quiero eliminar:
        // hacer delete a raiz
        //poner raiz en nulo
    //si hay al menos un nodo en el arbol:
        //-revisar si alguno de los hijos es el que quiero eliminar
        //- si ninguno de los hijos ees el que quiero eliminar:
            //- revisar cada nodo hijo y llamar a eliminar
}

template <class T>
bool ArbolGeneral<T>::buscar(T n){
    bool encontrado=false;
    if((this->raiz).esVacio()){
        return encontrado;
    }else if((this->raiz).obtenerDato== n){
        encontrado= true;
        return encontrado;
    }
    else{

        std::list<NodoGeneral<T>* >::iterator it;
        NodoGeneral<T>* aux;
        for(it=desc.begin(); it!=desc.end(); it++){
            aux= *it;
            if(!encontrado && aux.obtenerDato()== n ){
                aux.buscar(T n);
            }
        }
    }
    // si el arbol no esta vacio:
        //comparo dato en el nodo actual con dato en parametor
        //s i es ese, retorno que lo encontre
        //si no, prara cada nodo hijo hacer l llamado para buscar.
}

template <class T>
unsigned int ArbolGeneral::altura(){
    if(this->esVacio()){
        return -1;
    } else{
        return (this->raiz)->altura();
    }
}

template <class T>
 int ArbolGeneral::altura(NodoGeneral<T>* nodo){
    int alt = -1;

    if(nodo->esHoja()){
        alt=0;
    }else{
        int alth;
        std::list<NodoGeneral<T>* >::iterator it;
        for (it=nodo->desc.begin(); it != nodo->desc.end(); it++){
            alth = this->altura(*it);
            if(alt < alth +1)
                alt = alth+1;
        }
    }

    return alt;
}

tempalte <class T>
unsigned int ArbolGeneral<T>::tamano(){
    int tamano=0;
    if((this->raiz).esVacio()){
        return tamano;
    }else{
        std::list<NodoGeneral<T>* >::iterator it;
        for (it=nodo->desc.begin(); it != nodo->desc.end(); it++){
            aux= *it;
            tamano++;
            aux.t

        }
    }
    //si el arbol esta vacio retorno 0
    //si no esta vacio, para cada uno de los hijos llamao a tamaño
    // acumulo esos tamaños en una variabñe
    // retorno ese valor acumulado más 1
}

template <class T>
void ArbolGeneral<T>::preOrden(){
    if(!this->esVacio())
        this->preOrden(this->raiz);
}

template <class T>
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo){
    std::cout << nodo->obtenerDato() << " ";

    std::list< NodoGeneral<T>* >::iterator it;
    for( it= nodo->desc.begin(); it != nodo-desc.end(); it++ ){
        this->preOrden(*it);
    }
        
}    

template <class T>
void ArbolGeneral<T>::posOrden(){
    //lamar a posorden sobre cada hijo
    //imprimpo en pantalla el dato del nodo actual
}

template <class T>
void ArbolGeneral<T>::nivelOrden(){
    // no es recurrente, necesita un proceso iteratibo
    //Ubicarme en la raiz
    // poner la raiz en una cola
    // hacer un ciclo mientras haya algo en la cola
    // - saco el primero disponible en la cola
    // -imprimo su dato
    // -inserto en la cola todos sus hijos
}