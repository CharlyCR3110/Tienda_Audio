#include "Audifono.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Audifono::Audifono() :
	ParlanteCat()
{
	this->_nombreComponente = "Audifono";
}

Audifono::Audifono(std::string codigo, std::string caracteristicas, double precio) :
	ParlanteCat(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Audifono";
}

Audifono::Audifono(const Audifono& other) :
	ParlanteCat(other)
{
}

Audifono::~Audifono()
{
}

Componente* Audifono::clonar() const
{
	return new Audifono(*this);
}

void Audifono::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Audifono::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Audifono::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Audifono::clear()
{
	// Es una leaf, no tiene hijos
}

Audifono& Audifono::operator=(const Audifono& other)
{
	if (this != &other)
	{
		ParlanteCat::operator=(other);
	}
	return *this;
}