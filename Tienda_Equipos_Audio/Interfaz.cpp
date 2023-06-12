#include "Interfaz.h"

Tienda* Interfaz::tienda = new Tienda();	// Inicializacion de variable estatica

int Interfaz::menuPrincipal()
{
	int opcion = 0;
	std::cout << "-------------- Menu Principal ---------------" << std::endl;
	std::cout << "1. Venta Directa" << std::endl;
	std::cout << "2. Venta en linea" << std::endl;
	std::cout << "3. Mantenimiento" << std::endl;
	std::cout << "4. Reportes" << std::endl;
	std::cout << "5. Salir" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcion;
	return opcion;
}

// separando
int Interfaz::obtenerOpcionMenuVentaDirecta()
{
	int opcionMenuVentaDirecta = 0;
	bool opcionValida = false;

	while (!opcionValida)
	{
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "\tQue desea agregar al carrito" << std::endl;
		std::cout << "1. Sistema Personalizado" << std::endl;
		std::cout << "2. Sistema Preconfigurado" << std::endl;
		std::cout << "3. Componente Separado" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite una opcion del menu: ";
		std::cin >> opcionMenuVentaDirecta;
		std::cout << "----------------------------------------------------------------------------" << std::endl;

		if (opcionMenuVentaDirecta >= 1 && opcionMenuVentaDirecta <= 3)
		{
			opcionValida = true;
		}
		else
		{
			std::cout << "Opcion invalida. Por favor, intente nuevamente." << std::endl;
			pauseAndClearScreen();
		}

		// Limpiamos el buffer de entrada
		clearInputBuffer();
	}

	return opcionMenuVentaDirecta;
}

Componente* Interfaz::crearSistemaPersonalizado()
{
	Creador* factory = new CreadorSistemaPersonalizado();
	std::cout << "-----------------------CREANDO SISTEMA PERSONALIZADO------------------------" << std::endl;
	Componente* componente = factory->crearSistemaDeAudio();
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	delete factory;

	return componente;
}

Componente* Interfaz::escogerSistemaPreconfigurado()
{
	std::string codigo;

	Interfaz::menuMantenimientoVerCatalogoComponentes();

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
	system("pause");
	clearScreen();

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
	bool opcionValida = false;

	while (!opcionValida)
	{
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "\tQue desea agregar al carrito" << std::endl;
		std::cout << "1. Sistema Preconfigurado" << std::endl;
		std::cout << "2. Componente Separado" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite una opcion del menu: ";
		std::cin >> opcionMenuVentaEnLinea;
		std::cout << "----------------------------------------------------------------------------" << std::endl;

		if (opcionMenuVentaEnLinea == 1 || opcionMenuVentaEnLinea == 2)
		{
			opcionValida = true;
		}
		else
		{
			std::cout << "Opcion invalida. Por favor, intente nuevamente." << std::endl;
			system("pause");
			clearScreen();
		}

		// Limpiamos el buffer de entrada
		clearInputBuffer();
	}

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
	std::cout << "--------------- Mantenimiento ---------------" << std::endl;
	std::cout << "1. Ver Lista de clientes" << std::endl;
	std::cout << "2. Ingresar un nuevo cliente" << std::endl;
	std::cout << "3. Ver el catalogo" << std::endl;
	std::cout << "4. Ingresar un sistema al catalogo" << std::endl;
	std::cout << "5. Eliminar un sistema del catalogo" << std::endl;
	std::cout << "6. Modificar un sistema del catalogo" << std::endl;
	std::cout << "7. Regresar" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcion;
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
			pauseAndClearScreen();
		}

	} while (opcionTipoCliente < 1 || opcionTipoCliente > 2);

	std::cout << "Ha seleccionado " << (opcionTipoCliente == 1 ? "Cliente Empresa" : "Cliente Persona") << std::endl;

	clearInputBuffer();
	// solicitar datos compartidoss
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Por favor digite los siguientes datos" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	solicitarDatosCompartidos(nombre, cedula, pais, ciudad);	// se pasan como referencia para que se puedan modificar
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

