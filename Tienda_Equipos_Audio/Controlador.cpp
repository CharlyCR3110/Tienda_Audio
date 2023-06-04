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
		controladorVentaDirecta();
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

void Controlador::controladorVentaDirecta()
{
	Cliente* cliente = nullptr;
	try
	{
		cliente = Interfaz::buscarCliente();
		std::cout << "Bienvenido " << cliente->getNombre() << std::endl;
		std::system("pause");
		clearScreen();
	}
	catch (std::exception& e)
	{
		std::stringstream mensajeDeError;
		mensajeDeError << "Error. El cliente parece no estar suscrito. Motivo: " << e.what() << std::endl;
		mensajeDeError << "Por favor, registre al cliente antes de continuar." << std::endl;
		std::cerr << mensajeDeError.str() << std::endl;
		std::system("pause");
		clearScreen();
		return;
	}

	int unidades = 0;
	Componente* componenteActual = nullptr;
	char seguirComprando = 's';

	Venta* venta = new VentaDirecta(cliente, Interfaz::tienda->getFechaActual());

	do
	{
		try
		{
			componenteActual = controladorMenuVentaDirectaComprar();
			do
			{
				std::cout << "Cuantas unidades desea" << std::endl;
				std::cin >> unidades;
			} while (unidades < 0);
			venta->agregarComponente(componenteActual, unidades);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::system("pause");
		}

		do
		{
			std::cout << "Desea seguir comprando? (s/n): ";
			std::cin >> seguirComprando;
		} while (seguirComprando != 's' && seguirComprando != 'S' && seguirComprando != 'n' && seguirComprando != 'N');
	} while (seguirComprando == 's' || seguirComprando == 'S');

	clearScreen();
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	try
	{
		std::cout << venta->generarFactura() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::system("pause");
	}
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	try
	{
		Interfaz::tienda->agregarVenta(venta);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::system("pause");
	}
}

Componente* Controlador::controladorMenuVentaDirectaComprar()
{
	int opcionMenuVentaDirecta = Interfaz::obtenerOpcionMenuVentaDirecta();
	Componente* componente = nullptr;

	switch (opcionMenuVentaDirecta)
	{
	case 1:
		componente = Interfaz::crearSistemaPersonalizado();
		break;
	case 2:
		componente = Interfaz::escogerSistemaPreconfigurado();
		break;
	case 3:
		componente = Interfaz::escogerComponenteSeparado();
		break;
	default:
		throw std::exception("Menu Venta Directa: Opcion invalida");
		break;
	}

	return componente;
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
