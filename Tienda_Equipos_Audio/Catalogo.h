#pragma once
#include "Componente.h"
#include "ListaEnlazada.h"

class Catalogo
{
private:
	ListaEnlazada<Componente>* componentes;
public:
	Catalogo();
	~Catalogo();
	void agregarComponente(Componente* componente);
	void eliminarComponente(Componente* componente);
	void eliminarComponentePorCodigo(std::string codigo);
	std::string mostrarCatalogo();
	std::string mostrarCategoriaDelCatalogo(std::string categoria);
};