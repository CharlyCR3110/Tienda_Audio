#include "Catalogo.h"

Catalogo::Catalogo()
{
	componentes = new ListaEnlazada<Componente>();
}

Catalogo::Catalogo(const Catalogo& other)
{
	// se copian los componentes uno a uno
	if (componentes != nullptr)
	{
		componentes->~ListaEnlazada();
		delete componentes;
	}
	componentes = new ListaEnlazada<Componente>();
	for (int i = 0; i < other.componentes->getCantidad(); i++)
	{
		componentes->insertarDato(other.componentes->get(i));
	}
	std::cout << "Catalogo copiado" << std::endl;	// borrame
}

Catalogo::~Catalogo()
{
	delete componentes;
}

Catalogo* Catalogo::clonar() const
{
	return new Catalogo(*this);
}

void Catalogo::agregarComponente(Componente* componente)
{
	try
	{
		componentes->insertarDato(componente);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;	// borrame
		throw e;
	}
}

void Catalogo::eliminarComponente(Componente* componente)
{
	try
	{
		componentes->eliminarDato(componente);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Catalogo eliminar componente error: " << e.what() << std::endl;	// borrame
		throw std::exception(e.what());
	}
}

void Catalogo::eliminarComponentePorCodigo(std::string codigo)
{
	try
	{
		componentes->eliminarDatoPorCodigo(codigo);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;	// borrame
		throw std::exception(e.what());
	}
}

std::string Catalogo::mostrarCatalogo()
{
	try
	{
		return componentes->toString();
	}
	catch (ListaVaciaException& e)
	{
		std::cerr << "Mostrar Catalogo Error: " << e.what() << std::endl;	// borrame
		throw std::exception(e.what());
	}
}

std::string Catalogo::mostrarCategoriaDelCatalogo(std::string categoria)
{
	try
	{
		return componentes->mostrarPorCategoria(categoria);	
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;	// borrame
		throw e;
	}
}
