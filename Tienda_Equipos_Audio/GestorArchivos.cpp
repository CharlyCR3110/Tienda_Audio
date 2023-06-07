#include "GestorArchivos.h"

void GestorArchivos::guardarFecha(std::string fecha)
{
	std::ofstream archivo;
	archivo.open("../fecha.txt");

	if (archivo.fail())
	{
		throw std::runtime_error("Error al abrir el archivo fecha.txt");
	}

	archivo << fecha;
	archivo.close();
}

void GestorArchivos::guardarListaDeClientes(ListaEnlazada<Cliente>* clientes)
{
	std::ofstream archivoClientes("../clientes.txt");

	if (archivoClientes.fail())
	{
		throw std::runtime_error("Error al abrir el archivo clientes.txt");
	}

	// recorrer la lista de clientes
	for (int i = 0; i < clientes->getCantidad(); i++)
	{
		Cliente* cliente = clientes->get(i);
		// guardar los datos del cliente en el archivo
		archivoClientes << cliente->getTipo() << '|'; // tipo de cliente (P o E) // se usa | como separador
		// datos compartidos de empresa y persona
		archivoClientes << cliente->getNombre() << '|'; // nombre del cliente
		archivoClientes << cliente->getCedula() << '|'; // cedula del cliente
		archivoClientes << cliente->getPais() << '|'; // pais del cliente
		archivoClientes << cliente->getCiudad() << '|'; // ciudad del cliente

		// datos especificos de empresa
		if (cliente->getTipo() == 'E')
		{
			ClienteEmpresa* clienteEmpresa = dynamic_cast<ClienteEmpresa*>(cliente);
			archivoClientes << clienteEmpresa->getRazonSocial() << '|'; // razon social de la empresa
		}
		else // datos especificos de persona
		{
			ClientePersona* clientePersona = dynamic_cast<ClientePersona*>(cliente);
			archivoClientes << clientePersona->getCorreo() << '|'; // correo de la persona
			archivoClientes << clientePersona->getNacionalidad() << '|'; // nacionalidad de la persona
		}

		archivoClientes << '\n'; // salto de linea // representa el final de los datos de un cliente
	}

	archivoClientes.close();
}

void GestorArchivos::recuperarListaDeClientes(ListaEnlazada<Cliente>* clientes)
{
	std::ifstream archivoClientes("../clientes.txt");

	if (archivoClientes.fail())
	{
		throw std::runtime_error("Error al abrir el archivo clientes.txt");
	}

	std::string linea;
	while (std::getline(archivoClientes, linea))
	{
		// separar los datos de la linea
		std::string datos[7];
		int indice = 0;
		for (int i = 0; i < linea.length(); i++)
		{
			if (linea[i] == '|')
			{
				indice++;
			}
			else
			{
				datos[indice] += linea[i];
			}
		}

		// crear el cliente
		Cliente* cliente;
		if (datos[0] == "E")
		{
			cliente = new ClienteEmpresa(datos[1], datos[2], datos[3], datos[4], datos[5]);
		}
		else
		{
			cliente = new ClientePersona(datos[1], datos[2], datos[3], datos[4], datos[5], datos[6]);
		}

		// agregar el cliente a la lista
		clientes->insertarDato(cliente);
	}

	archivoClientes.close();
}

void GestorArchivos::guardarCatalogo(Catalogo* catalogo)
{
	std::ofstream archivoCatalogo("../catalogo.txt");

	if (archivoCatalogo.fail())
	{
		throw std::runtime_error("Error al abrir el archivo clientes.txt");
	}	
		
	archivoCatalogo << catalogo->guardarCatalogo();

	archivoCatalogo.close();
}

