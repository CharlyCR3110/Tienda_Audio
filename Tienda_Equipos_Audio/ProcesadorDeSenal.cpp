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

std::string ProcesadorDeSenal::toString() const
{
	std::stringstream ss;
	ss << "Codigo: " << _codigo << std::endl;
	ss << "Categoria: " << _categoria << std::endl;
	ss << "Nombre: " << _nombreComponente << std::endl;
	ss << "Caracteristicas: " << _caracteristicas << std::endl;
	ss << "Precio Unitario: " << _precio << std::endl;
	ss << "Cantidad: " << _cantidadEnElCarrito << std::endl;
	return ss.str();
}

ProcesadorDeSenal& ProcesadorDeSenal::operator=(const ProcesadorDeSenal& other)
{
	if (this != &other)
	{
		Componente::operator=(other);	// se llama al operador de asignacion de la clase base
	}
	return *this;
}