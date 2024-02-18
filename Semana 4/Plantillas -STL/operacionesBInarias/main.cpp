#include <iostream>
#include "OpBinaria.h"

using namespace std;

int main() {
  OpBinaria<int> enteros;
  enteros.op1 = 34;
  enteros.op2 = 786;
  enteros.operacion = '*';
  cout << enteros.EvaluarOperacion() << endl;
}