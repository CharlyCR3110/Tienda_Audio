#include "OpcionInvalidaException.h"

OpcionInvalidaException::OpcionInvalidaException(std::string mensaje):
	_mensaje(mensaje)
{
}

const char* OpcionInvalidaException::what() const throw()
{
	return _mensaje.c_str();
}
