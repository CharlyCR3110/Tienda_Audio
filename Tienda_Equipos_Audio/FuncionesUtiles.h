#include <iostream>
#include <limits>

// funcion para limpiar los errores de entrada
void clearInputBuffer();
// funcion para limpiar la pantalla
void clearScreen();

// funcion mas general para verificar que un string sea valido
bool esStringValido(std::string str, bool permitirEspacios, bool permitirNumeros, bool permitirCaracteresEspeciales, std::string tipo); // tipo es el nombre del campo que se esta validando (ej: "codigo", "nombre", etc)