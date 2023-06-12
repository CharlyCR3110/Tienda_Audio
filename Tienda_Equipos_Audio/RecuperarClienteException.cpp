#include "RecuperarClienteException.h"

RecuperarClienteException::RecuperarClienteException(std::string motivo):
	_motivo(motivo)
{
}

const char* RecuperarClienteException::what() const throw()
{
	return ("No se pudo recuperar el cliente: " + _motivo).c_str();
}
