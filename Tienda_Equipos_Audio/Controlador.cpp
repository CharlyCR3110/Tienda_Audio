#include "Controlador.h"

void Controlador::iniciar()
{
	try
	{
		Interfaz::tienda->recuperarClientes();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Interfaz::tienda->recuperarCatalogo();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Interfaz::tienda->recuperarVentas();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

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
		pauseScreen();
		break;
	case 2:
		controladorVentaEnLinea();
		break;
	case 3:
		controladorMantenimiento();
		break;
	case 4:
		controladorReportes();
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
		pauseAndClearScreen();
	}
	catch (std::exception& e)
	{
		std::stringstream mensajeDeError;
		mensajeDeError << "Error. El cliente parece no estar suscrito. Motivo: " << e.what() << std::endl;
		mensajeDeError << "Por favor, registre al cliente antes de continuar." << std::endl;
		std::cerr << mensajeDeError.str() << std::endl;
		pauseAndClearScreen();
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

				// Verificar si la entrada es un n�mero
				if (std::cin.fail())
				{
					std::cerr << "Error: entrada no v�lida. Por favor, ingrese un n�mero." << std::endl;

					// Restablecer el estado de std::cin
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					unidades = -1;	// para que se repita el ciclo
					pauseAndClearScreen();
				}

			} while (unidades < 0);
			pauseScreen();
			clearScreen();
			venta->agregarComponente(componenteActual, unidades);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;	// REVISAR
			pauseScreen();
		}

		do
		{
			std::cout << "Desea seguir comprando? (s/n): ";
			std::cin >> seguirComprando;
		} while (seguirComprando != 's' && seguirComprando != 'S' && seguirComprando != 'n' && seguirComprando != 'N');
		pauseAndClearScreen();
	} while (seguirComprando == 's' || seguirComprando == 'S');

	clearScreen();

	// se verifica que la venta tenga al menos un componente
	if (venta->getCarritoDeCompras()->estaVacia())
	{
		std::cerr << "Error. La venta no tiene ningun componente." << std::endl;
		std::cout << "Regresando al menu principal..." << std::endl;
		pauseAndClearScreen();
		return;
	}

	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << venta->generarFactura() << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	try
	{
		Interfaz::tienda->agregarVenta(venta);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;	// revisar
		pauseScreen();
	}
}

