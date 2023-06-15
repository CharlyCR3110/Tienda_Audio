#pragma once

// sistema de audio
#include "SistemaDeAudio.h"
// interfaz para crear los elementos
#include "ICrearProductos.h"

class Creador
{
public:
    virtual Componente* crearProcesadorDeSenal();
    virtual Componente* crearFuenteDeAudio();
    virtual Componente* crearParlanteCat();
    virtual Componente* crearSistemaDeAudio() = 0;
};