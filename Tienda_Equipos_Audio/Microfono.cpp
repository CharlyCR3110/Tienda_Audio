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

void Microfono::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Microfono::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Microfono::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Microfono::clear()
{
	// Es una leaf, no tiene hijos
}

Microfono& Microfono::operator=(const Microfono& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}