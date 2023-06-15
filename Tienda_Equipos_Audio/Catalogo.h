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

	std::string toStringReducido();

	bool estaVacio();

	std::string guardarCatalogo();	// archivos

	Componente* buscarComponentePorCodigo(std::string codigo);

	// retorna un puntero a un componente del catalogo, para poder modificarlo directamente
	Componente* obtenerPunteroAComponente(std::string codigo);

	bool existeOtroSistemaPreconfigurado(std::string codigo);

};