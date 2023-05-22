#pragma once
// fuentes de audio
#include "UnidadCD.h"
#include "Tornamesa.h"
#include "Radio.h"
#include "UnidadBluetooth.h"
#include "Microfono.h"
//procesador de senal
#include "Amplificador.h"
#include "Mezclador.h"
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
	static Tornamesa* crearTornamesa();
    static Radio* crearRadio();
    static UnidadBluetooth* crearUnidadBluetooth();
    static Microfono* crearMicrofono();

    // Procesador de senal
    static Amplificador* crearAplificador();
    static Mezclador* crearMezclador();

    // METODO TEMPLATE
	template<class T>
	static T* crearProducto(const std::vector<std::tuple<std::string, std::string, double>>& productos);
};

// Esta metodo es un template, por lo que se puede utilizar para crear cualquier tipo de producto.
// esto permite que el codigo sea mas limpio y no se tenga que repetir codigo.
template<class T>
inline T* ICrearProductos::crearProducto(const std::vector<std::tuple<std::string, std::string, double>>& productos)
{
    while (true)
    {
        // Mostrar las opciones de productos disponibles
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion:" << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        int i = 1;
        for (const auto& producto : productos)
        {
            // Mostrar detalles de cada producto: modelo, caracteristica y precio
            std::cout << i << ". Modelo: " << std::get<0>(producto) << ", Caracteristica: " << std::get<1>(producto)
                << ", Precio: $" << std::get<2>(producto) << std::endl;
            i++;
        }

        std::cout << "----------------------------------------------------------------------------" << std::endl;
        int opcion;
        std::cout << "Ingrese el numero de opcion: ";
        std::cin >> opcion;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        // Validar la entrada del usuario
        if (opcion >= 1 && opcion <= productos.size())
        {
            const auto& producto = productos[opcion - 1];
            // Crear un nuevo producto con los detalles del producto seleccionado
            return new T(std::get<0>(producto), std::get<1>(producto), std::get<2>(producto));
        }
        else
        {
            // Mostrar mensaje de error
            std::cout << "Opcion invalida. Por favor, ingrese un numero de opcion valido." << std::endl;
            clearInputBuffer(); // Limpiar los errores de entrada
        }
    }
}
