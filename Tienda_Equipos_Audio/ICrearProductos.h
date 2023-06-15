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
    // mensaje para solicitar el nombre del sistema de audio al usuario
    static std::string mensajeNombreSistemaDeAudio();
    // mensaje para solicitar el codigo del sistema de audio al usuario
    static std::string mensajeCodigoSistemaDeAudio();   // esta funcion solo sera utilizada en la clase CreadorPreConfiguradoFactory

	// fuentes de audio
	static FuenteDeAudio* crearFuenteDeAudio();

	static FuenteDeAudio* crearUnidadCD();
	static FuenteDeAudio* crearTornamesa();
	static FuenteDeAudio* crearRadio();
	static FuenteDeAudio* crearUnidadBluetooth();
	static FuenteDeAudio* crearMicrofono();
	//procesador de senal
    static ProcesadorDeSenal* crearProcesadorDeSenal();

	static ProcesadorDeSenal* crearAmplificador();
	static ProcesadorDeSenal* crearMezclador();
	// parlantes 
    static ParlanteCat* crearParlanteCat();

	static ParlanteCat* crearParlante();
	static ParlanteCat* crearAudifono();
	// METODOS TEMPLATE
	template<class T>
	static T* crearProducto(const std::string productos[][3], int numProductos);
    // 
	template<class T>
    static T* crearCategoria(const std::string& mensaje, const std::string* opciones, T* (*funciones[])(), int numOpciones);
};


template<class T>
inline T* ICrearProductos::crearProducto(const std::string productos[][3], int numProductos)
{
    while (true)
    {
        // Mostrar las opciones de productos disponibles
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "Seleccione un modelo:" << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        for (int i = 0; i < numProductos; i++)
        {
            // Mostrar detalles de cada producto: modelo, caracter�stica y precio
            std::cout << i + 1 << ". Modelo: " << productos[i][0] << ", Caracteristica: " << productos[i][1]
                << ", Precio: $" << productos[i][2] << std::endl;
        }

        std::cout << "----------------------------------------------------------------------------" << std::endl;
        int opcion;
        std::cout << "Ingrese el numero de opcion: ";
        std::cin >> opcion;
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        pauseAndClearScreen();

        // Validar la entrada del usuario
        if (opcion >= 1 && opcion <= numProductos)
        {
            const std::string& modelo = productos[opcion - 1][0];
            const std::string& caracteristica = productos[opcion - 1][1];
            double precio = std::strtod(productos[opcion - 1][2].c_str(), nullptr);

            // Crear un nuevo producto con los detalles del producto seleccionado
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            // Mostrar mensaje de confirmacion, mostrando el nombre del producto seleccionado
            std::cout << "Ha seleccionado el producto modelo: " << modelo << std::endl;
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            return new T(modelo, caracteristica, precio);
        }
        else
        {
            // Mostrar mensaje de error
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            std::cout << "Opcion invalida. Por favor, ingrese un numero de opcion valido." << std::endl;
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            pauseAndClearScreen();
            clearInputBuffer(); // Limpiar los errores de entrada
        }
    }
}

template<class T>
inline T* ICrearProductos::crearCategoria(const std::string& mensaje, const std::string* opciones, T* (*funciones[])(), int numOpciones)
{
    while (true)
    {
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << mensaje << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        for (size_t i = 0; i < numOpciones; i++)
        {
            std::cout << i + 1 << ". " << opciones[i] << std::endl;
        }

        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "Ingrese el numero de la opcion que desea: ";
        int opcion;
        std::cin >> opcion;
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        pauseAndClearScreen();

        if (opcion >= 1 && opcion <= numOpciones)
        {
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            std::cout << "A continuacion se le mostraran los modelos disponibles para la categoria: " << opciones[opcion - 1] << std::endl;
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            pauseAndClearScreen();
            return funciones[opcion - 1]();
        }
        else
        {
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            std::cout << "Opcion invalida. Por favor, ingrese un numero de opcion valido." << std::endl;
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            pauseAndClearScreen();
            clearInputBuffer(); // Limpiar los errores de entrada
        }
    }
}