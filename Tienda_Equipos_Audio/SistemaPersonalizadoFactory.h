#pragma once
#include "AbstractFactory.h"
class SistemaPersonalizadoFactory :
    public AbstractFactory
{
public:
    virtual Componente* crearSistemaDeAudio();
};

