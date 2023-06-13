#pragma once
class VentaVaciaException
{
public:
	VentaVaciaException();
	virtual const char* what() const throw();
};

