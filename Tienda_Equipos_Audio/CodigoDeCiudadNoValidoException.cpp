#include "CodigoDeCiudadNoValidoException.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

CodigoDeCiudadNoValidoException::CodigoDeCiudadNoValidoException(std::string codigoDeCiudad) :
	_codigoDeCiudad(codigoDeCiudad)
{
}

const char* CodigoDeCiudadNoValidoException::what() const throw()
{
	return ("El codigo de ciudad " + _codigoDeCiudad + " no es valido.").c_str();
}