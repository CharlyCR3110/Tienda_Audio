#include "UnidadCD.h"

UnidadCD::UnidadCD() :
	FuenteDeAudio()
{
	this->_nombreComponente = "UnidadCD";
}

UnidadCD::UnidadCD(std::string codigo, std::string caracteristicas, double precio) :
	FuenteDeAudio(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "UnidadCD";
}

UnidadCD::UnidadCD(const UnidadCD& other) :
	FuenteDeAudio(other)
{
}

UnidadCD::~UnidadCD()
{
}

std::string UnidadCD::toString() const
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

Componente* UnidadCD::clonar() const
{
	return new UnidadCD(*this);
}

void UnidadCD::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void UnidadCD::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* UnidadCD::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void UnidadCD::clear()
{
	// Es una leaf, no tiene hijos
}

UnidadCD& UnidadCD::operator=(const UnidadCD& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}
