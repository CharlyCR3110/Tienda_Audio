#pragma once
#include <stdexcept>

template<class T>
class ElementoNoEncontradoException : public std::exception
{
public:
	const char* what() const noexcept override;
};

template<class T>
inline const char* ElementoNoEncontradoException<T>::what() const noexcept
{
	return "El elemento buscado no existe en la lista";
}
