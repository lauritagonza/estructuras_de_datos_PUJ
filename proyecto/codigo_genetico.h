#ifndef _codigo_genetico__H__
#define _codigo_genetico__H__

#include <vector>
#include "base.h"

class codigoGenetico {
public:
codigoGenetico();
std::vector<base> getSecuencia(); 
void setSecuencia(std::vector<base> secuencia);
void agregarSecuencia(); 
base getTipo(); 
void setTipo(base tipo);
void enmascararSecuencia(); 

protected:
std::vector<base> secuencia; 
}; 

#endif // _codigoGenetico__H__
