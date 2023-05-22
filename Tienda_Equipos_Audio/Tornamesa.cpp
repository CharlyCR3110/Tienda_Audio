#include "Tornamesa.h"

Tornamesa::Tornamesa() :
	FuenteDeAudio()
{
}

Tornamesa::Tornamesa(std::string modelo, std::string caracteristicas, double precio):
	FuenteDeAudio(modelo, caracteristicas, precio)
{
}

Tornamesa::Tornamesa(const Tornamesa& other) :
	FuenteDeAudio(other)
{
}

Tornamesa::~Tornamesa()
{
}

std::string Tornamesa::toString() const
{
	std::stringstream ss;
	ss << "Tornamesa: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

Tornamesa& Tornamesa::operator=(const Tornamesa& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}
