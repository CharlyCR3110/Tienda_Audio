#include "UnidadBluetooth.h"

UnidadBluetooth::UnidadBluetooth() :
	FuenteDeAudio()
{
	this->_nombreComponente = "Unidad Bluetooth";
}

UnidadBluetooth::UnidadBluetooth(std::string codigo, std::string caracteristicas, double precio) :
	FuenteDeAudio(codigo, caracteristicas, precio)
{
	this->_nombreComponente = "Unidad Bluetooth";
}

UnidadBluetooth::UnidadBluetooth(const UnidadBluetooth& other) :
	FuenteDeAudio(other)
{
}

UnidadBluetooth::~UnidadBluetooth()
{
}

std::string UnidadBluetooth::toString() const
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

Componente* UnidadBluetooth::clonar() const
{
	return new UnidadBluetooth(*this);
}

void UnidadBluetooth::add(Componente* componente)
{
	// Es una leaf, no se puede agregar nada
}

void UnidadBluetooth::remove(Componente* componente)
{
	// Es una leaf, no se puede remover nada
}

Componente* UnidadBluetooth::getChild(int i) const
{
	// Es una leaf, no tiene hijos
	return nullptr;
}

void UnidadBluetooth::clear()
{
	// Es una leaf, no tiene hijos
}

UnidadBluetooth& UnidadBluetooth::operator=(const UnidadBluetooth& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}