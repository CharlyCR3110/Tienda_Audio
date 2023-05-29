#pragma once
#include "AbstractFactory.h"
class TiendaEnLineaFactory :
    public AbstractFactory
{
public:
    TiendaEnLineaFactory();
    ~TiendaEnLineaFactory();
    FuenteDeAudio* crearFuenteDeAudio() override;
    ProcesadorDeSenal* crearProcesadorDeSenal() override;
    ParlanteCat* crearParlante() override;
    std::string toString() const override;
};

