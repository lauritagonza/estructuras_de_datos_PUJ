/*
    Taller 4

    Estructuras de datos

    Laura Gonzales
    Victoria Chavarro
    Emma Gachancipa

    Compilar:
        g++ -std=c++11 main.cpp -o main
    Ejecutar:
        ./main
*/
#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include "ArbolQuad.h"
using namespace std;

void cargar(string nombre_archivo, ArbolQuad arbolito); 

int main() {
  string nombre_archivo;
  cout << "Ingresa el nombre del archivo que desea leer" << endl;
  cin >> nombre_archivo;
  ArbolQuad arbolito;
  cargar(nombre_archivo, arbolito);
}

void cargar(string nombre_archivo, ArbolQuad arbolito){

  cout << endl << "Cargando archivo:  " << nombre_archivo << endl;
  ifstream archivo_lectura(nombre_archivo);

  // Verificar si el archivo existe
  if (!archivo_lectura) {
    cout << endl << nombre_archivo << ":   No se encuentra o no puede leerse" << endl;
  }

  int width, height;
  int n=0;
  string c;
  string line;  

  // Leer archivo
  while (!archivo_lectura.eof())
  {
    archivo_lectura >> line;

    if (n == 0)
    {
      width = stoi(line);
      cout << "Ancho: " << width << endl; 
    }
    else if (n == 1)
    {
      height = stoi(line);
      cout << "Alto: " << height << endl; 
    } 
    // else
    //   cout << "Imagen: " << line << endl; 
    
    n++;
  }
  
  archivo_lectura.close();

  // Funcion para insertar los valores en el arbol

  for (int i = 0; i < (line.length()); i++)
  {
    c = line[i];
    arbolito.insertar(stoi(c));
  }
  arbolito.toImage("img.png", width);
}
