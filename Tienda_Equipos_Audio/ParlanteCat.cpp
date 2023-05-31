#include "ParlanteCat.h"

ParlanteCat::ParlanteCat() :
	Componente()
{
}

ParlanteCat::ParlanteCat(std::string codigo, std::string caracteristicas, double precio) :
	Componente(codigo, caracteristicas, precio)
{
}

ParlanteCat::ParlanteCat(const ParlanteCat& other) :
	Componente(other)
{
}

ParlanteCat::~ParlanteCat()
{
}

ParlanteCat& ParlanteCat::operator=(const ParlanteCat& other)
{
	if (this != &other)
	{
		Componente::operator=(other);	// se llama al operador de asignacion de la clase base
	}
	return *this;
}