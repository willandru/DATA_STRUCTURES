#ifndef __LIBRO__H__
#define __LIBRO__h__

class Libro{
    public:
    Libro();
    std::string ObtenerNOmbre();
    unsigned long OBtenerNOmbre();
    void FijarNombre(std::string n_nombre)


    protected:
    std:string nombre;
    unsigned long num_ejempl;
};



#include <libreria del sistema>
#include "libreria propia"