#ifndef __genoma__H__
#define __genoma__H__

#include <vector>
#include <string>
#include "codigo_genetico.h"

class genoma {
public:
genoma();
std::vector<codigoGenetico> getlSecuencias(); 
void setlSecuencias(std::vector<codigoGenetico> secuencias);
void agregarlSecuencias(); 
char getTipo(); 
void setTipo(char tipo);
std::string getNombre();
void setNombre(std::string nom); 
void enmascararSecuencia(); 
void esSubsecuencia(); 

protected:
std::string nombre;
std::vector <codigoGenetico> lsecuencias; 
char tipo; 

};

#endif // _genoma__H__
