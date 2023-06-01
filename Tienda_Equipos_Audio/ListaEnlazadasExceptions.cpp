#include "ListaEnlazadasExceptions.h"

ListaEnlazadasExceptions::ListaEnlazadasExceptions(const std::string& mensaje)
{
	_mensaje = mensaje;
}

const char* ListaEnlazadasExceptions::what() const noexcept
{
	return _mensaje.c_str();
}
