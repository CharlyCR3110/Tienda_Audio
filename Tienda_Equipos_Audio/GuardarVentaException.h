#pragma once
#include <stdexcept>

class GuardarVentaException:
	public std::exception
{
public:
	GuardarVentaException(std::string mensaje);
	const char* what() const throw();
private:
	std::string _mensaje;
};

