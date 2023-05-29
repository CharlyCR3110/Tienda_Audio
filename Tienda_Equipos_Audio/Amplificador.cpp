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

Componente* Amplificador::clonar() const
{
	return new Amplificador(*this);
}

void Amplificador::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Amplificador::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Amplificador::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Amplificador::clear()
{
	// Es una leaf, no tiene hijos
}

Amplificador& Amplificador::operator=(const Amplificador& other)
{
	if (this != &other)
	{
		ProcesadorDeSenal::operator=(other);
	}
	return *this;
}