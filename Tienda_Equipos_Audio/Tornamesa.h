#pragma once
#include "FuenteDeAudio.h"

class Tornamesa :
    public FuenteDeAudio
{
public:
	Tornamesa();
    Tornamesa(std::string modelo, std::string caracteristicas, double precio);
	Tornamesa(const Tornamesa& other);
	virtual ~Tornamesa();
	virtual std::string toString() const override; 
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Tornamesa& operator=(const Tornamesa& other);
};

