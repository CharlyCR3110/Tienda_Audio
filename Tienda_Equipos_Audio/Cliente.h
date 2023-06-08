#pragma once
#include "IObserver.h"
#include <fstream>

#include <iostream>
class Cliente :
	public IObserver
{
public:
	Cliente();
	Cliente(std::string nombre, std::string cedula, std::string pais, std::string ciudad);
	Cliente(const Cliente& cliente);
	~Cliente() = default;
	// metodos de IObserver
	virtual void Update() = 0;
	// getters
	virtual std::string getNombre() const;
	virtual std::string getCedula() const;
	virtual std::string getPais() const;
	virtual std::string getCiudad() const;

	virtual std::string getCodigo() const;

	virtual char getTipo() const;
	// setters
	virtual void setNombre(std::string nombre);
	virtual void setCedula(std::string cedula);
	virtual void setPais(std::string pais);
	virtual void setCiudad(std::string ciudad);
	// mostrar
	virtual std::string toString() const = 0;
	// clonar
	virtual Cliente* clonar() const = 0;
	// operadores
	Cliente& operator=(const Cliente& other);
	virtual bool operator==(const Cliente& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Cliente& other);
protected:
	std::string _nombre;
	std::string _cedula;
	std::string _pais;
	std::string _ciudad;

	char _tipo;	// Cliente Fisico o Persona = 'P', Cliente Empresa = 'E'
};

