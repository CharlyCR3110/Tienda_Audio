#include "SistemaDeAudioLlenoException.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programaci�n II
	Proyecto 2

	5-0452-0687 Andres Ure�a Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

SistemaDeAudioLlenoException::SistemaDeAudioLlenoException(const std::string& mensaje):
	_mensaje(mensaje)
{
}

const char* SistemaDeAudioLlenoException::what() const noexcept
{
	return _mensaje.c_str();
}
