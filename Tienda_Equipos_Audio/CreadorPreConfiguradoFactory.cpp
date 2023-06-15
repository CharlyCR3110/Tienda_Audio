#include "CreadorPreConfiguradoFactory.h"

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