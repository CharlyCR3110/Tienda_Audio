#include "GuardarVentaException.h"

GuardarVentaException::GuardarVentaException(std::string motivo):
	_motivo(motivo)
{
}

const char* GuardarVentaException::what() const throw()
{
	return ("Error al guardar la venta: " + _motivo).c_str();
}
