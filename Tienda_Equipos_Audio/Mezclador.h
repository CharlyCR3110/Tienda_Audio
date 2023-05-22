#pragma once
#include "ProcesadorDeSenal.h"
class Mezclador :
    public ProcesadorDeSenal
{
public:
	Mezclador();
	Mezclador(std::string modelo, std::string caracteristicas, double precio);
	Mezclador(const Mezclador& other);
	virtual ~Mezclador();
	virtual std::string toString() const override;
	Mezclador& operator=(const Mezclador& other);
};

