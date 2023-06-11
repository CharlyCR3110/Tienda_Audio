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
	Componente* escogerComponenteDelCatalogo(std::string codigo);	// este metodo clona el componente del catalogo y lo devuelve

	// devuelve un puntero al componente del catalogo, o sea, el mismo objeto
	Componente* obtenerPunteroAComponente(std::string codigo);

	bool existeOtroSistemaPreconfigurado(std::string codigo);

	bool existeUsuarioRegistrado(std::string codigo);
	Cliente* buscarCliente(std::string codigo);

	std::string mostrarComponenteMasVendido();

	std::string mostrarTotalVentas();

	void agregarVenta(Venta* venta);

	// getters
	Fecha* getFechaActual() const;

	Catalogo* getCatalogo() const;
	
	// Utilizados en menu mantenimiento
	std::string mostrarListaClientes();

	// muestra el nombre y el codigo de los componentes del catalogo
	std::string mostrarComponentesDelCatalagoReducido();

	std::string mostrarSistemaPreconfigurado(std::string codigo);

	// archivos

	void guardarClientes();
	void recuperarClientes();

	void guardarCatalogo();
	void recuperarCatalogo();

	void guardarVentas();
	void recuperarVentas();

private:
	Catalogo* _catalogo;	// Catalogo de productos de la tienda
	ListaEnlazada<Cliente>* _clientes;
	ListaEnlazada<Venta>* _ventas;	// lista de ventas realizadas
	Fecha* _fechaActual;	// fecha actual de la tienda
};