#pragma once
#include "Componente.h"
class FuenteDeAudio :
	public Componente
{
public:
	FuenteDeAudio();
	FuenteDeAudio(std::string codigo, std::string caracteristicas, double precio);
	FuenteDeAudio(const FuenteDeAudio& other);
	virtual ~FuenteDeAudio();

	virtual std::string toString() const override;	// el toString es igual para todas las fuentes de audio (no es virtual)
	// metodo clonar
	virtual Componente* clonar() const = 0;
	// metodos de composite
	virtual void add(Componente* componente) = 0;
	virtual void remove(Componente* componente) = 0;
	virtual Componente* getChild(int i) const = 0;
	virtual void clear() = 0;
	// sobrecarga de operadores
	FuenteDeAudio& operator=(const FuenteDeAudio& other);
};

