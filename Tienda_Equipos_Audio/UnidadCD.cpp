#include "UnidadCD.h"

UnidadCD::UnidadCD() :
	FuenteDeAudio()
{
}

UnidadCD::UnidadCD(std::string modelo, std::string caracteristicas, double precio) :
	FuenteDeAudio(modelo, caracteristicas, precio)
{
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
	ss << "UnidadCD: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
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
