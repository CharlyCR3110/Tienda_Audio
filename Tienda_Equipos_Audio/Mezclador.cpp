#include "Mezclador.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Mezclador::Mezclador() :
	ProcesadorDeSenal()
{
	this->_nombreComponente = "Mezclador";
}

Mezclador::Mezclador(std::string codigo, std::string caracteristicas, double precio) :
	ProcesadorDeSenal(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Mezclador";
}

Mezclador::Mezclador(const Mezclador& other) :
	ProcesadorDeSenal(other)
{
}

Mezclador::~Mezclador()
{
}

Componente* Mezclador::clonar() const
{
	return new Mezclador(*this);
}

void Mezclador::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Mezclador::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Mezclador::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Mezclador::clear()
{
	// Es una leaf, no tiene hijos
}

Mezclador& Mezclador::operator=(const Mezclador& other)
{
	if (this != &other)
	{
		ProcesadorDeSenal::operator=(other);
	}
	return *this;
}