#include "UnidadBluetooth.h"

UnidadBluetooth::UnidadBluetooth() :
	FuenteDeAudio()
{
}

UnidadBluetooth::UnidadBluetooth(std::string modelo, std::string caracteristicas, double precio) :
	FuenteDeAudio(modelo, caracteristicas, precio)
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
	ss << "Unidad Bluetooth: " << _modelo << " " << _caracteristicas << " " << _precio;
	return ss.str();
}

UnidadBluetooth& UnidadBluetooth::operator=(const UnidadBluetooth& other)
{
	if (this != &other)
	{
		FuenteDeAudio::operator=(other);
	}
	return *this;
}