#pragma once
#include "AbstractFactory.h"
class TiendaFisicaFactory :
    public AbstractFactory
{
public:
    virtual Componente* crearProcesadorDeSenal();
    virtual Componente* crearFuenteDeAudio();
    virtual Componente* crearParlanteCat();
    virtual Componente* crearSistemaDeAudio();
};

