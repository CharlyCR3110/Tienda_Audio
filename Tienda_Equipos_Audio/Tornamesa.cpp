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

void Tornamesa::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Tornamesa::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Tornamesa::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Tornamesa::clear()
{
	// Es una leaf, no tiene hijos
}

Tornamesa& Tornamesa::operator=(const Tornamesa& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}
