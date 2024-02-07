#include "OpBinaria.h"case


template <class T>
T OpBinaria<T>::OpBinaria(T a, T b, char c){
        op1=a;
        op2=b;
        op=c;
    }



template <class T>
T OpBinaria<T>::EvaluarOperacion(){
    T res;
    switch(op){
        case '+': res = op1 + op2; break;
        case '-': res = op1 - op2; break;
        case '*': res = op1 * op2; break;
        case '/': res = op1 / op2; break;
    }
    return res;

}