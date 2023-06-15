#include "Parlante.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Parlante::Parlante() :
	ParlanteCat()
{
	this->_nombreComponente = "Parlante";
}

Parlante::Parlante(std::string codigo, std::string caracteristicas, double precio) :
	ParlanteCat(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Parlante";
}

Parlante::Parlante(const Parlante& other) :
	ParlanteCat(other)
{
}

Parlante::~Parlante()
{
}

Componente* Parlante::clonar() const
{
	return new Parlante(*this);
}

void Parlante::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Parlante::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Parlante::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Parlante::clear()
{
	// Es una leaf, no tiene hijos
}

Parlante& Parlante::operator=(const Parlante& other)
{
	if (this != &other)
	{
		ParlanteCat::operator=(other);
	}
	return *this;
}