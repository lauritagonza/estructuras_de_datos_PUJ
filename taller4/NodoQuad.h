#ifndef __NODOQUAD__H__
#define __NODOQUAD__H__

#include <iostream>
#include <string>
using namespace std;


class NodoQuad
{
    protected:
        int dato;
        NodoQuad* hijoSupIzq; // (0, 0)
        NodoQuad* hijoSupDer; // (0, 1)
        NodoQuad* hijoInfDer; // (1, 1)
        NodoQuad* hijoInfIzq; // (1, 0)
    public:
        NodoQuad();
        NodoQuad(int val);
        ~NodoQuad();
        int obtenerDato();
        void fijarDato(int val);
        NodoQuad* obtenerHijoSupIzq();
        NodoQuad* obtenerHijoSupDer();
        NodoQuad* obtenerHijoInfDer();
        NodoQuad* obtenerHijoInfIzq();
        void fijarHijoSupIzq(NodoQuad* sizq);
        void fijarHijoSupDer(NodoQuad* sder);
        void fijarHijoInfDer(NodoQuad* ider);
        void fijarHijoInfIzq(NodoQuad* iizq);
        bool insert(int val, NodoQuad* nodo);
}; 

#include "NodoQuad.hxx"

#endif // __NODOQUAD__H__

// eof - NodoQuad.h



