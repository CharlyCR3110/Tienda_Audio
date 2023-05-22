#include "Microfono.h"

Microfono::Microfono() :
	FuenteDeAudio()
{
}

Microfono::Microfono(std::string modelo, std::string caracteristicas, double precio) :
	FuenteDeAudio(modelo, caracteristicas, precio)
{
}

Microfono::Microfono(const Microfono& other) :
	FuenteDeAudio(other)
{
}

Microfono::~Microfono()
{
}

std::string Microfono::toString() const
{
	std::stringstream ss;
	ss << "Microfono: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

Microfono& Microfono::operator=(const Microfono& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}