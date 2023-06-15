#pragma once
#include <stdexcept>
class RecuperarFechaVentaException:
	public std::exception
{
public:
	RecuperarFechaVentaException();
	const char* what() const throw();
};

