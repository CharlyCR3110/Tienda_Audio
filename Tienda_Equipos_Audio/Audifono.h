#pragma once
#include "ParlanteCat.h"

class Audifono :
    public ParlanteCat
{
public:
	Audifono();
	Audifono(std::string codigo, std::string caracteristicas, double precio);
	Audifono(const Audifono& other);
	virtual ~Audifono();

	// metodo clonar
	virtual Componente* clonar() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Audifono& operator=(const Audifono& other);
};

