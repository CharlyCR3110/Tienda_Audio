#include "RecuperarVentaException.h"

RecuperarVentaException::RecuperarVentaException(std::string motivo):
	_motivo(motivo)
{
}

const char* RecuperarVentaException::what() const throw()
{
	return ("Error al recuperar la venta: " + _motivo).c_str();
}
