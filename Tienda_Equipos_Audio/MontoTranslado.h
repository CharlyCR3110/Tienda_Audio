#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>	// libreria de C++ para manipular la salida de datos	// solo se usa setw
#include "CodigoDeCiudadNoValidoException.h"


class MontoTranslado	// tiene la lista, recibe el codigo y devuelve el monto
{
public:
	MontoTranslado() = default;
	~MontoTranslado() = default;
	static double getMonto(std::string codigo);
	static bool disponibilidadDeEnvio(std::string codigo);
	static std::string mostrarLista();
};

