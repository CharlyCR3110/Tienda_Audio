#include "ListaVaciaException.h"

const char* ListaVaciaException::what() const throw()
{
    return "La lista esta vacia";
}
