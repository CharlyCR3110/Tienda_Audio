#include "AbrirArchivoException.h"


AbrirArchivoException::AbrirArchivoException(std::string mensaje) :
	_mensaje(mensaje)
{
}

const char* AbrirArchivoException::what() const throw()
{
	return _mensaje.c_str();
}
