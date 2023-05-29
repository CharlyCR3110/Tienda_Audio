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
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Microfono& operator=(const Microfono& other);
};

