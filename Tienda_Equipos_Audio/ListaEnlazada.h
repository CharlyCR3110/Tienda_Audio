#pragma once
#include "Nodo.h"
// excepciones
#include "ListaEnlazadasExceptions.h"
#include "ListaVaciaException.h"
#include "ElementoNoEncontradoException.h"

template <class T>
class ListaEnlazada
{
public:
	ListaEnlazada();
	ListaEnlazada(const ListaEnlazada<T>& lista_);	// constructor copia
	~ListaEnlazada();
	// getters
	Nodo<T>* getPrimero();
	Nodo<T>* getUltimo();
	int getCantidad() const;
	// utiles
	const bool estaVacia() const;
	// metodos para insertar
	void insertar(T* dato);	// inserta al final
	void insertarAlInicio(T* dato);	// inserta al inicio
	// metodos para eliminar
	void eliminar(int posicion);	// elimina por posicion
	void eliminarPrimero();	// elimina el primero
	void eliminarUltimo();	// elimina el ultimo
	void eliminarDato(T* dato);	// elimina el dato
	void eliminarDatoPorCodigo(std::string codigo);	// elimina el dato por codigo
	// vaciar
	void vaciar();
	// metodos para buscar
	bool existeDato(T* dato);	// busca el dato y devuelve true si lo encuentra
	bool existeDatoPorCodigo(std::string codigo);	// busca el dato por codigo y devuelve true si lo encuentra
	Nodo<T>* buscarNodo(T* dato);	// busca el nodo y devuelve el nodo si lo encuentra
	T* buscarPorCodigo(std::string codigo);	// busca el dato por codigo y devuelve el dato si lo encuentra
	// mostrar datos
	std::string toString() const;
	std::string mostrarPorCategoria(std::string categoria) const;
private:
	Nodo<T>* _primero;
	Nodo<T>* _ultimo;
	int _cantidad;
};

template<class T>
inline ListaEnlazada<T>::ListaEnlazada()
{
	_primero = nullptr;
	_ultimo = nullptr;
	_cantidad = 0;
}

template<class T>
inline ListaEnlazada<T>::~ListaEnlazada()
{
	Nodo<T>* actual = _primero;
	while (actual != nullptr)
	{
		Nodo<T>* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
	_primero = nullptr;
	_ultimo = nullptr;
	_cantidad = 0;
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::getPrimero()
{
	return _primero;
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::getUltimo()
{
	return _ultimo;
}

template<class T>
inline int ListaEnlazada<T>::getCantidad() const
{
	return _cantidad;
}

template<class T>
inline const bool ListaEnlazada<T>::estaVacia() const
{
	return _cantidad == 0;
}

template<class T>
inline void ListaEnlazada<T>::insertar(T* dato)
{
	if (dato == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}

	Nodo<T>* nuevo = new Nodo<T>(dato);
	if (estaVacia())
	{
		_primero = nuevo;
	}
	else
	{
		_ultimo->setSiguiente(nuevo);
	}
	_ultimo = nuevo;
	_cantidad++;
}

template<class T>
inline void ListaEnlazada<T>::insertarAlInicio(T* dato)
{
	if (dato == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}


	Nodo<T>* nuevo = new Nodo<T>(dato);
	if (estaVacia())
	{
		_primero = nuevo;
		_ultimo = nuevo;
	}
	else
	{
		nuevo->setSiguiente(_primero);
		_primero = nuevo;
	}
	_cantidad++;
}

template<class T>
inline void ListaEnlazada<T>::eliminar(int posicion)
{
	if (posicion <= 0 || posicion > _cantidad)
	{
		throw ListaEnlazadasExceptions("Posicion invalida");
	}
	if (posicion == 1)
	{
		eliminarPrimero();
	}
	else if (posicion == _cantidad)
	{
		eliminarUltimo();
	}
	else
	{
		Nodo<T>* actual = _primero;
		for (int i = 1; i < posicion - 1; i++)
		{
			actual = actual->getSiguiente();
		}
		Nodo<T>* eliminar = actual->getSiguiente();
		actual->setSiguiente(eliminar->getSiguiente());
		delete eliminar;
		_cantidad--;
	}
}

template<class T>
inline void ListaEnlazada<T>::eliminarPrimero()
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}
	Nodo<T>* eliminar = _primero;
	_primero = _primero->getSiguiente();
	delete eliminar;
	_cantidad--;
	if (_cantidad == 0)
	{
		_ultimo = nullptr;
	}
}

template<class T>
inline void ListaEnlazada<T>::eliminarUltimo()
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	if (_cantidad == 1)
	{
		delete _primero;
		_primero = _ultimo = nullptr;
	}
	else
	{
		Nodo<T>* actual = _primero;
		while (actual->getSiguiente() != _ultimo)
		{
			actual = actual->getSiguiente();
		}
		delete _ultimo;
		_ultimo = actual;
		actual->setSiguiente(nullptr);
	}
	_cantidad--;
}

