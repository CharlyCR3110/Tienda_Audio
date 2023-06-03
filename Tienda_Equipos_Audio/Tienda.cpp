#include "Tienda.h"

Tienda::Tienda() :
	_catalogo(new Catalogo()),
	_clientes(new ListaEnlazada<Cliente>()),
	_ventas(new ListaEnlazada<Venta>()),
	_fechaActual(new Fecha())
{
}

Tienda::~Tienda()
{
	delete _catalogo;
	delete _clientes;
	delete _ventas;
}

void Tienda::agregarComponente(Componente* producto)
{
	_catalogo->agregarComponente(producto);
	notificarClientes();

}

void Tienda::eliminarComponente(Componente* producto)
{
	_catalogo->eliminarComponente(producto);
	notificarClientes();
}

void Tienda::suscribirCliente(Cliente* cliente)
{
	try
	{
		_clientes->insertarDato(cliente);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::desuscribirCliente(Cliente* cliente)
{
	try
	{
		_clientes->eliminarDato(cliente);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::notificarClientes()
{
	for (int i = 0; i < _clientes->getCantidad(); i++)
	{
		_clientes->get(i)->Update();
	}
}

std::string Tienda::mostrarCatalogo()
{
	try
	{
		return _catalogo->mostrarCatalogo();
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

Componente* Tienda::escogerComponenteDelCatalogo(std::string codigo)
{
	try
	{
		return _catalogo->buscarComponentePorCodigo(codigo);	// el componente se clona en buscarComponentePorCodigo para evitar que se modifique el original
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

bool Tienda::existeUsuarioRegistrado(std::string codigo)
{
	try
	{
		return _clientes->existeDatoPorCodigo(codigo);	// si la lista esta vacia, lanza una excepcion
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

Cliente* Tienda::buscarCliente(std::string codigo)
{
	try
	{
		return _clientes->buscarPorCodigo(codigo);	// si la lista esta vacia, lanza una excepcion
	}
	catch (std::exception& e)	// si no encuentra el cliente o la lista esta vacia
	{
		throw std::exception(e.what());
	}
}

Fecha* Tienda::getFechaActual() const
{
	return _fechaActual;
}
