#include "TiendaEnLineaFactory.h"

TiendaEnLineaFactory::TiendaEnLineaFactory()
{

}

TiendaEnLineaFactory::~TiendaEnLineaFactory()
{
}

FuenteDeAudio* TiendaEnLineaFactory::crearFuenteDeAudio()
{
	return nullptr;
}

ProcesadorDeSenal* TiendaEnLineaFactory::crearProcesadorDeSenal()
{
	return nullptr;
}

ParlanteCat* TiendaEnLineaFactory::crearParlante()
{
	return nullptr;
}

std::string TiendaEnLineaFactory::toString() const
{
	return std::string();
}
