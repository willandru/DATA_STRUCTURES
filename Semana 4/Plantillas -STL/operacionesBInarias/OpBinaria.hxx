#include "OpBinaria.h"

template <class N>
N OpBinaria<N>::EvaluarOperacion() {
  N resul;
  switch( operacion ) {
    case '+': resul = op1 + op2; break;
    case '-': resul = op1 - op2; break;
    case '*': resul = op1 * op2; break;
    case '/': resul = op1 / op2; break;
  }
  return resul;
}