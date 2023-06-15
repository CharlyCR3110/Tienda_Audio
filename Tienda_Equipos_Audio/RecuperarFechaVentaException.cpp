#include "RecuperarFechaVentaException.h"

RecuperarFechaVentaException::RecuperarFechaVentaException()
{
}

const char* RecuperarFechaVentaException::what() const throw()
{
	return "Error al recuperar la fecha de la venta";
}
