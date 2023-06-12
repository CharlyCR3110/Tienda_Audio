#pragma once
#include <stdexcept>
class OpcionInvalidaException :
	public std::exception
{
public:
	OpcionInvalidaException(std::string menu);
	virtual const char* what() const throw();
private:
	std::string _menu;	// representa el menu que se esta mostrando1
};

