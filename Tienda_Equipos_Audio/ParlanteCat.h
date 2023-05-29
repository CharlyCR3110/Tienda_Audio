#pragma once
#include "Componente.h"
class ParlanteCat :
    public Componente
{
public:
	ParlanteCat();
	ParlanteCat(std::string modelo, std::string caracteristicas, double precio);
	ParlanteCat(const ParlanteCat& other);
	virtual ~ParlanteCat();
	virtual std::string toString() const = 0;
	// metodos de composite
	virtual void add(Componente* componente) = 0;
	virtual void remove(Componente* componente) = 0;
	virtual Componente* getChild(int i) const = 0;
	virtual void clear() = 0;
	// sobrecarga de operadores
	ParlanteCat& operator=(const ParlanteCat& other);
};