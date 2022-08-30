#ifndef _genoma__H__
#define _genoma__H__

#include <vector>
#include <string>
#include "secuencia.h"

class Genoma {
    public:
        Genoma();
        void AgregarLineaSecuencia(std::string descripcion_secuencia, std::string l_secuencia);
        int ObtenerNSecuencias();
        void setNombre(std::string nom);
        void ListarSecuencias();
        void EliminarSecuencias();
        void HistogramaSecuencia(std::string descripcion_secuencia);
        
        // void setlSecuencias(std::vector<Secuencia> secuencias);
        // void agregarlSecuencias();
        // void setTipo(char tipo);
        // void enmascararSecuencia(); 
        // void esSubsecuencia(); 

    protected:
        std::string nombre;
        std::list <Secuencia> l_secuencias;
        char tipo;
        unsigned long n_secuencias;
};

#endif // _genoma__H__