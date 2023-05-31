#pragma once
#include "Cliente.h"
#include <sstream>
class ClienteEmpresa :
    public Cliente
{
public:
	ClienteEmpresa();
	ClienteEmpresa(std::string nombre, std::string cedula, std::string pais, std::string ciudad, std::string razonSocial);
	ClienteEmpresa(const ClienteEmpresa& empresa);
	~ClienteEmpresa() = default;
	// getters
	virtual std::string getRazonSocial() const;
	// setters
	virtual void setRazonSocial(std::string razonSocial);
	// clonar
	virtual Cliente* clonar() const override;
	// mostrar
	virtual std::string toString() const override;
	// operadores
	ClienteEmpresa& operator=(const ClienteEmpresa& other);
private:
	std::string _razonSocial;	// para meter relleno, pero es 0 necesario
};


//protected:
//	std::string _nombre;
//	std::string _cedula;
//	std::string _pais;
//	std::string _ciudad;
//};
