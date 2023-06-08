#include "ParlanteCat.h"

ParlanteCat::ParlanteCat() :
	Componente()
{
	this->_categoria = "Parlante";
}

ParlanteCat::ParlanteCat(std::string codigo, std::string caracteristicas, double precio) :
	Componente(codigo, caracteristicas, precio)
{
	this->_categoria = "Parlante";
}

ParlanteCat::ParlanteCat(const ParlanteCat& other) :
	Componente(other)
{
}

ParlanteCat::~ParlanteCat()
{
}

std::string ParlanteCat::toString() const
{
	std::stringstream ss;
	ss << "Codigo: " << _codigo << std::endl;
	ss << "Categoria: " << _categoria << std::endl;
	ss << "Nombre: " << _nombreComponente << std::endl;
	ss << "Caracteristicas: " << _caracteristicas << std::endl;
	ss << "Precio Unitario: " << _precio << std::endl;
	ss << "Cantidad: " << _cantidadEnElCarrito << std::endl;
	return ss.str();
}

ParlanteCat& ParlanteCat::operator=(const ParlanteCat& other)
{
	if (this != &other)
	{
		Componente::operator=(other);	// se llama al operador de asignacion de la clase base
	}
	return *this;
}