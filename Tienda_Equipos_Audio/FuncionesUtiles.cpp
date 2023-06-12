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

void pauseAndCleanScreen()
{
	std::system("pause");
	std::system("cls");
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

bool esNombreValido(std::string nombre)
{
	if (nombre.empty())
	{
		std::cout << "El nombre no puede estar vacio" << std::endl;
		return false;
	}
	for (int i = 0; i < nombre.length(); i++)
	{
		if (!isalpha(nombre[i]) && !isspace(nombre[i]))	// si no es alfanumerico ni espacio
		{
			std::cout << "El nombre no puede contener caracteres especiales" << std::endl;
			return false;
		}
	}
	return true;
}

bool esStringValido(std::string str, bool permitirEspacios, bool permitirNumeros, bool permitirCaracteresEspeciales, std::string tipo) {
    // Validar si el campo es vac�o (opcional)
    if (str.empty()) {
        std::cout << "El campo \"" << tipo << "\" no puede estar vac�o." << std::endl;
        return false;
    }

    // Validar caracteres uno por uno
    for (char c : str) {
        // Validar espacios
        if (!permitirEspacios && c == ' ') {
            std::cout << "El campo \"" << tipo << "\" no puede contener espacios." << std::endl;
            return false;
        }

        // Validar n�meros
        if (!permitirNumeros && std::isdigit(c)) {
            std::cout << "El campo \"" << tipo << "\" no puede contener n�meros." << std::endl;
            return false;
        }

        // Validar caracteres especiales
        if (!permitirCaracteresEspeciales && !std::isalnum(static_cast<unsigned char>(c))) {
			if (c == ' ') continue;	// Permitir espacios
            std::cout << "El campo \"" << tipo << "\" no puede contener caracteres especiales." << std::endl;
            return false;
        }
    }

    // El string es v�lido
    return true;
}
