#include "Fecha.h"

Fecha::Fecha() :
	_dia(0),
	_mes(0),
	_anio(0)
{
}

Fecha::Fecha(int dia, int mes, int anio) :
	_dia(dia),
	_mes(mes),
	_anio(anio)
{
}

Fecha::Fecha(const Fecha& fecha) :
	_dia(fecha._dia),
	_mes(fecha._mes),
	_anio(fecha._anio)
{
}

int Fecha::getDia() const
{
	return _dia;
}

int Fecha::getMes() const
{
	return _mes;
}

int Fecha::getAnio() const
{
	return _anio;
}

void Fecha::setDia(int dia)
{
	_dia = dia;
}

void Fecha::setMes(int mes)
{
	_mes = mes;
}

void Fecha::setAnio(int anio)
{
	_anio = anio;
}

std::string Fecha::toString() const
{
	std::stringstream ss;
	ss << _dia << "/" << _mes << "/" << _anio;
	return ss.str();
}

Fecha& Fecha::operator=(const Fecha& other)
{
	if (this != &other)
	{
		_dia = other._dia;
		_mes = other._mes;
		_anio = other._anio;
	}
	return *this;
}

bool Fecha::operator==(const Fecha& other) const
{
	return _dia == other._dia && _mes == other._mes && _anio == other._anio;
}

std::ostream& operator<<(std::ostream& out, const Fecha& other)
{
	out << other.toString();
	return out;
}
