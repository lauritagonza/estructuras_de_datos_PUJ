#include "secuencia.h"
#include <iostream>

// constructor
Secuencia::Secuencia( ){
  descripcion = " ";
  tipo = 'C';
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

int Secuencia::EncontrarBases()
{
  int n;
  std::string linea;
  std::list<std::string>::iterator itLineas;

  bases.clear();

  for (itLineas = l_lineas.begin(); itLineas != l_lineas.end(); itLineas++)
  {
    linea = *itLineas;
    n = linea.length();

    for (int i = 0; i < n; i++) {

      if (linea[i] == '-')
        this->tipo = 'I';
      
      // std::cout << linea[i] << " ";
      bases.insert(linea[i]);
    }
  }

  std::cout << std::endl <<"Bases encontradas: " << std::endl; 

  std::set<char>::iterator itBases;

  for (itBases = bases.begin(); itBases != bases.end(); itBases++) {
    std::cout << ' ' << *itBases;
  }
  return bases.size();
}

char Secuencia::getTipo()
{
  return tipo;
}

void Secuencia::Histograma()
{
  int n, i, count;
  char base;
  std::string linea;
  std::list<std::string>::iterator itLineas;

  // Encontrar bases únicas
  bases.clear();

  for (itLineas = l_lineas.begin(); itLineas != l_lineas.end(); itLineas++)
  {
    linea = *itLineas;
    n = linea.length();

    for (i = 0; i < n; i++) {

      if (linea[i] == '-')
        this->tipo = 'I';
      
      // std::cout << linea[i] << " ";
      bases.insert(linea[i]);
    }
  }

  // Encontrar frecuencia por base
  std::set<char>::iterator itBases;

  for (itBases = bases.begin(); itBases != bases.end(); itBases++) {
    count = 0;
    base = *itBases;

    for (itLineas = l_lineas.begin(); itLineas != l_lineas.end(); itLineas++)
    {
      linea = *itLineas;
      n = linea.length();

      for (i = 0; i < n; i++) {
        if (base == linea[i])
          count++;
      }
    }

    std::cout << std::endl << base << ": " << count;
  }
  std::cout << std::endl;
}