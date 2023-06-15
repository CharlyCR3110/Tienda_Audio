#pragma once
#include <stdexcept>

class RecuperarVentaException:
	public std::exception
{
public:
	RecuperarVentaException(std::string mensaje);
	virtual const char* what() const throw();
private:
	std::string _mensaje;
};

