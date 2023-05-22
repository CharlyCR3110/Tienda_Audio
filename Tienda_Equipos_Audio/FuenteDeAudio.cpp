#include "FuenteDeAudio.h"

FuenteDeAudio::FuenteDeAudio() :
	Componente()
{
}

FuenteDeAudio::FuenteDeAudio(std::string modelo, std::string caracteristicas, double precio) :
	Componente(modelo, caracteristicas, precio)
{
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
