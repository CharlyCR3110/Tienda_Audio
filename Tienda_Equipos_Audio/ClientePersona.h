#pragma once
#include "Cliente.h"
#include <sstream>

// Cliente Fisico o Persona
class ClientePersona :
    public Cliente
{
public:
    ClientePersona();
    ClientePersona(std::string nombre, std::string cedula, std::string pais, std::string ciudad, std::string correo, std::string nacionalidad);
    ClientePersona(const ClientePersona& persona);
    ~ClientePersona() = default;
    // getters
    virtual std::string getCorreo() const;
    virtual std::string getNacionalidad() const;
    // setters
    virtual void setCorreo(std::string correo);
    virtual void setNacionalidad(std::string nacionalidad);
    // clonar
    virtual Cliente* clonar() const override;
    // mostrar
    virtual std::string toString() const override;
    // operadores
    ClientePersona& operator=(const ClientePersona& other);
    virtual bool operator==(const ClientePersona& other) const;
private:
    std::string _correo;
    std::string _nacionalidad;
};