#pragma once
#include <stdexcept>

class AbrirArchivoException :
	public std::exception
{
public:
	AbrirArchivoException(std::string mensaje);
	~AbrirArchivoException() = default;
	virtual const char* what() const throw();
private:
	std::string _mensaje;
};

