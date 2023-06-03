#pragma once
#include "Venta.h"

class VentaDirecta :
	public Venta
{
public:
	VentaDirecta();
	VentaDirecta(Cliente* cliente, Fecha* fecha);
	VentaDirecta(const VentaDirecta& venta);
	~VentaDirecta();
	virtual void calcularTotal() override;
	virtual void calcularSubtotal() override;
	virtual std::string generarFactura() override;
	virtual std::string toString() const override;

	virtual Venta* clonar() const override;
};

