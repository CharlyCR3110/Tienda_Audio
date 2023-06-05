#include "Controlador.h"

void Controlador::iniciar()
{
	Interfaz::tienda->suscribirCliente(new ClientePersona("Carlos", "604", "Costa Rica", "Miramar", "Correo", "Tico"));
	Interfaz::tienda->suscribirCliente(new ClientePersona("Juan", "602", "Costa Rica", "Miramar", "Correo", "Tico"));
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
		controladorVentaEnLinea();
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
				std::cout << "Cuantas unidades desea: ";
				std::cin >> unidades;

				// Verificar si la entrada es un número
				if (std::cin.fail())
				{
					std::cerr << "Error: entrada no válida. Por favor, ingrese un número." << std::endl;

					// Restablecer el estado de std::cin
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					unidades = -1;	// para que se repita el ciclo
					std::system("pause");
					clearScreen();
				}

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

void Controlador::controladorVentaEnLinea()
{
	// se verifica que el usuario este registrado
	std::cout << "\t\tMenu Venta Online" << std::endl;
	Cliente* cliente = nullptr;
	try
	{
		cliente = Interfaz::buscarCliente();
		std::cout << "Bienvenido " << cliente->getNombre() << std::endl;
		std::system("pause");	// esto muestra "Presione cualquier tecla para continuar..."
		clearScreen();
	}
	catch (std::exception& e)
	{
		std::stringstream mensajeDeError;
		mensajeDeError << "Error. El cliente parece no estar subscrito. Motivo: " << e.what() << std::endl;
		mensajeDeError << "Por favor, registre al cliente antes de continuar." << std::endl;
		std::cerr << mensajeDeError.str() << std::endl;
		std::system("pause");
		clearScreen();
		return;
	}

	std::string codigoDeEnvio;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Lista de envios disponibles" << std::endl;
	std::cout << MontoTranslado::mostrarLista() << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	int numeroDeIntento = 0;	// se reinicia el numero de intentos

	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un codigo de envio valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el codigo de envio: ";
		std::cin >> codigoDeEnvio;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(codigoDeEnvio, false, true, false, "codigo de envio"));	// el codigo de envio solo puede contener numeros

	if (!MontoTranslado::disponibilidadDeEnvio(codigoDeEnvio))	// true si hay envios disponibles false sino
	{
		std::cerr << "Error. No hay cobertura de envio para el codigo ingresado." << std::endl;
		std::cout << "Regresando al menu principal..." << std::endl;
		std::system("pause");
		clearScreen();
		return;
	}
	else
	{
		std::cout << "Perfecto! Tenemos cobertura de envio. El envio tiene un costo de: " << MontoTranslado::getMonto(codigoDeEnvio) << std::endl;
	}

	Venta* venta = new VentaOnline(cliente, Interfaz::tienda->getFechaActual(), codigoDeEnvio);
	// unidades de un un producto
	int unidades = 0;
	Componente* componenteActual = nullptr;
	char seguirComprando = 's'; // acepta 's' 'S' 'n' 'N'
	do
	{
		try
		{
			componenteActual = controladorMenuVentaEnLineaComprar();
			do
			{
				std::cout << "Cuantas unidades desea: ";
				std::cin >> unidades;

				// Verificar si la entrada es un número
				if (std::cin.fail()) {
					std::cerr << "Error: entrada no válida. Por favor, ingrese un número." << std::endl;

					// Restablecer el estado de std::cin
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					unidades = -1;	// para que se repita el ciclo
				}

			} while (unidades < 0);
			venta->agregarComponente(componenteActual, unidades);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// preguntar si desea seguir comprando y obligarlo a introducir s o n
		do
		{
			std::cout << "Desea seguir comprando? (s/n): ";
			std::cin >> seguirComprando;
		} while (seguirComprando != 's' && seguirComprando != 'S' && seguirComprando != 'n' && seguirComprando != 'N');
	} while (seguirComprando == 's' || seguirComprando == 'S');;

	clearScreen();
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << venta->generarFactura() << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::system("pause");

	// se agrega la venta a la tienda
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

Componente* Controlador::controladorMenuVentaEnLineaComprar()
{
	int opcionMenuVentaEnLinea = Interfaz::obtenerOpcionMenuVentaEnLinea();
	Componente* componente = nullptr;

	switch (opcionMenuVentaEnLinea)
	{
	case 1:
		componente = Interfaz::escogerSistemaPreconfigurado();
	case 2:
		componente = Interfaz::escogerComponenteSeparado();
		break;
	default:
		throw std::exception("Menu Venta En Linea: Opcion invalida");
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
