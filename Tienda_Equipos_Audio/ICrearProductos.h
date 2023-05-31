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
class ICrearProductos
{
	public:
	// fuentes de audio
	static FuenteDeAudio* crearUnidadCD();
	static FuenteDeAudio* crearTornamesa();
	static FuenteDeAudio* crearRadio();
	static FuenteDeAudio* crearUnidadBluetooth();
	static FuenteDeAudio* crearMicrofono();
	//procesador de senal
	static ProcesadorDeSenal* crearAmplificador();
	static ProcesadorDeSenal* crearMezclador();
	// parlantes 
	static ParlanteCat* crearParlante();
	static ParlanteCat* crearAudifono();
	// METODO TEMPLATE
	template<class T>
	static T* crearProducto(const std::string productos[][3], int numProductos);
};


template<class T>
inline T* ICrearProductos::crearProducto(const std::string productos[][3], int numProductos)
{
    while (true)
    {
        // Mostrar las opciones de productos disponibles
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "Seleccione una opcion:" << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        for (int i = 0; i < numProductos; i++)
        {
            // Mostrar detalles de cada producto: modelo, característica y precio
            std::cout << i + 1 << ". Modelo: " << productos[i][0] << ", Caracteristica: " << productos[i][1]
                << ", Precio: $" << productos[i][2] << std::endl;
        }

        std::cout << "----------------------------------------------------------------------------" << std::endl;
        int opcion;
        std::cout << "Ingrese el numero de opcion: ";
        std::cin >> opcion;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        // Validar la entrada del usuario
        if (opcion >= 1 && opcion <= numProductos)
        {
            const std::string& modelo = productos[opcion - 1][0];
            const std::string& caracteristica = productos[opcion - 1][1];
            double precio = std::strtod(productos[opcion - 1][2].c_str(), nullptr);

            // Crear un nuevo producto con los detalles del producto seleccionado
            return new T(modelo, caracteristica, precio);
        }
        else
        {
            // Mostrar mensaje de error
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            std::cout << "Opcion invalida. Por favor, ingrese un numero de opcion valido." << std::endl;
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            clearInputBuffer(); // Limpiar los errores de entrada
        }
    }
}
