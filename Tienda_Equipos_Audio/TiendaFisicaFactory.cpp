#include "TiendaFisicaFactory.h"

Componente* TiendaFisicaFactory::crearProcesadorDeSenal()
{
    return ICrearProductos::crearProcesadorDeSenal();
}

Componente* TiendaFisicaFactory::crearFuenteDeAudio()
{
    return ICrearProductos::crearFuenteDeAudio();
}

Componente* TiendaFisicaFactory::crearParlanteCat()
{
    return ICrearProductos::crearParlanteCat();
}

Componente* TiendaFisicaFactory::crearSistemaDeAudio()
{
    // Un sistema de audio tiene un procesador de senal, una fuente de audio y un parlante
    Componente* sistemaDeAudio = new SistemaDeAudio();
    sistemaDeAudio->add(crearProcesadorDeSenal());
    sistemaDeAudio->add(crearFuenteDeAudio());
    sistemaDeAudio->add(crearParlanteCat());
    return sistemaDeAudio;
}
