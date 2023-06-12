#pragma once
#include "Interfaz.h"

// excepciones
#include "OpcionInvalidaException.h"

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

	void controladorModificarSistemaDeAudio();

	void controladorCambiarUnComponenteDeSistemaDeAudio(Componente* componente);

	// reportes
	void controladorReportes();

};

