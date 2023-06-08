#include "SistemaPreConfiguradoFactory.h"

Componente* SistemaPreConfiguradoFactory::crearSistemaDeAudio()
{
    // Un sistema de audio tiene un procesador de se�al, una fuente de audio y un parlante
    SistemaDeAudio* sistemaDeAudio = new SistemaDeAudio(ICrearProductos::mensajeCodigoSistemaDeAudio(), ICrearProductos::mensajeNombreSistemaDeAudio(), "Sistema Pre-Configurado");
    sistemaDeAudio->add(crearProcesadorDeSenal());
    sistemaDeAudio->add(crearFuenteDeAudio());
    sistemaDeAudio->add(crearParlanteCat());
	return sistemaDeAudio;
}