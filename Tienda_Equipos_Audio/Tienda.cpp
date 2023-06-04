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
	_catalogo->agregarComponente(producto->clonar());
	notificarClientes();
}

void Tienda::eliminarComponente(Componente* producto)
{
	_catalogo->eliminarComponente(producto);
	notificarClientes();
}

void Tienda::eliminarComponetePorCodigo(std::string codigo)
{
	try
	{
		_catalogo->eliminarComponentePorCodigo(codigo);
		notificarClientes();
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
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

#include <map>
std::string Tienda::mostrarComponenteMasVendido()
{
	if (_ventas->estaVacia()) {
		return "No se han realizado ventas.";
	}

	// Crear un mapa para realizar el conteo de componentes vendidos
	std::map<Componente*, int> conteoComponentes;

	// Iterar sobre la lista de ventas y contar los componentes vendidos
	Nodo<Venta>* nodoVenta = _ventas->getPrimero();
	while (nodoVenta != nullptr) {
		Nodo<Componente>* nodoComponente = nodoVenta->getDato()->getCarritoDeCompras()->getPrimero();
		while (nodoComponente != nullptr) {
			Componente* componente = nodoComponente->getDato();
			if (conteoComponentes.find(componente) != conteoComponentes.end()) {
				// El componente ya está en el mapa, incrementar su conteo
				conteoComponentes[componente]++;
			}
			else {
				// El componente no está en el mapa, inicializar su conteo en 1
				conteoComponentes[componente] = 1;
			}
			nodoComponente = nodoComponente->getSiguiente();
		}
		nodoVenta = nodoVenta->getSiguiente();
	}

	// Encontrar el componente más vendido
	Componente* componenteMasVendido = nullptr;
	int cantidadMasVendida = 0;
	for (const auto& pair : conteoComponentes) {
		if (pair.second > cantidadMasVendida) {
			componenteMasVendido = pair.first;
			cantidadMasVendida = pair.second;
		}
	}

	// Construir el mensaje de resultado utilizando stringstream
	std::stringstream ss;
	if (componenteMasVendido != nullptr) {
		ss << "El componente más vendido es: " << componenteMasVendido->toString() << std::endl;
		ss << "Cantidad vendida: " << cantidadMasVendida << " unidades.";
	}
	else {
		ss << "No se han vendido componentes aún.";
	}

	return ss.str();
}

std::string Tienda::mostrarTotalVentas()
{
	try
	{
		return _ventas->toString();
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::agregarVenta(Venta* venta)
{
	try
	{
		_ventas->insertarDato(venta);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}


Fecha* Tienda::getFechaActual() const
{
	return _fechaActual;
}

std::string Tienda::mostrarListaClientes()
{
	try
	{
		return _clientes->toString();
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}
