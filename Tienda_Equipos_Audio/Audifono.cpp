#include "Audifono.h"

Audifono::Audifono() :
	ParlanteCat()
{
}

Audifono::Audifono(std::string modelo, std::string caracteristicas, double precio) :
	ParlanteCat(modelo, caracteristicas, precio)
{
}

Audifono::Audifono(const Audifono& other) :
	ParlanteCat(other)
{
}

Audifono::~Audifono()
{
}

std::string Audifono::toString() const
{
	std::stringstream ss;
	ss << "Audifono: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

Audifono& Audifono::operator=(const Audifono& other)
{
	if (this != &other)
	{
		ParlanteCat::operator=(other);
	}
	return *this;
}