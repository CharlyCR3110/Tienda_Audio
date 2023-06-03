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

void Interfaz::menuMantenimientoVerListaClientes()
{
	clearScreen();
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Lista de clientes" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	try
	{
		std::cout << tienda->mostrarListaClientes() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error. " << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------" << std::endl;
}

void Interfaz::menuMantenimientoIngresarNuevoCliente()
{
	// hay 2 tipos de clientes 	ClienteEmpresa y ClientePersona
	// se debe de preguntar que tipo de cliente se desea ingresar
	// se debe de preguntar por los datos del cliente
	
	Cliente* cliente = nullptr;
	int opcionTipoCliente = 0;
	// datos compartidos
	std::string nombre;
	std::string cedula;
	std::string pais;
	std::string ciudad;
	// datos de cliente empresa
	std::string razonSocial;
	// datos de cliente persona
	std::string correo;
	std::string nacionalidad;

	// preguntar el tipo de cliente
	do
	{
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Que tipo de cliente desea ingresar?" << std::endl;
		std::cout << "1. Cliente Empresa" << std::endl;
		std::cout << "2. Cliente Persona" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite una opcion del menu: ";
		std::cin >> opcionTipoCliente;
		std::cout << "----------------------------------------------------------------------------" << std::endl;

		if (opcionTipoCliente < 1 || opcionTipoCliente > 2)
		{
			std::cout << "Opcion invalida" << std::endl;
			std::cout << "Por favor digite una opcion valida" << std::endl;
			std::system("pause");
			clearScreen();
		}

	} while (opcionTipoCliente < 1 || opcionTipoCliente > 2);

	// solicitar datos compartidoss
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Por favor digite los siguientes datos" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	solicitarDatosComportidos(nombre, cedula, pais, ciudad);	// se pasan como referencia para que se puedan modificar
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	if (opcionTipoCliente == 1)
	{
		solicitarDatosEmpresa(razonSocial);
	}
	else
	{
		solicitarDatosPersona(correo, nacionalidad);
	}
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	// se muestran los datos que se estan por registrar
	std::cout << "Los datos que se van a registrar son los siguientes" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Nombre: " << nombre << std::endl;
	std::cout << "Cedula: " << cedula << std::endl;
	std::cout << "Pais: " << pais << std::endl;
	std::cout << "Ciudad: " << ciudad << std::endl;
	if (opcionTipoCliente == 1)
	{
		std::cout << "Razon Social: " << razonSocial << std::endl;
	}
	else
	{
		std::cout << "Correo: " << correo << std::endl;
		std::cout << "Nacionalidad: " << nacionalidad << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	system("pause");
	clearScreen();

	if (opcionTipoCliente == 1)
	{
		cliente = new ClienteEmpresa(nombre, cedula, pais, ciudad, razonSocial);
	}
	else
	{
		cliente = new ClientePersona(nombre, cedula, pais, ciudad, correo, nacionalidad);
	}

	try
	{
		tienda->suscribirCliente(cliente);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Cliente agregado con exito" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error. " << e.what() << std::endl;
	}
}

void Interfaz::solicitarDatosComportidos(std::string& nombre, std::string& cedula, std::string& pais, std::string& ciudad)
{
	int numeroDeIntento = 0;

	// nombre del cliente o la empresa
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un nombre valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el nombre: ";
		std::getline(std::cin, nombre);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(nombre, false, false, false,"nombre"));


	// cedula juridica o cedula normal
	numeroDeIntento = 0;	// se reinicia el numero de intentos

	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite una cedula valida" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite la cedula: ";
		std::getline(std::cin, cedula);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(cedula, false, true, false, "numero de cedula"));	// se permite que la cedula tenga numeros

	// pais
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un nombre valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el pais: ";
		std::getline(std::cin, pais);	//getline para los espacios
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(pais, true, false, false, "pais"));	// se permite que el pais tenga espacios

	// ciudad
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un nombre de ciudad valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite la ciudad: ";
		std::getline(std::cin, ciudad);	//getline para los espacios
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(ciudad, true, false, false, "nombre de la ciudad"));	// se permite que la ciudad tenga espacios

}

void Interfaz::solicitarDatosEmpresa(std::string& razonSocial)
{
	int numeroDeIntento = 0;

	// razon social
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite una razon social valida" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite la razon social: ";
		std::getline(std::cin, razonSocial);	//getline para los espacios
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(razonSocial, true, false, false, "razon social"));	// se permite que la razon social tenga espacios
}

void Interfaz::solicitarDatosPersona(std::string& correo, std::string& nacionalidad)
{
	int numeroDeIntento = 0;

	// correo
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un correo valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el correo: ";
		std::getline(std::cin, correo);	//getline para los espacios
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(correo, false, true, true, "correo"));	// se permite que el correo tenga numeros y caracteres especiales

	// nacionalidad
	numeroDeIntento = 0;	// se reinicia el numero de intentos
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite una nacionalidad valida" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite la nacionalidad: ";
		std::getline(std::cin, nacionalidad);	//getline para los espacios
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(nacionalidad, false, false, false, "nacionalidad"));
}

void Interfaz::menuMantenimientoVerCatalogoComponentes()	// unicamente muestra el catalogo y mensajito bonito
{
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Catalogo de componentes" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	try
	{
		std::cout << tienda->mostrarCatalogo() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------" << std::endl;
}

Cliente* Interfaz::buscarCliente()
{
	std::string codigo;
	int numeroDeIntento = 0;
	// solicitar y comprobar que sea valida (no puede ser vacia ni tener caracteres especiales, solo letras y numeros)
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un nombre valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite la cedula: ";
		std::getline(std::cin, codigo);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(codigo, false, true, false, "codigo"));	// se permite que la cedula tenga numeros

	try
	{
		return tienda->buscarCliente(codigo);
	}
	catch (std::exception& e)
	{
		throw std::exception(e.what());
	}

}
