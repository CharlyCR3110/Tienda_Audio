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
	Parlante& operator=(const Parlante& other);
};