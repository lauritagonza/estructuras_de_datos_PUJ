#include "genoma.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

// constructor
Genoma::Genoma(){
  nombre = " ";
  tipo='-';
  n_secuencias=0;
}

void Genoma::setNombre(std::string nombre)
{
  this->nombre = nombre; 
}
  
// void Genoma::setTipo(char tipo) 
// {
//   this->tipo = tipo; 
// }

void Genoma::AgregarLineaSecuencia(std::string descripcion_secuencia, std::string linea_secuencia)
{
  std::list<Secuencia>::iterator itSec;
  std::list<Secuencia>::iterator itNewSec = l_secuencias.end();

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++ )
  {
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
    this->n_secuencias++;
  }

  // std::cout << ">>>" << n_secuencias << std::endl;
}

int Genoma::ObtenerNSecuencias()
{
  return (n_secuencias);
}

void Genoma::ListarSecuencias()
{
  int n_bases;
  char tipo;
  std::list<Secuencia>::iterator itSec;
  std::string linea, descripcion;

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++ )
  {
    n_bases = itSec->EncontrarBases();
    tipo = itSec->getTipo();
    descripcion = itSec->ObtenerDescripcion();

    if (tipo == 'C')
      std::cout << std::endl << "Secuencia " << descripcion << " contiene " << n_bases << " bases." << std::endl;
    else if (tipo == 'I')
      std::cout << std::endl << "Secuencia " << descripcion << " contiene al menos " << n_bases << " bases." << std::endl;
  }
  std::cout << std::endl;
}

void Genoma::EliminarSecuencias()
{
  l_secuencias.clear();
}

void Genoma::HistogramaSecuencia(std::string descripcion_secuencia)
{
  bool encontrada = false;
  std::list<Secuencia>::iterator itSec;

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++)
  {
    if (itSec->ObtenerDescripcion() == descripcion_secuencia)
    {
      itSec->Histograma();
      encontrada = true;
    }
  }

  if (!encontrada)
    std::cout << std::endl << "Secuencia invalida." << std::endl;
}

void Genoma::GuardarArchivo(std::string nombre_archivo)
{
  std::list<std::string> l_lineas;

  std::list<Secuencia>::iterator itSec;
  std::list<std::string>::iterator itLineas;

  std::ofstream MyFile(nombre_archivo);

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++)
  {
    // Escribir descripcion
    MyFile << ">" << itSec->ObtenerDescripcion() << "\n";
    
    l_lineas = itSec->ObtenerLLineas();

    for (itLineas = l_lineas.begin(); itLineas != l_lineas.end(); itLineas++)
    {
      // Escribir linea de secuencia
      MyFile << *itLineas << "\n";
    }
  }

  MyFile.close();
}

