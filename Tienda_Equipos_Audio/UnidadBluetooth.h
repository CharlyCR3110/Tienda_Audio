#pragma once
#include "FuenteDeAudio.h"
class UnidadBluetooth :
	public FuenteDeAudio
{
public:
	UnidadBluetooth();
	UnidadBluetooth(std::string modelo, std::string caracteristicas, double precio);
	UnidadBluetooth(const UnidadBluetooth& other);
	virtual ~UnidadBluetooth();
	virtual std::string toString() const override;
	UnidadBluetooth& operator=(const UnidadBluetooth& other);
};

