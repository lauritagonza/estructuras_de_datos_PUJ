#include "codigoGenetico.h"
#include <iostream>

// constructor
codigoGenetico::codigoGenetico( ){
  secuencia = vector<base> sec;
}

// agregar una nueva area de conocimiento
void codigoGenetico::setSecuencia(vector<base> sec) {
  this->secuencia= sec; 
  }

vector<base> getSecuencia(){
  return secuencia; 
}