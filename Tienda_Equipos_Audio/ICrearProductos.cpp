#include "ICrearProductos.h"

/*
	se esta trabajando con los modelos que vienen en el PDF. Ademas, estoy asumiendo que la tienda unicamente vende los productos(modelo) que se encuentran en el PDF.
*/

// EMPIEZAN LAS FUENTES DE AUDIO

UnidadCD* ICrearProductos::crearUnidadCD()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos = 
    {
        std::make_tuple("DF531", "Unidad basica", 100.00),
        std::make_tuple("MT909", "Proteccion de salto", 150.00),
        std::make_tuple("CE230", "Multiples velocidades", 175.00),
        std::make_tuple("YF292", "Soporte SACD", 200.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<UnidadCD>(productos);
}

Tornamesa* ICrearProductos::crearTornamesa()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos = 
    {
        std::make_tuple("FF211", "Unidad basica 33 / 45 RPM", 180.00),
        std::make_tuple("HA401", "Soporte 78 RPM", 230.00),
        std::make_tuple("EG266", "Brazo automatico", 320.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<Tornamesa>(productos);
}

Radio* ICrearProductos::crearRadio()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos =
    {
        std::make_tuple("NW671", "Basico AM / FM	 Precio", 90.00),
        std::make_tuple("JU272", "Onda corta", 300.00),
        std::make_tuple("OE214", "Sintonizador automatico", 220.00),
        std::make_tuple("LZ248", "Sintonizador programable", 280.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<Radio>(productos);
}

UnidadBluetooth* ICrearProductos::crearUnidadBluetooth()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos =
    {
		std::make_tuple("YM396", "Basico", 70.00),
		std::make_tuple("CE169", "Multicanal", 100.00),
		std::make_tuple("HN871", "Receptor FM", 90.00)
	};

    // se llama a la funcion template para crear el producto
	return crearProducto<UnidadBluetooth>(productos);
}

Microfono* ICrearProductos::crearMicrofono()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos =
    {
        std::make_tuple("GX610", "Alambrico", 90.00),
        std::make_tuple("HE601", "Alambrico omnidireccional", 95.00),
        std::make_tuple("EO222", "Inalambrico", 120.00),
        std::make_tuple("IS308", "Inalambrico rango ampliado", 180.00),
        std::make_tuple("UK405", "Inalambrico Bluetooth", 100.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<Microfono>(productos);
}

// EMPIEZAN LOS PROCESADORES de SENAL

Amplificador* ICrearProductos::crearAplificador()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos =
    {
        std::make_tuple("CA188", "80W", 90.00),
        std::make_tuple("SK956", "100W", 115.00),
        std::make_tuple("JV322", "200W", 140.00),
        std::make_tuple("UI569", "220W", 165.00),
        std::make_tuple("YV439", "400W", 190.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<Amplificador>(productos);
}

Mezclador* ICrearProductos::crearMezclador()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos =
    {
        std::make_tuple("JC327", "2 canales analogicos", 70.00),
        std::make_tuple("XJ941", "2 canales digitales", 85.00),
        std::make_tuple("DB258", "4 canales analogicos", 130.00),
        std::make_tuple("AN918", "4 canales digitales", 150.00),
        std::make_tuple("AI821", "8 canales(digital / analogico)", 325.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<Mezclador>(productos);
}
