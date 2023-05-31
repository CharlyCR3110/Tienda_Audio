#include "TiendaEnLineaFactory.h"

Componente* TiendaEnLineaFactory::crearProcesadorDeSenal()
{
    return ICrearProductos::crearProcesadorDeSenal();
}

Componente* TiendaEnLineaFactory::crearFuenteDeAudio()
{
    return ICrearProductos::crearFuenteDeAudio();
}

Componente* TiendaEnLineaFactory::crearParlanteCat()
{
    return ICrearProductos::crearParlanteCat();
}

Componente* TiendaEnLineaFactory::crearSistemaDeAudio()
{
    // Un sistema de audio tiene un procesador de se�al, una fuente de audio y un parlante
    Componente* sistemaDeAudio = new SistemaDeAudio();
    sistemaDeAudio->add(crearProcesadorDeSenal());
    sistemaDeAudio->add(crearFuenteDeAudio());
    sistemaDeAudio->add(crearParlanteCat());
	return sistemaDeAudio;
}