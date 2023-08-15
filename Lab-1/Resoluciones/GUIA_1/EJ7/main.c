#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/***
    Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes
    elementos en el mismo orden.
***/

    Pila dada,
         aux;

    int base = 0,
        tope = 0;

    ///Inicializamos las pilas
    inicpila(&dada);
    inicpila(&aux);

    ///Cargamos la pila
    cargarPila(&dada);

    ///Mostramos la pila inicial
    printf("\nPila inicial.\n");
    mostrar(&dada);

    ///Tomamos el tope de la pila dada que va a ser la nueva base
    if (!pilavacia(&dada))
    {
        base = desapilar(&dada);
    }

    ///Guardamos lo que queda de la pila dada en aux
    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }

    ///Guardamos la nueva base en dada
    apilar(&dada, base);

    ///Agarramos el tope de la pila aux que va a ser el nuevo tope
    if (!pilavacia(&aux))
    {
        tope = desapilar(&aux);
    }

    ///Guardamos nuevamente en dada lo que quedo en aux para poner como tope a la base anterior
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    ///Apilamos el nuevo tope
    if (!pilavacia(&dada))
    {
        apilar(&dada, tope);
    }

    ///Mostramos los resultados
    printf("Pila resultante.\n");
    mostrar(&dada);


    return 0;
}
