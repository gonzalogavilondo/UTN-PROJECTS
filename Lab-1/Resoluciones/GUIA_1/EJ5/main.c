#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/***
    5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos
    cargados originalmente en ella, pero en orden inverso.
***/

    Pila dada,
         aux1,
         aux2;

    ///Inicializamos las pilas
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    ///Cargamos la pila
    cargarPila(&dada);

    ///Mostramos originalmente los valores de la pila
    printf("\nPila original sin modificarla\n");
    mostrar(&dada);

    ///Invertimos la pila
    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }

    ///Invertimos la pila nuevamente para tener la pila original pero en otro auxiliar
    while(!pilavacia(&aux1))
    {
        apilar(&aux2, desapilar(&aux1));
    }

    ///Desapilamos la auxiliar que es igual a la original para tener la pila original invertida
    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    printf("Pila modificada\n");
    mostrar(&dada);

    return 0;
}
