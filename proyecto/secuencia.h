#ifndef _secuencia__H__
#define _secuencia__H__

#include <string>
#include <list>

class Secuencia
{
    public:
        Secuencia();

        std::string ObtenerDescripcion();
        void FijarDescripcion(std::string descripcion_secuencia);
        void AgregarLinea(std::string linea_secuencia);

        // std::vector<Base> getSecuencia(); 
        // void setSecuencia(std::vector<Base> secuencia);
        // void agregarSecuencia(); 
        // Base getTipo(); 
        // void setTipo(Base tipo);
        // void enmascararSecuencia(); 

    protected:
        std::string descripcion;
        std::list<std::string> l_lineas; 
}; 

#endif // _secuencia__H__
