#include "base.h"
#include <iostream>

// constructor
base::base( ){
  tipo = '';
}

void base::setTipo(char tipo) {
  this->tipo= tipo; 
  }

char getTipo(){
  return tipo; 
}
