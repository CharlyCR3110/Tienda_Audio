#pragma once
#include "FuenteDeAudio.h"
class Microfono :
	public FuenteDeAudio
{
public:
	Microfono();
	Microfono(std::string modelo, std::string caracteristicas, double precio);
	Microfono(const Microfono& other);
	virtual ~Microfono();
	virtual std::string toString() const override;
	Microfono& operator=(const Microfono& other);
};

