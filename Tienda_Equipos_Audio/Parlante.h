#pragma once
#include "ParlanteCat.h"

class Parlante :
    public ParlanteCat
{
public:
	Parlante();
	Parlante(std::string modelo, std::string caracteristicas, double precio);
	Parlante(const Parlante& other);
	virtual ~Parlante();
	virtual std::string toString() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Parlante& operator=(const Parlante& other);
};