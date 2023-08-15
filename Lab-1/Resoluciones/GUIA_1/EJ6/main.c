#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/***
    6.Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
    dejando los restantes elementos en el mismo orden
***/

    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    ///Cargamos la pila
    cargarPila(&dada);

    ///Mostramos la pila original
    printf("Pila original. \n");
    mostrar(&dada);

    ///Tomamos el primer valor de la pila dada y lo guardamos en aux1
    if (!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }

    ///Vaciamos dada con los demas valores en aux2
    while(!pilavacia(&dada))
    {
        apilar(&aux2, desapilar(&dada));
    }

    ///Guardamos el primer dato de aux1 (que era el tope de DADA originalmente) y lo ponemos como primer elemento de DADA
    if(!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }

    ///Vaciamos lo que queda de aux2 en DADA y asi dejamos la pila original pero con el ultimo valor como base
    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    printf("Pila modificada. \n");
    mostrar(&dada);

    return 0;
}
