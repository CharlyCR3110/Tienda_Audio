#pragma once
#include "Creador.h"
class CreadorSistemaPersonalizado :
    public Creador
{
public:
    virtual Componente* crearSistemaDeAudio();
};

