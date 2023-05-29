#pragma once
#include "FuenteDeAudio.h"

class Radio :
	public FuenteDeAudio
{
public:
	Radio();
	Radio(std::string modelo, std::string caracteristicas, double precio);
	Radio(const Radio& other);
	virtual ~Radio();
	virtual std::string toString() const override;
	// metodo clonar
	virtual Componente* clonar() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	Radio& operator=(const Radio& other);
};

