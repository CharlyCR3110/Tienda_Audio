#include "Radio.h"

Radio::Radio() :
	FuenteDeAudio()
{
}

Radio::Radio(std::string modelo, std::string caracteristicas, double precio) :
	FuenteDeAudio(modelo, caracteristicas, precio)
{
}

Radio::Radio(const Radio& other) :
	FuenteDeAudio(other)
{
}

Radio::~Radio()
{
}

std::string Radio::toString() const
{
	std::stringstream ss;
	ss << "Radio: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

Radio& Radio::operator=(const Radio& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}