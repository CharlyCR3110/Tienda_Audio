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

std::string Catalogo::toStringReducido()
{
	std::stringstream ss;
	Componente* componenteActual = nullptr;
	Nodo<Componente>* nodoActual = componentes->getPrimero();
	
	if (nodoActual == nullptr)
	{
		throw ListaVaciaException();
	}

	while (nodoActual != nullptr)
	{
		componenteActual = nodoActual->getDato();

		ss << "----------------------------------------------------------------------------" << std::endl;
		ss << "Nombre: " << componenteActual->getNombreComponente() << std::endl;
		ss << " Codigo: " << componenteActual->getCodigo() << std::endl;
		ss << "Codigo de los componentes del sistema: " << std::endl;
		ss << "Procesador de senal: " << componenteActual->getChild(0)->getCodigo() << std::endl;
		ss << "Amplificador: " << componenteActual->getChild(1)->getCodigo() << std::endl;
		ss << "Parlante: " << componenteActual->getChild(2)->getCodigo() << std::endl;
		ss << "----------------------------------------------------------------------------" << std::endl;
		nodoActual = nodoActual->getSiguiente();
	}

	return ss.str();

}

bool Catalogo::estaVacio()
{
	return componentes->estaVacia();
}

std::string Catalogo::guardarCatalogo()
{
	std::stringstream ss;
	Componente* componenteActual = nullptr;
	for (int i = 0; i < componentes->getCantidad(); i++)
	{
		// se obtiene el componente actual
		componenteActual = componentes->get(i);
		// se agrega el codigo del componnete actual seguido del caracter separador
		ss << componenteActual->getCodigo() << ";";
		// se agrega el nombre del componente actual seguido del caracter separador
		ss << componenteActual->getNombreComponente() << ";";
		// se agregan los codigos de los 3 componentes que componen el componente actual
		for (int j = 0; j < 3; j++)
		{
			ss << componenteActual->getChild(j)->getCodigo() << ";";
		}
		// se agrega un caracter para indicar el final de un componente y el inicio de otro
		ss << "\n";
	}
	return ss.str();
}

Componente* Catalogo::buscarComponentePorCodigo(std::string codigo)
{
	try
	{
		return componentes->buscarPorCodigo(codigo)->clonar();
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

Componente* Catalogo::obtenerPunteroAComponente(std::string codigo)
{
	try
	{
		return componentes->buscarPorCodigo(codigo);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}

bool Catalogo::existeOtroSistemaPreconfigurado(std::string codigo)
{
	try
	{
		return componentes->existeDatoPorCodigo(codigo);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}
}
