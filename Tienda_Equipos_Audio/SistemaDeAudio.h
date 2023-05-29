#pragma once
#include "Componente.h"
class SistemaDeAudio :
    public Componente
{
public:
	SistemaDeAudio();
	SistemaDeAudio(int capacidad);
	SistemaDeAudio(const SistemaDeAudio& other);
	virtual ~SistemaDeAudio();
	virtual std::string toString() const override;
	// metodo clonar
	virtual Componente* clonar() const override;
	// metodos de composite
	virtual void add(Componente* componente) override;
	virtual void remove(Componente* componente) override;
	virtual Componente* getChild(int i) const override;
	virtual void clear() override;
	// sobrecarga de operadores
	SistemaDeAudio& operator=(const SistemaDeAudio& other);
private:
	int _capacidad;
	int _cantidad;
	Componente** _componentes;
	//void resize(int n);
};