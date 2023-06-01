#include "Tienda.h"

Tienda::Tienda() :
	catalogo(new Catalogo()),
	clientes(new ListaEnlazada<Cliente>())
{
}

Tienda::~Tienda()
{
	delete catalogo;
	delete clientes;
}

void Tienda::agregarComponente(Componente* producto)
{
	catalogo->agregarComponente(producto);
	notificarClientes();

}

void Tienda::eliminarComponente(Componente* producto)
{
	catalogo->eliminarComponente(producto);
	notificarClientes();
}

void Tienda::suscribirCliente(Cliente* cliente)
{
	try
	{
		clientes->insertarDato(cliente);
	}
	catch (std::exception& e)
	{
		throw new std::exception(e.what());
	}
}

void Tienda::desuscribirCliente(Cliente* cliente)
{
	try
	{
		clientes->eliminarDato(cliente);
	}
	catch (std::exception& e)
	{
		throw new std::exception(e.what());
	}
}

void Tienda::notificarClientes()
{
	for (int i = 0; i < clientes->getCantidad(); i++)
	{
		clientes->get(i)->Update();
	}
}
