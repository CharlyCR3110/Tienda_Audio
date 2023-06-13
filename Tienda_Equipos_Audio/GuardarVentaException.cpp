#include "GuardarVentaException.h"

GuardarVentaException::GuardarVentaException(std::string mensaje):
	_mensaje(mensaje)
{
}

const char* GuardarVentaException::what() const throw()
{
	return _mensaje.c_str();
}
