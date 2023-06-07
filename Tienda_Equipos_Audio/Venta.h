#pragma once
#include "Cliente.h"
#include "Fecha.h"
#include "Catalogo.h"

class Venta
{
public:
	Venta();
	Venta(Cliente* cliente, Fecha* fecha);
	Venta(const Venta& venta);
	virtual ~Venta();
	// getters
	virtual Cliente* getCliente() const;
	virtual Fecha* getFecha() const;
	virtual ListaEnlazada<Componente>* getCarritoDeCompras();
	virtual char getTipoDeVenta() const;

	virtual double getTotal() const;
	virtual double getSubtotal() const;

	// setters
	virtual void setCliente(Cliente* cliente);
	virtual void setFecha(Fecha* fecha);
	virtual void setTotal(double total);
	virtual void setSubtotal(double subtotal);

	// mostrar
	virtual std::string toString() = 0;
	// metodos para la venta
	virtual void agregarComponente(Componente* componente, int cantidad);
	virtual void eliminarComponente(Componente* componente);
	virtual void vaciarCarrito();
	virtual void calcularTotal() = 0;
	virtual void calcularSubtotal() = 0;

	virtual std::string generarFactura() = 0;
	 // clonar
	virtual Venta* clonar() const = 0;

	// operadores
	//Venta& operator=(const Venta& other);
	//bool operator==(const Venta& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Venta& other);
protected:
	Cliente* _cliente;	// cliente que realiza la venta
	Fecha* _fecha;	// fecha de la venta
	ListaEnlazada<Componente>* _carritoDeCompras;	// lista de componentes comprados

	double _total;
	double _subtotal;

	char _tipoDeVenta;	// D = directa, O = online
};

