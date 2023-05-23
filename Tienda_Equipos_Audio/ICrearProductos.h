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
    // podria haber un metodo para cada tipo de fuente de audio, pero eso implicaria hacer cast en otras partes del codigo
	static FuenteDeAudio* crearUnidadCD();
	static FuenteDeAudio* crearTornamesa();
    static FuenteDeAudio* crearRadio();
    static FuenteDeAudio* crearUnidadBluetooth();
    static FuenteDeAudio* crearMicrofono();

    static FuenteDeAudio* crearFuenteDeAudio();

    // Procesador de senal
    static ProcesadorDeSenal* crearAplificador();
    static ProcesadorDeSenal* crearMezclador();

    static ProcesadorDeSenal* crearProcesadorDeSenal();
    // Parlantes
    static ParlanteCat* crearParlante();
    static ParlanteCat* crearAudifono();

    // METODO TEMPLATE
	template<class T>
	static T* crearProducto(const std::vector<std::tuple<std::string, std::string, double>>& productos);

    // recibe un vector con el nombre de las categorias, luego se utilizan los metodos que ya existen para crear los productos
    template<class T>
    static T* crearCategoria(const std::string& mensaje, const std::vector<std::string>& opciones, const std::vector<T* (*)()>& funciones);
    // mensaje representa el mensaje que se muestra al usuario
    // opciones representa las opciones que se muestran al usuario
    // funciones representa las funciones que se llaman para crear el producto
    /*
    const std::vector<T* (*)()>& funciones es una declaracion de parametro de funcion que indica que se espera un vector de punteros a funciones que no tienen parametros y devuelven un puntero a un objeto de tipo T
    */
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
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            std::cout << "Opcion invalida. Por favor, ingrese un numero de opcion valido." << std::endl;
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            clearInputBuffer(); // Limpiar los errores de entrada
        }
    }
}

template<class T>
inline T* ICrearProductos::crearCategoria(const std::string& mensaje, const std::vector<std::string>& opciones, const std::vector<T* (*)()>& funciones)
{
    while (true)
    {
        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << mensaje << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        for (size_t i = 0; i < opciones.size(); i++)
        {
            std::cout << i + 1 << ". " << opciones[i] << std::endl;
        }

        std::cout << "----------------------------------------------------------------------------" << std::endl;
        std::cout << "Ingrese el numero de la opcion que desea: ";
        int opcion;
        std::cin >> opcion;
        std::cout << "----------------------------------------------------------------------------" << std::endl;

        if (opcion >= 1 && opcion <= opciones.size())
        {
            return funciones[opcion - 1]();
        }
        else
        {
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            std::cout << "Opcion invalida. Por favor, ingrese un numero de opcion valido." << std::endl;
            std::cout << "----------------------------------------------------------------------------" << std::endl;
            clearInputBuffer(); // Limpiar los errores de entrada
        }
    }
}