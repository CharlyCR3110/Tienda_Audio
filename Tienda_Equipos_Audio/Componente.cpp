#include "Componente.h"

Componente::Componente() :
	_modelo(""),
	_caracteristicas(""),
	_precio(0.0)
{
}

Componente::Componente(std::string modelo, std::string caracteristicas, double precio) :
	_modelo(modelo), 
	_caracteristicas(caracteristicas), 
	_precio(precio)
{
}

Componente::Componente(const Componente& other):
	_modelo(other._modelo),
	_caracteristicas(other._caracteristicas),
	_precio(other._precio)
{
}

Componente::~Componente()
{
}

// getters y setters. No cambian en las clases hijas, por lo que se pueden implementar aqui
std::string Componente::getNombre() const
{
	return _modelo;
}

std::string Componente::getCaracteristicas() const
{
	return _caracteristicas;
}

double Componente::getPrecio() const
{
	return _precio;
}

void Componente::setNombre(std::string modelo)
{
	_modelo = modelo;
}

void Componente::setCaracteristicas(std::string caracteristicas)
{
	_caracteristicas = caracteristicas;
}

void Componente::setPrecio(double precio)
{
	_precio = precio;
}

Componente& Componente::operator=(const Componente& other)
{
	if (this != &other)
	{
		this->_modelo = other._modelo;
		this->_caracteristicas = other._caracteristicas;
		this->_precio = other._precio;
	}
	return *this;
}

// no es necesario implementar el operaedor de salida en las clases hijas, ya que se puede implementar aqui
std::ostream& operator<<(std::ostream& out, const Componente& other)
{
	out << other.toString();
	return out;
}