#include "secuencia.h"
#include <iostream>
#include <map>

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

int Secuencia::EncontrarBases(bool v)
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

  if (v)
    std::cout << std::endl <<"Bases encontradas: " << std::endl; 

  std::set<char>::iterator itBases;

  if (v) {
    for (itBases = bases.begin(); itBases != bases.end(); itBases++) {
      std::cout << ' ' << *itBases;
    }
  }
  return bases.size();
}

char Secuencia::getTipo()
{
  return tipo;
}

std::map<char, long int> Secuencia::Histograma(bool v)
{
  std::map<char, long int> dict_hist;
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

    dict_hist[base] = count;
    
    if (v)
      std::cout << std::endl << base << ": " << count;
  }
  if (v)
    std::cout << std::endl;

  return dict_hist;
}

std::list<std::string> Secuencia::ObtenerLLineas()
{
  return l_lineas;
}



/*
std::list<std::string>Secuencia::enmascararSec(std::string secUsuario){
  std::list<std::string>::iterator itLineas; 
  std::string nuevo; 
      int n=0; 
     for (itLineas = l_lineas.begin(); itLineas != l_lineas.end(); itLineas++)
    {
      nuevo=*itLineas;
      n++; 
      bool found = nuevo.find(secUsuario) != std::string::npos;
    if(found){
      char* cadenaNuevo=&nuevo[0]; 
      //cadenaNuevo=stringtovector(*itLineas);
      for(int i=0; i<secUsuario.size(); i++){
        std::cout<<n+i; 
        cadenaNuevo[n+i]='X';
          }
      std::string nuevaLinea(cadenaNuevo);
      std::cout<<nuevaLinea; 
        l_lineas.push_back(nuevaLinea); 
      return l_lineas; 
    }
}
}
*/