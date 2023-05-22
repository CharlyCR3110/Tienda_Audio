#include "ICrearProductos.h"

/*
	se esta trabajando con los modelos que vienen en el PDF. Ademas, estoy asumiendo que la tienda unicamente vende los productos(modelo) que se encuentran en el PDF.
*/

UnidadCD* ICrearProductos::crearUnidadCD()
{
//modelo:DF531 caracteristica: Unidad basica	 precio:100.00
//modelo: MT909	caracteristica: Proteccion de salto	 precio : 150.00
//modelo: CE230	caracteristica: Multiples velocidades	 precio : 175.00
//modelo: YF292	caracteristica: Soporte SACD	 precio : 200.00
    std::vector<std::tuple<std::string, std::string, double>> productos = {
        std::make_tuple("DF531", "Unidad basica", 100.00),
        std::make_tuple("MT909", "Proteccion de salto", 150.00),
        std::make_tuple("CE230", "Multiples velocidades", 175.00),
        std::make_tuple("YF292", "Soporte SACD", 200.00)
    };

    return crearProducto<UnidadCD>(productos);
}

Tornamesa* ICrearProductos::crearTornamesa()
{
//Modelo:FF211	Caracteristica: Unidad basica 33 / 45 RPM	 Precio: 180.00
//Modelo: HA401	Caracteristica: Soporte 78 RPM	 Precio: 230.00
//Modelo: EG266	Caracteristica: Brazo automatico	 Precio: 320.00
    std::vector<std::tuple<std::string, std::string, double>> productos = {
        std::make_tuple("FF211", "Unidad basica 33 / 45 RPM", 180.00),
        std::make_tuple("HA401", "Soporte 78 RPM", 230.00),
        std::make_tuple("EG266", "Brazo automatico", 320.00)
    };

    return crearProducto<Tornamesa>(productos);
}