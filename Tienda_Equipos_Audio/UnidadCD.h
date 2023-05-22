#pragma once
#include "FuenteDeAudio.h"
class UnidadCD :
	public FuenteDeAudio
{
public:
	UnidadCD();
	UnidadCD(std::string modelo, std::string caracteristicas, double precio);
	UnidadCD(const UnidadCD& other);
	virtual ~UnidadCD();
	virtual std::string toString() const override;
	UnidadCD& operator=(const UnidadCD& other);
};
