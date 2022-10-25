#ifndef __NODOCOD__H__
#define __NODOCOD__H__

#include "Base.h"

class NodoCod {
    //Atributos
    private:
    Base base;
    int suma;
    NodoCod* hijoIzq;
    NodoCod* hijoDer;
    
    public:
    //Constructores
    NodoCod();
    NodoCod(int);
    NodoCod(Base&);
    NodoCod(int, Base&);
    //Destructor
    ~NodoCod();
    //Manipuladores
    int obtenerSuma();
    void fijarSuma(int);
    Base& obtenerBase();
    void fijaBase(Base&);
    NodoCod* obtenerHijoIzq();
    NodoCod* obtenerHijoDer();
    void fijarHijoIzq(NodoCod* izq);
    void fijarHijoDer(NodoCod* der);
    bool esHoja();
    //Operaciones
};

class myComparator: public NodoCod {
public:
    int operator() (NodoCod* p1, NodoCod* p2)
    {
        return p1->obtenerSuma() > p2->obtenerSuma();
    }
};

#include "NodoCod.hxx"

#endif // __NODOCOD__H__

// eof - NodoCod.h