#pragma once
#include "AbstractFactory.h"
class TiendaEnLineaFactory :
    public AbstractFactory
{
public:
    virtual Componente* crearProcesadorDeSenal();
    virtual Componente* crearFuenteDeAudio();
    virtual Componente* crearParlanteCat();
    virtual Componente* crearSistemaDeAudio();
};