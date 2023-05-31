#include "ComponenteNoEncontradoException.h"

ComponenteNoEncontradoException::ComponenteNoEncontradoException(const std::string& mensaje):
	_mensaje(mensaje)
{
}

const char* ComponenteNoEncontradoException::what() const noexcept
{
	return _mensaje.c_str();
}
