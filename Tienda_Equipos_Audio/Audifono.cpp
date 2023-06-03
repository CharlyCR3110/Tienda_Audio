#include "Audifono.h"

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

std::string Audifono::toString() const
{
	std::stringstream ss;
	ss << _codigo << '\t' << _categoria << '\t' << _nombreComponente << '\t' << _caracteristicas << '\t' << _precio;
	return ss.str();
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