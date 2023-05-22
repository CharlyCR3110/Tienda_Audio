#include "Mezclador.h"

Mezclador::Mezclador() :
	ProcesadorDeSenal()
{
}

Mezclador::Mezclador(std::string modelo, std::string caracteristicas, double precio) :
	ProcesadorDeSenal(modelo, caracteristicas, precio)
{
}

Mezclador::Mezclador(const Mezclador& other) :
	ProcesadorDeSenal(other)
{
}

Mezclador::~Mezclador()
{
}

std::string Mezclador::toString() const
{
	std::stringstream ss;
	ss << "Mezclador: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

Mezclador& Mezclador::operator=(const Mezclador& other)
{
	if (this != &other)
	{
		ProcesadorDeSenal::operator=(other);
	}
	return *this;
}