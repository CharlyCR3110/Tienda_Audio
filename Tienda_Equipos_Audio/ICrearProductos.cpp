#include "ICrearProductos.h"

// fuentes de audio

std::string ICrearProductos::mensajeNombreSistemaDeAudio()
{
	std::string nombre;
	bool esNombreValido = false;

	while (!esNombreValido)
	{
		std::cout << "Digite el nombre que tendra sus sistema de audio: ";
		std::getline(std::cin, nombre);

		if (nombre.empty())
		{
			std::cerr << "Error: El nombre del sistema no puede estar vacio." << std::endl;
			clearInputBuffer();
			continue;
		}

		bool esCadenaValida = true;
		for (char c : nombre)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			std::cerr << "Error: El nombre del sistema solo puede contener letras y espacios." << std::endl;
			clearInputBuffer();
			continue;
		}
		esNombreValido = true;
	}
	return nombre;
}

std::string ICrearProductos::mensajeCodigoSistemaDeAudio()
{
	//validar que no exista otro curso con el mismo codigo
	std::string codigo;
	int numeroDeIntento = 0;
	// solicitar y comprobar que sea valida (no puede ser vacia ni tener caracteres especiales, solo letras y numeros)
	do
	{
		if (numeroDeIntento != 0)
		{
			std::cout << "----------------------------------------------------------------------------" << std::endl;
			std::cout << "Por favor digite un codigo valido" << std::endl;
			std::system("pause");
			clearScreen();
		}
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << "Digite el codigo del sistema de audio que desea agregar: ";
		std::getline(std::cin, codigo);
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		numeroDeIntento++;
	} while (!esStringValido(codigo, false, true, false, "codigo"));	// se permite que el codigo tenga numeros

	return codigo;
}

// metodo para crear una fuente de audio de cualquier tipo
FuenteDeAudio* ICrearProductos::crearFuenteDeAudio()
{
	const std::string mensaje = "Seleccione el tipo de fuente de audio que desea:";
	const std::string opciones[] = { "Unidad CD", "Tornamesa", "Radio", "Unidad Bluetooth", "Micr�fono" };
	FuenteDeAudio* (*funciones[])() = { crearUnidadCD, crearTornamesa, crearRadio, crearUnidadBluetooth, crearMicrofono };

	return crearCategoria<FuenteDeAudio>(mensaje, opciones, funciones, sizeof(opciones) / sizeof(opciones[0]));
}

FuenteDeAudio* ICrearProductos::crearUnidadCD()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{ "DF531", "Unidad basica", "100.00" },
		{ "MT909", "Proteccion de salto", "150.00" },
		{ "CE230", "Multiples velocidades", "175.00" },
		{ "YF292", "Soporte SACD", "200.00" }
	};

	return crearProducto<UnidadCD>(productos, 4);
}

FuenteDeAudio* ICrearProductos::crearTornamesa()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"FF211", "Unidad basica 33 / 45 RPM", "180.00"},
		{"HA401", "Soporte 78 RPM", "230.00"},
		{"EG266", "Brazo automatico", "320.00"}
	};

	return crearProducto<Tornamesa>(productos, 3);
}

FuenteDeAudio* ICrearProductos::crearRadio()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"NW671", "Basico AM / FM", "90.00"},
		{"JU272", "Onda corta", "300.00"},
		{"OE214", "Sintonizador automatico", "220.00"},
		{"LZ248", "Sintonizador programable", "280.00"}
	};

	return crearProducto<Radio>(productos, 4);
}

FuenteDeAudio* ICrearProductos::crearUnidadBluetooth()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"YM396", "Basico", "70.00"},
		{"CE169", "Multicanal", "100.00"},
		{"HN871", "Receptor FM", "90.00"}
	};

	return crearProducto<UnidadBluetooth>(productos, 3);
}

FuenteDeAudio* ICrearProductos::crearMicrofono()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"GX610", "Alambrico", "90.00"},
		{"HE601", "Alambrico omnidireccional", "95.00"},
		{"EO222", "Inalambrico", "120.00"},
		{"IS308", "Inalambrico rango ampliado", "180.00"},
		{"UK405", "Inalambrico Bluetooth", "100.00"}
	};
	
	return crearProducto<Microfono>(productos, 5);
}

// PROCESADORES DE SENAL

// metodo para crear un procesador de se�al de cualquier tipo
ProcesadorDeSenal* ICrearProductos::crearProcesadorDeSenal()
{
	const std::string mensaje = "Seleccione el tipo de procesador de senal que desea:";
	const std::string opciones[] = { "Amplificador", "Mezclador" };
	ProcesadorDeSenal* (*funciones[])() = { crearAmplificador, crearMezclador };

	return crearCategoria<ProcesadorDeSenal>(mensaje, opciones, funciones, sizeof(opciones) / sizeof(opciones[0]));
}


ProcesadorDeSenal* ICrearProductos::crearAmplificador()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"CA188", "80W", "90.00"},
		{"SK956", "100W", "115.00"},
		{"JV322", "200W", "140.00"},
		{"UI569", "220W", "165.00"},
		{"YV439", "400W", "190.00"}
	};

	return crearProducto<Amplificador>(productos, 5);
}

ProcesadorDeSenal* ICrearProductos::crearMezclador()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"JC327", "2 canales analogicos", "70.00"},
		{"XJ941", "2 canales digitales", "85.00"},
		{"DB258", "4 canales analogicos", "130.00"},
		{"AN918", "4 canales digitales", "150.00"},
		{"AI821", "8 canales(digital / analogico)", "325.00"}
	};
	
	return crearProducto<Mezclador>(productos, 5);
}

// PARLANTES CAT

// metodo para crear un parlante de cualquier tipo
ParlanteCat* ICrearProductos::crearParlanteCat()
{
	const std::string mensaje = "Seleccione el tipo de parlante que desea:";
	const std::string opciones[] = { "Parlante", "Audifono" };
	ParlanteCat* (*funciones[])() = { crearParlante, crearAudifono };

	return crearCategoria<ParlanteCat>(mensaje, opciones, funciones, sizeof(opciones) / sizeof(opciones[0]));
}


ParlanteCat* ICrearProductos::crearParlante()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"MK537", "200W", "235.00"},
		{"WR390", "400W", "275.00"},
		{"SE772", "400W perfil plano", "315.00"},
		{"HT863", "400W inalambrico", "355.00"},
		{"SN791", "300W 4 canales", "395.00"},
		{"EA457", "280W subwoofer", "435.00"}
	};

	return crearProducto<Parlante>(productos, 6);
}

ParlanteCat* ICrearProductos::crearAudifono()
{
	// Arreglo que contiene el modelo, caracter�stica y precio de cada producto
	const std::string productos[][3] =
	{
		{"UK930", "Basico(intraural)", "20.00"},
		{"DV270", "Basico(supraural.diadema)", "40.00"},
		{"AA891", "Basico(circumaural)", "45.00"},
		{"SZ314", "Basico(inalambrico)", "60.00"},
		{"OC829", "Circumaural bajos profundos", "90.00"},
		{"YG838", "Inalambrico bajos profundos", "120.00"}
	};

	return crearProducto<Audifono>(productos, 6);
}
