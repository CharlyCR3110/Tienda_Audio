#include "Controlador.h"

void Controlador::iniciar()
{
	int opcion = 0;
	do
	{
		clearScreen();
		opcion = Interfaz::menuPrincipal();
		clearInputBuffer();
		clearScreen();
		controladorPrincipal(opcion);
	} while (opcion != 5);
}

void Controlador::controladorPrincipal(int opcion)
{
	switch (opcion)
	{
	case 1:
		Interfaz::menuVentaDirecta();
		std::system("pause");
		break;
	case 2:
		Interfaz::menuVentaEnLinea();
		break;
	case 3:
		controladorMantenimiento();
		break;
	case 4:
		controladorReportes();
		std::system("pause");
		break;
	case 5:
		Interfaz::salir();
		break;
	default:
		Interfaz::opcionInvalida();
		break;
	}
}

void Controlador::controladorMantenimiento()
{
	int opcion;

	do
	{
		clearScreen();
		opcion = Interfaz::menuMantenimiento();
		clearScreen();
		switch (opcion)
		{ 
		case 1:
			Interfaz::menuMantenimientoVerListaClientes();
			break;
		case 2:
			Interfaz::menuMantenimientoIngresarNuevoCliente();
			break;
		case 3:
			Interfaz::menuMantenimientoVerCatalogoComponentes();
			break;
		case 4:
			Interfaz::menuMantenimientoIngresarNuevoComponente();
			break;
		case 5:
			Interfaz::menuMantenimientoEliminarComponenteCatalogo();
			break;
		case 6:
			Interfaz::regresar();
		}
		system("pause");
	} while (opcion != 6);
}

void Controlador::controladorReportes()
{
	int opcion;
	do
	{
		clearScreen();
		opcion = Interfaz::menuReportes();
		clearScreen();
		switch (opcion)
		{
		case 1:
			Interfaz::menuReportesComponenteMasVendido();
			break;
		case 2:
			Interfaz::menuReportesTotalVentas();
			break;
		case 3:
			Interfaz::regresar();
		}
		system("pause");
	} while (opcion != 3);
}
