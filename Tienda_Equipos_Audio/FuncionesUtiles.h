#include <iostream>
#include <limits>

// funcion para limpiar los errores de entrada
void clearInputBuffer();
// funcion para limpiar la pantalla
void clearScreen();
// funcion para verificar que un codigo sea valido (solo puede aceptar letras y numeros, no puede ser vacio ni tener espacios)
bool esCodigoValido(std::string codigo);
