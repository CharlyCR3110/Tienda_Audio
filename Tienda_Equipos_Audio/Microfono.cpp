#include "Microfono.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Microfono::Microfono() :
	FuenteDeAudio()
{
	this->_nombreComponente = "Microfono";
}

Microfono::Microfono(std::string codigo, std::string caracteristicas, double precio) :
	FuenteDeAudio(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Microfono";
}

Microfono::Microfono(const Microfono& other) :
	FuenteDeAudio(other)
{
}

Microfono::~Microfono()
{
}

Componente* Microfono::clonar() const
{
	return new Microfono(*this);
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