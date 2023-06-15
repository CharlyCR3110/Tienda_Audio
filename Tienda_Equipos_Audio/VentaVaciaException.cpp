#include "VentaVaciaException.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

VentaVaciaException::VentaVaciaException()
{
}

const char* VentaVaciaException::what() const throw()
{
	return "La venta esta vacia";
}
