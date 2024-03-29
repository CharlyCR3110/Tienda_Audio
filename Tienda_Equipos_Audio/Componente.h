#pragma once
#include <iostream>
#include <sstream>
/// <summary>
/// Como todos los productos tienen un codigo, caracteristicas y precio, se crea una clase abstracta que los contenga
/// </summary>
class Componente /*<< interface >>*/
{
public:
	Componente();
	Componente(std::string codigo, std::string caracteristicas, double precio);
	Componente(const Componente& other);
	virtual ~Componente();
	//getters
	virtual std::string getCodigo() const;
	virtual std::string getCaracteristicas() const;
	virtual double getPrecio() const;
	virtual double getPrecioUnitario() const;
	// categoria del producto
	virtual std::string getCategoria() const;
	// nombre del componente
	virtual std::string getNombreComponente() const;

	// nombre del paquete de componentes
	virtual std::string getNombre() const;

	// cantidad de componentes que se van a comprar
	virtual int getCantidadEnCarrito() const;
	//setters
	virtual void setCodigo(std::string codigo);
	virtual void setCaracteristicas(std::string caracteristicas);
	virtual void setPrecio(double precio);
	// categoria del producto
	virtual void setCategoria(std::string categoria);
	// nombre del componente
	virtual void setNombreComponente(std::string nombre);
	// nombre del paquete de componentes
	virtual void setNombre(std::string nombreDelPaquete);
	// cantidad de componentes que se van a comprar
	virtual void setCantidadEnCarrito(int cantidad);
	// mostrar informacion
	virtual std::string toString() const = 0;
	// metodo clonar
	virtual Componente* clonar() const = 0;
	// metodos de composite
	virtual void add(Componente* componente) = 0;
	virtual void remove(Componente* componente) = 0;
	virtual Componente* getChild(int i) const = 0;
	virtual void setChild(int i, Componente* componente);
	virtual void clear() = 0;
	// sobrecarga de operadores
	Componente& operator=(const Componente& other);
	friend std::ostream& operator<<(std::ostream& out, const Componente& other);
	bool operator==(const Componente& other) const;
protected:
	std::string _codigo;	// este atributo funciona como el modelo del producto y como el codigo del sistema de audio
	std::string _caracteristicas;	// caracteristicas del producto
	double _precio;	// este atributo funciona como el precio del producto y como el precio total del sistema de audio

	std::string _categoria;	// categoria del producto
	std::string _nombreComponente;	// nombre del componente

	int _cantidadEnElCarrito;	// cantidad de componentes que se van a comprar
};