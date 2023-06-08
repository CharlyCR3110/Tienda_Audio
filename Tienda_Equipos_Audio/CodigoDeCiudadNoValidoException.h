#pragma once
#include <stdexcept>
class CodigoDeCiudadNoValidoException :
	public std::exception
{
public:
	CodigoDeCiudadNoValidoException(std::string codigoDeCiudad);
	virtual const char* what() const throw();
private:
	std::string _codigoDeCiudad;
};