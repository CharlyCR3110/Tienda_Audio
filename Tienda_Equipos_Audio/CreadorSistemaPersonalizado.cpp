#include "CreadorSistemaPersonalizado.h"

Componente* CreadorSistemaPersonalizado::crearSistemaDeAudio()
{
    // Un sistema de audio tiene un procesador de senal, una fuente de audio y un parlante

    // el codigo debe de ser una cadena string de 5 numeros aleatorios
    srand(time(NULL));
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
