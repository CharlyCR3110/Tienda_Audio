#pragma once

#include "ICrearProductos.h"	// clase interfaz con los metodos staticos para crear productos
//{
//// fuentes de audio
//#include "UnidadCD.h"
//#include "Tornamesa.h"
//#include "Radio.h"
//#include "UnidadBluetooth.h"
//#include "Microfono.h"
////procesador de senal
//#include "Amplificador.h"
//#include "Mezclador.h"
//// parlantes 
//#include "Parlante.h"
//#include "Audifono.h"
//}
class AbstractFactory
{
public:
	virtual ~AbstractFactory();
	virtual FuenteDeAudio* crearFuenteDeAudio() = 0;
	virtual ProcesadorDeSenal* crearProcesadorDeSenal() = 0;
	virtual ParlanteCat* crearParlante() = 0;
	virtual std::string toString() const = 0;
protected:
	FuenteDeAudio* _fuenteDeAudio;
	ProcesadorDeSenal* _procesadorDeSenal;
	ParlanteCat* _parlante;
};