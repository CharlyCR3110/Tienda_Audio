#pragma once
#include <fstream>
#include <iostream>

// clase utilizada para guardar los datos de la tienta
//Catalogo* _catalogo;	// Catalogo de productos de la tienda
//ListaEnlazada<Cliente>* _clientes;	// lista de clientes de la tienda
//ListaEnlazada<Venta>* _ventas;	// lista de ventas realizadas
//Fecha* _fechaActual;	// fecha actual de la tienda

#include "ListaEnlazada.h"
#include "ClienteEmpresa.h"
#include "ClientePersona.h"

#include "Catalogo.h"


// fuentes de audio
#include "UnidadCD.h"
#include "Tornamesa.h"
#include "Radio.h"
#include "UnidadBluetooth.h"
#include "Microfono.h"
//procesador de senal
#include "Amplificador.h"
#include "Mezclador.h"
// parlantes 
#include "Parlante.h"
#include "Audifono.h"

#include "SistemaDeAudio.h"

#include "Venta.h"
#include "VentaDirecta.h"
#include "VentaOnline.h"

class GestorArchivos
{
public:
	static void guardarFecha(std::string fecha);

	static void guardarListaDeClientes(ListaEnlazada<Cliente>* clientes);

	static void recuperarListaDeClientes(ListaEnlazada<Cliente>* clientes);

	static void guardarCatalogo(Catalogo* catalogo);

	static void recuperarCatalogo(Catalogo* catalogo);

	static void guardarVentas(ListaEnlazada<Venta>* ventas);

	static Componente* recuperarComponenteEspecifico(std::string codigo);
};