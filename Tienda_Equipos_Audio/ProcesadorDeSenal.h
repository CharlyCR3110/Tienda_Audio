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
	// metodos de composite
	virtual void add(Componente* componente) = 0;
	virtual void remove(Componente* componente) = 0;
	virtual Componente* getChild(int i) const = 0;
	virtual void clear() = 0;
	ProcesadorDeSenal& operator=(const ProcesadorDeSenal& other);
};