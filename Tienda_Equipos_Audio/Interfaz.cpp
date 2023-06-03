#include "Interfaz.h"

Tienda* Interfaz::tienda = new Tienda();	// Inicializacion de variable estatica

int Interfaz::menuPrincipal()
{
	int opcion = 0;
	std::cout << "\t\tMenu Principal" << std::endl;
	std::cout << "1. Venta Directa" << std::endl;
	std::cout << "2. Venta en linea" << std::endl;
	std::cout << "3. Mantenimiento" << std::endl;
	std::cout << "4. Reportes" << std::endl;
	std::cout << "5. Salir" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcion;
	return opcion;
}

void Interfaz::menuVentaDirecta()
{
	tienda->suscribirCliente(new ClienteEmpresa("Empresa1", "333", "Costa Rica", "San Jose", "Empresa1"));	// eliminar
	// se verifica que el usuario este registrado
	std::cout << "\t\tMenu Venta Directa" << std::endl;
	Cliente* cliente = nullptr;
	try
	{
		cliente = buscarCliente();
		std::cout << "Bienvenido " << cliente->getNombre() << std::endl;
		std::system("pause");	// esto muestra "Presione cualquier tecla para continuar..."
		clearScreen();
	}
	catch (std::exception& e)
	{
		std::stringstream mensajeDeError;
		mensajeDeError << "Error. El cliente parece no estar subscrito. Motivo: " << e.what() << std::endl;
		mensajeDeError << "Por favor, registre al cliente antes de continuar." << std::endl;
		throw std::exception(mensajeDeError.str().c_str());
	}
	
	// unidades de un un producto
	int unidades = 0;
	Componente* componenteActual = nullptr;
	char seguirComprando = 's'; // acepta 's' 'S' 'n' 'N'
	Venta* venta = new VentaDirecta(cliente, tienda->getFechaActual());
	// se deben de agregar cosas a 
	do
	{
		try 
		{
			componenteActual = menuVentaDirectaComprar();
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

}

Componente* Interfaz::menuVentaDirectaComprar()
{
	int opcionMenuVentaDirecta = 0;
	Componente* componente = nullptr;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\tQue desea agregar al carrito" << std::endl;
	std::cout << "1. Sistema Personalizado" << std::endl;
	std::cout << "2. Sistema Preconfigurado" << std::endl;
	std::cout << "3. Componente Separado" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcionMenuVentaDirecta;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	switch (opcionMenuVentaDirecta)
	{
	case 1:
	{
		AbstractFactory* factory = new SistemaPersonalizadoFactory();
		std::cout << "-----------------------CREANDO SISTEMA PERSONALIZADO------------------------" << std::endl;
		componente = factory->crearSistemaDeAudio();
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		delete factory;
		break;
	}
	case 2:
	{
		std::string codigo;
		try
		{
			std::cout << "-------------------------------CATALOGO-------------------------------------" << std::endl;
			tienda->mostrarCatalogo();
			std::cout << "----------------------------------------------------------------------------" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "Error. " << e.what() << std::endl;
			throw std::exception(e.what());	// se tira el en caso de que el catalogo este vacio
		}
		std::cout << "Digite el codigo del sistema preconfigurado: ";
		std::cin >> codigo;
		try
		{
			componente = tienda->escogerComponenteDelCatalogo(codigo);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error. " << e.what() << std::endl;
			throw std::exception(e.what());	// se tira el en caso de que el codigo no exista
		}
		break;
	}
	case 3:
	{
		int categoriaComponente = 0;
		do
		{
			std::cout << "Categorias de componentes disponibles" << std::endl;
			std::cout << "1. Fuentes de Audio" << std::endl;
			std::cout << "2. Procesadores de Señal" << std::endl;
			std::cout << "3. Parlantes (Reproductores de Sonido)" << std::endl;
			std::cout << "Seleccione una categoria: ";
			std::cin >> categoriaComponente;

			switch (categoriaComponente)
			{
			case 1:
				componente = ICrearProductos::crearFuenteDeAudio();
				break;
			case 2:
				componente = ICrearProductos::crearProcesadorDeSenal();
				break;
			case 3:
				componente = ICrearProductos::crearParlante();
				break;
			default:
				std::cout << "Opcion invalida" << std::endl;
				break;
			}
		} while (categoriaComponente < 1 || categoriaComponente > 3);
		break;
	}
	default:
		throw std::exception("Menu Venta Directa: Opcion invalida");
		break;
	}

	return componente;
}

void Interfaz::menuVentaEnLinea()
{
	tienda->suscribirCliente(new ClienteEmpresa("Empresa1", "333", "Costa Rica", "San Jose", "Empresa1"));	// eliminar
	// se verifica que el usuario este registrado
	std::cout << "\t\tMenu Venta Online" << std::endl;
	Cliente* cliente = nullptr;
	try
	{
		cliente = buscarCliente();
		std::cout << "Bienvenido " << cliente->getNombre() << std::endl;
		std::system("pause");	// esto muestra "Presione cualquier tecla para continuar..."
		clearScreen();
	}
	catch (std::exception& e)
	{
		std::stringstream mensajeDeError;
		mensajeDeError << "Error. El cliente parece no estar subscrito. Motivo: " << e.what() << std::endl;
		mensajeDeError << "Por favor, registre al cliente antes de continuar." << std::endl;
		throw std::exception(mensajeDeError.str().c_str());
	}

	std::string codigoDeEnvio;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Lista de envios disponibles" << std::endl;
	std::cout << MontoTranslado::mostrarLista() << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	do
	{
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el codigo de envio: ";
		std::cin >> codigoDeEnvio;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		if (!esCodigoValido(codigoDeEnvio))
		{
			clearScreen();
		}
	} while (!esCodigoValido(codigoDeEnvio));

	if (!MontoTranslado::disponibilidadDeEnvio(codigoDeEnvio))	// true si hay envios disponibles false sino
	{
		throw std::exception("No hay envios disponibles");	// cambiar por excepcion de envios
	}
	else
	{
		std::cout << "Perfecto! Tenemos cobertura de envio. El envio tiene un costo de: " << MontoTranslado::getMonto(codigoDeEnvio) << std::endl;
	}

	Venta* venta = new VentaOnline(cliente, tienda->getFechaActual(), codigoDeEnvio);
	// unidades de un un producto
	int unidades = 0;
	Componente* componenteActual = nullptr;
	char seguirComprando = 's'; // acepta 's' 'S' 'n' 'N'
	// se deben de agregar cosas a 
	do
	{
		try
		{
			componenteActual = menuVentaEnLineaComprar();	// cambiar por menuVentaOnlineComprar
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
}

Componente* Interfaz::menuVentaEnLineaComprar()
{
	int opcionMenuVentaOnline = 0;
	Componente* componente = nullptr;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\tQue desea agregar al carrito" << std::endl;
	std::cout << "1. Sistema Preconfigurado" << std::endl;
	std::cout << "2. Componente Separado" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcionMenuVentaOnline;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	switch (opcionMenuVentaOnline)
	{
	case 1:
	{
		std::string codigo;
		try
		{
			std::cout << "-------------------------------CATALOGO-------------------------------------" << std::endl;
			tienda->mostrarCatalogo();
			std::cout << "----------------------------------------------------------------------------" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "Error. " << e.what() << std::endl;
			throw std::exception(e.what());	// se tira el en caso de que el catalogo este vacio
		}
		std::cout << "Digite el codigo del sistema preconfigurado: ";
		std::cin >> codigo;
		try
		{
			componente = tienda->escogerComponenteDelCatalogo(codigo);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error. " << e.what() << std::endl;
			throw std::exception(e.what());	// se tira el en caso de que el codigo no exista
		}
		break;
	}
	case 2:
	{
		int categoriaComponente = 0;
		do
		{
			std::cout << "Categorias de componentes disponibles" << std::endl;
			std::cout << "1. Fuentes de Audio" << std::endl;
			std::cout << "2. Procesadores de Señal" << std::endl;
			std::cout << "3. Parlantes (Reproductores de Sonido)" << std::endl;
			std::cout << "Seleccione una categoria: ";
			std::cin >> categoriaComponente;

			switch (categoriaComponente)
			{
			case 1:
				componente = ICrearProductos::crearFuenteDeAudio();
				break;
			case 2:
				componente = ICrearProductos::crearProcesadorDeSenal();
				break;
			case 3:
				componente = ICrearProductos::crearParlante();
				break;
			default:
				std::cout << "Opcion invalida" << std::endl;
				break;
			}
		} while (categoriaComponente < 1 || categoriaComponente > 3);
		break;
	}
	default:
		throw std::exception("Menu Venta Online: Opcion invalida");
		break;
	}
	return componente;
}

Cliente* Interfaz::buscarCliente()
{
	std::string codigo;
	// solicitar y comprobar que sea valida (no puede ser vacia ni tener caracteres especiales, solo letras y numeros)
	do
	{
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el codigo del cliente: ";
		std::cin >> codigo;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		if (!esCodigoValido(codigo))
		{
			clearScreen();
		}
	} while (!esCodigoValido(codigo));

	try
	{
		return tienda->buscarCliente(codigo);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}

}
