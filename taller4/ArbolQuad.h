#ifndef __ARBOLQUAD__H__
#define __ARBOLQUAD__H__

#include <iostream>
#include <string>
#include "NodoQuad.h"
using namespace std;

class ArbolQuad
{
    protected:
        NodoQuad* raiz;
    public:
        ArbolQuad();
        ArbolQuad(int val);
        //~ArbolQuad();
        int datoRaiz();
        NodoQuad* obtenerRaiz();
        void fijarRaiz(NodoQuad* n_raiz);
        bool esVacio();
        bool insertar(int val);
        void preOrden();
        void inOrden(NodoQuad *node, int img_size, int x, int y);
        void posOrden();
        void nivelOrden();
        void toImage(string img_file, int img_size);
}; 

#include "ArbolQuad.hxx"

#endif // __ARBOLQUAD__H__

// eof - ArbolAVL.h



