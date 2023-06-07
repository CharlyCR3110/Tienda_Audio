#include "Venta.h"

Venta::Venta() :
	_cliente(nullptr),
	_fecha(new Fecha()),
	_carritoDeCompras(new ListaEnlazada<Componente>()),
	_total(0),
	_subtotal(0),
	_tipoDeVenta(' ')
{
}

Venta::Venta(Cliente* cliente, Fecha* fecha) :
	_cliente(cliente),
	_fecha(fecha),
	_carritoDeCompras(new ListaEnlazada<Componente>()),
	_total(0),
	_subtotal(0),
	_tipoDeVenta(' ')
{
}

Venta::Venta(const Venta& venta) :
	_cliente(venta._cliente),
	_fecha(venta._fecha),
	_carritoDeCompras(venta._carritoDeCompras),
	_total(venta._total),
	_subtotal(venta._subtotal),
	_tipoDeVenta(venta._tipoDeVenta)
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

ListaEnlazada<Componente>* Venta::getCarritoDeCompras()
{
	return _carritoDeCompras;	// tal vez se deba retornar una copia
}

char Venta::getTipoDeVenta() const
{
	return _tipoDeVenta;
}

double Venta::getTotal() const
{
	return _total;
}

double Venta::getSubtotal() const
{
	return _subtotal;
}


void Venta::setCliente(Cliente* cliente)
{
	_cliente = cliente;
}

void Venta::setFecha(Fecha* fecha)
{
	_fecha = fecha;
}

void Venta::setTotal(double total)
{
	_total = total;
}

void Venta::setSubtotal(double subtotal)
{
	_subtotal = subtotal;
}

void Venta::agregarComponente(Componente* componente, int cantidad)
{
	// se clona el componente y luego se agrega
	Componente* componenteClonado = componente->clonar();
	componenteClonado->setCantidadEnCarrito(cantidad);

	try
	{
		_subtotal += componenteClonado->getPrecioUnitario() * cantidad;

		// comprobar que el componente no se encuentre en la lista de componentes
		// si se encuentra, se aumenta la cantidad
		// si no se encuentra, se agrega a la lista
		for (int i = 0; i < _carritoDeCompras->getCantidad(); i++)
		{
			Componente* componenteEnLista = _carritoDeCompras->get(i);

			if (componenteEnLista->getCodigo() == componenteClonado->getCodigo())
			{
				// se aumenta la cantidad
				componenteEnLista->setCantidadEnCarrito(componenteEnLista->getCantidadEnCarrito() + cantidad);
				return;
			}
		}
		// si no se encuentra, se agrega a la lista
		_carritoDeCompras->insertarDato(componenteClonado);
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
