#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    13. Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Un
    jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al
    hacerlo coloca todas las cartas (las de él y las de su rival) en su pila de puntos. En caso de
    empate (y para simplificar) siempre gana el jugador1. Simular la ejecución del juego de tal
    manera que dada una pila MAZO (con un número de elementos múltiplo de cuatro)
    distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran
    jugado. Utilizar las pilas auxiliares que crea conveniente
**/

int main()
{
    Pila mazo, jugador1, jugador2, puntosJug1, puntosJug2, auxJugador1, auxJugador2;

    int puntosJugador1 = 0,
        puntosJugador2 = 0,
        cntCartas      = 0;

    ///Inicializamos pilas
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&puntosJug1);
    inicpila(&puntosJug2);
    inicpila(&auxJugador1);
    inicpila(&auxJugador2);

    printf("Ingrese las cartas\n");
    cargarPila(&mazo);

    ///Pausa y limpiamos pantalla
    system("pause");
    system("cls || clear");

    printf("--PILA MAZO--\n");
    mostrar(&mazo);

    ///Se reparte a jugador 1 y jugador 2 solo si la cantidad de "cartas" (datos) que contiene la pila es par.
    while(!pilavacia(&mazo))
    {
        ///Cuento la cantidad de cartas
        cntCartas = longitudPila(&mazo);

        if(cntCartas % 2 == 0)
        {
            while(!pilavacia(&mazo)) ///Se reparten las cartas (2 por jugador en cada mano)
            {
                apilar(&jugador1, desapilar(&mazo));
                apilar(&jugador1, desapilar(&mazo));

                apilar(&jugador2, desapilar(&mazo));
                apilar(&jugador2, desapilar(&mazo));
            }
        }
        else
        {
            printf("No hay cartas suficientes para repartir de forma equitativa.\n");
            exit(1); //El codigo de error es 1. Si quisiera mapear los tipos de errores mas adelante, el 1 seria que no hay cartas suficientes para repartir de forma equitativa
        }
    }

    ///Procesamiento principal
    while(!pilavacia(&jugador1) && !pilavacia(&jugador2))
    {
        puntosJugador1 += tope(&jugador1);
        puntosJugador2 += tope(&jugador2);

        apilar(&auxJugador1, desapilar(&jugador1));
        apilar(&auxJugador2, desapilar(&jugador2));
    }

    ///En caso de empate o si tiene mas puntos el jugador1 gana.
    if (puntosJugador1 >= puntosJugador2)
    {
        while(!pilavacia(&auxJugador1))
        {
            apilar(&puntosJug1, desapilar(&auxJugador1));
            apilar(&puntosJug1, desapilar(&auxJugador2));
        }
    }
    else
    {
        while(!pilavacia(&auxJugador2))
        {
            apilar(&puntosJug2, desapilar(&auxJugador2));
            apilar(&puntosJug2, desapilar(&auxJugador1));
        }
    }

    printf("PILA PUNTOS JUGADOR 1: %d", puntosJugador1);
    mostrar(&puntosJug1);

    printf("PILA PUNTOS JUGADOR 2: %d", puntosJugador2);
    mostrar(&puntosJug2);

    return 0;
}
