#include "AbstractFactory.h"
#include "AbstractFactory.h"

AbstractFactory::~AbstractFactory()
{
	if (_fuenteDeAudio != nullptr)
	{
		delete _fuenteDeAudio;
		_fuenteDeAudio = nullptr;
	}
	
	if (_procesadorDeSenal != nullptr)
	{
		delete _procesadorDeSenal;
		_procesadorDeSenal = nullptr;
	}

	if (_parlante != nullptr)
	{
		delete _parlante;
		_parlante = nullptr;
	}
}
