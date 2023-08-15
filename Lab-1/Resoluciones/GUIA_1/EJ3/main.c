#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/***
    3.	Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS
    todos aquellos elementos distintos al valor 8
***/

    Pila dada,
         distintos,
         descarte;

    ///Inicializamos las pilas
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&descarte);

    ///Cargo los valores de la pila por teclado
    cargarPila(&dada);

    ///Pausa y borramos pantalla
    system("pause");
    system("cls || clear");

    ///Mostramos por pantalla las pilas iniciales
    printf("--PILA DADA--\n");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        if (tope(&dada)!= 8)
        {
            apilar(&distintos, desapilar(&dada));
        }
        else
        {
            apilar(&descarte, desapilar(&dada)); //Guardo todos los "8s" en una pila descarte.
        }
    }


    printf("\n--PILA DISTINTOS--\n");
    mostrar(&distintos);

    return 0;
}
