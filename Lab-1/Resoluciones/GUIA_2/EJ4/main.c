#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
    4- Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo
    pilas
**/
int main()
{
    Pila pila, pilaMenor, aux;
    int flagEncontrado = 0,
        valor          = 0;

    ///Inicializamos todas las pilas
    inicpila(&pila);
    inicpila(&pilaMenor);
    inicpila(&aux);

    ///Cargamos ambas pilas
    printf("Ingrese los datos para la pila\n");
    cargarPila(&pila);

    ///MOSTRAMOS LA PILA
    printf("--PILA--\n");
    mostrar(&pila);

    while (!pilavacia(&pila))
    {
        valor = desapilar(&pila);
        if (!flagEncontrado || valor < tope(&pilaMenor))
        {
            if (flagEncontrado)
            {
                apilar(&aux, desapilar(&pilaMenor)); ///SIEMPRE ME VA A QUEDAR EL ULTIMO MENOR NADA MAS.
            }
            apilar(&pilaMenor, valor);
            flagEncontrado = 1; //Flag que se encontro un nuevo valor menor.
        }
        else
        {
            apilar(&aux, valor);
        }
    }

    ///Volvemos a dejar la pila con todos sus valores menos el menor encontrado
    while(!pilavacia(&aux))
    {
        apilar(&pila, desapilar(&aux));
    }

    ///MOSTRAMOS LA PILA
    printf("\n\t---RESULTADOS FINALES---\n\n");
    printf("--PILA--\n");
    mostrar(&pila);

    printf("--PILA MENOR VALOR--\n");
    mostrar(&pilaMenor);

    return 0;
}
