#pragma once
#include "Componente.h"
class ProcesadorDeSenal :
	public Componente
{
public:
	ProcesadorDeSenal();
	ProcesadorDeSenal(std::string modelo, std::string caracteristicas, double precio);
	ProcesadorDeSenal(const ProcesadorDeSenal& other);
	virtual ~ProcesadorDeSenal();
	virtual std::string toString() const = 0;
	ProcesadorDeSenal& operator=(const ProcesadorDeSenal& other);
};