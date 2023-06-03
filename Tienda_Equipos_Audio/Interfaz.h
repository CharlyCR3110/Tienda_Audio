#pragma once
#include "Tienda.h"
#include "SistemaPersonalizadoFactory.h"
#include "SistemaPreConfiguradoFactory.h"
#include "FuncionesUtiles.h"

class Interfaz
{
public:
	static Tienda* tienda;

	// MENU PRINCIPAL DE LA TIENDA
	static int menuPrincipal();

	// MENU DE VENTA DIRECTA DE SISTEMAS (PERSONALIZADOS, PRECONFIGURADOS Y COMPONENTES SEPARADOS)
	static int menuVentaDirecta();

	static Componente* menuVentaDirectaComprar();	// aqui se puede comprar PERSONALIZADOS, PRECONFIGURADOS Y COMPONENTES SEPARADOS

	// MENU DE VENTA EN LINEA (PRECONFIGURADOS Y COMPONENTES SEPARADOS)
	static int menuVentaEnLinea();

	// MENU DE MANTENIMIENTO
	static int menuMantenimiento();

	// MENU REPORTES
	static int menuReportes();

	// UTILES
	// metodo para buscar un usuario
	static Cliente* buscarCliente();
};


