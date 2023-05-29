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
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	UnidadBluetooth& operator=(const UnidadBluetooth& other);
};

