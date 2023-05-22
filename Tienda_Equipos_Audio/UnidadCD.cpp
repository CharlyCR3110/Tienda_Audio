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

UnidadCD& UnidadCD::operator=(const UnidadCD& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}
