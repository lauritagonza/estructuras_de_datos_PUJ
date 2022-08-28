#include "genoma.h"
#include <iostream>

// constructor
genoma::genoma( ){
  nombre = "";
}

void genoma::setlSecuencias(vector<codigoGenetico> sec) {
  this->lsecuencias= sec; 
  }

vector<codigogenetico> getlSecuencias(){
  return lsecuencias; 
}

void genoma::setNombre(string nombre) {
  this->nombre= nombre; 
  }

string getNombre(){
  return nombre; 
}
void genoma::setTipo(char tipo) {
  this->tipo= tipo; 
  }

string getTipo(){
  return tipo; 
}