void GestorArchivos::recuperarCatalogo(Catalogo* catalogo)
{
	std::ifstream archivoCatalogo("../catalogo.txt");
 
	if (archivoCatalogo.fail())
	{
		throw std::runtime_error("Error al abrir el archivo clientes.txt");
	}

	std::string linea;
	while (std::getline(archivoCatalogo, linea))
	{
		
		// separar los datos de la linea
		std::string datos[6];
		int indice = 0;

		for (int i = 0; i < linea.length(); i++)
		{
			if (linea[i] == ';')
			{
				indice++;
			}
			else
			{
				datos[indice] += linea[i];
			}
		}

		// crear el sistema
		Componente* sistema = new SistemaDeAudio(datos[0], datos[1], "Sistema Pre-Configurado");

		sistema->add(recuperarComponenteEspecifico(datos[2]));
		sistema->add(recuperarComponenteEspecifico(datos[3]));
		sistema->add(recuperarComponenteEspecifico(datos[4]));

		catalogo->agregarComponente(sistema);
	}

	archivoCatalogo.close();

}

void GestorArchivos::guardarVentas(ListaEnlazada<Venta>* ventas)
{
	std::ofstream archivoVentas("../ventas.txt");

	if (archivoVentas.fail())
	{
		throw std::runtime_error("Error al abrir el archivo ventas.txt");
	}

	Nodo<Venta>* nodoVenta = ventas->getPrimero();
	while (nodoVenta != nullptr)
	{
		Venta* venta = nodoVenta->getDato();

		// guardar la cedula del cliente
		archivoVentas << venta->getCliente()->getCedula() << '|';

		// guardar la fecha de la venta
		archivoVentas << *venta->getFecha() << '|';	// obtiene la fecha con el formato dd/mm/aaaa

		// guardar el tipo de venta (Online (O) o Directa (D))
		archivoVentas << venta->getTipoDeVenta() << '|';

		// guardar los componentes de la venta
		Nodo<Componente>* nodoComponente = venta->getCarritoDeCompras()->getPrimero();
		while (nodoComponente != nullptr)
		{
			Componente* componente = nodoComponente->getDato();

			if (componente == nullptr)
			{
				throw std::runtime_error("Error al guardar la venta. El componente es nulo");
			}

			// si NO es un sistema de audio
			if (!dynamic_cast<SistemaDeAudio*>(componente))
			{
				// significa que es un componente especifico
				archivoVentas << componente->getCodigo() << '|';	// codigo del componente
				// obtener la cantidad de componentes que se vendieron
				archivoVentas << componente->getCantidadEnCarrito() << '|';
			}
			else
			{
				SistemaDeAudio* sistema = dynamic_cast<SistemaDeAudio*>(componente);
				// si es un sistema de audio (componente compuesto)
				// guardar el nombre y categoria
				archivoVentas << sistema->getNombreComponente() << '|';	// nombre del componente
				archivoVentas << sistema->getCategoria() << '|';	// categoria del componente

				// guardar el codigo de los 3 componentes que forman parte del sistema de audio

				// obtener los 3 componentes del sistema de audio
				for (int i = 0; i < 3; i++)
				{
					Componente* sistema = componente->getChild(i);
					archivoVentas << sistema->getCodigo() << '|';	// codigo del componente
				}

				// obtener la cantidad de sistemas de audio que se vendieron
				archivoVentas << componente->getCantidadEnCarrito() << '|';
			}

			nodoComponente = nodoComponente->getSiguiente();
		}

		archivoVentas << std::endl;	// salto de linea, para la siguiente venta

		nodoVenta = nodoVenta->getSiguiente();
	}

	archivoVentas.close();
}

