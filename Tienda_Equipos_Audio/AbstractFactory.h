#pragma once
// fuentes de audio
#include "UnidadCD.h"
#include "Tornamesa.h"
#include "Radio.h"
#include "UnidadBluetooth.h"
#include "Microfono.h"
//procesador de senal
#include "Amplificador.h"
#include "Mezclador.h"
// parlantes 
#include "Parlante.h"
#include "Audifono.h"

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