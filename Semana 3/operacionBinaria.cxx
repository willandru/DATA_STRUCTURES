#include "operacionBinaria.h"
#include <iostream>

template<class T>
OperacionBinaria<T>::OperacionBinaria(T op1, T op2, char op) : operando1(op1), operando2(op2), operacion(op) {}

template<class T>
T OperacionBinaria<T>::EvaluarOperacion() {
    switch(operacion) {
        case '+':
            return operando1 + operando2;
        case '-':
            return operando1 - operando2;
        case '*':
            return operando1 * operando2;
        case '/':
            if(operando2 != 0) {
                return operando1 / operando2;
            } else {
                std::cerr << "Error: División por cero." << std::endl;
                return 0; // Por defecto, en este caso, se retorna 0
            }
        default:
            std::cerr << "Error: Operación no válida." << std::endl;
            return 0; // Por defecto, en este caso, se retorna 0
    }
}
