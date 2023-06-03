#include "Venta.h"

Venta::Venta() :
	_cliente(nullptr),
	_fecha(new Fecha()),
	_carritoDeCompras(new ListaEnlazada<Componente>()),
	_total(0),
	_subtotal(0)
{
}

Venta::Venta(Cliente* cliente, Fecha* fecha) :
	_cliente(cliente),
	_fecha(fecha),
	_carritoDeCompras(new ListaEnlazada<Componente>()),
	_total(0),
	_subtotal(0)
{
}

Venta::Venta(const Venta& venta) :
	_cliente(venta._cliente),
	_fecha(venta._fecha),
	_carritoDeCompras(venta._carritoDeCompras),
	_total(venta._total),
	_subtotal(venta._subtotal)
{
}

Venta::~Venta()
{
	delete _carritoDeCompras;
	delete _fecha;
	delete _cliente;
}

Cliente* Venta::getCliente() const
{
	return _cliente;
}

Fecha* Venta::getFecha() const
{
	return _fecha;
}


void Venta::setCliente(Cliente* cliente)
{
	_cliente = cliente;
}

void Venta::setFecha(Fecha* fecha)
{
	_fecha = fecha;
}

void Venta::agregarComponente(Componente* componente, int cantidad)
{
	// se clona el componente y luego se agrega
	Componente* componenteClonado = componente->clonar();
	componenteClonado->setCantidadEnCarrito(cantidad);

	try
	{
		_carritoDeCompras->insertarDato(componenteClonado);
		std::cout << "Componente precio: " << componenteClonado->getPrecioUnitario() << std::endl;	// "debug
		std::cout << "cantidad: " << cantidad << std::endl;	// "debug
		_subtotal += componenteClonado->getPrecioUnitario() * cantidad;
		std::cout << "subtotal: " << _subtotal << std::endl;	// "debug
		_total = _subtotal;
		std::cout << "Componente agregado al carrito de compras" << std::endl;
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Venta::eliminarComponente(Componente* componente)
{
	try
	{
		_carritoDeCompras->eliminarDato(componente);
		std::cout << "Componente eliminado del carrito de compras" << std::endl;
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Venta::vaciarCarrito()
{
	_carritoDeCompras->vaciar();
}

std::ostream& operator<<(std::ostream& out, const Venta& other)
{
	out << other.toString();
	return out;
}