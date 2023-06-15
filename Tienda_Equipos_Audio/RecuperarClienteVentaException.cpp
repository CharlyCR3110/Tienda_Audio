#include "RecuperarClienteVentaException.h"

RecuperarClienteVentaException::RecuperarClienteVentaException()
{
}

const char* RecuperarClienteVentaException::what() const throw()
{
	return "Error al recuperar el cliente de la venta";
}
