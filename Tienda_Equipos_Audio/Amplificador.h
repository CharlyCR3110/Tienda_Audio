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
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Amplificador& operator=(const Amplificador& other);
};

