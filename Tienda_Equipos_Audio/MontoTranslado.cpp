#include "MontoTranslado.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

#include "Mapa.h"
double MontoTranslado::getMonto(std::string codigo)
{
	Mapa<std::string, double> montos;
	montos.insertar("010", 175.00);
	montos.insertar("020", 150.00);
	montos.insertar("030", 160.00);
	montos.insertar("031", 150.00);
	montos.insertar("032", 100.00);
	montos.insertar("040", 200.00);
	montos.insertar("050", 200.00);
	montos.insertar("060", 250.00);
	montos.insertar("090", 50.00);
	montos.insertar("091", 80.00);
	
	// si la clave no existe se inserta al mapa con un valor predeterminado entonces se debe de tener en cuenta

	if (montos.encontrar(codigo))
	{
		return montos[codigo];
	}
	else
	{
		throw CodigoDeCiudadNoValidoException(codigo);	// Lanzo una excepcion si el codigo no es valido ( esto no no va a pasar porque ya lo verifico en el metodo disponibilidadDeEnvio() )
	}
}

bool MontoTranslado::disponibilidadDeEnvio(std::string codigo)
{
	return codigo == "010" || codigo == "020" || codigo == "030" || codigo == "031" || codigo == "032" || codigo == "040" || codigo == "050" || codigo == "060" || codigo == "090" || codigo == "091";
}

// setw es para definir el ancho de la columna	(Unicamente lo estoy usando para que se vea bonito en la consola)
std::string MontoTranslado::mostrarLista()
{
	std::stringstream ss;
	ss << std::setw(10) << "Codigo" << std::setw(15) << "Pais" << std::setw(20) << "Ciudad" << std::setw(25) << "Costo de traslado" << std::endl;
	ss << std::setw(5) << "010" << std::setw(20) << "Argentina" << std::setw(23) << "Buenos Aires" << std::setw(20) << "175.00" << std::endl;
	ss << std::setw(5) << "020" << std::setw(20) << "Brasil" << std::setw(23) << "Brasilia" << std::setw(20) << "150.00" << std::endl;
	ss << std::setw(5) << "030" << std::setw(20) << "Canad�" << std::setw(23) << "Ontario" << std::setw(20) << "160.00" << std::endl;
	ss << std::setw(5) << "031" << std::setw(20) << "EEUU" << std::setw(23) << "California" << std::setw(20) << "150.00" << std::endl;
	ss << std::setw(5) << "032" << std::setw(20) << "EEUU" << std::setw(23) << "New York" << std::setw(20) << "100.00" << std::endl;
	ss << std::setw(5) << "040" << std::setw(20) << "Francia" << std::setw(23) << "Paris" << std::setw(20) << "200.00" << std::endl;
	ss << std::setw(5) << "050" << std::setw(20) << "Inglaterra" << std::setw(23) << "Londres" << std::setw(20) << "200.00" << std::endl;
	ss << std::setw(5) << "060" << std::setw(20) << "Italia" << std::setw(23) << "Milan" << std::setw(20) << "250.00" << std::endl;
	ss << std::setw(5) << "090" << std::setw(20) << "Costa Rica" << std::setw(23) << "GAM" << std::setw(20) << "50.00" << std::endl;
	ss << std::setw(5) << "091" << std::setw(20) << "Costa Rica" << std::setw(23) << "fuera de la GAM" << std::setw(20) << "80.00" << std::endl;
	return ss.str();
}