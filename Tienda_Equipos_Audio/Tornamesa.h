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
	Tornamesa& operator=(const Tornamesa& other);
};

