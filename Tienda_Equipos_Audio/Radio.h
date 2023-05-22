#pragma once
#include "FuenteDeAudio.h"

class Radio :
	public FuenteDeAudio
{
public:
	Radio();
	Radio(std::string modelo, std::string caracteristicas, double precio);
	Radio(const Radio& other);
	virtual ~Radio();
	virtual std::string toString() const override;
	Radio& operator=(const Radio& other);
};

