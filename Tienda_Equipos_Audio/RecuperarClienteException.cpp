#include "RecuperarClienteException.h"

RecuperarClienteException::RecuperarClienteException(std::string mensaje):
	_mensaje(mensaje)
{
}

const char* RecuperarClienteException::what() const throw()
{
	return _mensaje.c_str();
}
