#include "Nodo.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programaci�n II
	Proyecto 2

	5-0452-0687 Andres Ure�a Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

template<class T>
std::ostream& operator<<(std::ostream& out, Nodo<T>& nodo)
{
	out << *nodo._dato;
	return out;
}