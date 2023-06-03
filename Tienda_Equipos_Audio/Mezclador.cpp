#include "Mezclador.h"

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

std::string Mezclador::toString() const
{
	std::stringstream ss;
	ss << _codigo << '\t' << _categoria << '\t' << _nombreComponente << '\t' << _caracteristicas << '\t' << _precio;
	return ss.str();
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