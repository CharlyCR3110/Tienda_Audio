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

class GestorArchivos
{
public:
	static void guardarFecha(std::string fecha);

	static void guardarListaDeClientes(ListaEnlazada<Cliente>* clientes);

	static void recuperarListaDeClientes(ListaEnlazada<Cliente>* clientes);
};