Componente* GestorArchivos::recuperarComponenteEspecifico(std::string codigo)
{
	// unidades CD 

	if (codigo == "DF531") { return new UnidadCD("DF531", "Unidad basica", 100.00); }
	else if (codigo == "MT909") { return new UnidadCD("MT909", "Proteccion de salto", 150.00); }
	else if (codigo == "CE230") { return new UnidadCD("CE230", "Multiples velocidades", 175.00); }
	else if (codigo == "YF292") { return new UnidadCD("YF292", "Soporte SACD", 200.00); }

	// tornamesas

	if (codigo == "FF211") { return new Tornamesa("FF211", "Unidad basica 33 / 45 RPM", 180.00); }
	else if (codigo == "HA401") { return new Tornamesa("HA401", "Soporte 78 RPM", 230.00); }
	else if (codigo == "EG266") { return new Tornamesa("EG266", "Brazo automatico", 320.00); }

	// Ra 

	if (codigo == "NW671") { return new Radio("NW671", "Basico AM / FM", 90.00); }
	else if (codigo == "JU272") { return new Radio("JU272", "Onda corta", 300.00); }
	else if (codigo == "OE214") { return new Radio("OE214", "Sintonizador automatico", 220.00); }
	else if (codigo == "LZ248") { return new Radio("LZ248", "Sintonizador programable", 280.00); }

	// unidades bluetooth

	if (codigo == "YM396") { return new UnidadBluetooth("YM396", "Basico", 70.00); }
	else if (codigo == "OE214") { return new UnidadBluetooth("OE214", "Multicanal", 100.00); }
	else if (codigo == "HN871") { return new UnidadBluetooth("HN871", "Receptor FM", 90.00); }

	// microfonos

	if (codigo == "GX610") { return new Microfono("GX610", "Alambrico", 90.00); }
	else if (codigo == "HE601") { return new Microfono("HE601", "Alambrico omnidireccional", 95.00); }
	else if (codigo == "EO222") { return new Microfono("EO222", "Inalambrico", 120.00); }
	else if (codigo == "IS308") { return new Microfono("IS308", "Inalambrico rango ampliado", 180.00); }
	else if (codigo == "UK405") { return new Microfono("UK405", "Inalambrico Bluetooth", 100.00); }

	// amplificadores

	if (codigo == "CA188") { return new Amplificador("CA188", "80W", 90.00); }
	else if (codigo == "SK956") { return new Amplificador("SK956", "100W", 115.00); }
	else if (codigo == "JV322") { return new Amplificador("JV322", "200W", 140.00); }
	else if (codigo == "UI569") { return new Amplificador("UI569", "220W", 165.00); }
	else if (codigo == "YV439") { return new Amplificador("YV439", "400W", 190.00); }

	// mezcladores

	if (codigo == "JC327") { return new Mezclador("JC327", "2 canales analogicos", 70.00); }
	else if (codigo == "XJ941") { return new Mezclador("XJ941", "2 canales digitales", 85.00); }
	else if (codigo == "DB258") { return new Mezclador("AN918", "4 canales digitales", 150.00); }
	else if (codigo == "AN918") { return new Mezclador("AN918", "4 canales digitales", 150.00); }
	else if (codigo == "AI821") { return new Mezclador("AI821", "8 canales(digital / analogico)", 325.00); }

	// parlantes

	if (codigo == "MK537") { return new Parlante("MK537", "200W", 235.00); }
	else if (codigo == "WR390") { return new Parlante("WR390", "400W", 275.00); }
	else if (codigo == "SE772") { return new Parlante("SE772", "400W perfil plano", 315.00); }
	else if (codigo == "HT863") { return new Parlante("HT863", "400W inalambrico", 355.00); }
	else if (codigo == "SN791") { return new Parlante("SN791", "300W 4 canales", 395.00); }
	else if (codigo == "EA457") { return new Parlante("EA457", " 0W subwoofer", 435.00); }

	// audifonos

	if (codigo == "UK930") { return new Audifono("UK930", "Basico(intraural)", 20.00); }
	else if (codigo == "DV270") { return new Audifono("DV270", "Basico(supraural.diadema)", 40.00); }
	else if (codigo == "AA891") { return new Audifono("AA891", "Basico(circumaural)", 45.00); }
	else if (codigo == "SZ314") { return new Audifono("SZ314", "Basico(inalambrico)", 60.00); }
	else if (codigo == "OC829") { return new Audifono("OC829", "Circumaural bajos profundos", 90.00); }
	else if (codigo == "YG838") { return new Audifono("YG838", "Inalambrico bajos profundos", 120.00); }
}
