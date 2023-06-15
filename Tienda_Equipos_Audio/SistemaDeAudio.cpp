#include "SistemaDeAudio.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

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

	this->_categoria = "Sistema de Audio";
}

SistemaDeAudio::SistemaDeAudio(std::string codigo, std::string nombre, std::string categoria):
	Componente(codigo, "", 0.0),
	_capacidad(3),
	_cantidad(0),
	_componentes(new Componente* [3])
{
	for (int i = 0; i < 3; i++)
	{
		_componentes[i] = nullptr;	// inicializar el arreglo
	}
	this->_nombreComponente = nombre;
	this->_categoria = categoria;	// la categoria puede ser "Sistema Preconfigurado" o "Sistema Personalizado", siendo el primero el sistema creado por la tienda y el segundo el sistema creado por el usuario
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
	this->_categoria = "Sistema de Audio";
}

SistemaDeAudio::SistemaDeAudio(const SistemaDeAudio& other) :
	Componente(other)
{
	_capacidad = other._capacidad;
	_cantidad = other._cantidad;
	_componentes = new Componente * [_capacidad];

	for (int i = 0; i < _cantidad; i++)
	{
		_componentes[i] = other._componentes[i]->clonar();
	}
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
	return _precio * _cantidadEnElCarrito;
}

std::string SistemaDeAudio::toString() const
{
	std::stringstream ss;
	ss << _categoria << std::endl;
	ss << "----------------------------------------------------------------------------" << std::endl;
	ss << "Codigo del sistema: " << _codigo << std::endl
		<< "Nombre: " << _nombreComponente << std::endl
		<< "Precio Unitario: " << getPrecioUnitario() << std::endl
		<< "Cantidad: " << _cantidadEnElCarrito << std::endl;
	ss << "----------------------------------------------------------------------------" << std::endl;
	ss << "Sistema de Audio: " << _cantidad << " de " << _capacidad << " componentes" << std::endl;
	ss << "----------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < _cantidad; i++)
	{
		if (_componentes[i] != nullptr)	// para evitar problemas
		{
			// numero del producto 
			ss << "--------------------------" << "SUBPRODUCTO DEL SISTEMA" << "-------------------------" << std::endl;
			ss << _componentes[i]->toString() << std::endl;
			ss << "----------------------------------------------------------------------------" << std::endl;
		}
	}
	ss << "----------------------------------------------------------------------------" << std::endl;
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
		_precio += componente->getPrecio();
	}
	else
	{
		std::string mensaje = "No se puede agregar el componente " + componente->getCodigo() + " porque el sistema de audio esta lleno";
		throw SistemaDeAudioLlenoException(mensaje);
	}
}

void SistemaDeAudio::remove(Componente* componente)
{
	for (int i = 0; i < _cantidad; i++)
	{
		if (*_componentes[i] == *componente)
		{
			std::cout << "Se ha eliminado el componente " << componente->getCodigo() << " del sistema de audio" << std::endl;
			_precio -= componente->getPrecio();
			delete _componentes[i];
			_componentes[i] = _componentes[--_cantidad];
			_componentes[_cantidad] = nullptr;
			return;
		}
	}
	std::string mensaje = "No se puede eliminar el componente " + componente->getCodigo() + " porque no esta en el sistema de audio";
	throw ComponenteNoEncontradoException(mensaje);
}

Componente* SistemaDeAudio::getChild(int i) const
{
	if (i >= 0 && i < _cantidad)
	{
		return _componentes[i];
	}
	else
	{
		std::string mensaje = "No se puede obtener el componente " + std::to_string(i) + " porque no esta en el sistema de audio";
		throw ComponenteNoEncontradoException(mensaje);
	}
}

void SistemaDeAudio::setChild(int i, Componente* componente)
{
	if (i >= 0 && i < _cantidad)
	{
		_componentes[i] = componente->clonar();
	}
	else
	{
		std::string mensaje = "No se puede establecer el componente " + std::to_string(i) + " porque no esta en el sistema de audio";
		throw ComponenteNoEncontradoException(mensaje);
	}

	// se actualiza el precio del sistema de audio
	_precio = 0;
	for (int i = 0; i < _cantidad; i++)
	{
		_precio += _componentes[i]->getPrecio();
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

		_codigo = other._codigo;
		_nombreComponente = other._nombreComponente;
		_precio = other._precio;
		
		// estos atributos son heredados, pero no son utilizados en esta clase
		_caracteristicas = other._caracteristicas;
		_categoria = other._categoria;
		//
		
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
