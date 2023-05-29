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

void Radio::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Radio::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Radio::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Radio::clear()
{
	// Es una leaf, no tiene hijos
}

Radio& Radio::operator=(const Radio& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}