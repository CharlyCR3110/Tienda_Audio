#pragma once
#include "ListaEnlazada.h"
#include "Componente.h"
#include "Catalogo.h"
// observerss
#include "IObserver.h"
#include "Cliente.h"
#include "ClientePersona.h"
#include "ClienteEmpresa.h"
#include "Venta.h"

#include "VentaDirecta.h"
#include "VentaOnline.h"

#include "GestorArchivos.h"

// Cliente hereda de IObserver
// De Cliente heredan ClientePersona y ClienteEmpresa


class Tienda	// la tienda es un sujeto observado
{
public:
	Tienda();
	virtual ~Tienda();
	void agregarComponente(Componente* producto);
	void eliminarComponente (Componente* producto);
	void eliminarComponetePorCodigo(std::string codigo);

	void suscribirCliente(Cliente* cliente);
	void desuscribirCliente(Cliente* cliente);
	void notificarClientes();

	std::string mostrarCatalogo();
	Componente* escogerComponenteDelCatalogo(std::string codigo);

	bool existeOtroSistemaPreconfigurado(std::string codigo);

	bool existeUsuarioRegistrado(std::string codigo);
	Cliente* buscarCliente(std::string codigo);

	std::string mostrarComponenteMasVendido();

	std::string mostrarTotalVentas();

	void agregarVenta(Venta* venta);

	// getters
	Fecha* getFechaActual() const;
	
	// Utilizados en menu mantenimiento
	std::string mostrarListaClientes();

	// archivos

	void guardarClientes();

private:
	Catalogo* _catalogo;	// Catalogo de productos de la tienda
	ListaEnlazada<Cliente>* _clientes;
	ListaEnlazada<Venta>* _ventas;	// lista de ventas realizadas
	Fecha* _fechaActual;	// fecha actual de la tienda
};