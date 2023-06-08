#pragma once
#include "Interfaz.h"

class Controlador
{
public:
	void iniciar();

	void controladorPrincipal(int opcion);

	// venta directa
	void controladorVentaDirecta();

	Componente* controladorMenuVentaDirectaComprar();

	//	venta en linea
	void controladorVentaEnLinea();

	Componente* controladorMenuVentaEnLineaComprar();

	// mantenimiento
	void controladorMantenimiento();

	// reportes
	void controladorReportes();

};

