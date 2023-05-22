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
	ParlanteCat& operator=(const ParlanteCat& other);
};