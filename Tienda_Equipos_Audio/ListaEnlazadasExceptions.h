#pragma once
#include <stdexcept>

class ListaEnlazadasExceptions :
	public std::exception
{
public:
	ListaEnlazadasExceptions(const std::string& mensaje);
	const char* what() const noexcept override;
private:
	std::string _mensaje;
};

