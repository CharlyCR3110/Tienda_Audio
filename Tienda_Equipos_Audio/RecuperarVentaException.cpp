#include "RecuperarVentaException.h"

RecuperarVentaException::RecuperarVentaException(std::string mensaje):
	_mensaje(mensaje)
{
}

const char* RecuperarVentaException::what() const throw()
{
	return _mensaje.c_str();
}
