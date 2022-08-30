#ifndef _secuencia__H__
#define _secuencia__H__

#include <string>
#include <list>
#include <set>

class Secuencia
{
    public:
        Secuencia();

        std::string ObtenerDescripcion();
        void FijarDescripcion(std::string descripcion_secuencia);
        void AgregarLinea(std::string linea_secuencia);
        int EncontrarBases();
        char getTipo();
        void Histograma();
        std::list<std::string> ObtenerLLineas();

        // std::vector<Base> getSecuencia(); 
        // void setSecuencia(std::vector<Base> secuencia);
        // void agregarSecuencia(); 
        // Base getTipo(); 
        // void setTipo(Base tipo);
        // void enmascararSecuencia(); 

    protected:
        std::string descripcion;
        std::list<std::string> l_lineas;
        std::set<char> bases;
        char tipo;
}; 

#endif // _secuencia__H__
