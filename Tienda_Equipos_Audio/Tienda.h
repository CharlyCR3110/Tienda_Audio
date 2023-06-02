#pragma once
#include "ListaEnlazada.h"
#include "Componente.h"
#include "Catalogo.h"
// observerss
#include "IObserver.h"
#include "Cliente.h"
#include "ClientePersona.h"
#include "ClienteEmpresa.h"

// Cliente hereda de IObserver
// De Cliente heredan ClientePersona y ClienteEmpresa


class Tienda	// la tienda es un sujeto observado
{
public:
	Tienda();
	virtual ~Tienda();
	void agregarComponente(Componente* producto);
	void eliminarComponente (Componente* producto);
	void suscribirCliente(Cliente* cliente);
	void desuscribirCliente(Cliente* cliente);
	void notificarClientes();

	bool existeUsuarioRegistrado(std::string codigo);
private:
	Catalogo* catalogo;	// Catalogo de productos de la tienda
	ListaEnlazada<Cliente>* clientes;
};