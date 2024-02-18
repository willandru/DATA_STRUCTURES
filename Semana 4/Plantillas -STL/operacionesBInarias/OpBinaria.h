#ifndef OPBINARIA_H
#define OPBINARIA_H

template <class N>
struct OpBinaria {
  N op1;
  N op2;
  char operacion;
  N EvaluarOperacion();  
};

#include "OpBinaria.hxx"

#endif