#include "ArbolCod.h"
#include <iostream>
#include <vector>
#include <queue>


// ArbolCod::ArbolCod() {
//     this->raiz = NULL;
// }

ArbolCod::ArbolCod(int& val) {
    (this->raiz)->fijarSuma(val);
}

//Destructor
ArbolCod::~ArbolCod() {
    if(this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}

//Manipuladores
bool ArbolCod::esVacio() {
    return (this->raiz == NULL);
}

int ArbolCod::obtenerDato() {
    return (this->raiz)->obtenerSuma();
}

void ArbolCod::fijarRaiz(NodoCod *n_raiz) {
    this->raiz = n_raiz;   
}

NodoCod* ArbolCod::obtenerRaiz() {
    return this->raiz;
}

// To compare two points
void ArbolCod::insertar(std::queue <Base> C_bases) {

    bool insertado = false;

    std::priority_queue <NodoCod, std::vector<NodoCod*>, myComparator> C_pmin;
    
    while (!C_bases.empty())
    {
        Base b;
        b = C_bases.front();
        C_bases.pop();
        int sum = b.ObtenerFrecuencia();
        NodoCod* nuevo = new NodoCod(sum, b);
        C_pmin.push(nuevo);
    } 
 
    //Mientras la cola tenga más de dos datos
    //Cuando la cola tenga 1 dato, ese dato será la raíz del árbol
    while (C_pmin.size() > 1)
    {
        //Obtener nodos minimos de la cola
        NodoCod* n1 = C_pmin.top();
        C_pmin.pop();
        NodoCod* n2 = C_pmin.top();
        C_pmin.pop();
        int sum;
        sum = n1->obtenerSuma() + n2->obtenerSuma();

        NodoCod* c1 = new NodoCod (sum);
        c1->fijarHijoIzq(n1);
        c1->fijarHijoDer(n2);

        C_pmin.push(c1);
    } 

    NodoCod* aux = C_pmin.top();
    this->raiz = aux;

}

void ArbolCod::preOrden (){
  if (!this->esVacio())
    this->preOrden(this->raiz);
  std::cout << std::endl;
}


void ArbolCod::preOrden (NodoCod* nodo){

  if (nodo != NULL) {
    std::cout << nodo->obtenerSuma() << " ";
    this->preOrden(nodo->obtenerHijoIzq());
    this->preOrden(nodo->obtenerHijoDer());
  }
}


void ArbolCod::inOrden (){
  if(!this->esVacio())
    this->inOrden(this->raiz);
  std::cout << std::endl;
}


void ArbolCod::inOrden (NodoCod* nodo){
  
  if (nodo != NULL) {
    this->inOrden(nodo->obtenerHijoIzq());
    std::cout << nodo->obtenerSuma() << " ";
    this->inOrden(nodo->obtenerHijoDer());
  }
}

void ArbolCod::posOrden (){
  if (!this->esVacio())
    this->posOrden(this->raiz);
  std::cout << std::endl;
}

void ArbolCod::posOrden (NodoCod* nodo){
  if (nodo != NULL) {
    this->posOrden(nodo->obtenerHijoIzq());
    this->posOrden(nodo->obtenerHijoDer());
    std::cout << nodo->obtenerSuma() << " ";
  }
}


void ArbolCod::nivelOrden (){
  
  if (!this->esVacio()) {
    
    std::queue < NodoCod* > cola;
    cola.push(this->raiz);
    NodoCod* nodo;

    while (!cola.empty()) {
      nodo = cola.front();
      cola.pop();
      
      std::cout << nodo->obtenerSuma() << " ";

      if (nodo->obtenerHijoIzq() != NULL)
        cola.push(nodo->obtenerHijoIzq());
      
      if (nodo->obtenerHijoDer() != NULL)
        cola.push(nodo->obtenerHijoDer());
    }
  }
}
