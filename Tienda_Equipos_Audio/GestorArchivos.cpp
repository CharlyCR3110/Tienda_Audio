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
