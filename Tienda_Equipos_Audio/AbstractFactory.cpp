#include "AbstractFactory.h"

Componente* AbstractFactory::crearProcesadorDeSenal()
{
    return ICrearProductos::crearProcesadorDeSenal();
}

Componente* AbstractFactory::crearFuenteDeAudio()
{
    return ICrearProductos::crearFuenteDeAudio();
}

Componente* AbstractFactory::crearParlanteCat()
{
    return ICrearProductos::crearParlanteCat();
}
