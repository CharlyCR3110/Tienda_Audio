#include "AbrirArchivoException.h"


AbrirArchivoException::AbrirArchivoException(std::string nombreDelArchivo) 
{
	_nombreDelArchivo = nombreDelArchivo;
}

const char* AbrirArchivoException::what() const throw()
{
	return ("Error al abrir el archivo: " + _nombreDelArchivo).c_str();
}
