#include "genoma.h"
#include <vector>
#include <list>
#include <iostream>

// constructor
Genoma::Genoma(){
  nombre = " ";
  tipo='-';
  n_secuencias=0;
}

// void Genoma::setNombre(std::string nombre)
// {
//   this->nombre = nombre; 
// }
  
// void Genoma::setTipo(char tipo) 
// {
//   this->tipo = tipo; 
// }

void Genoma::AgregarLineaSecuencia(std::string descripcion_secuencia, std::string linea_secuencia)
{
  std::list<Secuencia>::iterator itSec;
  std::list<Secuencia>::iterator itNewSec = l_secuencias.end();

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++ ) {
    if (itSec->ObtenerDescripcion() == descripcion_secuencia) {
        itSec->AgregarLinea(linea_secuencia);
        itNewSec = itSec;
      }
  }
  
  if (itNewSec == l_secuencias.end( ) ) {
      Secuencia secuencia;
      secuencia.FijarDescripcion(descripcion_secuencia);
      secuencia.AgregarLinea(linea_secuencia);
      l_secuencias.push_back(secuencia);

      n_secuencias++;
  }
}

/*
void Genoma::setlSecuencias(std::vector<::codigoGenetico> secuencias) {
  this->lsecuencias= secuencias; 
  }

std::vector<::codigoGenetico> getlSecuencias(){
  return lsecuencias; 
}
std::string getNombre(){
  return genoma::nombre; 
}
std::string getTipo(){
  return ::tipo; 
}
*/