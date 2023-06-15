#include "FuenteDeAudio.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

FuenteDeAudio::FuenteDeAudio() :
	Componente()
{
	this->_categoria = "Fuente de Audio";
}

FuenteDeAudio::FuenteDeAudio(std::string codigo, std::string caracteristicas, double precio) :
	Componente(codigo, caracteristicas, precio)
{
	this->_categoria = "Fuente de Audio";
}

FuenteDeAudio::FuenteDeAudio(const FuenteDeAudio& other) :
	Componente(other)
{
}

FuenteDeAudio::~FuenteDeAudio()
{
}

std::string FuenteDeAudio::toString() const
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

FuenteDeAudio& FuenteDeAudio::operator=(const FuenteDeAudio& other)
{
	if (this != &other)
	{
		Componente::operator=(other);	// se llama al operador de asignacion de la clase base
	}
	return *this;
}
