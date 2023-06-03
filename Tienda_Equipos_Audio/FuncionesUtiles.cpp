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

bool esCodigoValido(std::string codigo)
{
	if (codigo.empty())
	{
		std::cout << "El codigo no puede estar vacio" << std::endl;
		return false;
	}
	for (int i = 0; i < codigo.length(); i++)
	{
		if (!isalnum(codigo[i]))	// si no es alfanumerico
		{
			std::cout << "El codigo no puede contener caracteres especiales" << std::endl;
			return false;
		}
	}
	return true;
}
