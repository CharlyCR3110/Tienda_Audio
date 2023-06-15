#include "VentaVaciaException.h"

VentaVaciaException::VentaVaciaException()
{
}

const char* VentaVaciaException::what() const throw()
{
	return "La venta esta vacia";
}
