#include "FuncionesUtiles.h"

void clearInputBuffer()
{
	std::cin.clear();  // Limpiar los errores de entrada
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada incorrecta
}

void clearScreen()
{
	system("cls");
}
