#pragma once
#include <iostream>
#include <sstream>

//template
template <class T>
class Nodo
{
private:
	T* _dato;
	Nodo<T>* _siguiente;
public:
	Nodo(const T& dato);	//constructor copia
	Nodo(T* dato);
	~Nodo();
	void setSiguiente(Nodo<T>* siguiente_);
	Nodo<T>* getSiguiente();
	T* getDato();
	//sobrecarga de metodos
	friend std::ostream& operator<<(std::ostream& out, Nodo<T>& nodo);	// operador de salida
	Nodo<T>& operator=(const Nodo<T>& other);	// operador de asignacion
};

template<class T>
inline Nodo<T>::Nodo(const T& dato)
{
	_dato = new T(dato);
	_siguiente = nullptr;
}

template<class T>
inline Nodo<T>::Nodo(T* dato)
{
	_dato = dato;
	_siguiente = nullptr;
}

template<class T>
Nodo<T>::~Nodo()
{
	delete _dato;
	_dato = nullptr;
	_siguiente = nullptr;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente)
{
	_siguiente = siguiente;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente()
{
	return _siguiente;
}

template<class T>
T* Nodo<T>::getDato()
{
	return _dato;
}

template<class T>
inline Nodo<T>& Nodo<T>::operator=(const Nodo<T>& other)
{
	if (this != &other)
	{
		_dato = other._dato;
		_siguiente = other._siguiente;
	}
	return *this;
}