template<class T>
inline void ListaEnlazada<T>::eliminarDato(T* dato_)
{
	if (dato_ == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}


	if (estaVacia())
	{
		throw ListaVaciaException();
	}
	Nodo<T>* actual = _primero;
	Nodo<T>* anterior = nullptr;

	while (actual != nullptr && actual->getDato() != dato_)
	{
		anterior = actual;
		actual = actual->getSiguiente();
	}

	if (actual == nullptr)
	{
		throw ElementoNoEncontradoException<T>();
	}

	if (actual == _primero)
	{
		eliminarPrimero();
	}
	else if (actual == _ultimo)
	{
		eliminarUltimo();
	}

	else
	{
		anterior->setSiguiente(actual->getSiguiente());
		delete actual;
		_cantidad--;
	}
}

template<class T>
inline void ListaEnlazada<T>::eliminarDatoPorCodigo(std::string codigo)
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}
	Nodo<T>* actual = _primero;
	Nodo<T>* anterior = nullptr;
	while (actual != nullptr && actual->getDato()->getCodigo() != codigo)
	{
		anterior = actual;
		actual = actual->getSiguiente();
	}
	if (actual == nullptr)
	{
		throw ElementoNoEncontradoException<T>();
	}
	if (actual == _primero)
	{
		eliminarPrimero();
	}
	else if (actual == _ultimo)
	{
		eliminarUltimo();
	}
	else
	{
		anterior->setSiguiente(actual->getSiguiente());
		delete actual;
		_cantidad--;
	}
}

template<class T>
inline void ListaEnlazada<T>::vaciar()
{
	Nodo<T>* actual = _primero;
	while (actual != nullptr)
	{
		Nodo<T>* siguiente = actual->getSiguiente();
		delete actual;
		actual = siguiente;
	}
	_primero = nullptr;
	_ultimo = nullptr;
	_cantidad = 0;
}

// busca el dato en la lista, si existe devuelve true, sino false
template<class T>
inline bool ListaEnlazada<T>::existeDato(T* dato)
{
	if (dato == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}

	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	Nodo<T>* actual = _primero;
	while (actual != nullptr && actual->getDato() != dato)	// recorre la lista hasta encontrar el dato o hasta llegar al final
	{
		actual = actual->getSiguiente();
	}
	// si actual es nulo, es porque llego al final de la lista y no encontro el dato
	return actual != nullptr;
}

template<class T>
inline bool ListaEnlazada<T>::existeDatoPorCodigo(std::string codigo)
{
	if (estaVacia())
	{
		return false;
	}

	Nodo<T>* actual = _primero;
	while (actual != nullptr) {
		if ((actual->getDato())->getCodigo() == codigo) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::buscarNodo(T* dato)
{
	if (dato == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}

	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	Nodo<T>* actual = _primero;
	while (actual != nullptr && actual->getDato() != dato)	// recorre la lista hasta encontrar el dato o hasta llegar al final
	{
		actual = actual->getSiguiente();
	}

	// si actual es nulo, es porque llego al final de la lista y no encontro el dato
	if (actual == nullptr)
	{
		throw ElementoNoEncontradoException<T>();
	}

	return actual;
}

template<class T>
inline T* ListaEnlazada<T>::buscarPorCodigo(std::string codigo)
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	Nodo<T>* actual = _primero;
	while (actual != nullptr && actual->getDato()->getCodigo() != codigo)	// recorre la lista hasta encontrar el dato o hasta llegar al final
	{
		actual = actual->getSiguiente();
	}

	// si actual es nulo, es porque llego al final de la lista y no encontro el dato
	if (actual == nullptr)
	{
		throw ElementoNoEncontradoException<T>();
	}

	return actual->getDato();
}

template<class T>
inline std::string ListaEnlazada<T>::toString() const
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	std::stringstream ss;
	Nodo<T>* actual = _primero;
	while (actual != nullptr)
	{
		//ss << *actual->getDato() << std::endl;
		ss << actual->getDato()->toString() << std::endl;
		actual = actual->getSiguiente();

	}
	return ss.str();
}

template<class T>
inline std::string ListaEnlazada<T>::mostrarPorCategoria(std::string categoria) const
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	std::stringstream ss;
	Nodo<T>* actual = _primero;
	while (actual != nullptr)
	{
		if (actual->getDato()->getCategoria() == categoria) {
			ss << actual->getDato()->toString() << std::endl;
		}
		actual = actual->getSiguiente();

	}
	return ss.str();
}
