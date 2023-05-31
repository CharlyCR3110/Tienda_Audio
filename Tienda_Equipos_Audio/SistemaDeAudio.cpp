#include "SistemaDeAudio.h"

// por defecto se crea un sistema de audio con capacidad 3
SistemaDeAudio::SistemaDeAudio():
	Componente(),
	_capacidad(3),
	_cantidad(0),
	_componentes(new Componente* [3])
{
	for (int i = 0; i < 3; i++)
	{
		_componentes[i] = nullptr;	// inicializar el arreglo
	}
}

SistemaDeAudio::SistemaDeAudio(std::string codigo, std::string nombre):
	Componente(codigo, "", 0.0),
	_capacidad(3),
	_cantidad(0),
	_componentes(new Componente* [3])
{
	this->_nombre = nombre;
	for (int i = 0; i < 3; i++)
	{
		_componentes[i] = nullptr;	// inicializar el arreglo
	}
}

SistemaDeAudio::SistemaDeAudio(int capacidad) :
	Componente(),
	_capacidad(capacidad),
	_cantidad(0),
	_componentes(new Componente* [capacidad])
{
	for (int i = 0; i < capacidad; i++)
	{
		_componentes[i] = nullptr;	// inicializar el arreglo
	}
}

SistemaDeAudio::SistemaDeAudio(const SistemaDeAudio& other)
{
	*this = other;
}

SistemaDeAudio::~SistemaDeAudio()
{
	for (int i = 0; i < _cantidad; i++)
	{
		delete _componentes[i];
	}
	delete[] _componentes;
	_componentes = nullptr;
	_cantidad = 0;
	_capacidad = 0;
}

double SistemaDeAudio::getPrecio() const
{
	double precio = 0;
	for (int i = 0; i < _cantidad; i++)
	{
		precio += _componentes[i]->getPrecio();
	}
	return precio;
}

std::string SistemaDeAudio::getNombre() const
{
	return std::string();
}

std::string SistemaDeAudio::toString() const
{
	std::stringstream ss;
	ss << "Codigo: " << _codigo << "\tNombre: " << _nombre << "\tPrecio: " << getPrecio() << std::endl;
	ss << "Sistema de Audio: " << _cantidad << " de " << _capacidad << " componentes" << std::endl;
	for (int i = 0; i < _cantidad; i++)
	{
		ss << "\t" << _componentes[i]->toString() << std::endl;
	}
	return ss.str();
}

Componente* SistemaDeAudio::clonar() const
{
	return new SistemaDeAudio(*this);
}

void SistemaDeAudio::add(Componente* componente)
{
	if (_cantidad < _capacidad)
	{
		_componentes[_cantidad++] = componente->clonar();
	}
	else
	{
		// TO-DO cambiar por excepcion
		std::cout << "No se puede agregar el componente " << componente->getCodigo() << " porque el sistema de audio esta lleno" << std::endl;
	}
}

void SistemaDeAudio::remove(Componente* componente)
{
	for (int i = 0; i < _cantidad; i++)
	{
		if (*_componentes[i] == *componente)
		{
			std::cout << "Se ha eliminado el componente " << componente->getCodigo() << " del sistema de audio" << std::endl;
			delete _componentes[i];
			_componentes[i] = _componentes[--_cantidad];
			_componentes[_cantidad] = nullptr;
			return;
		}
	}
	// TO-DO cambiar por excepcion
	std::cout << "No se puede eliminar el componente " << componente->getCodigo() << " porque no esta en el sistema de audio" << std::endl;
}

Componente* SistemaDeAudio::getChild(int i) const
{
	if (i >= 0 && i < _cantidad)
	{
		return _componentes[i];
	}
	else
	{
		return nullptr;
	}
}

void SistemaDeAudio::clear()
{
	// elimina los componentes del sistema de audio
	for (int i = 0; i < _cantidad; i++)
	{
		delete _componentes[i];
	}
	_cantidad = 0;
}

SistemaDeAudio& SistemaDeAudio::operator=(const SistemaDeAudio& other)
{
	if (this != &other)
	{
		//  Primero, liberamos la memoria ocupada por los componentes existentes
		clear();
		// se copian los miembros heredados de Componente
		Componente::operator=(other);

		// Copiamos los miembros especificos de SistemaDeAudio
		_capacidad = other._capacidad;
		_cantidad = other._cantidad;

		// se crea un nuevo arreglo de componentes
		_componentes = new Componente* [_capacidad];

		// se copian los componentes
		if (_capacidad > _cantidad)	// para evitar desbordamiento
		{
			for (int i = 0; i < _cantidad; i++)
			{
				_componentes[i] = other._componentes[i]->clonar();
			}
		}
	}
	return *this;
}
