#pragma once
#include <iostream>

// si pudiera usar la STL, usaria un map, pero como no puedo, lo implemento yo
template<typename KeyType, typename ValueType>
class Mapa {
public:
    struct Nodo 
    {
        KeyType clave;
        ValueType valor;
        Nodo* siguiente;

        Nodo(const KeyType& k, const ValueType& v) : clave(k), valor(v), siguiente(nullptr) {}
    };

    Nodo* primero;

public:
    Mapa();
    ~Mapa();

    void insertar(const KeyType& clave, const ValueType& valor);

    ValueType& operator[](const KeyType& clave);

    bool encontrar(const KeyType& clave);

    // Metodo begin() para iterar sobre los elementos del Mapa
    Nodo* begin() const {
        return primero;
    }

    // Metodo end() para marcar el final de la iteracion
    Nodo* end() const {
        return nullptr;
    }
};

template<typename KeyType, typename ValueType>
inline Mapa<KeyType, ValueType>::Mapa() :
    primero(nullptr)
{
}

template<typename KeyType, typename ValueType>
inline Mapa<KeyType, ValueType>::~Mapa()
{
    while (primero != nullptr)
    {
        Nodo* nodo = primero;
        primero = primero->siguiente;
        delete nodo;
    }
}

template<typename KeyType, typename ValueType>
inline void Mapa<KeyType, ValueType>::insertar(const KeyType& clave, const ValueType& valor)
{
    Nodo* nuevoNodo = new Nodo(clave, valor);
    nuevoNodo->siguiente = primero;
    primero = nuevoNodo;
}

template<typename KeyType, typename ValueType>
inline ValueType& Mapa<KeyType, ValueType>::operator[](const KeyType& clave)
{
    Nodo* nodo = primero;
    while (nodo != nullptr) 
    {
        if (nodo->clave == clave) 
        {
            return nodo->valor;
        }
        nodo = nodo->siguiente;
    }

    // Si la clave no existe, la insertamos con un valor predeterminado
    insertar(clave, ValueType());
    return primero->valor;
}

template<typename KeyType, typename ValueType>
inline bool Mapa<KeyType, ValueType>::encontrar(const KeyType& clave)
{
    {
        Nodo* nodo = primero;
        while (nodo != nullptr)
        {
            if (nodo->clave == clave)
            {
                return true;
            }
            nodo = nodo->siguiente;
        }
        return false;
    }
}
