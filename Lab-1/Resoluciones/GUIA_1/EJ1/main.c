#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/***
    1.Cargar desde el teclado una pila DADA con 5 elementos.
    Pasar los tres primeros elementos a la pila aux1 y los dos restantes a la pila aux2,
    ambas pilas inicializadas en vacío.
***/

    Pila dada;
    Pila aux1;
    Pila aux2;

    ///Inicializo la pila
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    ///Cargamos la pila
    printf("Ingrese los 5 valores a cargar\n\n");
    for(int i = 0; i < 5; i++)
    {
        leer(&dada);
    }

    ///Apilo en aux1 los primeros 3 valores que desapilo de dada
    for(int i = 0; i < 3; i++)
    {
        apilar(&aux1, desapilar(&dada));
    }

    ///Apilo en aux2 los ultimos 2 valores que desapilo de dada
    for(int i = 0; i < 2; i++)
    {
        apilar(&aux2, desapilar(&dada));
    }

    ///Muestro las pilas por pantalla
    printf("\n\nPila aux1\n");
    mostrar(&aux1);
    printf("Pila aux2\n");
    mostrar(&aux2);

    return 0;
}
