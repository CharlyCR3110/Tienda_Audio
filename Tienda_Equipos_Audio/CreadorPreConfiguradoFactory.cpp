#include "CreadorPreConfiguradoFactory.h"

/* -------------------------------------------------------------------------------------------------

    EIF204 Programación II
    Proyecto 2

    5-0452-0687 Andres Ureña Guido			Grupo 02
    6-0489-0217 Carlos Gonzalez Garita		Grupo 02
    1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Componente* CreadorPreConfiguradoFactory::crearSistemaDeAudio()
{
    clearInputBuffer();
    // Un sistema de audio tiene un procesador de se�al, una fuente de audio y un parlante
    SistemaDeAudio* sistemaDeAudio = new SistemaDeAudio(ICrearProductos::mensajeCodigoSistemaDeAudio(), ICrearProductos::mensajeNombreSistemaDeAudio(), "Sistema Pre-Configurado");
    pauseAndClearScreen();
    sistemaDeAudio->add(crearProcesadorDeSenal());
    pauseAndClearScreen();
    sistemaDeAudio->add(crearFuenteDeAudio());
    pauseAndClearScreen();
    sistemaDeAudio->add(crearParlanteCat());
    pauseAndClearScreen();
	return sistemaDeAudio;
}