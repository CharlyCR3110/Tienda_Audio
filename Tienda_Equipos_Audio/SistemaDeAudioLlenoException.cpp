#include "SistemaDeAudioLlenoException.h"

SistemaDeAudioLlenoException::SistemaDeAudioLlenoException(const std::string& mensaje):
	_mensaje(mensaje)
{
}

const char* SistemaDeAudioLlenoException::what() const noexcept
{
	return _mensaje.c_str();
}
