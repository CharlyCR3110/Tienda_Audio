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
	// abre el archivo de texto (LO ABRE, PERO NO BORRA LO QUE YA ESTABA ESCRITO)
	std::ofstream archivo("../Archivos/notificaciones.txt", std::ios::app); // solo para que muestre que se elimino el componente
	archivo << "El componente con codigo " << producto->getCodigo() << " ha sido agregado al catalogo." << std::endl;
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
		// abre el archivo de texto (LO ABRE, PERO NO BORRA LO QUE YA ESTABA ESCRITO)
		std::ofstream archivo("../Archivos/notificaciones.txt", std::ios::app); // solo para que muestre que se elimino el componente
		archivo << "El componente con codigo " << codigo << " ha sido eliminado del catalogo." << std::endl;
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

Componente* Tienda::obtenerPunteroAComponente(std::string codigo)
{
	return _catalogo->obtenerPunteroAComponente(codigo);
}

bool Tienda::existeOtroSistemaPreconfigurado(std::string codigo)
{
	try
	{
		return _catalogo->existeOtroSistemaPreconfigurado(codigo);
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

#include "Mapa.h"
std::string Tienda::mostrarComponenteMasVendido()
{
	if (_ventas->estaVacia()) 
	{
		return "No se han realizado ventas.";
	}

	// Crear un mapa para realizar el conteo de componentes vendidos
	Mapa<Componente*, int> conteoComponentes;

	// Iterar sobre la lista de ventas y contar los componentes vendidos
	Nodo<Venta>* nodoVenta = _ventas->getPrimero();
	while (nodoVenta != nullptr) 
	{
		Nodo<Componente>* nodoComponente = nodoVenta->getDato()->getCarritoDeCompras()->getPrimero();
		while (nodoComponente != nullptr) 
		{
			Componente* componente = nodoComponente->getDato();
			if (conteoComponentes.encontrar(componente)) 
			{
				// El componente ya está en el mapa, incrementar su conteo
				conteoComponentes[componente] += componente->getCantidadEnCarrito();
			}
			else
			{
				// El componente no está en el mapa, agregarlo normalmente
				conteoComponentes.insertar(componente, componente->getCantidadEnCarrito());
			}
			nodoComponente = nodoComponente->getSiguiente();
		}
		nodoVenta = nodoVenta->getSiguiente();
	}

	// Encontrar el componente más vendido
	Componente* componenteMasVendido = nullptr;
	int cantidadMasVendida = 0;
	for (Mapa<Componente*, int>::Nodo* it = conteoComponentes.begin(); it != conteoComponentes.end(); it = it->siguiente) 
	{
		if (it->valor > cantidadMasVendida) 
		{
			componenteMasVendido = it->clave;
			cantidadMasVendida = it->valor;
		}
	}


	// Construir el mensaje de resultado utilizando stringstream
	std::stringstream ss;
	if (componenteMasVendido != nullptr) 
	{
		ss << "El componente más vendido es: " << componenteMasVendido->toString() << std::endl;
		ss << "Cantidad vendida: " << cantidadMasVendida << " unidades.";
	}
	else 
	{
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

Catalogo* Tienda::getCatalogo() const
{
	return _catalogo;
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

std::string Tienda::mostrarComponentesDelCatalagoReducido()
{

	try
	{
		return _catalogo->toStringReducido();
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

std::string Tienda::mostrarSistemaPreconfigurado(std::string codigo)
{
	try
	{
		return _catalogo->buscarComponentePorCodigo(codigo)->toString();
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::guardarClientes()
{
	try
	{
		GestorArchivos::guardarListaDeClientes(_clientes);
		std::cout << "Se ha guardado la lista de clientes." << std::endl;
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::recuperarClientes()
{
	try
	{
		GestorArchivos::recuperarListaDeClientes(_clientes);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::guardarCatalogo()
{
	try
	{
		GestorArchivos::guardarCatalogo(_catalogo);
		std::cout << "Se ha guardado el catalogo." << std::endl;
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::recuperarCatalogo()
{
	try
	{
		GestorArchivos::recuperarCatalogo(_catalogo);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::guardarVentas()
{
	try
	{
		GestorArchivos::guardarVentas(_ventas);
		std::cout << "Se ha guardado la lista de ventas." << std::endl;
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

void Tienda::recuperarVentas()
{
	try
	{
		GestorArchivos::recuperarVentas(_ventas, _clientes);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}
