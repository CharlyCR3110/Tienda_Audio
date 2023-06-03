#pragma once
#include <iostream>

class MontoTranslado	// tiene la lista, recibe el codigo y devuelve el monto
{
public:
	MontoTranslado() = default;
	~MontoTranslado() = default;
	static double getMonto(std::string codigo);
};

