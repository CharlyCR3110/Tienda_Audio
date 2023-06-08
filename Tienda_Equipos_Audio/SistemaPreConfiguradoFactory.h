#pragma once
#include "AbstractFactory.h"
class SistemaPreConfiguradoFactory :
    public AbstractFactory
{
public:
    virtual Componente* crearSistemaDeAudio();
};