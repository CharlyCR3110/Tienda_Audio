#pragma once
#include "ProcesadorDeSenal.h"
class Mezclador :
    public ProcesadorDeSenal
{
public:
	Mezclador();
	Mezclador(std::string codigo, std::string caracteristicas, double precio);
	Mezclador(const Mezclador& other);
	virtual ~Mezclador();
	// metodo clonar
	virtual Componente* clonar() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Mezclador& operator=(const Mezclador& other);
};