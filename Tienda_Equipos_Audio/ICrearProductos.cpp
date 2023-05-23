#include "ICrearProductos.h"

/*
	se esta trabajando con los modelos que vienen en el PDF. Ademas, estoy asumiendo que la tienda unicamente vende los productos(modelo) que se encuentran en el PDF.
*/

/*
    La firma de algunos metodos dice que retorna un puntero a X, pero en el cuerpo de la funcion se retorna un puntero a Y, Z, etc. Por ejemplo, algunos metodos dicen retornar un puntero a FuenteDeAudio, pero en el cuerpo de la funcion se retorna un puntero a Tornamesa, UnidadCD, etc.
    Esto se debe a que estas clases heredan de FuenteDeAudio, por lo que se puede retornar un puntero a cualquiera de estas clases. Ademas, no se puede retornar un puntero a FuenteDeAudio porque es una clase abstracta. (tiene metodos virtuales puros).
    
    Hablo de FuenteDeAudio, pero esto aplica para las demas clases (Parlante y ProcesadorDeSenal) y sus respectivas hijas. 
*/

// EMPIEZAN LAS FUENTES DE AUDIO

FuenteDeAudio* ICrearProductos::crearUnidadCD()
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

FuenteDeAudio* ICrearProductos::crearTornamesa()
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

FuenteDeAudio* ICrearProductos::crearRadio()
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

FuenteDeAudio* ICrearProductos::crearUnidadBluetooth()
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

FuenteDeAudio* ICrearProductos::crearMicrofono()
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

FuenteDeAudio* ICrearProductos::crearFuenteDeAudio()
{
    std::string mensaje = "Seleccione el tipo de fuente de audio que desea comprar:";
    std::vector<std::string> opciones = { "Unidad CD", "Tornamesa", "Radio", "Unidad Bluetooth", "Micr�fono" };
    std::vector<FuenteDeAudio* (*)()> funciones = { crearUnidadCD, crearTornamesa, crearRadio, crearUnidadBluetooth, crearMicrofono };  

    return crearCategoria<FuenteDeAudio>(mensaje, opciones, funciones);
}

// EMPIEZAN LOS PROCESADORES de SENAL

ProcesadorDeSenal* ICrearProductos::crearAplificador()
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

ProcesadorDeSenal* ICrearProductos::crearMezclador()
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

ProcesadorDeSenal* ICrearProductos::crearProcesadorDeSenal()
{
    std::string mensaje = "Seleccione el tipo de procesador de senal que desea comprar:";
    std::vector<std::string> opciones = { "Amplificador", "Mezclador" };
    std::vector<ProcesadorDeSenal* (*)()> funciones = { crearAplificador, crearMezclador };

    return crearCategoria<ProcesadorDeSenal>(mensaje, opciones, funciones);
}

// EMPIEZAN LOS PARLANTES

ParlanteCat* ICrearProductos::crearParlante()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos =
    {
        std::make_tuple("MK537", "200W", 235.00),
        std::make_tuple("WR390", "400W", 275.00),
        std::make_tuple("SE772", "400W perfil plano", 315.00),
        std::make_tuple("HT863", "400W inalambrico", 355.00),
        std::make_tuple("SN791", "300W 4 canales", 395.00),
        std::make_tuple("EA457", "280W subwoofer", 435.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<Parlante>(productos);
}

ParlanteCat* ICrearProductos::crearAudifono()
{
    // vector de tuplas que contiene el modelo, caracteristica y precio de cada producto
    std::vector<std::tuple<std::string, std::string, double>> productos =
    {
        std::make_tuple("UK930", "Basico(intraural)", 20.00),
        std::make_tuple("DV270", "Basico(supraural.diadema)", 40.00),
        std::make_tuple("AA891", "Basico(circumaural)", 45.00),
        std::make_tuple("SZ314", "Basico(inalambrico)", 60.00),
        std::make_tuple("OC829", "Circumaural bajos profundos", 90.00),
        std::make_tuple("YG838", "Inalambrico bajos profundos", 120.00)
    };

    // se llama a la funcion template para crear el producto
    return crearProducto<Audifono>(productos);
}

ParlanteCat* ICrearProductos::crearParlanteCat()
{
    std::string mensaje = "Seleccione el tipo de parlante que desea comprar:";
    std::vector<std::string> opciones = { "Parlante", "Audifono" };
    std::vector<ParlanteCat* (*)()> funciones = { crearParlante, crearAudifono };

    return crearCategoria<ParlanteCat>(mensaje, opciones, funciones);
}
