#include "Cliente.h"

Cliente::Cliente():
	_nombre(""),
	_cedula(""),
	_pais(""),
	_ciudad("")
{
}

Cliente::Cliente(std::string nombre, std::string cedula, std::string pais, std::string ciudad):
	_nombre(nombre),
	_cedula(cedula),
	_pais(pais),
	_ciudad(ciudad)
{
}

Cliente::Cliente(const Cliente& other):
	_nombre(other._nombre),
	_cedula(other._cedula),
	_pais(other._pais),
	_ciudad(other._ciudad)
{
}

std::string Cliente::getNombre() const
{
	return _nombre;
}

std::string Cliente::getCedula() const
{
	return _cedula;
}

std::string Cliente::getPais() const
{
	return _pais;
}

std::string Cliente::getCiudad() const
{
	return _ciudad;
}

void Cliente::setNombre(std::string nombre)
{
	_nombre = nombre;
}

void Cliente::setCedula(std::string cedula)
{
	_cedula = cedula;
}

void Cliente::setPais(std::string pais)
{
	_pais = pais;
}

void Cliente::setCiudad(std::string ciudad)
{
	_ciudad = ciudad;
}

Cliente& Cliente::operator=(const Cliente& other)
{
	if (this != &other)
	{
		_nombre = other._nombre;
		_cedula = other._cedula;
		_pais = other._pais;
		_ciudad = other._ciudad;
	}
	return *this;
}

bool Cliente::operator==(const Cliente& other) const
{
	return _cedula == other._cedula;	// solo importa la cedula porque debe de ser unica
}

std::ostream& operator<<(std::ostream& out, const Cliente& other)
{
	out << other.toString();
	return out;
}