void Interfaz::solicitarDatosCompartidos(std::string& nombre, std::string& cedula, std::string& pais, std::string& ciudad)
{
	int numeroDeIntento = 0;

	// nombre del cliente o la empresa
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un nombre valido" << std::endl;
			pauseAndClearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el nombre: ";
		std::getline(std::cin, nombre);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(nombre, false, false, false,"nombre"));


	// cedula juridica o cedula normal
	numeroDeIntento = 0;	// se reinicia el numero de intentos
	bool existeOtroClienteConLaMismaCedula = false;
	do
	{
		if (numeroDeIntento != 0 && !existeOtroClienteConLaMismaCedula)	// por si la cedula es invalida y no existe otro cliente con la misma cedula
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite una cedula valida" << std::endl;
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			pauseAndClearScreen();
		}

		if (existeOtroClienteConLaMismaCedula)	// por si la cedula es valida pero ya existe otro cliente con la misma cedula
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Ya existe un cliente con esa cedula" << std::endl;
			std::cout << "Por favor digite una cedula diferente" << std::endl;
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			pauseAndClearScreen();
		}

		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite la cedula: ";
		std::getline(std::cin, cedula);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;

		// validar que no haya otro cliente con la misma cedula

		try
		{
			existeOtroClienteConLaMismaCedula = tienda->existeUsuarioRegistrado(cedula);
		}
		catch (std::exception&)
		{
			// si se lanza una excepcion es porque la lista esta vacia, lo que significa que no hay otro cliente con la misma cedula
			existeOtroClienteConLaMismaCedula = false;
		}

	// mientras el string no sea valido o exista otro cliente con la misma cedula
	} while (!esStringValido(cedula, false, true, false, "numero de cedula") || existeOtroClienteConLaMismaCedula);	// se permite que la cedula tenga numeros

	// pais
	numeroDeIntento = 0;	// se reinicia el numero de intentos

	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un pais valido" << std::endl;
			pauseAndClearScreen();
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
			pauseAndClearScreen();
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
			pauseAndClearScreen();
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
			pauseAndClearScreen();
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
			pauseAndClearScreen();
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
	Creador* fabrica = new CreadorPreConfiguradoFactory();
	Componente* componentePreConfigurado = nullptr;
	componentePreConfigurado = fabrica->crearSistemaDeAudio();

	// verificar que no exita otro sistema de audio con ese codigo
	std::string codigo;
	
	bool seModificoElCodigo = false;

	while (true) {
		try 
		{
			if (tienda->existeOtroSistemaPreconfigurado(componentePreConfigurado->getCodigo())) 
			{
				seModificoElCodigo = true;
				clearInputBuffer();
				std::cout << "----------------------------------------------------------------------------" << std::endl;
				std::cout << "Ups... parece que ya existe un sistema de audio con ese codigo" << std::endl;
				std::cout << "----------------------------------------------------------------------------" << std::endl;
				int numeroDeIntento = 0;
				do 
				{
					if (numeroDeIntento != 0) 
					{
						std::cout << "----------------------------------------------------------------------------" << std::endl;
						std::cout << "Por favor digite un codigo valido" << std::endl;
						pauseAndClearScreen();
					}
					std::cout << "----------------------------------------------------------------------------" << std::endl;
					std::cout << "Por favor digite otro codigo: ";
					std::getline(std::cin, codigo);
					std::cout << "----------------------------------------------------------------------------" << std::endl;
					numeroDeIntento++;
				} while (!esStringValido(codigo, false, true, false, "codigo"));    // se permite que el codigo tenga numeros
				componentePreConfigurado->setCodigo(codigo);

				std::cout << "----------------------------------------------------------------------------" << std::endl;
			}
			else 
			{
				break;  // Sale del bucle while si no existe otro sistema con el mismo código
			}
		}
		catch (const std::exception&) 
		{
			break;  // Sale del bucle while si la lista está vacía
		}
	}


	try
	{
		componentePreConfigurado->setPrecio(componentePreConfigurado->getPrecio() * 0.35 + componentePreConfigurado->getPrecio() * 0.35);	// se le agrega el 35% de ganancia
		tienda->agregarComponente(componentePreConfigurado);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	clearScreen();
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "El sistema de audio se ha agregado exitosamente al catalogo" << std::endl;	
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	delete fabrica;
	delete componentePreConfigurado;
}

void Interfaz::menuMantenimientoEliminarComponenteCatalogo()
{
	std::string codigo;
	int numeroDeIntento = 0;
	
	// Se muestra el catalogo
	menuMantenimientoVerCatalogoComponentes();

	// solicitar y comprobar que sea valida (no puede ser vacia ni tener caracteres especiales, solo letras y numeros)
	clearInputBuffer();	// se limpia el buffer de entrada
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un codigo valido" << std::endl;
			pauseAndClearScreen();
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

	pauseAndClearScreen();

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "El componente se ha eliminado exitosamente del catalogo" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

}

int Interfaz::menuMantenimientoModificarSistemaCatalogo()
{
	int opcionDelMenu = 0;
	int numeroDeIntento = 0;
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite una opcion valida" << std::endl;
			pauseAndClearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "\t\tMenu de opciones" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "1. Modificar nombre" << std::endl;
		std::cout << "2. Modificar codigo" << std::endl;
		std::cout << "3. Modificar componentes" << std::endl;
		std::cout << "4. Regresar" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite una opcion del menu: ";
		std::cin >> opcionDelMenu;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
	} while (opcionDelMenu < 1 || opcionDelMenu > 4);

	return opcionDelMenu;
}

