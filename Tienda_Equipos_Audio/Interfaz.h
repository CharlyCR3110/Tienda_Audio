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
	static void menuVentaDirecta();

	static Componente* menuVentaDirectaComprar();	// aqui se puede comprar PERSONALIZADOS, PRECONFIGURADOS Y COMPONENTES SEPARADOS

	// MENU DE VENTA EN LINEA (PRECONFIGURADOS Y COMPONENTES SEPARADOS)
	static void menuVentaEnLinea();

	static Componente* menuVentaEnLineaComprar();	// aqui se puede comprar PRECONFIGURADOS Y COMPONENTES SEPARADOS


	// MENU DE MANTENIMIENTO
	static int menuMantenimiento();

	//submenus de mantenimiento	// estas opciones se controlan desde Controlador MVC
	// 1. Ver lista de clientes registrados
	static void menuMantenimientoVerListaClientes();
	// 2. Ingresar nuevo cliente
	static void menuMantenimientoIngresarNuevoCliente();

	// submenus de mantenimiento de clientes
	static void solicitarDatosComportidos(std::string& nombre, std::string& codigo, std::string& pais, std::string& ciudad);

	static void solicitarDatosEmpresa(std::string& razonSocial);

	static void solicitarDatosPersona(std::string& correo, std::string& nacionalidad);

	// 3. Ver catalogo de componentes
	static void menuMantenimientoVerCatalogoComponentes();
	// 4. Ingresar nuevo componente
	static void menuMantenimientoIngresarNuevoComponente();
	// 5. Eliminar componente del catalogo
	static void menuMantenimientoEliminarComponenteCatalogo();

	// MENU REPORTES
	static int menuReportes();

	// submenus de reportes
	static void menuReportesComponenteMasVendido();

	static void menuReportesTotalVentas();

	// UTILES
	// metodo para buscar un usuario
	static Cliente* buscarCliente();


	static void regresar();

	static void salir();

	static void opcionInvalida();
};


