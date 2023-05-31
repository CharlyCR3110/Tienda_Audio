#pragma once
#include <iostream>
#include <sstream>
/// <summary>
/// Como todos los productos tienen un modelo, caracteristicas y precio, se crea una clase abstracta que los contenga
/// </summary>
class Componente /*<< interface >>*/
{
public:
	Componente();
	Componente(std::string modelo, std::string caracteristicas, double precio);
	Componente(const Componente& other);
	virtual ~Componente();
	virtual std::string getModelo() const;
	virtual std::string getCaracteristicas() const;
	virtual double getPrecio() const;
	virtual void setNombre(std::string modelo);
	virtual void setCaracteristicas(std::string caracteristicas);
	virtual void setPrecio(double precio);
	virtual std::string toString() const = 0;
	// metodo clonar
	virtual Componente* clonar() const = 0;
	// metodos de composite
	virtual void add(Componente* componente) = 0;
	virtual void remove(Componente* componente) = 0;
	virtual Componente* getChild(int i) const = 0;
	virtual void clear() = 0;
	// sobrecarga de operadores
	Componente& operator=(const Componente& other);
	friend std::ostream& operator<<(std::ostream& out, const Componente& other);
	bool operator==(const Componente& other) const;
protected:
	std::string _modelo;
	std::string _caracteristicas;
	double _precio;
};