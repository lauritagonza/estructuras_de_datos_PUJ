#include "genoma.h"
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
std::string Genoma::getNombre(){
  return this->nombre;
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
    n_bases = itSec->EncontrarBases(true);
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

std::map<char, long int> Genoma::HistogramaTotal()
{
  std::map<char, long int> dict_total, dict_aux;
  std::map<char, long int>::iterator it;
  std::list<Secuencia>::iterator itSec;

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++)
  {
      dict_aux = itSec->Histograma(false);

      for (it=dict_aux.begin(); it!=dict_aux.end(); ++it)
      {
        if (dict_total[it->first] )
          dict_total[it->first] += it->second;
        else
          dict_total[it->first] = it->second;
      }
  }
  return dict_total;
}

void Genoma::HistogramaSecuencia(std::string descripcion_secuencia)
{
  bool encontrada = false;
  std::list<Secuencia>::iterator itSec;

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++)
  {
    if (itSec->ObtenerDescripcion() == descripcion_secuencia)
    {
      itSec->Histograma(true);
      encontrada = true;
    }
  }

  if (!encontrada)
    std::cout << std::endl << "Secuencia invalida." << std::endl;
}

int Genoma::esSubsecuencia(std::string secUsuario){
  std::list<Secuencia>::iterator itSec;
  std::list<std::string> l_lineas; 
  std::list<std::string>::iterator itLineas;
  int n=0; 
  std::string nuevo; 

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++ )
  { 
    l_lineas=itSec->ObtenerLLineas(); 
    
     for (itLineas = l_lineas.begin(); itLineas != l_lineas.end(); itLineas++)
    {
      nuevo=*itLineas;
      bool found = nuevo.find(secUsuario) != std::string::npos;
    if(found)
    n++;
    }
    }
  return n; 
  }

void Genoma::enmascararSecuencia(std::string secUsuario){
   std::list<Secuencia>::iterator itSec;
  std::list<std::string> l_lineas; 
  std::list<std::string>::iterator itLineas; 
  std::string nuevo, des; 
  
  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++ )
  { 
    l_lineas=itSec->ObtenerLLineas(); 
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
        cadenaNuevo[n+i]='X';
          }
      std::string nuevaLinea(cadenaNuevo);
      std::cout<<nuevaLinea; 
       l_lineas.push_back(nuevaLinea); 
}
    }
    
    }
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

std::vector<char> Genoma::stringtovector(std::string input){
  char nuevo; 
  std::vector<char> results; 

  char* nstring = std::strcpy(new char[input.length() + 1], input.c_str());

  for(int i=0; i<input.length(); i++){
    nuevo=nstring[i];
    results.push_back(nuevo); 
    //cout<<endl<<results[i]; 
  }
  
  return results;
}


int Genoma::nombreSecuencia(){
   std::list<Secuencia>::iterator itSec;
  std::string descripcion; 
   int tamano_descripcion;
  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++ )
  {
    descripcion = itSec->ObtenerDescripcion();
    tamano_descripcion=stringtovector(descripcion).size();
    std::cout<<descripcion<<tamano_descripcion<<std::endl;
    }
  return tamano_descripcion;

}

/*/
void Genoma::enmascararSecuencia(std::string secUsuario){
 std::list<Secuencia>::iterator itSec;
  std::string descripcion; 
   std::list<std::string> l_lineas;
  std::list<std::string>::iterator itLineas;

  for (itSec = l_secuencias.begin(); itSec != l_secuencias.end(); itSec++)
  { 
   l_lineas =enmascararSec(secUsuario);
      itSec->l_lineas.ObtenerLLineas(); 
  }
  }
*/