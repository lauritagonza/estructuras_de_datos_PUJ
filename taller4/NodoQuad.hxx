#include "NodoQuad.h"
#include <iostream>
using namespace std; 


NodoQuad::NodoQuad() {
  this->hijoSupIzq = NULL;
  this->hijoSupDer = NULL;
  this->hijoInfIzq = NULL;
  this->hijoInfDer = NULL;
}

NodoQuad::NodoQuad(int val){
  this->dato = val;
  this->hijoSupIzq = NULL;
  this->hijoSupDer = NULL;
  this->hijoInfIzq = NULL;
  this->hijoInfDer = NULL;
}

int NodoQuad::obtenerDato() {
  return this->dato;
}
void NodoQuad::fijarDato(int val) {
  this->dato = val;
}

NodoQuad* NodoQuad::obtenerHijoSupIzq() {
  return this->hijoSupIzq;
}
NodoQuad* NodoQuad::obtenerHijoSupDer() {
  return this->hijoSupDer;
}
NodoQuad* NodoQuad::obtenerHijoInfIzq() {
  return this->hijoInfIzq;
}
NodoQuad* NodoQuad::obtenerHijoInfDer() {
  return this->hijoInfDer;
}

void NodoQuad::fijarHijoSupIzq(NodoQuad *sizq) {
  this->hijoSupIzq = sizq;
}
void NodoQuad::fijarHijoSupDer(NodoQuad *sder) {
  this->hijoSupDer = sder;
}
void NodoQuad::fijarHijoInfIzq(NodoQuad *iizq) {
  this->hijoInfIzq = iizq;
}
void NodoQuad::fijarHijoInfDer(NodoQuad *ider) {
  this->hijoInfDer = ider;
}

bool full_node(NodoQuad* nodo)
{
  int hojas = 0;

  if (nodo->obtenerHijoSupIzq() != NULL)
    hojas++;
  if (nodo->obtenerHijoSupDer() != NULL)
    hojas++;
  if (nodo->obtenerHijoInfDer() != NULL)
    hojas++;
  if (nodo->obtenerHijoInfIzq() != NULL)
    hojas++;

  if (hojas == 4)
    return true;

  return false;
}

bool NodoQuad::insert(int val, NodoQuad* nodo) {
  bool res = false;
  bool full = false;
  NodoQuad *actual_node = nodo;
  NodoQuad *new_node;

  if (actual_node->obtenerDato() == 2)
  {
    if (actual_node->obtenerHijoSupIzq() == NULL)
    {
      new_node = new NodoQuad(val);
      actual_node->fijarHijoSupIzq(new_node);
      return true;
    }
    else if (actual_node->obtenerHijoSupIzq() != NULL)
    {
      if (actual_node->obtenerHijoSupIzq()->obtenerDato() == 2)
      {
        full = full_node(actual_node->obtenerHijoSupIzq());
      
        if (full == false)
        {
          res = this->insert(val, actual_node->obtenerHijoSupIzq());

          if (res == true)
            return true;
        }
      }
    }

    if (actual_node->obtenerHijoSupDer() == NULL)
    {
      new_node = new NodoQuad(val);
      actual_node->fijarHijoSupDer(new_node);
      return true;
    }
    else if (actual_node->obtenerHijoSupDer() != NULL)
    {
      if (actual_node->obtenerHijoSupDer()->obtenerDato() == 2)
      {
        full = full_node(actual_node->obtenerHijoSupDer());
        
        if (full == false)
        {
          res = this->insert(val, actual_node->obtenerHijoSupDer());

          if (res == true)
            return true;
        }
      }
    }
    if (actual_node->obtenerHijoInfDer() == NULL)
    {
      new_node = new NodoQuad(val);
      actual_node->fijarHijoInfDer(new_node);
      return true;
    }
    else if (actual_node->obtenerHijoInfDer() != NULL)
    {
      if (actual_node->obtenerHijoInfDer()->obtenerDato() == 2)
      {
        full = full_node(actual_node->obtenerHijoInfDer());
      
        if (full == false)
        {
          res = this->insert(val, actual_node->obtenerHijoInfDer());

          if (res == true)
            return true;
        }
      }
      
    }
    if (actual_node->obtenerHijoInfIzq() == NULL)
    {
      new_node = new NodoQuad(val);
      actual_node->fijarHijoInfIzq(new_node);
      return true;
    }
    else if (actual_node->obtenerHijoInfIzq() != NULL)
    {
      if (actual_node->obtenerHijoInfIzq()->obtenerDato() == 2)
      {
        full = full_node(actual_node->obtenerHijoInfIzq());
        
        if (full == false)
        {
          res = this->insert(val, actual_node->obtenerHijoInfIzq());

          if (res == true)
            return true;
        }
      }
    }
  }
  return false;
}

// eof - NodoQuad.hxx