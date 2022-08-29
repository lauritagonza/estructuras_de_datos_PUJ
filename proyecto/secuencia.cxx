#include "secuencia.h"
#include <iostream>

// constructor
Secuencia::Secuencia( ){
  descripcion = " ";
}

// Obtener descripcion de la secuencia
std::string Secuencia::ObtenerDescripcion()
{
  return descripcion;
};

// Fijar descripcion de la secuencia
void Secuencia::FijarDescripcion(std::string descripcion_secuencia) {
  this->descripcion = descripcion_secuencia;
}

void Secuencia::AgregarLinea(std::string linea_secuencia){
  l_lineas.push_back(linea_secuencia);
}


// agregar una nueva area de conocimiento
// void Secuencia::setSecuencia(std::vector<::base> secuencia) {
//   this->secuencia= secuencia; 
//   }
/*
std::vector<::base> getSecuencia(){
  return secuencia; 
}
*/