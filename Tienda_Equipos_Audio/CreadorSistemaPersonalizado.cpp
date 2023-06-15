#include "CreadorSistemaPersonalizado.h"

/* -------------------------------------------------------------------------------------------------

    EIF204 Programación II
    Proyecto 2

    5-0452-0687 Andres Ureña Guido			Grupo 02
    6-0489-0217 Carlos Gonzalez Garita		Grupo 02
    1-1886-0401 Sebastian Fuentes Jimenez	Grupo 03

------------------------------------------------------------------------------------------------- */

Componente* CreadorSistemaPersonalizado::crearSistemaDeAudio()
{
    // Un sistema de audio tiene un procesador de senal, una fuente de audio y un parlante

    // el codigo debe de ser una cadena string de 5 numeros aleatorios
    srand(static_cast<unsigned int>(time(NULL)));   // genera una semilla para el generador de numeros aleatorios (se usa static_cast para evitar un warning)
    std::string codigo = "";
    for (int i = 0; i < 5; i++)
    {
        int num = rand() % 10;
        char c = num + 48;
        codigo += c;
    }

    Componente* sistemaDeAudio = new SistemaDeAudio(codigo, ICrearProductos::mensajeNombreSistemaDeAudio(), "Sistema Personalizado");
    pauseAndClearScreen();
    sistemaDeAudio->add(crearProcesadorDeSenal());
    pauseAndClearScreen();
    sistemaDeAudio->add(crearFuenteDeAudio());
    pauseAndClearScreen();
    sistemaDeAudio->add(crearParlanteCat());
    pauseAndClearScreen();
    return sistemaDeAudio;
}
