#pragma once
#include "Componente.h"
#include "ListaEnlazada.h"

class Catalogo
{
private:
	ListaEnlazada<Componente>* componentes;
public:
	Catalogo();
	Catalogo(const Catalogo& other);
	~Catalogo();
	Catalogo* clonar() const;
	void agregarComponente(Componente* componente);
	void eliminarComponente(Componente* componente);
	void eliminarComponentePorCodigo(std::string codigo);
	std::string mostrarCatalogo();
	std::string mostrarCategoriaDelCatalogo(std::string categoria);

	std::string guardarCatalogo();	// archivos

	Componente* buscarComponentePorCodigo(std::string codigo);
	bool existeOtroSistemaPreconfigurado(std::string codigo);

};