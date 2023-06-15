#include "Tornamesa.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Tornamesa::Tornamesa() :
	FuenteDeAudio()
{
	this->_nombreComponente = "Tornamesa";
}

Tornamesa::Tornamesa(std::string codigo, std::string caracteristicas, double precio):
	FuenteDeAudio(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Tornamesa";
}

Tornamesa::Tornamesa(const Tornamesa& other) :
	FuenteDeAudio(other)
{
}

Tornamesa::~Tornamesa()
{
}

Componente* Tornamesa::clonar() const
{
	return new Tornamesa(*this);
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
