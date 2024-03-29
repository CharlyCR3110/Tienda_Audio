#include "VentaOnline.h"

VentaOnline::VentaOnline() :
	Venta(),
	_codigoLugarEntrega("")
{
	this->_tipoDeVenta = 'O';
}

VentaOnline::VentaOnline(Cliente* cliente, Fecha* fecha, std::string codigoLugarEntrega)
	: Venta(cliente, fecha),
	_codigoLugarEntrega(codigoLugarEntrega)
{
	_total = MontoTranslado::getMonto(_codigoLugarEntrega);
	this->_tipoDeVenta = 'O';
}

VentaOnline::VentaOnline(const VentaOnline& other) :
	Venta(other),
	_codigoLugarEntrega(other._codigoLugarEntrega)
{
	this->_tipoDeVenta = 'O';
}

VentaOnline::~VentaOnline()
{
}

void VentaOnline::calcularTotal()
{
	//double total = 0;
	//for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
	//{
	//	total += _carritoDeCompras->get(i)->getPrecio();
	//}
	//total += MontoTranslado::getMonto(_codigoLugarEntrega);
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
		if (_carritoDeCompras->get(i)->getCategoria() != "Sistema Personalizado" && _carritoDeCompras->get(i)->getCategoria() != "Sistema Pre-Configurado")
		{
			ss << "( " << i + 1 << " )   " << "Componente Simple\t" << _carritoDeCompras->get(i)->toString() << std::endl;
		}
		else
		{
			ss << "( " << i + 1 << " )   " << _carritoDeCompras->get(i)->toString() << std::endl;
		}
	}
	ss << "------------------------------------------" << std::endl;
	ss << "Subtotal: " << _subtotal << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Total: " << _total << std::endl;
	ss << "------------------------------------------" << std::endl;
	return ss.str();
}

std::string VentaOnline::toString()
{
	calcularTotal();
	std::stringstream ss;
	ss << "------------------------------------------" << std::endl;
	ss << "Venta online" << std::endl;
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
		if (_carritoDeCompras->get(i)->getCategoria() != "Sistema Personalizado" && _carritoDeCompras->get(i)->getCategoria() != "Sistema Pre-Configurado")
		{
			ss << "( " << i + 1 << " )   " << "Componente Simple\t" << _carritoDeCompras->get(i)->toString() << std::endl;
		}
		else
		{
			ss << "( " << i + 1 << " )   " << _carritoDeCompras->get(i)->toString() << std::endl;
		}
	}
	ss << "------------------------------------------" << std::endl;
	ss << "Precio del envio: " << MontoTranslado::getMonto(_codigoLugarEntrega) << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Total: " << _total << std::endl;
	ss << "------------------------------------------" << std::endl;
	return ss.str();
}

std::string VentaOnline::getCodigoLugarEntrega() const
{
	return _codigoLugarEntrega;
}

Venta* VentaOnline::clonar() const
{
	return new VentaOnline(*this);
}
