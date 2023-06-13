#pragma once
#include <stdexcept>

class RecuperarClienteException
	: public std::exception
{
public:
	RecuperarClienteException(std::string _mensaje);
	virtual const char* what() const throw();
private:
	std::string _mensaje;
};

