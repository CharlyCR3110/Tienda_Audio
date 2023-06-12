#include "OpcionInvalidaException.h"

OpcionInvalidaException::OpcionInvalidaException(std::string menu):
	_menu(menu)
{
}

const char* OpcionInvalidaException::what() const throw()
{
	return (_menu + ": Opcion invalida").c_str();
}
