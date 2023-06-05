#include "VentaDirecta.h"

VentaDirecta::VentaDirecta():
	Venta()
{
}

VentaDirecta::VentaDirecta(Cliente* cliente, Fecha* fecha):
	Venta(cliente, fecha)
{
}

VentaDirecta::VentaDirecta(const VentaDirecta& other):
	Venta(other)
{
}

VentaDirecta::~VentaDirecta()
{
	Venta::~Venta();
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

std::string VentaDirecta::toString() const
{
	std::stringstream ss;
	ss << "------------------------------------------" << std::endl;
	ss << "Venta DIrecta" << std::endl;
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
