#ifndef __NODOGENERAL_H__
#define __NODOGENERAL_H__

#include <list>

template<class T>
class NodoGeneral{
    protected:
        T dato;
        std::list<NodoGeneral<T>* > desc;
    public:
        NodoGeneral();
        ~NodoGeneral();
<<<<<<< HEAD

        T& obtenerDato();
        void fijarDato(T& val);
        
=======
        T& obtenerDato();
        void fijarDato(T& val);
>>>>>>> 605ab8f0e8b0dd8f8a9e420f7530ef90a600479e
        void limpiarLista();
        void adicionarDesc(T& nval);
        bool eliminarDesc(T& val);
        bool esHoja();

};

#include "NodoGeneral.hxx"

#endif