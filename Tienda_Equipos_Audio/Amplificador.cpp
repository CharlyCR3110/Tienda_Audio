#include "Amplificador.h"

Amplificador::Amplificador() :
	ProcesadorDeSenal()
{
	this->_nombreComponente = "Amplificador";
}

Amplificador::Amplificador(std::string codigo, std::string caracteristicas, double precio) :
	ProcesadorDeSenal(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Amplificador";
}

Amplificador::Amplificador(const Amplificador& other) :
	ProcesadorDeSenal(other)
{
}

Amplificador::~Amplificador()
{
}

std::string Amplificador::toString() const
{
	std::stringstream ss;
	ss << "Codigo: " << _codigo << std::endl;
	ss << "Categoria: " << _categoria << std::endl;
	ss << "Nombre: " << _nombreComponente << std::endl;
	ss << "Caracteristicas: " << _caracteristicas << std::endl;
	ss << "Precio Unitario: " << _precio << std::endl;
	ss << "Cantidad: " << _cantidadEnElCarrito << std::endl;
	return ss.str();
}

Componente* Amplificador::clonar() const
{
	return new Amplificador(*this);
}

void Amplificador::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Amplificador::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Amplificador::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Amplificador::clear()
{
	// Es una leaf, no tiene hijos
}

Amplificador& Amplificador::operator=(const Amplificador& other)
{
	if (this != &other)
	{
		ProcesadorDeSenal::operator=(other);
	}
	return *this;
}