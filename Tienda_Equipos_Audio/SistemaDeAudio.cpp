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

std::string SistemaDeAudio::toString() const
{
	std::stringstream ss;
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
		std::cout << "No se puede agregar el componente " << componente->getNombre() << " porque el sistema de audio esta lleno" << std::endl;
	}
}

void SistemaDeAudio::remove(Componente* componente)
{
	bool encontrado = false;
	int i = 0;
	while (!encontrado && i < _cantidad)
	{
		if (_componentes[i] == componente)
		{
			encontrado = true;
		}
		else
		{
			i++;
		}
	}
	if (encontrado)
	{
		// se elimina el componente
		delete _componentes[i];
		// se rellena el espacio
		for (int j = i; j < _cantidad - 1; j++)
		{
			_componentes[j] = _componentes[j + 1];
		}
		_cantidad--;
	}
	else
	{
		// TO-DO cambiar por excepcion
		std::cout << "No se puede eliminar el componente " << componente->getNombre() << " porque no esta en el sistema de audio" << std::endl;
	}
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
