#include "MontoTranslado.h"

//código	país	ciudad	costo_traslado
//010	Argentina	Buenos Aires	175.00
//020	Brasil	Brasilia	150.00
//030	Canadá	Ontario	160.00
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
		throw new std::exception("Código de país no encontrado");
	}
}
