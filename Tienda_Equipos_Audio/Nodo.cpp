#include "Nodo.h"

template<class T>
std::ostream& operator<<(std::ostream& out, Nodo<T>& nodo)
{
	out << *nodo._dato;
	return out;
}