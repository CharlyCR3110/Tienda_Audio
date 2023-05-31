#include "Componente.h"

Componente::Componente() :
	_codigo(""),
	_caracteristicas(""),
	_precio(0.0)
{
}

Componente::Componente(std::string codigo, std::string caracteristicas, double precio) :
	_codigo(codigo),
	_caracteristicas(caracteristicas), 
	_precio(precio)
{
}

Componente::Componente(const Componente& other):
	_codigo(other._codigo),
	_caracteristicas(other._caracteristicas),
	_precio(other._precio)
{
}

Componente::~Componente()
{
}

// getters y setters. No cambian en las clases hijas, por lo que se pueden implementar aqui
std::string Componente::getCodigo() const
{
	return _codigo;
}

std::string Componente::getCaracteristicas() const
{
	return _caracteristicas;
}

double Componente::getPrecio() const
{
	return _precio;
}

std::string Componente::getNombre() const
{
	return std::string();
}


void Componente::setCodigo(std::string codigo)
{
	_codigo = codigo;
}

void Componente::setCaracteristicas(std::string caracteristicas)
{
	_caracteristicas = caracteristicas;
}

void Componente::setPrecio(double precio)
{
	_precio = precio;
}

void Componente::setNombre(std::string nombreDelPaquete)
{
	// aqui no se hace nada
}

Componente& Componente::operator=(const Componente& other)
{
	if (this != &other)
	{
		this->_codigo = other._codigo;
		this->_caracteristicas = other._caracteristicas;
		this->_precio = other._precio;
	}
	return *this;
}

bool Componente::operator==(const Componente& other) const
{
	return this->_codigo == other._codigo && this->_caracteristicas == other._caracteristicas && this->_precio == other._precio;
}

// no es necesario implementar el operaedor de salida en las clases hijas, ya que se puede implementar aqui
std::ostream& operator<<(std::ostream& out, const Componente& other)
{
	out << other.toString();
	return out;
}