#include "Audifono.h"

Audifono::Audifono() :
	ParlanteCat()
{
	this->_nombreComponente = "Audifono";
}

Audifono::Audifono(std::string codigo, std::string caracteristicas, double precio) :
	ParlanteCat(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Audifono";
}

Audifono::Audifono(const Audifono& other) :
	ParlanteCat(other)
{
}

Audifono::~Audifono()
{
}

std::string Audifono::toString() const
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

Componente* Audifono::clonar() const
{
	return new Audifono(*this);
}

void Audifono::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void Audifono::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* Audifono::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void Audifono::clear()
{
	// Es una leaf, no tiene hijos
}

Audifono& Audifono::operator=(const Audifono& other)
{
	if (this != &other)
	{
		ParlanteCat::operator=(other);
	}
	return *this;
}