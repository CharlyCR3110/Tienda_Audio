#pragma once

// sistema de audio
#include "SistemaDeAudio.h"
// interfaz para crear los elementos
#include "ICrearProductos.h"

class AbstractFactory
{
public:
    virtual Componente* crearProcesadorDeSenal() = 0;
    virtual Componente* crearFuenteDeAudio() = 0;
    virtual Componente* crearParlanteCat() = 0;
    virtual Componente* crearSistemaDeAudio() = 0;
};