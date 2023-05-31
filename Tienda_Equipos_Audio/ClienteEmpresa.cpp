#include "ClienteEmpresa.h"

ClienteEmpresa::ClienteEmpresa():
	Cliente(),
	_razonSocial("0")
{
}

ClienteEmpresa::ClienteEmpresa(std::string nombre, std::string cedula, std::string pais, std::string ciudad, std::string razonSocial):
	Cliente(nombre, cedula, pais, ciudad),
	_razonSocial(razonSocial)
{
}

ClienteEmpresa::ClienteEmpresa(const ClienteEmpresa& empresa):
	Cliente(empresa),
	_razonSocial(empresa._razonSocial)
{
}

std::string ClienteEmpresa::getRazonSocial() const
{
	return _razonSocial;
}

void ClienteEmpresa::setRazonSocial(std::string razonSocial)
{
	_razonSocial = razonSocial;
}

Cliente* ClienteEmpresa::clonar() const
{
	return new ClienteEmpresa(*this);
}

std::string ClienteEmpresa::toString() const
{
	std::stringstream ss;
	ss << "---EMPRESA---" << std::endl;
	ss << "Nombre: " << _nombre << std::endl;
	ss << "Cedula Juridica: " << _cedula << std::endl;
	ss << "Pais: " << _pais << std::endl;
	ss << "Ciudad: " << _ciudad << std::endl;
	ss << "Razon Social: " << _razonSocial << std::endl;
	ss << "--------------" << std::endl;
	return ss.str();
}

ClienteEmpresa& ClienteEmpresa::operator=(const ClienteEmpresa& other)
{
	if (this != &other)
	{
		Cliente::operator=(other);
		_razonSocial = other._razonSocial;
	}
	return *this;
}