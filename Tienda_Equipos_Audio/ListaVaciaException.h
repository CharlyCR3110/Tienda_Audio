#pragma once
#include <stdexcept>

class ListaVaciaException : 
	public std::exception
{
public:
	const char* what() const throw();
};

