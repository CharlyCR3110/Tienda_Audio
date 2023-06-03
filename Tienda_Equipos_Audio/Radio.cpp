#include "Radio.h"

Radio::Radio() :
	FuenteDeAudio()
{
	this->_nombreComponente = "Radio";
}

Radio::Radio(std::string codigo, std::string caracteristicas, double precio) :
	FuenteDeAudio(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Radio";
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
	ss << _codigo << '\t' << _categoria << '\t' << _nombreComponente << '\t' << _caracteristicas << '\t' << _precio;
	return ss.str();
}

Componente* Radio::clonar() const
{
	return new Radio(*this);
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