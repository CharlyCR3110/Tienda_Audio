#pragma once
#include "Creador.h"
class CreadorPreConfiguradoFactory :
    public Creador
{
public:
    virtual Componente* crearSistemaDeAudio();
};