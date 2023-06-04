#pragma once
#include "Interfaz.h"

class Controlador
{
public:
	void iniciar();

	void controladorPrincipal(int opcion);

	// Separando el menuVentaDirecta en partes
	void controladorVentaDirecta();

	Componente* controladorMenuVentaDirectaComprar();



	void controladorMantenimiento();

	void controladorReportes(); // en construccion

};

