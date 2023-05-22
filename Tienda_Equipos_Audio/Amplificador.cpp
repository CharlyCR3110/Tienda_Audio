#include "Amplificador.h"

Amplificador::Amplificador() :
	ProcesadorDeSenal()
{
}

Amplificador::Amplificador(std::string modelo, std::string caracteristicas, double precio) :
	ProcesadorDeSenal(modelo, caracteristicas, precio)
{
}

Amplificador::Amplificador(const Amplificador& other) :
	ProcesadorDeSenal(other)
{
}

Amplificador::~Amplificador()
{
}

std::string Amplificador::toString() const
{
	std::stringstream ss;
	ss << "Amplificador: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

Amplificador& Amplificador::operator=(const Amplificador& other)
{
	if (this != &other)
	{
		ProcesadorDeSenal::operator=(other);
	}
	return *this;
}