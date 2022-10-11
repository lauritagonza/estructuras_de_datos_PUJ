#include "ArbolQuad.h"
#include <iostream>
#include <fstream>
using namespace std; 

ArbolQuad::ArbolQuad() {
  this->raiz = NULL;
}

ArbolQuad::ArbolQuad(int val) {
  this->raiz = new NodoQuad(val);
}

//Destructor
// ArbolQuad::~ArbolQuad() {
//   if (this->raiz != NULL) {
//     delete this->raiz;
//     this->raiz = NULL;
//   }
// }

//Raiz
NodoQuad* ArbolQuad::obtenerRaiz() {
  return this->raiz;
}

void ArbolQuad::fijarRaiz(NodoQuad *n_raiz) {
  this->raiz = n_raiz;
}

//EsVacio
bool ArbolQuad::esVacio() {
  return (this->raiz == NULL);
}

//METODOS
//Insertar

bool ArbolQuad::insertar(int val) {
  bool res = false;
  
  if (this->raiz == NULL)
  {
    this->raiz = new NodoQuad(val);
    return true;
  }

  else
  {
    NodoQuad *parent_node = this->raiz;

    return parent_node->insert(val, parent_node);
  }
  
  return res;
}

void save_mtx(int **matrix, int img_size, string nombre_imagen)
{
  ofstream myfile (nombre_imagen);

  if (myfile.is_open())
  {
    myfile << "P1" << endl;
    myfile << img_size << " " << img_size << endl;
    
    for (int i = 0; i < img_size; i++)
    {
      for (int j = 0; j < img_size; j++)
      {
        myfile << matrix[i][j];
      }
      myfile << endl;
    }
  }
}

void fill_mtx(int **matrix, int x, int y, int act_size, int val)
{
  for (int i = x; i < x + act_size; i++)
  {
    for (int j = y; j < y + act_size; j++)
    {
      matrix[i][j] = val;
    }
  }

}

void Init_2D_Array(int*** foo, int x_size, int y_size)
{
  *foo = new int*[x_size];    // new alloc mem lost post func exit
  for (int i=0;i<x_size;i++)
  {
      (*foo)[i] = new int[y_size];     // new alloc mem lost post func exit
  }
}


void color(NodoQuad *node, int full_size, int img_size, int x, int y, int **matrix)
{
  if (node != NULL)
    {
        // cout << node->obtenerDato() << " " << img_size << endl << endl;

        fill_mtx(matrix, x, y, img_size, node->obtenerDato());

        img_size /= 2;
        color(node->obtenerHijoSupIzq(), full_size, img_size, x, y, matrix);
        color(node->obtenerHijoSupDer(), full_size, img_size, x, y + img_size, matrix);
        color(node->obtenerHijoInfDer(), full_size, img_size, x + img_size, y + img_size, matrix);
        color(node->obtenerHijoInfIzq(), full_size, img_size, x + img_size, y, matrix);
    }
}

void ArbolQuad::toImage(string img_file, int img_size)
{
  int** matrix = NULL;
  Init_2D_Array(&matrix, img_size, img_size);
  fill_mtx(matrix, 0, 0, img_size, 2);

  color(this->raiz, img_size, img_size, 0, 0, matrix);
  save_mtx(matrix, img_size, img_file);
}

// eof - ArbolAVL.hxx
