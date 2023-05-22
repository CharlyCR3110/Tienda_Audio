#pragma once
// fuentes de audio
#include "UnidadCD.h"
#include "Tornamesa.h"
#include "Radio.h"
#include "UnidadBluetooth.h"
#include "Microfono.h"
//procesador de senal
#include "Mezclador.h"
#include "Amplificador.h"
// parlantes 
#include "Parlante.h"
#include "Audifono.h"
// Funciones utiles
#include "FuncionesUtiles.h"
// STL
#include <vector>
#include <tuple>
class ICrearProductos
{
public:
	// fuentes de audio
	static UnidadCD* crearUnidadCD();


	template<class T>
	static T* crearProducto(const std::vector<std::tuple<std::string, std::string, double>>& productos);
	/*
	Nota: Podria hacer solamente un metodo y que este devuelva un Componente*. Y dependiendo del codigo(modelo) que introduzca el usuario devuelva el componente correspondiente.
	*/
};

// Esta metodo es un template, por lo que se puede utilizar para crear cualquier tipo de producto.
// esto permite que el codigo sea mas limpio y no se tenga que repetir codigo.
template<class T>
inline T* ICrearProductos::crearProducto(const std::vector<std::tuple<std::string, std::string, double>>& productos)
{
    while (true)
    {
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion:" << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        int i = 1;
        for (const auto& producto : productos)
        {
            std::cout << i << ". Modelo: " << std::get<0>(producto) << ", Caracteristica: " << std::get<1>(producto)
                << ", Precio: $" << std::get<2>(producto) << std::endl;
            i++;
        }

        std::cout << "----------------------------------------------------------------------------" << std::endl;
        int opcion;
        std::cout << "Ingrese el numero de opcion: ";
        std::cin >> opcion;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        // Validar entrada
        if (opcion >= 1 && opcion <= productos.size())
        {
            const auto& producto = productos[opcion - 1];
            return new T(std::get<0>(producto), std::get<1>(producto), std::get<2>(producto));
        }
        else
        {
            std::cout << "Opcion invalida. Por favor, ingrese un numero de opcion valido." << std::endl;
            clearInputBuffer();
        }
    }
}
