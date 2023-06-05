#include "Interfaz.h"

Tienda* Interfaz::tienda = new Tienda();	// Inicializacion de variable estatica

int Interfaz::menuPrincipal()
{
	tienda->suscribirCliente(new ClientePersona("Carlos", "604", "Costa Rica", "Miramar", "Correo", "Tico"));
	tienda->suscribirCliente(new ClientePersona("Juan", "602", "Costa Rica", "Miramar", "Correo", "Tico"));

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

// separando
int Interfaz::obtenerOpcionMenuVentaDirecta()
{
	int opcionMenuVentaDirecta = 0;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\tQue desea agregar al carrito" << std::endl;
	std::cout << "1. Sistema Personalizado" << std::endl;
	std::cout << "2. Sistema Preconfigurado" << std::endl;
	std::cout << "3. Componente Separado" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcionMenuVentaDirecta;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	return opcionMenuVentaDirecta;
}

Componente* Interfaz::crearSistemaPersonalizado()
{
	AbstractFactory* factory = new SistemaPersonalizadoFactory();
	std::cout << "-----------------------CREANDO SISTEMA PERSONALIZADO------------------------" << std::endl;
	Componente* componente = factory->crearSistemaDeAudio();
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	delete factory;

	return componente;
}

Componente* Interfaz::escogerSistemaPreconfigurado()
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
		throw std::exception(e.what());    // se tira el en caso de que el catalogo este vacio
	}

	std::cout << "Digite el codigo del sistema preconfigurado: ";
	std::cin >> codigo;

	try
	{
		return tienda->escogerComponenteDelCatalogo(codigo);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error. " << e.what() << std::endl;
		throw std::exception(e.what());    // se tira el en caso de que el codigo no exista
	}
}

Componente* Interfaz::escogerComponenteSeparado()
{
	int categoriaComponente = obtenerCategoriaComponente();

	Componente* componente = nullptr;
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

	return componente;
}

int Interfaz::obtenerCategoriaComponente()
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
	} while (categoriaComponente < 1 || categoriaComponente > 3);

	return categoriaComponente;
}

// online

int Interfaz::obtenerOpcionMenuVentaEnLinea()
{
	int opcionMenuVentaEnLinea = 0;

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\tQue desea agregar al carrito" << std::endl;
	std::cout << "1. Sistema Preconfigurado" << std::endl;
	std::cout << "2. Componente Separado" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcionMenuVentaEnLinea;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	return opcionMenuVentaEnLinea;
}

int Interfaz::cuantasUnidadesDesea()
{
	int cantidad;

	do {
		std::cout << "Cuantas unidades desa: ";
		std::cin >> cantidad;

		// Verificar si la entrada es un número
		if (std::cin.fail()) {
			std::cout << "Error: entrada no válida. Por favor, ingrese un número." << std::endl;

			// Restablecer el estado de std::cin
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (std::cin.fail());

	return cantidad;
}

int Interfaz::menuMantenimiento()
{
	int opcion;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\t\tMantenimiento" << std::endl;
	std::cout << "1. Ver Lista de clientes" << std::endl;
	std::cout << "2. Ingreso de nuevos clientes" << std::endl;
	std::cout << "3. Ver lista del catalogo" << std::endl;
	std::cout << "4. Ingresar productos al catalogo" << std::endl;
	std::cout << "5. Eliminar productos del cat�logo" << std::endl;
	std::cout << "6. Salir" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcion;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	return opcion;
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

	std::cout << "Ha seleccionado " << (opcionTipoCliente == 1 ? "Cliente Empresa" : "Cliente Persona") << std::endl;

	clearInputBuffer();
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
	numeroDeIntento = 0;	// se reinicia el numero de intentos

	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un pais valido" << std::endl;
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
	numeroDeIntento = 0;	// se reinicia el numero de intentos
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

void Interfaz::menuMantenimientoIngresarNuevoComponente()	// metodo para crear los sistemas preconfigurados
{
	AbstractFactory* fabrica = new SistemaPreConfiguradoFactory();
	Componente* componentePreConfigurador = nullptr;
	componentePreConfigurador = fabrica->crearSistemaDeAudio();

	try
	{
		componentePreConfigurador->setPrecio(componentePreConfigurador->getPrecio() * 0.35 + componentePreConfigurador->getPrecio() * 0.35);	// se le agrega el 35% de ganancia
		tienda->agregarComponente(componentePreConfigurador);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete fabrica;
	delete componentePreConfigurador;
}

void Interfaz::menuMantenimientoEliminarComponenteCatalogo()
{
	std::string codigo;
	int numeroDeIntento = 0;
	
	// Se muestra el catalogo
	menuMantenimientoVerCatalogoComponentes();

	// solicitar y comprobar que sea valida (no puede ser vacia ni tener caracteres especiales, solo letras y numeros)
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un codigo valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el codigo del componente que desea eliminar: ";
		std::getline(std::cin, codigo);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(codigo, false, true, false, "codigo"));	// se permite que el codigo tenga numeros

	try
	{
		tienda->eliminarComponetePorCodigo(codigo);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

int Interfaz::menuReportes()
{
	// En la opción 1, muestre el producto que mas se ha vendido (sea componente o sistema)
	//En la opción 2, muestre el total de ventas según todos los productos vendidos, especifique cuantos fueron componente y cuantos fueron sistemas
	int opcion;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "\t\tReportes" << std::endl;
	std::cout << "1. Reporte equipos mas vendidos" << std::endl;
	std::cout << "2. Reporte ventas" << std::endl;
	std::cout << "3. Salir" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcion;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	return opcion;
}

 void Interfaz::menuReportesComponenteMasVendido()
 {
 	//1, muestre el producto que mas se ha vendido(sea componente o sistema)
 	std::cout << "----------------------------------------------------------------------------" << std::endl;
 	std::cout << "El componente mas vendido es: " << std::endl;
 	std::cout << "----------------------------------------------------------------------------" << std::endl;
 	try
 	{
 		std::cout << tienda->mostrarComponenteMasVendido() << std::endl;
 	}
 	catch (std::exception& e)
 	{
 		std::cerr << e.what() << std::endl;
 	}
 }

 void Interfaz::menuReportesTotalVentas()
 {
	 std::cout << "----------------------------------------------------------------------------" << std::endl;
	 std::cout << "El total de ventas es: " << std::endl;
	 std::cout << "----------------------------------------------------------------------------" << std::endl;
	 try
	 {
		 std::cout << tienda->mostrarTotalVentas() << std::endl;
		 std::system("Pause");
	 }
	 catch (std::exception& e)
	 {
		 std::cerr << e.what() << std::endl;
	 }
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

void Interfaz::regresar()
{
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Regresando al menu principal" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::system("pause");
	clearScreen();
}

void Interfaz::salir()
{
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Saliendo del programa" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::system("pause");
	clearScreen();
}

void Interfaz::opcionInvalida()
{
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Opcion invalida" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::system("pause");
	clearScreen();
}