Componente* Controlador::controladorMenuVentaDirectaComprar()
{
	int opcionMenuVentaDirecta = Interfaz::obtenerOpcionMenuVentaDirecta();
	Componente* componente = nullptr;

	pauseAndClearScreen();
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
		throw OpcionInvalidaException("Menu Venta Directa");	// esta excepcion no se va a lanzar, pero por si acaso
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
		pauseAndClearScreen();
	}
	catch (std::exception& e)
	{
		std::stringstream mensajeDeError;
		mensajeDeError << "Error. El cliente parece no estar subscrito. Motivo: " << e.what() << std::endl;
		mensajeDeError << "Por favor, registre al cliente antes de continuar." << std::endl;
		std::cerr << mensajeDeError.str() << std::endl;
		pauseAndClearScreen();
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
			pauseAndClearScreen();
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
		pauseAndClearScreen();
		return;
	}
	else
	{
		std::cout << "Perfecto! Tenemos cobertura de envio. El envio tiene un costo de: " << MontoTranslado::getMonto(codigoDeEnvio) << std::endl;
		pauseAndClearScreen();
	}

	Venta* venta = new VentaOnline(cliente, Interfaz::tienda->getFechaActual(), codigoDeEnvio);
	// unidades de un un producto
	int unidades = 0;
	Componente* componenteActual = nullptr;
	char seguirComprando = 's'; // acepta 's' 'S' 'n' 'N'
	do
	{
		clearScreen();
		try
		{
			componenteActual = controladorMenuVentaEnLineaComprar();
			do
			{
				std::cout << "Cuantas unidades desea: ";
				std::cin >> unidades;
				std::cout << "----------------------------------------------------------------------------" << std::endl;

				// Verificar si la entrada es un numero
				if (std::cin.fail()) {
					std::cerr << "Error: entrada no valida. Por favor, ingrese un numero." << std::endl;

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
	// se verifica que la venta tenga al menos un componente
	if (venta->getCarritoDeCompras()->estaVacia())
	{
		std::cerr << "Error. La venta no tiene ningun componente." << std::endl;
		std::cout << "Regresando al menu principal..." << std::endl;
		pauseAndClearScreen();
		return;
	}


	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << venta->generarFactura() << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	pauseScreen();

	// se agrega la venta a la tienda
	try
	{
		Interfaz::tienda->agregarVenta(venta);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		pauseScreen();
	}
}

Componente* Controlador::controladorMenuVentaEnLineaComprar()
{
	int opcionMenuVentaEnLinea = Interfaz::obtenerOpcionMenuVentaEnLinea();
	Componente* componente = nullptr;

	system("pause");
	clearScreen();
	switch (opcionMenuVentaEnLinea)
	{
	case 1:
		componente = Interfaz::escogerSistemaPreconfigurado();
		break;
	case 2:
		componente = Interfaz::escogerComponenteSeparado();
		break;
	default:
		throw OpcionInvalidaException("Menu Venta En Linea");	// esta excepcion no se va a lanzar, pero por si acaso
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
			controladorModificarSistemaDeAudio();
			break;
		case 7:
			Interfaz::regresar();
			break;
		default:
			std::cerr << "Error. Opcion invalida." << std::endl;
			break;
		}
		system("pause");
	} while (opcion != 7);
}

void Controlador::controladorModificarSistemaDeAudio()
{
	int opcion;
	bool regresar = false;

	// se verifica que exista al menos un sistema de audio
	if (Interfaz::tienda->getCatalogo()->estaVacio())
	{
		std::cerr << "Error. No hay sistemas de audio en el catalogo." << std::endl;
		std::cout << "Regresando al menu principal..." << std::endl;
		pauseAndClearScreen();
		return;
	}

	// solicitar el codigo del sistema de audio
	std::string codigoDelSistema = Interfaz::menuMantenimientoModificarSistemaCatalogoSolicitarCodigo();

	pauseAndClearScreen();

	// se verifica que el sistema de audio exista
	if (!Interfaz::tienda->existeOtroSistemaPreconfigurado(codigoDelSistema))
	{
		std::cerr << "Error. El sistema de audio no existe." << std::endl;
		std::cout << "Regresando al menu principal..." << std::endl;
		pauseAndClearScreen();
		return;
	}

	// se obtiene el sistema de audio
	Componente* sistema = nullptr;
	try
	{
		sistema = Interfaz::tienda->obtenerPunteroAComponente(codigoDelSistema);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "Regresando al menu principal..." << std::endl;
		pauseAndClearScreen();
		return;
	}

	// para que el programa no se caiga
	if (sistema == nullptr)
	{
		std::cerr << "Error. El sistema de audio no existe. NULLPTR" << std::endl;
		std::cout << "Regresando al menu principal..." << std::endl;
		pauseAndClearScreen();
		return;
	}


	// se muestra el sistema de audio
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\t\t\tSISTEMA A MODIFICAR" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	try
	{
		std::cout << sistema->toString() << std::endl;	// muestra el toString del sistema preconfigurado
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	pauseScreen();


	std::string nuevoNombre;	// case 1;
	std::string nuevoCodigo;	// case 2;

	do
	{
		clearScreen();
		opcion = Interfaz::menuMantenimientoModificarSistemaCatalogo();
		clearScreen();
		switch (opcion)
		{
		case 1:
			nuevoNombre = Interfaz::menuMantenimientoModificarNombreSistemaPreconfigurado();
			sistema->setNombreComponente(nuevoNombre);
			std::cout << "El nombre del sistema de audio ha sido modificado." << std::endl;
			pauseAndClearScreen();
			//return;
			break;
		case 2:
			nuevoCodigo = Interfaz::menuMantenimientoModificarCodigoSistemaPreconfigurado();
			sistema->setCodigo(nuevoCodigo);
			std::cout << "El codigo del sistema de audio ha sido modificado." << std::endl;
			pauseAndClearScreen();
			//return;
			break;
		case 3:
			controladorCambiarUnComponenteDeSistemaDeAudio(sistema);
			std::cout << "El componente del sistema de audio ha sido modificado." << std::endl;
			pauseAndClearScreen();
			break;
		case 4:
			Interfaz::regresar();
		}
		system("pause");
	} while (opcion != 4 || regresar);
}

void Controlador::controladorCambiarUnComponenteDeSistemaDeAudio(Componente* sistemaDeAudio)
{
	// recibe un sistema de audio
	Componente* componenteRemplazo = nullptr;
	int opcion = Interfaz::menuMantemientoCambiarUnComponenteDelSistema();

	pauseAndClearScreen();

	switch (opcion)
	{
	case 1:
		componenteRemplazo = ICrearProductos::crearProcesadorDeSenal();
		try
		{
			sistemaDeAudio->setChild(0, componenteRemplazo);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		break;
	case 2:
		componenteRemplazo = ICrearProductos::crearFuenteDeAudio();
		try
		{
			sistemaDeAudio->setChild(1, componenteRemplazo);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		break;
	case 3:
		componenteRemplazo = ICrearProductos::crearParlanteCat();
		try
		{
			sistemaDeAudio->setChild(2, componenteRemplazo);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		break;
	}
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
	} while (opcion != 3);
}
