#pragma once
#include "Componente.h"
// excepciones
#include "SistemaDeAudioLlenoException.h"
#include "ComponenteNoEncontradoException.h"
class SistemaDeAudio :
    public Componente
{
public:
	SistemaDeAudio();
	SistemaDeAudio(std::string codigo, std::string nombre);	// codigo se almacenara en _codigo(de la clase Componente) y nombre en _nombre de la esta clase
	SistemaDeAudio(int capacidad);
	SistemaDeAudio(const SistemaDeAudio& other);
	virtual ~SistemaDeAudio();
	virtual double getPrecio() const override;
	virtual std::string getNombre() const override;
	virtual void setNombre(std::string nombre);
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
	std::string _nombre;
};