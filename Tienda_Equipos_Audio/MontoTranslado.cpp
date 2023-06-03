#include "MontoTranslado.h"

//c�digo	pa�s	ciudad	costo_traslado
//010	Argentina	Buenos Aires	175.00
//020	Brasil	Brasilia	150.00
//030	Canad�	Ontario	160.00
//031	EEUU	California	150.00
//032	EEUU	New York	100.00
//040	Francia	Paris	200.00
//050	Inglaterra	Londres	200.00
//060	Italia	Milan	250.00
//090	Costa Rica(local)	GAM	50.00
//091	Costa Rica(local)	fuera de la GAM	80.00
double MontoTranslado::getMonto(std::string codigo)
{
	if (codigo == "010")
	{
		return 175.00;
	}
	else if (codigo == "020")
	{
		return 150.00;
	}
	else if (codigo == "030")
	{
		return 160.00;
	}
	else if (codigo == "031")
	{
		return 150.00;
	}
	else if (codigo == "032")
	{
		return 100.00;
	}
	else if (codigo == "040")
	{
		return 200.00;
	}
	else if (codigo == "050")
	{
		return 200.00;
	}
	else if (codigo == "060")
	{
		return 250.00;
	}
	else if (codigo == "090")
	{
		return 50.00;
	}
	else if (codigo == "091")
	{
		return 80.00;
	}
	else
	{
		throw new std::exception("C�digo de pa�s no encontrado");
	}
}

bool MontoTranslado::disponibilidadDeEnvio(std::string codigo)
{
	if (codigo == "010" || codigo == "020" || codigo == "030" || codigo == "031" || codigo == "032" || codigo == "040" || codigo == "050" || codigo == "060" || codigo == "090" || codigo == "091")
	{
		return true;
	}
	else
	{
		return false;
	}
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