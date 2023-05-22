#pragma once
#include "Componente.h"
class FuenteDeAudio :
	public Componente
{
public:
	FuenteDeAudio();
	FuenteDeAudio(std::string modelo, std::string caracteristicas, double precio);
	FuenteDeAudio(const FuenteDeAudio& other);
	virtual ~FuenteDeAudio();
	virtual std::string toString() const = 0;
	FuenteDeAudio& operator=(const FuenteDeAudio& other);
};

