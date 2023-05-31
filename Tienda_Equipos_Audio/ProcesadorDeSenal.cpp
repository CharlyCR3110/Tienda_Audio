#include "ProcesadorDeSenal.h"

ProcesadorDeSenal::ProcesadorDeSenal() :
	Componente()
{
}

ProcesadorDeSenal::ProcesadorDeSenal(std::string codigo, std::string caracteristicas, double precio) :
	Componente(codigo, caracteristicas, precio)
{
}

ProcesadorDeSenal::ProcesadorDeSenal(const ProcesadorDeSenal& other) :
	Componente(other)
{
}

ProcesadorDeSenal::~ProcesadorDeSenal()
{
}

ProcesadorDeSenal& ProcesadorDeSenal::operator=(const ProcesadorDeSenal& other)
{
	if (this != &other)
	{
		Componente::operator=(other);	// se llama al operador de asignacion de la clase base
	}
	return *this;
}