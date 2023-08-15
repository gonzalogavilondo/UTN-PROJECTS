#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa
**/

int main()
{
    Pila mazo,
         jugador1,
         jugador2;

    int cntCartas = 0,
             cnt  = 0;

    ///Inicializamos las pilas
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    ///Cargamos la pila MAZO
    printf("--CARGAR DEL MAZO--\n");
    cargarPila(&mazo);

    printf("\n--MAZO ORIGINAL--\n");
    mostrar(&mazo);

    ///Se reparte a jugador 1 y jugador 2 solo si la cantidad de "cartas" (datos) que contiene la pila es par.
    while(!pilavacia(&mazo))
    {
        ///Cuento la cantidad de cartas
        cntCartas = longitudPila(&mazo);

        if(cntCartas % 2 == 0)
        {
            while(!pilavacia(&mazo)) ///Se reparten las cartas de forma alternativa
            {
                if(cnt % 2 == 0) // Se reparte el elemento a jugador 1
                {
                    apilar(&jugador1, desapilar(&mazo));
                }
                else // Se reparte el elemento a jugador 2
                {
                    apilar(&jugador2, desapilar(&mazo));
                }
                cnt++;
            }
        }
        else
        {
            printf("No hay cartas suficientes para repartir de forma equitativa.\n");
            exit(1); //El codigo de error es 1. Si quisiera mapear los tipos de errores mas adelante, el 1 seria que no hay cartas suficientes para repartir de forma equitativa
        }
    }
    printf("\n--JUGADOR 1--\n");
    mostrar(&jugador1);
    printf("\n--JUGADOR 2--\n");
    mostrar(&jugador2);

    return 0;
}
