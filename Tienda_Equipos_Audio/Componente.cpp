#include "Componente.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Componente::Componente() :	// constructor por defecto
	_codigo(""),
	_caracteristicas(""),
	_precio(0.0),
	_categoria(""),
	_nombreComponente(""),
	_cantidadEnElCarrito(1)
{
}

Componente::Componente(std::string codigo, std::string caracteristicas, double precio) :
	_codigo(codigo),
	_caracteristicas(caracteristicas), 
	_precio(precio),
	_cantidadEnElCarrito(1)
{
}

Componente::Componente(const Componente& other):
	_codigo(other._codigo),
	_caracteristicas(other._caracteristicas),
	_precio(other._precio),
	_categoria(other._categoria),
	_nombreComponente(other._nombreComponente),
	_cantidadEnElCarrito(other._cantidadEnElCarrito)
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
	return _precio * _cantidadEnElCarrito;
}

double Componente::getPrecioUnitario() const
{
	return _precio;
}

std::string Componente::getCategoria() const
{
	return _categoria;
}

std::string Componente::getNombreComponente() const
{
	return _nombreComponente;
}

std::string Componente::getNombre() const
{
	return std::string();
}


int Componente::getCantidadEnCarrito() const
{
	return _cantidadEnElCarrito;
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

// estos 2 metodos no deberian de utilizarse
void Componente::setCategoria(std::string categoria)
{
	_categoria = categoria;
}

void Componente::setNombreComponente(std::string nombre)
{
	_nombreComponente = nombre;
}
//

void Componente::setNombre(std::string nombreDelPaquete)
{
	// aqui no se hace nada
}

void Componente::setCantidadEnCarrito(int cantidad)
{
	_cantidadEnElCarrito = cantidad;
}

void Componente::setChild(int i, Componente* componente)
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
		this->_categoria = other._categoria;
		this->_nombreComponente = other._nombreComponente;
	}
	return *this;
}

bool Componente::operator==(const Componente& other) const
{
	return this->_codigo == other._codigo && this->_caracteristicas == other._caracteristicas && this->_precio == other._precio && this->_categoria == other._categoria && this->_nombreComponente == other._nombreComponente;
}

// no es necesario implementar el operaedor de salida en las clases hijas, ya que se puede implementar aqui
std::ostream& operator<<(std::ostream& out, const Componente& other)
{
	out << other.toString();
	return out;
}