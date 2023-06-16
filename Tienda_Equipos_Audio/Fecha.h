#pragma once
#include <iostream>
#include <sstream>

class Fecha
{
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	Fecha(const Fecha& fecha);
	~Fecha() = default;
	// getters
	int getDia() const;
	int getMes() const;
	int getAnio() const;
	// setters
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	// mostrar
	std::string toString() const;

	Fecha* clonar() const;

	std::string guardarFecha() const;	// no se usa
	// operadores
	Fecha& operator=(const Fecha& other);
	bool operator==(const Fecha& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Fecha& other);
private:
	int _dia;
	int _mes;
	int _anio;
};

