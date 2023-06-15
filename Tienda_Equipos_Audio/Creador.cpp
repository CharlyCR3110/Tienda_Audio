#include "Creador.h"

/* -------------------------------------------------------------------------------------------------

	EIF204 Programación II
	Proyecto 2

	5-0452-0687 Andres Ureña Guido			Grupo 02
	6-0489-0217 Carlos Gonzalez Garita		Grupo 02
	1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Componente* Creador::crearProcesadorDeSenal()
{
    return ICrearProductos::crearProcesadorDeSenal();
}

Componente* Creador::crearFuenteDeAudio()
{
    return ICrearProductos::crearFuenteDeAudio();
}

Componente* Creador::crearParlanteCat()
{
    return ICrearProductos::crearParlanteCat();
}
