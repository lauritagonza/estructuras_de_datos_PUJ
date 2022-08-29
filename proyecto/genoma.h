#ifndef _genoma__H__
#define _genoma__H__

#include <vector>
#include <string>
#include "secuencia.h"

class Genoma {
    public:
        Genoma();
        void AgregarLineaSecuencia(std::string descripcion_secuencia, std::string l_secuencia);
        
        // void setlSecuencias(std::vector<Secuencia> secuencias);
        // void agregarlSecuencias();
        // void setTipo(char tipo);
        // void setNombre(std::string nom); 
        // void enmascararSecuencia(); 
        // void esSubsecuencia(); 

    protected:
        std::string nombre;
        std::list <Secuencia> l_secuencias;
        char tipo;
        int n_secuencias;
};

#endif // _genoma__H__