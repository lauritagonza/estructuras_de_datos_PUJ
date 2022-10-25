#include <iostream>
#include "NodoCod.h"

NodoCod::NodoCod() {
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

NodoCod::NodoCod(int val) {
    this->suma = val;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

NodoCod::NodoCod(Base& bas) {
    Base b = bas;
    this->base.FijarFrecuencia(b.ObtenerFrecuencia());
    this->base.FijarBase(b.ObtenerBase());
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

NodoCod::NodoCod(int val, Base &bas) {
    this->suma = val;
    Base b = bas;
    this->base.FijarFrecuencia(b.ObtenerFrecuencia());
    this->base.FijarBase(b.ObtenerBase());
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

NodoCod::~NodoCod() {
    if (this->hijoIzq != NULL) {
        delete this->hijoIzq;
        this->hijoIzq = NULL;
        }

    if (this->hijoDer != NULL) {
        delete this->hijoDer;
        this->hijoDer = NULL;
        }
}

int NodoCod::obtenerSuma(){
    return this->suma;
}

void NodoCod::fijarSuma(int val) {
    this->suma = val;
}

Base& NodoCod::obtenerBase() {
    return this->base;   
}

void NodoCod::fijaBase(Base& base) {
    this->base = base;
}

NodoCod* NodoCod::obtenerHijoIzq() {
    return this->hijoIzq;
}

NodoCod* NodoCod::obtenerHijoDer() {
    return this->hijoDer;
}

void NodoCod::fijarHijoIzq(NodoCod* izq) {
    this->hijoIzq = izq;
}

void NodoCod::fijarHijoDer(NodoCod* der) {
    this->hijoDer = der;
}

bool NodoCod::esHoja() {
    return((this->hijoDer == NULL) && (this->hijoIzq == NULL));
  }
