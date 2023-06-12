#pragma once
#include <stdexcept>

class AbrirArchivoException :
	public std::exception
{
public:
	AbrirArchivoException(std::string nombreDelArchivo);
	~AbrirArchivoException() = default;
	virtual const char* what() const throw();
private:
	std::string _nombreDelArchivo;
};

