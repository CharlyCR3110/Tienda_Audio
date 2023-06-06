#pragma once
#include "Venta.h"
#include "MontoTranslado.h"

class VentaOnline :
	public Venta
{
public:
	VentaOnline();
	VentaOnline(Cliente* cliente, Fecha* fecha, std::string codigoLugarEntrega);
	VentaOnline(const VentaOnline& venta);
	~VentaOnline();
	virtual void calcularTotal() override;
	virtual void calcularSubtotal() override;
	virtual std::string generarFactura() override;
	virtual std::string toString() const override;

	std::string getCodigoLugarEntrega() const;

	virtual Venta* clonar() const override;
private:
	// codigo del lugar donde se debe entregar el producto
	std::string _codigoLugarEntrega;
};