std::string Interfaz::menuMantenimientoModificarSistemaCatalogoSolicitarCodigo()
{
	std::string codigo;
	int numeroDeIntento = 0;
	clearInputBuffer();	// se limpia el buffer de entrad

	// mostrar los sistemas preconfigurados actuales
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Catalogo de sistemas preconfigurados" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	try
	{
		std::cout << tienda->mostrarComponentesDelCatalagoReducido() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un codigo valido" << std::endl;
			pauseAndClearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el codigo del sistema que desea modificar: ";
		std::getline(std::cin, codigo);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(codigo, false, true, false, "codigo"));	// se permite que el codigo tenga numeros

	return codigo;
}

std::string Interfaz::menuMantenimientoModificarNombreSistemaPreconfigurado()
{
	// solicita el nuevo nombre del sistema preconfigurado y lo retorna
	std::string nombreNuevo;
	int numeroDeIntento = 0;
	clearInputBuffer();	// se limpia el buffer de entrada

	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un nombre valido" << std::endl;
			pauseAndClearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el nuevo nombre del sistema preconfigurado: ";
		std::getline(std::cin, nombreNuevo);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(nombreNuevo, true, false, false, "nombre"));	// se permite que el nombre tenga espacios

	return nombreNuevo;

}

std::string Interfaz::menuMantenimientoModificarCodigoSistemaPreconfigurado()
{
	// solicita el nuevo nombre del sistema preconfigurado y lo retorna
	std::string codigoNuevo;
	int numeroDeIntento = 0;
	bool existeOtroSistemaPreconfigurado = false;

	clearInputBuffer();	// se limpia el buffer de entrada

	do
	{
		existeOtroSistemaPreconfigurado = false;
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un codigo valido" << std::endl;
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			pauseAndClearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el nuevo codigo del sistema preconfigurado: ";
		std::getline(std::cin, codigoNuevo);
		std::cout << "----------------------------------------------------------------------------" << std::endl;

		// comprobar que el codigo no exista en el catalogo
		if (tienda->existeOtroSistemaPreconfigurado(codigoNuevo))
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "El codigo ya existe en el catalogo" << std::endl;
			pauseAndClearScreen();
			existeOtroSistemaPreconfigurado = true;
		}


		numeroDeIntento++;
	} while (!esStringValido(codigoNuevo, false, true, false, "nombre") || existeOtroSistemaPreconfigurado);	// se permite que el codigo tenga numeros

	return codigoNuevo;
}

int Interfaz::menuMantemientoCambiarUnComponenteDelSistema()
{
	int opcion = 0;
	int numeroDeIntento = 0;
	clearInputBuffer();	// se limpia el buffer de entrada

	do
	{
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "\t\tMenu de opciones" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "1. Cambiar el procesador de senal" << std::endl;
		std::cout << "2. Cambiar la fuente de audio" << std::endl;
		std::cout << "3. Cambiar el tipo de parlante" << std::endl;
		std::cout << "Ingrese una opcion del menu: ";
		std::cin >> opcion;

	} while (opcion < 1 || opcion > 3);	// unicamente se aceptan las opciones 1, 2 y 3

	return opcion;
}

int Interfaz::menuReportes()
{
	// En la opción 1, muestre el producto que mas se ha vendido (sea componente o sistema)
	//En la opción 2, muestre el total de ventas según todos los productos vendidos, especifique cuantos fueron componente y cuantos fueron sistemas
	int opcion;
	std::cout << "----------------- Reportes ------------------" << std::endl;
	std::cout << "\t\tReportes" << std::endl;
	std::cout << "1. Reporte equipos mas vendidos" << std::endl;
	std::cout << "2. Reporte ventas" << std::endl;
	std::cout << "3. Salir" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Digite una opcion del menu: ";
	std::cin >> opcion;
	return opcion;
}

 void Interfaz::menuReportesComponenteMasVendido()
 {
	//1, muestre el producto que mas se ha vendido(sea componente o sistema)
	std::cout << "----------- Componente Mas Vendido ------------" << std::endl;
	try
	{
		std::cout << tienda->mostrarComponenteMasVendido() << std::endl;
		pauseScreen();
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
		 pauseScreen();
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
			pauseAndClearScreen();
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
	pauseAndClearScreen();
}

void Interfaz::salir()
{
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Saliendo del programa" << std::endl;
	pauseAndClearScreen();

	try
	{
		tienda->guardarClientes();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		tienda->guardarVentas();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		tienda->guardarCatalogo();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Interfaz::opcionInvalida()
{
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "Opcion invalida" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	pauseAndClearScreen();
}
