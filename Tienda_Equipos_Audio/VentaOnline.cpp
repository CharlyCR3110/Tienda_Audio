#include "VentaOnline.h"

VentaOnline::VentaOnline() :
	Venta(),
	_codigoLugarEntrega("")
{
}

VentaOnline::VentaOnline(Cliente* cliente, Fecha* fecha, Catalogo* catalogo, std::string codigoLugarEntrega)
	: Venta(cliente, fecha, catalogo),
	_codigoLugarEntrega(codigoLugarEntrega)
{
	_total = MontoTranslado::getMonto(_codigoLugarEntrega);
}

VentaOnline::VentaOnline(const VentaOnline& other) :
	Venta(other),
	_codigoLugarEntrega(other._codigoLugarEntrega)
{
}

VentaOnline::~VentaOnline()
{
	Venta::~Venta();
}

void VentaOnline::calcularTotal()
{
	_total += MontoTranslado::getMonto(_codigoLugarEntrega);
}

void VentaOnline::calcularSubtotal()
{
	double subtotal = 0;
	for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
	{
		subtotal += _carritoDeCompras->get(i)->getPrecio();
	}
	_subtotal = subtotal;
}

std::string VentaOnline::generarFactura()
{
	calcularTotal();
	//calcularSubtotal();

	std::stringstream ss;
	ss << "------------------------------------------" << std::endl;
	ss << "Factura de venta online" << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Cliente: " << _cliente->getNombre() << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Fecha: " << _fecha->toString() << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Codigo de lugar de entrega: " << _codigoLugarEntrega << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Productos comprados: " << std::endl;
	ss << "------------------------------------------" << std::endl;
	for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
	{
		ss << "( " << i + 1 << " )   " << _carritoDeCompras->get(i)->toString() << std::endl;
	}
	ss << "------------------------------------------" << std::endl;
	ss << "Subtotal: " << _subtotal << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Total: " << _total << std::endl;
	ss << "------------------------------------------" << std::endl;
	return ss.str();
}

std::string VentaOnline::toString() const
{
	std::stringstream ss;
	ss << "Factura de venta online" << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Cliente: " << _cliente->getNombre() << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Fecha: " << _fecha->toString() << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Codigo de lugar de entrega: " << _codigoLugarEntrega << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Productos comprados: " << std::endl;
	ss << "------------------------------------------" << std::endl;
	for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
	{
		ss << _carritoDeCompras->get(i)->toString() << std::endl;
	}
	ss << "------------------------------------------" << std::endl;
	ss << "Subtotal: " << _subtotal << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Total: " << _total << std::endl;
	return ss.str();
}

Venta* VentaOnline::clonar() const
{
	return new VentaOnline(*this);
}
