#include "Parlante.h"

Parlante::Parlante() :
	ParlanteCat()
{
}

Parlante::Parlante(std::string modelo, std::string caracteristicas, double precio) :
	ParlanteCat(modelo, caracteristicas, precio)
{
}

Parlante::Parlante(const Parlante& other) :
	ParlanteCat(other)
{
}

Parlante::~Parlante()
{
}

std::string Parlante::toString() const
{
	std::stringstream ss;
	ss << "Parlante: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

Parlante& Parlante::operator=(const Parlante& other)
{
	if (this != &other)
	{
		ParlanteCat::operator=(other);
	}
	return *this;
}