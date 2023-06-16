#include "VentaDirecta.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

VentaDirecta::VentaDirecta():
	Venta()
{
	this->_tipoDeVenta = 'D';
}

VentaDirecta::VentaDirecta(Cliente* cliente, Fecha* fecha):
	Venta(cliente, fecha)
{
	this->_tipoDeVenta = 'D';
}

VentaDirecta::VentaDirecta(const VentaDirecta& other):
	Venta(other)
{
	this->_tipoDeVenta = 'D';
}

VentaDirecta::~VentaDirecta()
{
}

void VentaDirecta::calcularTotal()
{
	double total = 0;
	for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
	{
		total += _carritoDeCompras->get(i)->getPrecio();
	}
	_total = total;
}

void VentaDirecta::calcularSubtotal()	// ???
{
	double subtotal = 0;
	for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
	{
		subtotal += _carritoDeCompras->get(i)->getPrecio();
	}
	_subtotal = subtotal;
}

std::string VentaDirecta::generarFactura()
{
	std::stringstream ss;
	ss << "------------------------------------------" << std::endl;
	ss << "Factura de venta directa" << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Cliente: " << _cliente->getNombre() << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Fecha: " << _fecha->toString() << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Productos comprados: " << std::endl;
	ss << "------------------------------------------" << std::endl;
	for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
	{
		ss << "******************************************" << std::endl;
		if (_carritoDeCompras->get(i)->getCategoria() != "Sistema Personalizado" && _carritoDeCompras->get(i)->getCategoria() != "Sistema Pre-Configurado")
		{
			ss << "( " << i + 1 << " )   " << "Componente Simple\t" << _carritoDeCompras->get(i)->toString() << std::endl;
		}
		else
		{
			ss << "( " << i + 1 << " )   " << _carritoDeCompras->get(i)->toString() << std::endl;
		}
		ss << "******************************************" << std::endl;
	}
	ss << "------------------------------------------" << std::endl;
	ss << "Subtotal: " << _subtotal << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Total: " << _total << std::endl;
	ss << "------------------------------------------" << std::endl;
	return ss.str();
}

std::string VentaDirecta::toString()
{
	calcularTotal();
	calcularSubtotal();
	std::stringstream ss;
	ss << "------------------------------------------" << std::endl;
	ss << "Venta Directa" << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Cliente: " << _cliente->getNombre() << std::endl;
	ss << "------------------------------------------" << std::endl;
	ss << "Fecha: " << _fecha->toString() << std::endl;
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
	ss << "Total: " << _total << std::endl;
	ss << "------------------------------------------" << std::endl;
	return ss.str();
}

Venta* VentaDirecta::clonar() const
{
	return new VentaDirecta(*this);
}
