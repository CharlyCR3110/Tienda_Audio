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
