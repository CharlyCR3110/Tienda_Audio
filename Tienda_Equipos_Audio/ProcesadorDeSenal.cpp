#include "ProcesadorDeSenal.h"

ProcesadorDeSenal::ProcesadorDeSenal() :
	Componente()
{
	this->_categoria = "Procesador de senal";
}

ProcesadorDeSenal::ProcesadorDeSenal(std::string codigo, std::string caracteristicas, double precio) :
	Componente(codigo, caracteristicas, precio)
{
	this->_categoria = "Procesador de senal";
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