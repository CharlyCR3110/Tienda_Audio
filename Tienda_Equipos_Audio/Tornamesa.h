#pragma once
#include "FuenteDeAudio.h"

class Tornamesa :
    public FuenteDeAudio
{
public:
	Tornamesa();
    Tornamesa(std::string codigo, std::string caracteristicas, double precio);
	Tornamesa(const Tornamesa& other);
	virtual ~Tornamesa();
	// metodo clonar
	virtual Componente* clonar() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Tornamesa& operator=(const Tornamesa& other);
};

