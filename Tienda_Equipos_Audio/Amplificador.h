#pragma once
#include "ProcesadorDeSenal.h"

class Amplificador :
	public ProcesadorDeSenal
{
public:
	Amplificador();
	Amplificador(std::string modelo, std::string caracteristicas, double precio);
	Amplificador(const Amplificador& other);
	virtual ~Amplificador();
	virtual std::string toString() const override;
	Amplificador& operator=(const Amplificador& other);
};

