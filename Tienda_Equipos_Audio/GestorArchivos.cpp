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