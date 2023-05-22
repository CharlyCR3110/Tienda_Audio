#pragma once
#include "ParlanteCat.h"

class Audifono :
    public ParlanteCat
{
public:
	Audifono();
	Audifono(std::string modelo, std::string caracteristicas, double precio);
	Audifono(const Audifono& other);
	virtual ~Audifono();
	virtual std::string toString() const override;
	Audifono& operator=(const Audifono& other);
};

