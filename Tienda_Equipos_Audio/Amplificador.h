#pragma once
#include "ProcesadorDeSenal.h"

class Amplificador :
	public ProcesadorDeSenal
{
public:
	Amplificador();
	Amplificador(std::string codigo, std::string caracteristicas, double precio);
	Amplificador(const Amplificador& other);
	virtual ~Amplificador();
	// metodo clonar
	virtual Componente* clonar() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Amplificador& operator=(const Amplificador& other);
};

