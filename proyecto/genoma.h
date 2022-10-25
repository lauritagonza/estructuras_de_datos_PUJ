#ifndef _genoma__H__
#define _genoma__H__

#include <map>
#include <vector>
#include <string>
#include "secuencia.h"

class Genoma {
    public:
        Genoma();
        void AgregarLineaSecuencia(std::string descripcion_secuencia, std::string l_secuencia);
        int ObtenerNSecuencias();
        void setNombre(std::string nom);
        std::string getNombre(); 
        void ListarSecuencias();
        std::list<std::string> NombresSecuencias();
        std::map<char, long int> HistogramaTotal();

        void EliminarSecuencias();
        void HistogramaSecuencia(std::string descripcion_secuencia);
        void GuardarArchivo(std::string nombre_archivo);
        int esSubsecuencia(std::string secUsuario); 
        void enmascararSecuencia(std::string secUsuario);
        std::vector<char> stringtovector(std::string input);
        int nombreSecuencia();
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