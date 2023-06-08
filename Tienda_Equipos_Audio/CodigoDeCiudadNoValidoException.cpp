#include "CodigoDeCiudadNoValidoException.h"

CodigoDeCiudadNoValidoException::CodigoDeCiudadNoValidoException(std::string codigoDeCiudad) :
	_codigoDeCiudad(codigoDeCiudad)
{
}

const char* CodigoDeCiudadNoValidoException::what() const throw()
{
	return ("El codigo de ciudad " + _codigoDeCiudad + " no es valido.").c_str();
}