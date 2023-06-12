#pragma once
#include <stdexcept>

class RecuperarClienteException
	: public std::exception
{
public:
	RecuperarClienteException(std::string motivo);
	virtual const char* what() const throw();
private:
	std::string _motivo;
};

