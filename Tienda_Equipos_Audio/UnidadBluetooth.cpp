#include "UnidadBluetooth.h"

UnidadBluetooth::UnidadBluetooth() :
	FuenteDeAudio()
{
}

UnidadBluetooth::UnidadBluetooth(std::string codigo, std::string caracteristicas, double precio) :
	FuenteDeAudio(codigo, caracteristicas, precio)
{
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
	ss << "Unidad Bluetooth: " << _codigo << " " << _caracteristicas << " " << _precio;
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