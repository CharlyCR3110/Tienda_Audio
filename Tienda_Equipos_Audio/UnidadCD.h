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
	// metodo clonar
	virtual Componente* clonar() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	UnidadCD& operator=(const UnidadCD& other);
};
