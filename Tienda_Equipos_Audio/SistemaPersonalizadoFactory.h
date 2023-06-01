#pragma once
#include "AbstractFactory.h"
class SistemaPersonalizadoFactory :
    public AbstractFactory
{
public:
    virtual Componente* crearProcesadorDeSenal();
    virtual Componente* crearFuenteDeAudio();
    virtual Componente* crearParlanteCat();
    virtual Componente* crearSistemaDeAudio();
};

