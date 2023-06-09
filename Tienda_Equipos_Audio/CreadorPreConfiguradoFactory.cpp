#include "CreadorPreConfiguradoFactory.h"

Componente* CreadorPreConfiguradoFactory::crearSistemaDeAudio()
{
    // Un sistema de audio tiene un procesador de se�al, una fuente de audio y un parlante
    SistemaDeAudio* sistemaDeAudio = new SistemaDeAudio(ICrearProductos::mensajeCodigoSistemaDeAudio(), ICrearProductos::mensajeNombreSistemaDeAudio(), "Sistema Pre-Configurado");
    sistemaDeAudio->add(crearProcesadorDeSenal());
    std::system("pause");
    clearScreen();
    sistemaDeAudio->add(crearFuenteDeAudio());
    std::system("pause");
    clearScreen();
    sistemaDeAudio->add(crearParlanteCat());
    std::system("pause");
    clearScreen();
	return sistemaDeAudio;
}