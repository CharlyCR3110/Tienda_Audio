#include "Creador.h"

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
