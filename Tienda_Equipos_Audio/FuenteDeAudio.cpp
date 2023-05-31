#include "FuenteDeAudio.h"

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

FuenteDeAudio& FuenteDeAudio::operator=(const FuenteDeAudio& other)
{
	if (this != &other)
	{
		Componente::operator=(other);	// se llama al operador de asignacion de la clase base
	}
	return *this;
}
