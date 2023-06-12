#pragma once
#include <stdexcept>

class RecuperarClienteVentaException :
	public std::exception
{
public:
	RecuperarClienteVentaException();
	const char* what() const throw();
};

